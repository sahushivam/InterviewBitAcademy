/**
 *   author: sahushivam
 *   created: 10 January 2020 (Friday)  15:03:35
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

int knapSack(int W,int wt[],int val[],int n)
{
	if(W<=0 || n==0) return 0;
	if(wt[n-1]>W) 
		return knapSack(W,wt,val,)
}
void solve(){
	int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);  
    cout<<knapSack(W, wt, val, n);  
    return 0;  
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}