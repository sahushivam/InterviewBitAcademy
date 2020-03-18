/**
 *   author: sahushivam
 *   created: 08 August 2019 (Thursday)  11:05:41
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n,i,j;
	cin>>n;
	vector<ll> dp(n,LLONG_MAX),h(n);
	for(i=0;i<n;i++){
		cin>>h[i];
	}
	dp[0]=0;
	for(i=1;i<n;i++){
		j=0;
		for(j=1;j<=i;j<<=1){
        	dp[i] = min( dp[i] , dp[i-j] + abs(h[i] - h[i-j]) );
		}
	}
	cout<<dp[n-1]; 	
return 0;
}