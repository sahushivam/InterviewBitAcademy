/**
 *   author: sahushivam
 *   created: 27 December 2019 (Friday)  20:06:35
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
	int n,m1; cin>>n>>m1;
	vector<pair<int,int>> a(n); vector<int> b(m1);

	for(int i=0;i<n;i++){ cin>>a[i].first; a[i].second=i+1;}
	for(int i=0;i<m1;i++) cin>>b[i];
	vector<pair<int,int>> arr(100005);

	for(int i=0;i<n;i++)
	{
		arr[a[i].first].first=1;
		arr[a[i].first].second=a[i].second;
	}

	a.clear();
	for(int i=0;i<b.size();i++){
        if(arr[b[i]].first == 1){
                a.push_back({b[i],arr[b[i]].second});
                arr[b[i]].first=0;
            }
        }
  
    for(int i=0;i<arr.size();i++){
        if(arr[i].first==1){
                a.push_back({i,arr[i].second});
            }
        }
    int total=0; int maxi=1;
    for(int i=0;i<m1;i++)
    {
    	if(a[i].second <= maxi)
    	{
    		total++;
    	}
    	else
    	{
    		int k=1+i;
    		maxi=a[i].second;
    		total+=(maxi-k)*2+1;

    	}
    }
    cout<<total<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}