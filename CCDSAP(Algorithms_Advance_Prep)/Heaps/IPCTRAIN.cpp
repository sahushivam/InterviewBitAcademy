#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct poll{
	ll d,t,s;
	poll(ll a,ll b,ll c){
		d = a;
		t = b;
		s = c;
	}
};

struct comp{
	bool operator()(poll const &x, poll const &y){
		if(x.d > y.d)
			return true;
		else if(x.d == y.d)
			return x.s < y.s;
		return false;
	}
};

void solve(){
	priority_queue<poll, vector<poll>, comp> pq;
	ll n,d; cin>>n>>d;
	for(ll i=0;i<n;i++){
		ll a,b,c; cin>>a>>b>>c;
		pq.push(poll(a,b,c));
	}
	
	ll t = 0;
	while(!pq.empty() && t!=d){
		poll p = pq.top();
		pq.pop();
		if(p.d <= t+1){
			if(p.t-1 > 0){
				pq.push(poll(p.d, p.t-1, p.s));
			}
		}
		else{
			pq.push(poll(p.d, p.t, p.s));
		}
		t++;
	}
	ll ans = 0;
	while(!pq.empty()){
		poll p = pq.top();
		pq.pop();
		ans += p.t * p.s;
	}
	cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    	solve();
return 0;
}