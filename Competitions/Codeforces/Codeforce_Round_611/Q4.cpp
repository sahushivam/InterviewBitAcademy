/**
 *   author: sahushivam
 *   created: 29 December 2019 (Sunday)  00:34:34
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
	int n,m; cin>>n>>m;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}//multi sources bfs
	queue<int> q;
	map<int, int> d;
	for (int i = 0; i < n; ++i) {
		d[x[i]] = 0;
		q.push(x[i]);
	}
	long long ans = 0;
	vector<int> res;
	while (!q.empty()) {
		if ((res.size()) == m) break;
		int cur = q.front();
		q.pop();
		if (d[cur] != 0) {
			ans += d[cur];
			res.push_back(cur);
		}
		if (!d.count(cur - 1)) {
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
		if (!d.count(cur + 1)) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
	}
	cout << ans << endl;
	for (auto it : res) cout << it << " ";
	cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}