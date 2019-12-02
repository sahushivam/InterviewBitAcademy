/**
 *   author: sahushivam
 *   created: 13 November 2019 (Wednesday)  16:16:19
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
#define N 10000005
vector<int> tree(N),lazy(N),a(N);
void init()
{
	for(int i=0;i<N;i++) 
	{
		tree[i]=0; lazy[i]=0; a[i]=0;
	}
}
void update(int s,int e,int l,int r,int val,int n)
{
	if(lazy[n]!=0)
	{
		tree[n]+=(e-s+1) * lazy[n];
		if(s!=e)
		{
			lazy[2*n]+=lazy[n];
			lazy[2*n+1]+=lazy[n];
		}
		lazy[n]=0;
	}
	if(s>e || l>r || r<s || l>e) return;
	if(s>=l && e<=r)
	{
		tree[n] += (e-s+1) * val;
        if(s != e)
        {
            lazy[n*2] += val;
            lazy[n*2+1] += val;
        }
        return;
	}
	int mid=(s+e)/2;
	update(s,mid,l,r,val,2*n);
	update(mid+1,e,l,r,val,2*n+1);
	tree[n]=tree[2*n]+tree[2*n+1];
}

int query(int s,int e,int l,int r,int n)
{
	if(s>e || r<s || l>e) return 0;
	if(lazy[n]!=0)
	{
		tree[n]+=(e-s+1)* lazy[n];
		if(s!=e)
		{
			lazy[2*n]+=lazy[n];
			lazy[2*n+1]+=lazy[n];
		}
		lazy[n]=0;
	}
	if(s>=l && e<=r){
        return tree[n];
	}
	int mid=(s+e)/2;
	int p1=query(s,mid,l,r,2*n);
	int p2=query(mid+1,e,l,r,2*n+1);
	return p1+p2;
}


signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	init();
    	int n,c;
    	cin>>n>>c;
    	while(c--){
	    	int choice,p,q,val; cin>>choice>>p>>q;
	    	switch(choice)
	    	{
	    		case 0:
	    			cin>>val;
	    			update(0,n-1,p-1,q-1,val,1);
	    			break;
	    		case 1:
	    			cout<<query(0,n-1,p-1,q-1,1)<<'\n';
	    			break;
	    	}
    	}
    }

return 0;
}