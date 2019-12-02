/**
 *   author: sahushivam
 *   created: 01 July 2019  22:44:27
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;



void build(int node,int left,int right,vector<int>&tree,vector<int> &A)
{
	if(start==end) tree[node]=A[start];
	int mid=(left+right)/2;
	build(2*node,left,mid);
	build(2*node+1,mid+1,right);

	return tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> tree(4*n);
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    


return 0;
}