/**	epsileer 09 May 2019  19:04:27  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll limit = 1000000007;

void solve(){
	priority_queue<ll> pq1,pq2;
	pq1.push(1);
	int flag = 1;

	ll a,b,c,n; cin>>a>>b>>c>>n;
	ll sum = 1;

	for(int i=2;i<=n;i++){
		ll x = ((a*pq1.top())%limit + (b*i)%limit + c)%limit;
		if(flag == 0){
			if(x <= -pq2.top()){
				pq1.push(x);
			}
			else{
				ll y = -pq2.top(); pq2.pop();
				pq2.push(-x);
				pq1.push(y);
			}
		}
		else{
			if(x >= pq1.top()){
				pq2.push(-x);
			}
			else{
				ll y = pq1.top(); pq1.pop();
				pq1.push(x);
				pq2.push(-y);
			}
		}
		sum += x;
		flag = (flag+1)%2;
	}
	cout<<sum<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}