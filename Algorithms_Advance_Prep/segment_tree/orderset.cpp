/**
 *   author: sahushivam
 *   created: 06 November 2019 (Wednesday)  22:02:37
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long

void solve()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	vector<int> v(26,0);
	for(int i=0;i<n;i++)
	{
		v[s1[i]-'a']++;
		v[s2[i]-'a']++;
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]%2!=0){
			cout<<"No\n";
			return;
		}
	}
	vector<pair<int,int> > ans;
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2[i]) continue;
		char c=s1[i];
		int ind=-1;
		for(int j=i+1;j<n;j++)
		{
			if(s1[j]==c)
			{
				ind=j;	
				break;
			}
		}
		ans.push_back({i+1,ind+1});
	}
	cout<<ans.size()<<endl;
	for(auto i: ans)
	{
		cout<<i.first<<" "<<i.second<<'\n';
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1; 
    cin>>t;
    while(t--)
    {
    	solve();
    }
return 0;
}