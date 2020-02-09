#import <iostream>
#import <string>
#import <vector>

using namespace std;


vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{
	// your code goes here
  int n=source.length();
  int m=target.length();
  vector<vector<int>> dp(n+1,vector<int>(m+1));
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(i==0)
        dp[i][j]=j;
      else if(j==0)
        dp[i][j]=i;
      else if(source[i-1]==target[j-1])
        dp[i][j]=dp[i-1][j-1];
      else
        dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
    }
  }
  
 
  vector<string> ans;  
  string g="";
  int i=n, j=m;
  while(i!=0 && j!=m){
     g="";
      
      if(dp[i][j]==dp[i-1][j]+1)
      {
        g+="-";
        g+=source[i-1];
        i--;
      }
      else if(dp[i][j]==dp[i][j-1]+1)
      {
         g+="+";
         g+=target[j-1];
         j--;
      }
      else
      {
        g=g+target[j-1];
        i--;
        j--;
      }
     ans.push_back(g);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main() 
{
  string source="ABCDEFG";
  string target="ABDFFGH";
  vector<string>ans = diffBetweenTwoStrings(source,target);
  for(string i: ans)
    cout<<i<<" ";
	return 0;
}

/*
source = ABCDEFG   target = ABDFFGH

["A", "B", "-C", "D", "-E", "F", "+F", "G", "+H"]

edit distance problem

1- add
2- delete

minimum possible edit

n is length of source 
m is length of target

if(source[i-1]==target[j-1])  
  dp[i][j] = dp[i-1][j-1]
else
  dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
  
 
dp[n][m]

0 1 2 3 4 5 6 7
1 0 1 2 3 4 5 6
2 1 0 1 2 3 4 5
3 2 1 2 3 4 5 6
4 3 2 1 2 3 4 5
5 4 3 2 3 4 5 6
6 5 4 3 2 3 4 5
7 6 5 4 3 4 3 4
                      , B ,D  -E  F    +F ,G,+H
                      
                      

reverse(ans);
*/
