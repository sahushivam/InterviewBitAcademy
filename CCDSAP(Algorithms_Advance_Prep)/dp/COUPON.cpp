/**
 *   author: sahushivam
 *   created: 08 August 2019 (Thursday)  08:02:13
 *   https://www.codechef.com/problems/COUPON
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> > arr(n);
        vector<vector<ll> > discount(n);
        for(ll i=0;i<n;i++)
        {
            arr[i].resize(m);
            for(ll j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(ll i=0;i<n;i++)
        {
            discount[i].resize(m);
            for(ll j=0;j<m;j++)
            {
                cin>>discount[i][j];
            }
        }
        vector<ll> low(n,1e15);

        vector<vector<ll> > dp(n);
        for(ll i=0;i<n;i++)
            dp[i].resize(m);
        for(ll i=0;i<m;i++){
            dp[0][i]=arr[0][i];
            low[0]=min(low[0],dp[0][i]);
        }
        for(ll i=1;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll cur = arr[i][j];
                ll off = discount[i-1][j];
                dp[i][j] = min(low[i-1]+cur,dp[i-1][j]+max(0ll,cur-off));
                low[i]=min(low[i],dp[i][j]);
            }
        }
        cout<<low[n-1]<<"\n";
    }
return 0;
}