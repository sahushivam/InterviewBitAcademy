#include <iostream>
#include<vector>

using namespace std;

int numOfPathsToDest( int n ) 
{
  // your code goes here
  vector<int> dp(n);
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<n;i++)
  {
   dp[i]=0;
    for(int j=0;j<i;j++)
    {
      dp[i]+=dp[j]*dp[i-j-1];
    }
  }
  return dp[n-1];
}

int main() {
  int n=4;
  cout<<numOfPathsToDest(n);
  return 0;
}
