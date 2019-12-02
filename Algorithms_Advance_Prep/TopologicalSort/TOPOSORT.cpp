/**
 *   author: sahushivam
 *   created: 11 November 2019 (Monday)  21:52:20
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
#define N 100005
vector<int> gp[N];
vector<int> vis1(N,0);

vector<int> ans;

bool compare(int a,int b){
 	return a>b;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    int n,m; cin>>n>>m;
    vector<int> indegree(n,0);
    priority_queue<int,vector<int> ,greater<int> >pq;
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	a--; b--;
    	gp[a].PB(b);
    	indegree[b]++;
    }
    for(int i=0;i<n;i++){
    	if(indegree[i]==0){
    		pq.push(i);
    	}
    }
    while(!pq.empty())
    {
    	int p=pq.top();
    	ans.push_back(p);
    	pq.pop();
    	for(auto i: gp[p])
    	{
    		indegree[i]--;
    		if(!indegree[i])
    			pq.push(i);
    	}
    }
    if(ans.size()!=n)
    {
    	cout<<"Sandro fails.";
    }
    else
    {
    	for(auto i: ans) cout<<i+1<<" ";
    }
return 0;
}