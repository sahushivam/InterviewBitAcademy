
/**
 *   author: sahushivam
 *   created: 10 May 2019  09:12:21
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define REP(i, a, b) for(long long i = a; i < b; i++)
#define RREP(i, a, b) for(long long i = a-1; i >= b; i--)
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 0x7fffffff

void optimizeIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}

int arr[10005];
int X[2015];

priority_queue< int,vector<int>,greater<int> > Q;

int main()
{
	int t,i,j,n,k1,k2,k3,k,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>k1>>k2>>k3;
		for(i=1;i<=n;i++)
		{
		cin>>arr[i];
		arr[i]+=arr[i-1];
		}
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				x=arr[j]-arr[i-1];
				if(Q.size()<k3)
				Q.push(x);
				else
				{
					if(x>Q.top())
					{
						Q.pop();Q.push(x);
					}
				}
			}
		}
		 k=k3;
		
		while(!Q.empty())
		{
			X[k--]=Q.top();
			Q.pop();
		}
		printf("%d %d %d\n",X[k1],X[k2],X[k3]);
	}
	return 0;
}
