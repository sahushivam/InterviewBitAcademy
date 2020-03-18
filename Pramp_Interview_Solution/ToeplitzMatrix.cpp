#import <iostream>
#import <vector>

using namespace std;

bool isToeplitz(const vector<vector<int>>& arr)
{
	// your code goes here
  int row = arr.size();
  if(row==0) return true;
  
  int col = arr[0].size(); // value here...3
  
  for(int i=1;i<row;i++) // 1 - 3
  {
    for(int j=1;j<col;j++)
    {
      if(arr[i][j]!=arr[i-1][j-1]) 
        return false;
    }
  }

  return true;
}

int main() 
{
 vector<vector<int>> arr= {{1,2,3,4},
                            {5,1,2,3},
                            {6,5,1,2}};
  cout<<isToeplitz(arr);
	return 0;
}


/*

are you there?
[0][0]

[[1,2,3,4],
 [5,1,2,3],
 [6,5,1,2]]
 
 
 
 i- [0 to 2]
    j- 1
 
0,0,

0,0 --->1,1,--> 2,2 
0,1 ---> 1,2 ---> 2,3
0,2 ---->1,3 
0,

//second

1,0 ----> 2,1 ---> 

for(0-arr.size()) //first element of adiagonal above tha main;
{
  for() //select other element of diagonal
}

for(1-arr[0].size())
{
  
}

*/
