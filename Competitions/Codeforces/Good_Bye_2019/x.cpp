/**
 *   author: sahushivam
 *   created: 10 January 2020 (Friday)  20:21:15
**/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long
int ans=INF;
void cal(vector<int> a,int mask,int pos)
{
	int n=a.size();
	if(pos==-1)
	{
		int maxi=0;
		for(int i=0;i<n;i++)
		{
			maxi=max(maxi,a[i]^mask);
		}
		ans=min(ans,maxi);
		return;
	}
	vector<int> temp1, temp2;
	for(int i=0;i<n;i++)
	{
		if(a[i] & (1LL<<pos))
			temp1.PB(a[i]);
		else
			temp2.PB(a[i]);
	}
	if(temp2.size()==0)
		cal(temp1,mask | (1LL<<pos),pos-1);
	else if(temp1.size()==0)
		cal(temp2,mask, pos-1);
	else
	{
		cal(temp1,mask,pos-1);
		cal(temp2,mask | (1LL<<pos), pos-1);
	}
}
void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	int pos=31;
	int mask=0;
	cal(a,mask,pos);
	cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}