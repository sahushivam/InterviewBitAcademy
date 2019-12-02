/**
 *   author: sahushivam
 *   created: 05 November 2019 (Tuesday)  20:17:38
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

vector<int> arr(100001),tree(400000);
void build(int s,int e,int node)
{
	if(s==e)
	{
		tree[node]=arr[s];
	}
	else
	{
		int mid=(s+e)/2;
		build(s,mid,2*node);
		build(mid+1,e,2*node+1);
		tree[node]=tree[2*node] & tree[2*node+1];
	}
}
int query(int s,int e, int n, int l,int h)
{
	if(s>e || s>h || e<l)
		return (1LL<<60)-1;
	if(s >= l && e <= h)
		return tree[n];
	int mid = (s+e)/2;
	return query(s, mid, 2*n,l, h) & query(mid+1, e, 2*n+1, l, h);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
	    int n,k;
	    cin>>n>>k;
	    for(int i=0;i<100000;i++) arr[i]=0;
	    for(int i=0;i<400000;i++) tree   [i]=0;
	    for(int i=0;i<n;i++) cin>>arr[i];

	    for(int i=0;i<n;i++)
	    {
	    	arr[i+n]=arr[i+2*n]=arr[i];
	    }
	    build(0,3*n-1,1);

	    k = min(k, n-1);
	    for(int i=n;i<2*n;i++){
	    	int x = query(0, 3*n-1, 1, i-k, i);
	    	x &= query(0, 3*n-1, 1, i, i+k);
	    	cout<<x<<" ";
	    }	
    	cout<<endl;
	}

return 0;
}