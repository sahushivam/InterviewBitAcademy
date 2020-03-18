/**
 *   author: sahushivam
 *   created: 04 November 2019 (Monday)  01:00:57
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
	multiset<int> ms;
	vector<int> ss,ans;
	ss.push_back(0LL);
	int size= 1<<n;
	for(int i=0;i<size;i++)
	{
		int a; cin>>a;
		if(a)
			ms.insert(a);
	}
	while(!ms.empty())
	{
		int x=*ms.begin();
		ans.push_back(x);
		ll sz = ss.size();
		for(int i=0;i<sz;i++){
			ms.erase(ms.lower_bound(ss[i]+x));
			ss.push_back(ss[i]+x);
		}
	}
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    	solve();
return 0;
}