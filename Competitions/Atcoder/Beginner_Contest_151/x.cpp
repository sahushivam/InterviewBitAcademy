/**
 *   author: sahushivam
 *   created: 26 January 2020 (Sunday)  17:53:05
**/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long

void solve(){
	int m,n; cin>>m>>n;
	vector<vector<int>> dp(10*m+1,vector<int> (n+1));
	vector<int> C(n);
	vector<int> B(n);
	for(int i=0;i<n;i++)
	{
		cin>>B[i]>>C[i];
	}
    for(int i=0;i<=10*m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            {
                  dp[i][j]=0;  
            }
            else if(j==0) dp[i][j]=1000000000;
            else
            {
                if(i >= B[j-1]){
                    dp[i][j] = min(dp[i][j-1], dp[i-B[j-1]][j] + C[j-1]);
                }
                else dp[i][j] = dp[i][j-1];
            }
        }
    }
    int ans=INF;
  	for(int i=m;i<10*m;i++){
   		ans=min(ans,dp[i][n]);
  	}
  	cout<<ans;
   	
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}	