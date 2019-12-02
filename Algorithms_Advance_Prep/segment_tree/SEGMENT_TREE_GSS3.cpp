/**
 *   author: sahushivam
 *   created: 03 July 2019  00:29:12
**/


//http://strangeonehere.blogspot.com/2018/03/spoj-gss1.html

// A node contains- 
// [ START & END is a node's segment limit ] 

// Prefix is the maximum sum starting at START, end can be anywhere.
// There are two possibilities of the maximum. One, node's leftChild's prefix or two, adding leftChild's sum + rightChild's prefix. (which will make the prefix contiguous)

// Suffix is the maximum sum ending at END, start can be anywhere. 
// There's two possibility of the maximum. One, node's rightChild's already calculated suffix or two, add rightChild's sum + leftChild's suffix (which will make the suffix contiguous).

// Sum: leftChild's sum + rightChild's sum.

// MAX Maximum of  - 
// prefix (result is in the node, starts from START but doesn't end in END )
// suffix  (result is in the node, doesn't start from START but surely ends in END )
// leftChild's max ( result is in left child completely )
// rightChild's max (result is in right child completely )
// leftChild's suffix + rightChild's prefix ( result is in between leftChild & rightChild )
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

struct point{
    int sum,pre,suf,mx;
};

vector<int> arr(100000);
vector<point> tree(500000);

point merge(point a, point b){
    point res;
    res.sum = a.sum + b.sum;
    res.pre = max(a.pre, a.sum + b.pre);
    res.suf = max(b.suf, b.sum + a.suf);
    res.mx = max(max(a.mx, b.mx), a.suf + b.pre);
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

point query(int start, int end, int node, int l, int r){
    if(start > r || end < l){
        point p; p.sum = 0; p.pre = 0; p.suf = 0; p.mx = 0;
        return p;
    }
    if(start >= l && end <= r)
        return tree[node];
    int mid = (start + end)/2;
    if(r <= mid)
        return query(start, mid, 2*node, l, r);
    if(l > mid)
        return query(mid+1, end, 2*node+1, l, r);
    return merge(query(start, mid, 2*node, l, r), query(mid+1, end, 2*node+1, l, r));
}

void update(int start, int end, int node, int idx, int value){
	if(start == end){
		tree[node].sum = value;
		tree[node].pre = value;
		tree[node].suf = value;
		tree[node].mx = value;
		return;
	}
	int mid = (start + end)/2;
	if(start <= idx && mid >= idx)
		update(start, mid, 2*node, idx, value);
	else
		update(mid+1, end, 2*node+1, idx, value);
	tree[node] = merge(tree[2*node], tree[2*node+1]);
}

void solve(){
    int n; cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];

    build(0, n-1, 1);

    int q; cin>>q;

    while(q--){
        int x,l,r; cin>>x>>l>>r;
		if(x)
			cout<<query(0, n-1, 1, --l, --r).mx<<endl;
		else
			update(0, n-1, 1, l-1, r);

    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t = 1; while(t--) solve();
return 0;
}