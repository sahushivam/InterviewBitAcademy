/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  10:30:06
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

int c;
void subset(vector<int> &a,int &initial,int n,int m,int sum)
{
	if(n==-1)
	{
		if((initial+sum)%m==0){
			c++;
		}
		return;
	}
	else
	{
		subset(a,initial,n-1,m,sum+a[n]);
		subset(a,initial,n-1,m,sum);
	}
}
long long power(int a,int b,int mod)
{
	long long res=1;
	while(b>0)
	{
		if(b & 1) res = (res*a)%mod;
		a=((a%mod)*(a%mod))%mod;
		b=b/2;
	}
	return res%mod;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	string s; cin>>s;
    	vector<int> a;	
    	int initial=0;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i]=='_')a.PB(power(2,n-1-i,m));
    		else if(s[i]=='1')
    		{
    			initial+=power(2,n-1-i,m);
    		}
    	}
    	int n1=a.size(); 
    	c=0;
    	int sum=0;
    	subset(a,initial,n1-1,m,sum);
    	cout<<c<<"\n";
    }
return 0;
}