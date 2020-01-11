/**
 *   author: sahushivam
 *   created: 19 December 2019 (Thursday)  19:51:34
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
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	if(t.length()>=s.length()){
	for(int i=0;i<t.length()-s.length()+1;i++)
	{
		string c=t.substr(i,s.length());
		sort(c.begin(),c.end());
		if(c==s)
		{
			cout<<"YES\n";
			return;
		}
	}
}
	cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t;
    while(t--)
    	solve();
    return 0;
}