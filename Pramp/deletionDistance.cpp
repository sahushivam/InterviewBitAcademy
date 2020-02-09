#include <iostream>
#include <string>
#include<vector>

using namespace std;

int deletionDistance( const string& str1, const string& str2 ) 
{
  int n=str1.size();
  int m=str2.size();
  if(n==0 && m==0) return 0;
  if(n==0 || m==0) return max(n,m);
  vector<vector<int> > dp(n+1,vector<int>(m+1,0));
  
  
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(i==0)
        dp[i][j]=0;
      else if(j==0)
        dp[i][j]=0;
      else if(str1[i-1]==str2[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return (n+m)-2*dp[n][m]; 
}

int main() {
  return 0;
}


//dp[i][j]=number of character to delete //where i is length of first string I have seen, j is length of second string I have seen

//d f


// if str1[i]==str2[j]
// dp[i][j]=dp[i-1][j-1];
//else
//  dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2)



/*
dog frog

0  1  2  3
1  2  
2
3



3*4 

dp[0][0]=0;
dp[i][0]=i
dp[0][j]=j


loop 1 to str1.len
  loop 2 to str2.len
    if(str1[i-1]!=str2[j-1])
    {
      dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2)
    }

    else
    {
      dp[i][j]=dp[i-1][j-1];
    }


n=str1 m=str2

ans= (n+m)-2*lcs(n,m)

can I go to coding?
//yes

// coming in a minute

d(str1,str2) = 1 + min( d(str1.substring(0, n-1), str2), d(str1, str2.substring(0, m-1)) )
*/
