#include <bits/stdc++.h>
using namespace std;
vector<int> tree(500000);
int max_area=0;

//in node of segment tree I am storing the index of the minimum element in that range

void build(int start,int end,int node,vector<int> &A)
{
    if(start>end) return;
    if(start==end)
    {
        tree[node]=start;//storing the index of the minimum element
        return;
    }
    else
    {
        int mid=(start+end)/2;
        build(start,mid,2*node,A);
        build(mid+1,end,2*node+1,A);
        if(A[tree[2*node]]<A[tree[2*node+1]])
        {
            tree[node]=tree[2*node];
        }
        else
        {
            tree[node]=tree[2*node+1];
        }
    }
}
int query(int start,int end,int left,int right,int node,vector<int> &A)
{
    if(start>right || end<left) //out of range
    {
        return -1; 
    }
    if(start>=left && end<=right) // completely in the range
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    int index1= query(start,mid,left,right,2*node,A);
    int index2= query(mid+1,end,left,right,2*node+1,A);
    if(index1==-1 && index2==-1) return -1;
    else if(index1==-1) return index2;
    else if(index2==-1) return index1;
    if(A[index1]<A[index2])
        return index1;
    else
        return index2;
}
void withSegmentTree(int left,int right,int n, vector<int> &A)
{
    while(left<=right)
    {
        int pivot=query(0,n-1,left,right,1,A);
        if(pivot!=-1){
            withSegmentTree(0,pivot-1,n,A);
            withSegmentTree(pivot+1,n-1,n,A);
            int base =right-left+1;
            int height=A[pivot];
            int area = base * height;
            max_area=max(area,max_area);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    build(0,n-1,1, A);
    withSegmentTree(0,n-1,n,A);
    cout<<max_area;
}
