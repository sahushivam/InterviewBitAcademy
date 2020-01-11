/**
 *   author: sahushivam
 *   created: 28 December 2019 (Saturday)  23:40:18
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
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> arr(1000004,0);
	vector<int> arr1(1000004,0);
	for(int i=0;i<n;i++)
	{
		arr[a[i]]++;
		arr1[a[i]]++;
	}
	
	if(arr[1]>1){arr[0]=1; arr[1]--;} 
	for(int i=1;i<1000000;i++)
	{
		if(arr[i]==0 && arr[i-1]>1)
		{
			arr[i]=1;
			arr[i-1]--;
		}
		
		else if(i-2>=0 && arr[i-2]>1 && arr1[i-1]>=1)
		{
			arr[i]=1;
			arr[i-2]--;
		}
		else if(arr[i]==0 && arr[i+1]>=1)
		{
			arr[i]=1;
			arr[i+1]--;
		}
	}
	int maxi=0;
	for(int i=0;i<1000000;i++)
	{
		if(arr[i]){
			maxi++;

		}
	}
	//cout<<maxi<<endl;
	//for minimum
	
	int mini=0;
	for(int i=1;i<=n;i++)
	{
		if (!arr1[i]) continue;
		++mini;
		i += 2;

	}
	cout<<mini<<" "<<maxi;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}