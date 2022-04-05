#include <iostream>
#include "image.h"
#include "deque.hpp"

bool checkEnd(int r, int c,Image<Pixel> maze){
  if(r == 0 || c == 0 || r == maze.height()-1 || c == maze.width()-1){
    return true;
  }

  else{
    return false;
  }
}

int main(int argc, char *argv[])
{
  // TODO
if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }
  
Image<Pixel> inputFile = readFromFile(argv[1]);
//Image<Pixel> outputFile = readFromFile(argv[2]);

Image<Pixel> maze; //input image
maze = inputFile;

//Making variables for height and width
int mazeHeight;
int mazeWidth;
int currColumn;
int currRow;

mazeHeight = maze.height();
mazeWidth = maze.width();

//Variables for the starting position;
int sWidth;
int sHeight;

//Variable to track how many red pixels
int red;
//Finding the starting position
for(int i=0;i<mazeWidth;i++){
  for(int j=0;j<mazeHeight;j++){
    if(maze(i,j) == RED){
      sWidth = i;
      sHeight = j;
      red++;
    }

    //Error checking to see if image contains colors other than black, white, or red
    if(maze(i,j)!=RED,maze(i,j)!=BLACK,maze(i,j)!=WHITE){
      std::cerr << "Error: Contains a color that is not black, white, or red!!!";
      EXIT_FAILURE;
    }
  }
}

//Error checking to see that there is only 1 red pixel shitter
if(red>1){
  std::cerr << "Error: Contains more than 1 red pixel!!!";
}

//2 deques for the width and height
Deque <int> w;
Deque <int> h;

//Input starting position into the deque
w.pushBack(sWidth);
h.pushBack(sHeight);

//Make in infinite while loop shitter
while(1){
  //Check if the dequeue is empty or snah
  if(w.isEmpty() || h.isEmpty()){
    break; //If empty that means that its unsolvable
  }

  //Set these var
  currColumn= w.front();
  currRow = h.front();

  //These will be the checks of for adding to the dequeue

  //Previous Row
  if(maze(currColumn-1,currRow) == WHITE){
    w.pushBack(currColumn-1);
    h.pushBack(currRow);
    maze(currColumn-1,currRow) = BLUE; //Setting to blue so it doesnt check it again
    //Checking to see if its an end peice
    if(checkEnd(currColumn-1,currRow,maze)){
      maze(currColumn-1,currRow) = GREEN;
      break;
    }
  }

  //Next Row
  if(maze(currColumn+1,currRow) == WHITE){
    w.pushBack(currColumn+1);
    h.pushBack(currRow);
    maze(currColumn+1,currRow) = BLUE; //Setting to blue so it doesnt check it again
    //Checking to see if its an end peice
    if(checkEnd(currColumn+1,currRow,maze)){
      maze(currColumn+1,currRow) = GREEN;
      break;
    }
  }

  //Previous Column
  if(maze(currColumn,currRow-1) == WHITE){
    w.pushBack(currColumn);
    h.pushBack(currRow-1);
    maze(currColumn,currRow-1) = BLUE; //Setting to blue so it doesnt check it again

    //Checking to see if its an end peice
    if(checkEnd(currColumn,currRow-1,maze)){
      maze(currColumn,currRow-1) = GREEN;
      break;
    }
  }


  //Next Column
  if(maze(currColumn,currRow+1) == WHITE){
    w.pushBack(currColumn);
    h.pushBack(currRow+1);
    maze(currColumn,currRow+1) = BLUE; //Setting to blue so it doesnt check it again

    //Checking to see if its an end peice
    if(checkEnd(currColumn,currRow+1,maze)){
      maze(currColumn,currRow+1) = GREEN;
      break;
    }
  }

  //At the end pop them out
  w.popFront();
  h.popFront();

 
}

//Clearing blue tiles
for(int i=0;i<mazeWidth;i++){
  for(int j=0;j<mazeHeight;j++){
    if(maze(i,j) == BLUE){
      maze(i,j) = WHITE;
    }
  }
}

//Writing to the output File
writeToFile(maze,argv[2]);
EXIT_SUCCESS;

}
