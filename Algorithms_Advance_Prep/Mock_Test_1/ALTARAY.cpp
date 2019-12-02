/**
 *   author: sahushivam
 *   created: 14 November 2019 (Thursday)  10:47:53
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long

bool possible(int mid,vector<int> a,int h)
{
	int days=0;
	for(int i=0;i<a.size();i++)
	{
		days+=(a[i]-1)/mid+1;
	}
	return days>h;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,h; cin>>n>>h;
    	vector<int> a(n);
    	for(int i=0;i<n;i++) cin>>a[i];
    	sort(a.begin(),a.end());
    	int high=*max_element(a.begin(),a.end());
    	int low=0;
    	int ans=INT_MAX;
    	int ans1=INT_MAX;
    	while(low<high)
    	{
    		int mid=(low+high)/2;
    		if(possible(mid,a,h))
    		{
    			low=mid+1;
    		}
    		else{
    			high=mid;
    		}
    	}
    	
    	cout<<high<<endl;
    }
return 0;
}