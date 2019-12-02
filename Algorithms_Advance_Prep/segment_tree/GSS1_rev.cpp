/**
 *   author: sahushivam
 *   created: 04 November 2019 (Monday)  16:10:05
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

struct point
{
	int pre,suf,mx,sum;
};

vector<int> arr(100005);
vector<point> tree(500000);

point merge(point a,point b)
{
	point res;
	res.sum=a.sum+b.sum;
	res.pre=max(a.pre,a.sum+b.pre);
	res.suf=max(b.suf,b.sum+a.suf);
	res.mx=max(max(a.mx,b.mx),a.suf+b.pre);
	return res;
}


void build(int start, int end, int node){
    if(start == end){
        tree[node].sum = arr[start];
        tree[node].pre = arr[start];
        tree[node].suf = arr[start];
        tree[node].mx = arr[start];
        return;
    }
    int mid = (start + end)/2;
    build(start, mid, 2*node);
    build(mid+1, end, 2*node+1);

    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

point query(int start,int end,int node,int l,int r)
{
	if(start>r || end <l)
	{
		point res;
		res.mx=0; res.pre=0; res.suf=0; res.sum=0;
		return res;
	}
	else
	{
		if(start>=l && end<=r)
			return tree[node];
		int mid=(start+end)/2;
		if(r <= mid)
    		return query(start, mid, 2*node, l, r);
		if(l > mid)
    		return query(mid+1, end, 2*node+1, l, r);
		return merge(query(start, mid, 2*node, l, r), query(mid+1, end, 2*node+1, l, r));
	}
}


void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	build(0, n-1, 1);

    int q; cin>>q;

    while(q--){
        int l,r; cin>>l>>r; --l; --r;
        cout<<query(0, n-1, 1, l, r).mx<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    while(t--)
    	solve();

return 0;
}