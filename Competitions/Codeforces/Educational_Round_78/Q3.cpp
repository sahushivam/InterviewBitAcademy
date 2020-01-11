/**
 *   author: sahushivam
 *   created: 24 December 2019 (Tuesday)  20:09:00
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

void solve(){
	int n,p,k; cin>>n>>p>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int pref=0, ans=0; 
	for (int i = 0; i <= k; i++) {
            int sum = pref;
            if (sum > p) break;
            int cnt = i;
            for (int j = i + k - 1; j < n; j += k) {
                if (sum + a[j] <= p) {
                    cnt += k;
                    sum += a[j];
                } else {
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}