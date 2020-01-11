/**
 *   author: sahushivam
 *   created: 10 January 2020 (Friday)  19:38:58
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
int maxSubArraySum( vector<int> a, int size,int i) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
void solve(){
	int n; cin>>n; 
	vector<int> a(n);
	int s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	int ss1=maxSubArraySum(a,n,1);
	int ss2=maxSubArraySum(a,n-1,0);  
	int ss=max(ss1,ss2);
	if(ss<s)
		cout<<"YES\n";
	else
		cout<<"NO\n";
 
}
 
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; cin>>t; while(t--) solve();
    return 0;
}