#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007
#define INF 0x7fffffff

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	ll n;cin>>n;
	vector <ll> a(n);
	vector <ll> arr(200005,0);
	vector <ll> arr1(200005,0);
	for(int i=0;i<n;i++)cin>>a[i];
	ll maxi = 0, mini = 0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(arr[a[i]+1]){
			arr[a[i]+1]++;
		}
		else if(arr[a[i]-1]){
			arr[a[i]-1]++;
		}
		else if(arr[a[i]]){
			arr[a[i]]++;
		}
		else{
			arr[a[i]+1]++;
			mini++;
		}
	}
	for(int i=0;i<n;i++){
		if(!arr1[a[i]-1]){
			arr1[a[i]-1]++;
			maxi++;
		}
		else if(!arr1[a[i]]){
			arr1[a[i]]++;
			maxi++;
		}
		else if(!arr1[a[i]+1]){
			arr1[a[i]+1]++;
			maxi++;
		}
	}
	cout<<mini<<" "<<maxi<<endl;
return 0;
}