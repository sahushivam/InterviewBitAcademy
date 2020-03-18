/**
 *   author: sahushivam
 *   created: 05 November 2019 (Tuesday)  16:01:09
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
int container=0;
vector<int> tree(400000),arr(100000);


int query(int start,int end,int node,int l,int r,int value,int K)
{
	
	if(start==end)
	{
		return start;
	}
	else
	{
		int mid=(start+end)/2;
		if(tree[2*node]+value<=K)
			return query(start,mid,2*node,l,r,value,K);
		else
			return query(mid+1,end,2*node+1,l,r,value,K);
	}
}

void update(int start,int end,int idx,int node,int val)
{
	//
	//cout<<start<<" "<<end<<" "<<node<<endl;
	if(start==end)
	{
		if(tree[node]==0) container++;
		tree[node]+=val;
		return;
	}
	else
	{
		int mid=(start+end)/2;
		if(idx<=mid)
			update(start,mid,idx,2*node,val);
		else
			update(mid+1,end,idx,2*node+1,val);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}
signed main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int t=1,K,N;
    cin>>t;
    int size=100000;
    while(t--){
    	container=0;
    	for(int i=0;i<4*size;i++) tree[i]=0;
    	cin>>K>>N;
		
		int ships = 0, sum = 0;
		char line[100];
		gets(line);
		while (N > 0) {
			gets(line);
			int cant, w;
			if (sscanf(line,"b %d %d",&cant,&w)!= 2) {
			      sscanf(line,"%d",&w);
			      cant=1;
			}
			N-=cant;
			while (cant--){
				sum += w;
				int pos=query(0,size,1,0,size,w,K);
				update(0,size,pos,1,w);
			}

		}
		cout<<container<<" ";
		cout<<(K*container-sum)<<endl;		
	}
return 0;
}