#include <iostream>
#include <math.h>
#include <tuple>
using namespace std;
class TicTacToeGame{
public:
  TicTacToeGame();
  virtual ~TicTacToeGame();
  void play();

// private:
  void initializeGrid();
  void displayGrid();
  std :: tuple<int,int> firstUnoccupied();
  tuple<int,int> getGridCoord();
  bool checkForDraw();
  bool checkForWin();
private:
  char** pp_cGrid = nullptr;
};

TicTacToeGame :: TicTacToeGame(){
  this->pp_cGrid = new char* [3]; //an array of three pointers, each pointer points to an arraylist of 3

  for(int row = 0;row<3;row++)
  {
    pp_cGrid[row] = new char[3]; //each pointer getting assigned to an arraylist of length 3
  }
  initializeGrid();
}

TicTacToeGame::~TicTacToeGame()
{
  for(int row = 0;row<3;row++)
  {
    delete[] pp_cGrid[row];
  }

  delete[] pp_cGrid;
  pp_cGrid = nullptr;
}

void TicTacToeGame::initializeGrid()
{
  for(int row = 0;row<3;row++)
  {
    for(int column = 0; column < 3; column++)
    {
      this->pp_cGrid[row][column] = '~';
    }
  }
}

void TicTacToeGame::displayGrid()
{
  for(int row = 0;row<3;row++)
  {
    for(int column = 0; column < 3; column++)
    {
      cout << this->pp_cGrid[row][column] << " ";
    }
    cout << endl;
  }
}

tuple<int, int> TicTacToeGame::firstUnoccupied()
{
  int unoccupiedRow = -1;
  int unoccupiedColumn = -1;

  bool found = false;

  for(int row = 0; (row < 3) && !found; row++)
  {
    for(int column = 0; (column < 3) && !found; column++)
    {
      if(this->pp_cGrid[row][column] == '~')
      {
        unoccupiedRow = row;
        unoccupiedColumn = column;
        found = true;
      }
    }
  }
  tuple<int,int> tupleUnoccupiedGridSquare(unoccupiedRow,unoccupiedColumn);
  return tupleUnoccupiedGridSquare;
}

tuple<int,int> TicTacToeGame::getGridCoord()
{
  int row = 0;
  int column = 0;

  cout << "Please enter a grid row number" << endl;
  cin >> row;

  cout << "Please enter a grid column number" << endl;
  cin >> column;

  tuple<int,int> tupleCoord = make_tuple(row, column);

  return tupleCoord;
}

bool TicTacToeGame::checkForDraw()
{
  bool continue = false;

  for(int row = 0; row <3; row++)
  {
    for(int column = 0; column < 3;column++)
    {
      if(this->pp_cGrid[row][column] != 'X' && this->pp_cGrid[row][column] != 'O')
        continue = true;
    }
  }
  return !continue;
}

bool TicTacToeGame::checkForWin()
{
  bool win = false;

  for(int row = 0; (row < 3) && !win; row++)
  {
    if(this->pp_cGrid[row][0] != '~')
    {
      if((this->pp_cGrid[row][0] == this->pp_cGrid[row][1]) && this->pp_cGrid[row][0] == this->pp_cGrid[row][2])
      {
        win = true;
        cout << "WINNER: " << this->pp_cGrid[row][0] << "!" << endl;
      }
    }
  }
  for(int column = 0; (column < 3) && !win; column++)
  {
    if(this->pp_cGrid[0][column] != '~')
    {
      if((this->pp_cGrid[0][column] == this->pp_cGrid[1][column]) && this->pp_cGrid[0][column] == this->pp_cGrid[2][column])
      {
        win = true;
        cout << "WINNER: " << this->pp_cGrid[0][column] << "!" << endl;
      }
    }
  }

  if(this->pp_cGrid[0][0] != '~')
  {
    if((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][0] == this->pp_cGrid[2][2]))
    {
      win = true;
      cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << endl;
    }
  }
  if(this->pp_cGrid[0][2] != '~')
  {
    if((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][2] == this->pp_cGrid[2][0]))
    {
      win = true;
      cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << endl;
    }
  }

  return win;
}

void TicTacToeGame::play()
{

  bool win = false;
  bool draw = false;

  displayGrid();
  while(!win && !draw)
  {
    int row = 0;
    int column = 0;
    tie(row, column) = getGridCoord();
    this->pp_cGrid[row][column] = 'X';

    displayGrid();
    win = checkForWin();
    draw = checkForDraw();

    if(!win and !draw)
    {
      tie(row,column) = firstUnoccupied();
      this->pp_cGrid[row][column] = 'O';
      displayGrid();
      win = checkForWin();
      draw = checkForDraw();
    }
    if(draw)
    {
      cout << "Draw!" << endl;
    }
  }

  cout << "Game over" << endl;
  return;
}

int main()
{
  TicTacToeGame *p_game = new TicTacToeGame();

  p_game->play();

  delete p_game;
}
