/**
 *   author: sahushivam
 *   created: 01 July 2019  06:36:08
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define NMAX 100100 
ll parent[10005];	//It tells s[i]th dish belong to which chef.

ll Find(ll v) {
    if (parent[v]==-1)
        return v;
    parent[v] = Find(parent[v]);
    return parent[v];
}


void Union(ll i, ll j,vector <ll> &s) {
	ll x = Find(i);
	ll y = Find(j);
	if (x == y){
		cout << "Invalid query!" <<endl;
		return;
	}else{
		ll xs = s[x];
        ll ys = s[y];
        if(xs == ys){
            return;
        }else if(xs>ys){
            
        }else{
            parent[x] = y;
        }
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	vector <ll> s(n+1);

    	for (ll i = 1; i <=n; i++) {
			parent[i] = -1;
    		cin>>s[i];
    	}	
    	ll q;
    	cin>>q;

    	while(q--)
    	{
    		ll c,x,y;
    		cin>>c;
    		if(!c){
    				cin>>x>>y;
    				Union(x,y,s);
    			}
    		else{
    				cin>>x;
    				cout<<Find(x)<<endl;
    			}
    		}
    	}

return 0;
}