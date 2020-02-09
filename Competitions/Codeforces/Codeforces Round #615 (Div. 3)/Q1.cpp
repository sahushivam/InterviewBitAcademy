/**
 *   author: sahushivam
 *   created: 22 January 2020 (Wednesday)  20:04:17
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
	 int a,b,c,n;
	 cin>>a>>b>>c>>n;
	 vector<int> a1(3); a1[0]=a; a1[1]=b; a1[2]=c;
	 sort(a1.begin(),a1.end());
	 int maxi=a1[2];
	 int ss=2*maxi-(a1[0]+a1[1]);
 
	 n=n-ss;
	 if(n<0 || (n%3)!=0) {cout<<"No\n"; return;}
	 else cout<<"Yes\n";
 
 
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}