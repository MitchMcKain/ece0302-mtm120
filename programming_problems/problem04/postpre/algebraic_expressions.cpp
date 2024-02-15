#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"
#include <stack>

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  /* string convert(string &preExp) {
  preLength = the length of preExp
  ch = first character in the preExp
  postExp = an empty string
  if (ch is a lowercase letter)
    // base case-single identifier
    postExp = postExp + ch
  else
    //pre has the form <operator> <prefix1> <prefix2>
    endFirst = endPre(preExp, 1) //Find the end of prefix1
    //Recursively convert prefix1 into postfix form
    postExp = postExp + convert(preExp[1..endFirst])
    //Recursively convert prefix2 into postfix form
    postExp = postExp + convert(preExp[endFirst + 1..preLength - 1])
    postExp = postExp + ch //Append the operator to the end of postExp
  }
  return postExp
  } */
  
  std::stack<string> expression;
  string postExp = postfix;
  int postLength = postfix.length();
  char ch = postfix[0];
  string preExp = "";
  if (isoperator(ch) ) // see if the first element is an operator
    { 
      prefix += ch;
      expression.push(prefix);
    }
  else // element must be a number
    {
      int endFirst = endPost(postfix, postLength);
      preExp += convert(postExp.substr(1,endFirst), preExp);
      preExp += convert(postExp.substr(endFirst + 1, postLength -1), preExp);
      preExp += ch;
      expression.push(ch);
    }
}
