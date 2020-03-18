/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  11:57:03
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
#define N 500005
vector<int> tree5[5],tree4[5],tree3[5],tree2[5],a(N);
int k;
void init()
{
	for(int i=0;i<5;i++){
		tree5[i].resize(4*N);
		tree4[i].resize(4*N);
		tree3[i].resize(4*N);
		tree2[i].resize(4*N);
	}
	for(int j=0;j<5;j++)
	{
		for(int i=0;i<4*N;i++) 
		{
			tree5[j][i]=0;
			tree4[j][i]=0;
			tree3[j][i]=0;
			tree2[j][i]=0;
		}
	}
	for(int i=0;i<N;i++) a[i]=0;
}
void build(int s,int e,int n)
{
	if(s==e){
		int num=a[s];
		tree5[num%5][n]=1;
		tree4[num%4][n]=1;
		tree3[num%3][n]=1;
		tree2[num%2][n]=1;
	}
	else
	{
		int mid=(s+e)/2;
		build(s,mid,2*n);
		build(mid+1,e,2*n+1);
		for(int i=0;i<5;i++){
			tree5[i][n]=tree5[i][2*n]+tree5[i][2*n+1];
			tree4[i][n]=tree4[i][2*n]+tree4[i][2*n+1];
			tree3[i][n]=tree3[i][2*n]+tree3[i][2*n+1];
			tree2[i][n]=tree2[i][2*n]+tree2[i][2*n+1];
		}
	}
}

int query5(int s,int e,int l,int r,int n,int rem)
{
	if(s>e || l>r || r<s || l>e) return 0;
	else
	{
		if(l>=s && r<=e) return tree5[rem][n];
	}
	int mid=(s+e)/2;
	int left=query5(s,mid,l,r,2*n,rem);
	int right=query5(mid+1,e,l,r,2*n+1,rem);
	return left+right;
}

int query4(int s,int e,int l,int r,int n,int rem)
{
	if(s>e || l>r || r<s || l>e) return 0;
	else
	{
		if(l>=s && r<=e) return tree4[rem][n];
	}
	int mid=(s+e)/2;
	int left=query4(s,mid,l,r,2*n,rem);
	int right=query4(mid+1,e,l,r,2*n+1,rem);
	return left+right;
}

int query3(int s,int e,int l,int r,int n,int rem)
{
	if(s>e || l>r || r<s || l>e) return 0;
	else
	{
		if(l>=s && r<=e) return tree3[rem][n];
	}
	int mid=(s+e)/2;
	int left=query3(s,mid,l,r,2*n,rem);
	int right=query3(mid+1,e,l,r,2*n+1,rem);
	return left+right;
}

int query2(int s,int e,int l,int r,int n,int rem)
{
	if(s>e || l>r || r<s || l>e) return 0;
	else
	{
		if(l>=s && r<=e) return tree2[rem][n];
	}
	int mid=(s+e)/2;
	int left=query2(s,mid,l,r,2*n,rem);
	int right=query2(mid+1,e,l,r,2*n+1,rem);
	return left+right;
}

void update(int s,int e,int idx,int val,int n)
{
	if(s==e)
	{
		int num=a[s];
		tree5[num%5][n]=0;
		tree4[num%4][n]=0;
		tree3[num%3][n]=0;
		tree2[num%2][n]=0;

		a[s]+=val;
		num+=val;

		tree5[num%5][n]=1;
		tree4[num%4][n]=1;
		tree3[num%3][n]=1;
		tree2[num%2][n]=1;
	}
	else
	{
        int mid = (s + e) / 2;
        if(idx <= mid)
        {
            update(s,mid,idx,val,2*n);
        }
        else
        {
            update(mid+1,e,idx,val,2*n+1);
        }
        for(int i=0;i<5;i++){
			tree5[i][n]=tree5[i][2*n]+tree5[i][2*n+1];
			tree4[i][n]=tree4[i][2*n]+tree4[i][2*n+1];
			tree3[i][n]=tree3[i][2*n]+tree3[i][2*n+1];
			tree2[i][n]=tree2[i][2*n]+tree2[i][2*n+1];
		}
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    while(t--){
    int n,q;
    cin>>n>>q>>k;
    init();
    for(int i=0;i<n;i++) cin>>a[i], a[i]%k;
    build(0,n-1,1);
	//for(int i=0;i<4*n;i++) cout<<tree5[0][i]<<" ";
	while(q--)
	{
		int c;
		cin>>c;
		if(c==2)
		{
			int left,right,rem;
			cin>>left>>right>>rem;
			left--; right--;
			switch(k)
			{
				case 5: cout<<query5(0,n-1,left,right,1,rem)<<endl; break;
				case 4: cout<<query4(0,n-1,left,right,1,rem)<<endl; break;
				case 3: cout<<query3(0,n-1,left,right,1,rem)<<endl; break;
				case 2: cout<<query2(0,n-1,left,right,1,rem)<<endl; break;
				case 1: if(rem==0) cout<<left-right+1<<'\n'; else cout<<"0\n"; break;
			}
		}
		else
		{
			int idx,val;
			cin>>idx>>val;
			update(0,n-1,idx-1,val,1);
		}
	}
}
return 0;
}