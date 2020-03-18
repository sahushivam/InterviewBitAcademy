#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  // your code goes here
  int n=inputMatrix.size();
  int m=inputMatrix[0].size();
  int row_start=0, row_end=n-1;
  int col_start=0, col_end=m-1;
  vector<int> ans;
  while(row_start<=row_end && col_start<=col_end)
  {
    for(int i=col_start; i<=col_end;i++)
      ans.push_back(inputMatrix[row_start][i]);
      row_start++;

    for(int i=row_start;i<=row_end;i++)
         ans.push_back(inputMatrix[i][col_end]);

    col_end--;
    if(row_start<=row_end){
    for(int i=col_end; i>=col_start;i--)
      ans.push_back(inputMatrix[row_end][i]);
    row_end--;
    }
    if(col_start<=col_end){
    for(int i=row_end;i>=row_start;i--)
        ans.push_back(inputMatrix[i][col_start]);
    col_start++;
    }
  }
  return ans;
}

int main() {
  
  vector<vector<int>> arr={ {1,    2,   3,  4,    5},
                           {6,    7,   8,  9,   10},
                           {11,  12,  13,  14,  15},
                           
                         };
  vector<int> ans=spiralCopy(arr);
  for(int i: ans) cout<<i<<" ";

  return 0;
}




