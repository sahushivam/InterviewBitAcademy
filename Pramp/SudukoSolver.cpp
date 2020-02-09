#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<vector<char>>& board, int i,int j,char val)
{
  int row = i-i%3;
  int col = j-j%3;
  for(int x=0;x<9;x++)
  {
    if(board[x][j]==val) return false;
  }
  for(int y=0;y<9;y++)
  {
    if(board[i][y]==val) return false;
  }
  for(int x=0;x<3;x++)
  {
    for(int y=0;y<3;y++)
    {
      if(board[row+x][col+y]==val) return false;
    }
  }
  return true;
}
bool solve(vector<vector<char>>&board, int i,int j)
{
  if(i==9) return true;
  if(j==9) return solve(board,i+1,0);
  if(board[i][j]!='.') return solve(board,i,j+1);
  
  for(char val='1';val<='9';val++)
  {
    if(isPossible(board,i,j,val))
     {
        board[i][j]=val;
        if(solve(board,i,j+1)) return true;
        board[i][j]='.';
     }
  }
  return false;
}
bool sudokuSolve( const vector<vector<char>>& board ) 
{
  // your code goes here
  vector<vector<char>>board1(board.begin(),board.end());
  return solve(board1,0,0);
}

int main() {
  return 0;
}

/*

ispossible(board,i,j,num)
{
  whether possible to write num at cell i,j
}

suduko_solve(board,i,j){
if(i==board.size())
{
    return true;
}
else if(j==board[0].size())
  soduko_solve(board,i+1,0)

    //if board cell is empty
    for(int k=1;k<=9;k++)
    {
      ispossible(board,i,j,k)
      {
        boord[i][j]=k;
        if(sudoko_solve(board,i,j+1)) return true
        board[i][j]=' ';
      }
    
  }
  return false;
  
}
//noise at your end
can you hear now?
can you hear?  no
i can hear you, but seems like you can't
still can't hear?
yes I can't
too bad.. something 

refresh the page at your end
i just did.

Now also I can't hear
we have to end it.. :-(
but you are doing great.

don't end it. I will solve and you can do the same

ok, go ahead

I am done.
great excellent.
do you have any question?
no, you did very well right from the idea to implementation. good job.]
Thank you. so swap the role

let's do that

*/
