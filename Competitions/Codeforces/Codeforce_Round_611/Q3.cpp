/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  22:43:35
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
	int n; cin>>n;
	vector<int> a(n);
	vector<int> arr(n+1);
	stack<int> stk;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		arr[a[i]]=1;
		if(!a[i]) stk.push(i);
	}
	priority_queue<int , vector<int>, greater<int>> pq;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]==0)
		{
			pq.push(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			if(!pq.empty() && pq.top()!=i+1)
			{
				a[i]=pq.top();
				pq.pop();
			}
			else
			{
				int j=pq.top();
				pq.pop();
				if(!pq.empty()){
					a[i]=pq.top();
					pq.pop();
				}
				pq.push(j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int j;
		if(a[i]==0)
		{
			a[i]=i+1;
			while(!stk.empty())
			{
				if(a[stk.top()]!=a[i]){
					j=stk.top();
					break;
				}
				stk.pop();
			}
			swap(a[i],a[j]);
		}
	}
	for(auto i: a)
		cout<<i<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}