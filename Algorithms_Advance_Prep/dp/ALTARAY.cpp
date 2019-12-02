/**
 *   author: sahushivam
 *   created: 19 August 2019 (Monday)  09:55:57
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	for(ll i=0;i<n;i++) cin>>v[i];
    	vector<ll> ans(n,0);
    	if(v[n-1]!=0) ans[n-1]=1;
    	for(ll i=n-2;i>=0;i--)
    	{
    		if((v[i]>0 && v[i+1]<0)||(v[i+1]>0 && v[i]<0))
    			ans[i]=ans[i+1]+1;
    		else if(v[i]!=0)
    			ans[i]=1;
    	}
    	for(ll i=0;i<n;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }

return 0;
}