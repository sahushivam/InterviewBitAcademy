/**
 *   author: sahushivam
 *   created: 11 November 2019 (Monday)  23:01:47
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

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n=1;
    cin>>n;

    vector<vector<char>>a(n,vector<char>(n));
    priority_queue<int,vector<int> ,greater<int> >pq;
    vector<int> ans;
    for(int i=0;i<n;i++) 
    	for(int j=0;j<n;j++)
    		cin>>a[i][j];

    vector<int> graph[n];
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='1')
			{
				graph[i].PB(j);
				indegree[j]++;
			}
		}
	}
	cout<<n<<"  nnn ";
	for(int i=0;i<n;i++){
    	if(indegree[i]==0){
    		pq.push(i);
    		cout<<i<<" ";
    	}
    }
    while(!pq.empty())
    {
    	int p=pq.top();
    	ans.push_back(p);
    	pq.pop();
    	for(auto i: graph[p])
    	{
    		indegree[i]--;
    		if(!indegree[i])
    			pq.push(i);
    	}
    }

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		int x=ans[i];
    		int y=ans[j];
    		if(a[x][y]!=1)
    		{	
    			arr.PB({x+1,y+1});
    		}
    	}
    }
    sort(arr.begin(),arr.end());
    cout<<ans.size()<<endl;
    for(auto i: arr)
    	cout<<i.first<<" "<<i.second<<endl;

return 0;
}