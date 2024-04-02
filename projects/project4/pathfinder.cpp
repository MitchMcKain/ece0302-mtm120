#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"
#include <vector>

//******************************************
//***********Function Prototypes************
//******************************************

//intial locates and returns the coordinate of the red pixel
std::vector<int> initial(Image<Pixel>);

// see if we are at the solution
bool goal(std::vector<int>, Image<Pixel> &);

//actions returns a list of all the possible next moves given a specific coordinate
List< std::vector<int> > actions(std::vector<int>, Image<Pixel> &);

//breadthFirstSearch attempts to find the exit to the maze
void breadthFirstSearch(Image<Pixel> &);

//pixelErrors checks if the image has proper requirements to BFS
void pixelErrors(Image<Pixel> &);



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

  pixelErrors(image);

  breadthFirstSearch(image);

  // Write solution image to file
  writeToFile(image, output_file);
  
  exit(EXIT_SUCCESS);
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

bool goal(std::vector<int> s, Image<Pixel>& maze)
{
  if (((s[0] == 0) || (s[1] == 0) || (s[0] == maze.width() - 1) || (s[1] == maze.height() - 1)) && maze(s[0], s[1]) == WHITE)
    { return true; }
  else
    { return false; }
}

List< std::vector<int> > actions(std::vector<int> s, Image<Pixel>& maze)
{
  List< std::vector<int> > states;

  //check if we can move down
  if ((s[0] - 1) == -1) //we are at the bottom border
    {}
  else if (maze(s[0] - 1, s[1]) == WHITE)
    { 
      std::vector<int> down{s[0] - 1, s[1]};
      states.insert(states.getLength(), down); 
    }
  else
    {}

  //check if we can move up
  if ((s[0] + 1) == maze.height()) //we are at the top border
    {}
  else if (maze(s[0] + 1, s[1]) == WHITE)
    {
      std::vector<int> up{s[0] + 1, s[1]};
      states.insert(states.getLength(), up);
    }
  else
    {}

  //check if we can move left
  if ((s[1] - 1) == - 1) //we are at the left border
    {}
  else if (maze(s[0], s[1] - 1) == WHITE)
    {
      std::vector<int> left{s[0], s[1] - 1};
      states.insert(states.getLength(), left);
    }
  else
    {}

  //check if we can move right
  if((s[1] + 1) == maze.height())// we are at the right border
    {}
  else if (maze(s[0], s[1] + 1) == WHITE)
    {
      std::vector<int> right{s[0], s[1] + 1};
      states.insert(states.getLength(), right);
    }
    else
    {}

  return states;
}

void breadthFirstSearch(Image<Pixel> &problem)
{
  std::vector<int> s = initial(problem);
  if (goal(s, problem))
    { 
      std::cout << "Solution Found" << std::endl;
      problem(s[0], s[1]) = GREEN; //the initial state is the exit
      return;
    }

  List< std::vector<int> > initialMoves = actions(s, problem);
  Queue< std::vector<int>, List< std::vector<int> > > frontier;
  frontier.enqueue(s);

  int rows = problem.width();
  int cols = problem.height();
  std::vector< std::vector<bool> > explored(rows, std::vector<bool>(cols, false)); //this initializes explored to all false
 
  while (1)
  {
    if (frontier.isEmpty())
      { 
        std::cout << "No Solution Found" << std::endl;
        return; //there is no solution to the maze
      }

    s = frontier.peekFront();
    frontier.dequeue();
          
    if(goal(s, problem))
      { 
        std::cout << "Solution Found" << std::endl;
        problem(s[0], s[1]) = GREEN;
        return; //we have found the exit
      }

    List< std::vector<int> > newActions = actions(s, problem);
    for (int i = 0; i < newActions.getLength(); i++)
      {
        if (explored[newActions.getEntry(i)[0]][newActions.getEntry(i)[1]] == false)
          { 
            frontier.enqueue(newActions.getEntry(i));
            explored[newActions.getEntry(i)[0]][newActions.getEntry(i)[1]] = true; //we have explored this pixel
          }
      }

    newActions.clear();

  }

}

//pixelErrors checks if the image has proper requirements to BFS
void pixelErrors(Image<Pixel> &maze)
{
  int rows = maze.width();
  int cols = maze.height();
  int red = 0;
  int blue = 0;
  int green = 0;
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          if (maze(i, j) == RED)
            { red++; }
          if (maze(i, j) == BLUE)
            { blue++; }
          if (maze(i, j) == GREEN)
            { green++; }
        }
    }
  
  if (red > 1)
    {
      std::cout << "Error: There is more than one starting location" << std::endl;
      exit(EXIT_FAILURE);
    }
  if (blue > 0 || green > 0)
    {
      std::cout << "Error: The maze contains a color other than black, white, or red" << std::endl;
      exit(EXIT_FAILURE);
    }
}