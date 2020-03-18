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
    priority_queue<int,vector<int> ,greater<int> >pq;
    int n; cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    {
    	cin>>s[i];
    }
    vector<int> indegree(26,0);
    for(int i=0;i<n-1;i++)
    {
    	string a=s[i];
    	string b=s[i+1];
    	bool flag=false;
    	for(int j=0;j<min(a.length(),b.length());j++)
    	{
    		if(a[j]!=b[j])
    		{
    			//cout<<a[j]-97<<" "<<b[j]-97<<endl;
    			gp[a[j]-97].PB(b[j]-97);
    			indegree[b[j]-97]++;
    			flag=1;
    			break;
    		}
    	}
    	if(!flag && a.length()>b.length())
    	{
    		cout<<"Impossible";
    		return 0;
    	}
    }

    for(int i=0;i<26;i++)
    {
    	if(indegree[i]==0)
    		pq.push(i);
    }

    ans.clear();
   
   
    while(!pq.empty())
    {
    	int p=pq.top();
    	ans.push_back(p);
    	pq.pop();
    	for(auto i: gp[p])
    	{
    		indegree[i]--;
    		if(indegree[i]==0)
    			pq.push(i);
    	}
    }
    if(ans.size()!=26)
    {
    	cout<<"Impossible";
    }
    else
    {
    	for(auto i: ans) cout<<char(i+97);
    }
return 0;
}