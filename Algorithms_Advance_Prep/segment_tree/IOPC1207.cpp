/**
 *   author: sahushivam
 *   created: 05 November 2019 (Tuesday)  10:57:53
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

vector<int> x(400005),y(400005),z(400005);
vector<int> lazyx(400005),lazyy(400005),lazyz(400005);

int query1(int start,int end,int node,int l,int r)
{
	if(l>end || r<start) return 0;
	if(lazyx[node])
	{
		x[node]=(end-start+1) - x[node]; //update it
		if(start!=end)
		{
			lazyx[2*node]=!lazyx[2*node];
			lazyx[2*node+1]=!lazyx[2*node+1];
		}
		lazyx[node]=0;
	}
	if(l<=start && r>=end)
	{
		return x[node];
	}
	int mid=(start+end)/2;

	ll q1=query1(start,mid,2*node,l,r);
	ll q2=query1(mid+1,end,2*node+1,l,r);
	return q1+q2;
}

int query2(int start,int end,int node,int l,int r)
{
	if(l>end || r<start) return 0;
	if(lazyy[node])
	{
		y[node]=(end-start+1) - y[node]; //update it
		if(start!=end)
		{
			lazyy[2*node]=!lazyy[2*node];
			lazyy[2*node+1]=!lazyy[2*node+1];
		}
		lazyy[node]=0;
	}
	if(l<=start && r>=end)
	{
		return y[node];
	}
	int mid=(start+end)/2;

	ll q1=query2(start,mid,2*node,l,r);
	ll q2=query2(mid+1,end,2*node+1,l,r);
	return q1+q2;
}

int query3(int start,int end,int node,int l,int r)
{
	if(l>end || r<start) return 0;
	if(lazyz[node])
	{
		z[node]=(end-start+1) - z[node]; //update it
		if(start!=end)
		{
			lazyz[2*node]=!lazyz[2*node];
			lazyz[2*node+1]=!lazyz[2*node+1];
		}
		lazyz[node]=0;
	}
	if(l<=start && r>=end)
	{
		return z[node];
	}
	int mid=(start+end)/2;

	ll q1=query3(start,mid,2*node,l,r);
	ll q2=query3(mid+1,end,2*node+1,l,r);
	return q1+q2;
}
void update1(int start,int end,int node,int l,int r)
{
	if(lazyx[node])
	{
		x[node]=(end-start+1)-x[node];
		if(start!=end)
		{
			lazyx[2*node]=!lazyx[2*node];
			lazyx[2*node+1]=!lazyx[2*node+1];
		}
		lazyx[node]=0;
	}
	if(r<start || l>end)
		return;
	if(l<=start && r>=end)
	{
		x[node]=(end-start)+1-x[node];
		if(start!=end)
		{
			lazyx[2*node]=!lazyx[2*node];
			lazyx[2*node+1]=!lazyx[2*node+1];
		}
		return;
	}
	int mid=(start+end)/2;
	update1(start,mid,2*node,l,r);
	update1(mid+1,end,2*node+1,l,r);
	x[node]=x[node*2]+x[2*node+1];
}
void update2(int start,int end,int node,int l,int r)
{
	if(lazyy[node])
	{
		y[node]=(end-start+1)-y[node];
		if(start!=end)
		{
			lazyy[2*node]=!lazyy[2*node];
			lazyy[2*node+1]=!lazyy[2*node+1];
		}
		lazyy[node]=0;
	}
	if(r<start || l>end)
		return;
	if(l<=start && r>=end)
	{
		y[node]=(end-start)+1-y[node];
		if(start!=end)
		{
			lazyy[2*node]=!lazyy[2*node];
			lazyy[2*node+1]=!lazyy[2*node+1];
		}
		return;
	}
	int mid=(start+end)/2;
	update2(start,mid,2*node,l,r);
	update2(mid+1,end,2*node+1,l,r);
	y[node]=y[node*2]+y[2*node+1];
}

void update3(int start,int end,int node,int l,int r)
{
	if(lazyz[node])
	{
		z[node]=(end-start+1)-z[node];
		if(start!=end)
		{
			lazyz[2*node]=!lazyz[2*node];
			lazyz[2*node+1]=!lazyz[2*node+1];
		}
		lazyz[node]=0;
	}
	if(r<start || l>end)
		return;
	if(l<=start && r>=end)
	{
		z[node]=(end-start)+1-z[node];
		if(start!=end)
		{
			lazyz[2*node]=!lazyz[2*node];
			lazyz[2*node+1]=!lazyz[2*node+1];
		}
		return;
	}
	int mid=(start+end)/2;
	update3(start,mid,2*node,l,r);
	update3(mid+1,end,2*node+1,l,r);
	z[node]=z[node*2]+z[2*node+1];
}


signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
   	cin>>t;
   	while(t--)
   	{
   		int nx,ny,nz,q;
   		cin>>nx>>ny>>nz>>q;
   		for(int i=0;i<400005;i++){
   			x[i]=0; lazyx[i]=0;
   			y[i]=0; lazyy[i]=0;
   			z[i]=0; lazyz[i]=0;
   		}
   		while(q--){
   			int c;
   			cin>>c;
   			int i,j;
	   		switch(c)
	   		{
	   			case 0:
	   				cin>>i>>j;
	   				update1(0,nx-1,1,i,j);
	   				break;
	   			case 1:
	   				cin>>i>>j;
	   				update2(0,ny-1,1,i,j);
	   				break;
	   			case 2:
	   				cin>>i>>j;
	   				update3(0,nz-1,1,i,j);
	   				break;
	   			case 3:
	   				int x1,x2,y1,y2,z1,z2;
	   				cin>>x1>>y1>>z1>>x2>>y2>>z2;
	   				ll r1=query1(0,nx-1,1,x1,x2);
	   				ll r2=query2(0,ny-1,1,y1,y2);
	   				ll r3=query3(0,nz-1,1,z1,z2);
	   				ll sum=(abs(x2-x1+1)*abs(y2-y1+1)*abs(z2-z1+1));
	   				ll g1=abs(x2-x1+1)-r1;
	   				ll g2=abs(y2-y1+1)-r2;
	   				ll g3=abs(z2-z1+1)-r3;
	   				cout<<sum- g1*g2*g3 - g1*r2*r3 - r1*r2*g3 - r1*g2*r3<<endl;
	   		}
	   	}
   	}
return 0;
}