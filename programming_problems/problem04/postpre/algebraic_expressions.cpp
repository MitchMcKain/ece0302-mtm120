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
  //I tried modeling this after the textbook example first, but I couldn't figure it out with recursion -_-
  std::stack<string> expression;

  int length = postfix.length();

  for (int i = 0; i < length; i++)
    {
      char ch = postfix[i];
      if (isoperator(ch)) //if we encounter an operator, we must perform operation on two most recent operands
        {
          string op = "";
          op += ch;
          string first = expression.top(); //get the item from top of stack
          string second = expression.top(); //get the new item that has been moved to top
          op += first + second; //make the full prefix expression
          expression.push(op); //push full prefix expression to stack
        }
      else //we ecounter an operand
      {
        string op = "";
        op += ch;
        expression.push(op); //push operand onto the stack
      }
    }
}
