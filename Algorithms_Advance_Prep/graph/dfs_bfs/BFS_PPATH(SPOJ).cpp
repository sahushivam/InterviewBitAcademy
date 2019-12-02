/**
 *   author: sahushivam
 *   created: 11 July 2019 (Thursday)  11:42:43
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void sieve(std::vector<int> &v)
{
	bool prime[100009];
	memset(prime,true,100009*sizeof(bool));
	prime[0]=prime[1]=false;
	for(int i=2;i*i<100009;i++)
	{
		if(prime[i]){
			for(int j=i*i;j<=10000;j+=i)
				prime[j]=false;
		}
	}
	for(int i=1000;i<9999;i++)
		if(prime[i])
			v.push_back(i);
	// for(auto i:v)
	// 	cout<<i<<" ";
}
bool compare(int num1, int num2) 
{ 
	string s1 = to_string(num1); 
	string s2 = to_string(num2); 
	int c = 0; 
	if (s1[0] != s2[0]) 
		c++; 
	if (s1[1] != s2[1]) 
		c++; 
	if (s1[2] != s2[2]) 
		c++; 
	if (s1[3] != s2[3]) 
		c++; 
	return (c == 1); 
} 
void createPath(vector<vector<int> >&G,vector<int> v,int nodes)
{
	for (int i = 0; i < nodes; i++) 
		for (int j = i + 1; j < nodes; j++) 
			if (compare(v[i], v[j])) 
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
}
int bfs(vector<vector<int> >&G,int a,int b)
{
	int nodes=G.size();
	queue<int> q;
	int level[nodes];
	memset(level,-1,sizeof(int)*nodes);
	level[a]=0;
	q.push(a);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(auto i:G[f])
		{
			if(level[i]==-1)
			{
				level[i]=level[f]+1;
				q.push(i);
			}
			if(i==b)
				return level[i];
		}
	}
	//for(auto i:level) cout<<i<<" ";
	return -1;
}

int shortestPath(vector<vector<int> >&G,vector<int> &v,int a, int b)
{
	int in1, in2; 
	for (int j = 0; j < v.size(); j++) 
		if (v[j] == a) 
			in1 = j; 
	for (int j = 0; j < v.size(); j++) 
		if (v[j] == b) 
			in2 = j; 
	return bfs(G,in1, in2); 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    std::vector<int> v;
    sieve(v);
    int nodes=v.size();
    vector<vector<int> >G(nodes);
    createPath(G,v,nodes);
    while(t--)
    {
    	int a,b;
    	cin>>a>>b;
    	cout<<shortestPath(G,v,a,b)<<'\n';
    }
return 0;
}