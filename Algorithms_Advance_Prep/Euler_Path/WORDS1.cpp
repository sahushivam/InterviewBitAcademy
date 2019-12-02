/**
 *   author: sahushivam
 *   created: 14 November 2019 (Thursday)  18:30:06
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
vector <int> visited(26,0);
vector<vector<int>>gp(26);
void init()
{
	for(int i=0;i<26;i++)
	{
		gp[i].clear();
		visited[i]=0;
	}
}
void dfs(int a)
{
	visited[a]=1;
	for(auto c: gp[a])
	{
		if(!visited[c])
			dfs(c);
	}
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n; bool flag=true; init();
    	cin>>n;
    	vector<string> a(n);
    	for(int i=0;i<n;i++) cin>>a[i];
    	vector<int> indegree(26,0),outdegree(26,0), node_present(26,0);
    	int start=0;
    	for(int i=0;i<n;i++)
    	{
    		int s=a[i][0]-'a';
    		int l=a[i].length();
    		int e=a[i][l-1]-'a';
    		
    		node_present[s]=node_present[e]=1; start=s;
    		
    		outdegree[s]++; indegree[e]++;
    		gp[s].PB(e);
    		gp[e].PB(s);
    	}
    	dfs(start);
    	// 1-
    	for(int i=0;i<26;i++)
    	{
    		if(node_present[i] && !visited[i]){
    			flag=false;
    		}
    	}
    	// 2
    	int c2=0,c1=0;
    	for(int i=0;i<26;i++)
    	{
    		if(c1==0 && (indegree[i]-outdegree[i]==1)) c1++;
    		else if(indegree[i]-outdegree[i]==0) continue;
    		else if(c2==0 && (indegree[i]-outdegree[i]==-1)) c2++;
    		else{
    			flag=false;
    			break;
    		}
    	}
    	if(!flag)
    	{
    		cout<<"The door cannot be opened.\n";
    	}
    	else
    	{
    		cout<<"Ordering is possible.\n";
    	}
    	//1- check if graph is connected do dfs
    	//2- check if indegree - outdegree is 0 for all except two vertices
    	//3- 
   	}

return 0;
}