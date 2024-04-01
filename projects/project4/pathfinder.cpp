#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"
#include <vector>

//******************************************
//***********Function Prototypes************
//******************************************
std::vector<int> initial(Image<Pixel>);
bool goal(std::vector<int>, Image<Pixel>);
List< std::vector<int> > actions(std::vector<int>, Image<Pixel> &);
std::vector<int> breadthFirstSearch(Image<Pixel>);



//******************************************
//******************main********************
//******************************************
int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image = readFromFile(input_file);

  std::vector<int> soln = breadthFirstSearch(image);

  image(soln[0], soln[1]) = GREEN;

  // Write solution image to file
  writeToFile(image, output_file);
  
}



//******************************************
//***********Function Definitions***********
//******************************************
std::vector<int> initial(Image<Pixel> maze)
{
  std::vector<int> failedStartCoordinate{-1, -1};

  for(int i = 0; i < maze.height(); i++)
    {
      for(int j = 0; j < maze.width(); j++)
        {
          if (maze(i,j) == RED) //we found the starting spot
            {
              std::vector<int> startCoordinate{i, j};
              return startCoordinate;
            }
        }
    }

  return failedStartCoordinate;
}

bool goal(std::vector<int> s, Image<Pixel> maze) // see if we are at end
{
  if ((s[0] == 0 || s[1] == 0) && maze(s[0], s[1]) == WHITE)
    { return true; }
  else
    { return false; }
}

List< std::vector<int> > actions(std::vector<int> s, Image<Pixel>& maze)
{
  List< std::vector<int> > states;

  //check if we can move down
  if (maze(s[0] - 1, s[1]) == WHITE)
    { 
      std::vector<int> down{s[0] - 1, s[1]};
      states.insert(states.getLength(), down); 
    }

  //check if we can move up
  if (maze(s[0] + 1, s[1]) == WHITE)
    {
      std::vector<int> up{s[0] + 1, s[1]};
      states.insert(states.getLength(), up);
    }

  //check if we can move left
  if (maze(s[0], s[1] - 1) == WHITE)
    {
      std::vector<int> left{s[0], s[1] - 1};
      states.insert(states.getLength(), left);
    }

  //check if we can move right
  if (maze(s[0], s[1] + 1) == WHITE)
    {
      std::vector<int> right{s[0], s[1] + 1};
      states.insert(states.getLength(), right);
    }

  return states;
}

std::vector<int> breadthFirstSearch(Image<Pixel> problem)
{
  std::vector<int> s = initial(problem);
  if (goal(s, problem))
    { return s; } //the start is the exit

  List< std::vector<int> > initialMoves = actions(s, problem);
  Queue< std::vector<int>, List< std::vector<int> > > frontier;
  frontier.enqueue(s);

  int rows = problem.width();
  int cols = problem.height();
  std::vector< std::vector<bool> > explored(rows, std::vector<bool>(cols, false)); //this initializes explored to all false
 
  while (1)
  {
    if (frontier.isEmpty())
      { exit(EXIT_FAILURE); }

    s = frontier.peekFront();
    frontier.dequeue();
      
    if(goal(s, problem))
      { return s; } //we have found the exit

    explored[s[0]][s[1]] = true; //we have explored this pixel

    List< std::vector<int> > newActions = actions(s, problem);
    for (int i = 0; i < newActions.getLength(); i++)
      {
        if (explored[newActions.getEntry(i)[0]][newActions.getEntry(i)[1]] == false)
          { frontier.enqueue(newActions.getEntry(i)); }
      }
  }

}