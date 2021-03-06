
int Solution::isMatch(const string text, const string pattern) {
    int n=text.size();
  int m=pattern.size();
  vector<vector<bool>> dp(n+1,vector<bool> (m+1,false)); 
  dp[0][0]=true;
  for(int i=1;i<=m;i++)
  {
    if(pattern[i-1]=='*')
      dp[0][i]=dp[0][i-2];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(text[i-1]==pattern[j-1])
        dp[i][j]=dp[i-1][j-1];
      else if(pattern[j-1]=='.')
        dp[i][j]=dp[i-1][j-1];
      else if(pattern[j-1]=='*'){
        dp[i][j]=(dp[i][j-2]);
        if((pattern[j-2]=='.') || (pattern[j-2]==text[i-1]))
            dp[i][j]=dp[i][j] | dp[i-1][j];
      }
      
      else
        dp[i][j]=false;
    }
  }
  return dp[n][m];
}
