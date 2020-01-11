/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  22:35:01
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
    int h,m;
    int min=24*60;
    cin>>h>>m;
    int ans= min-h*60-m;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}