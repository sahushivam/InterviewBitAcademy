/**
 *   author: sahushivam
 *   created: 27 March 2020 (Friday)  20:17:33
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

//Approach
/*
1- Loop through all bits
2- find position all of unset bit(vec) because that will not contribute in ans
3- 	if bits are consecutive than do cnt++;
	else
		cntSubArrayNotSet += cnt * (cnt + 1)/2;
		cnt = 1;


	for (int j = 1; j < vec.size(); j++) { 
            if (vec[j] - vec[j - 1] == 1) { 
                cnt++; 
            } 
            else { 
                cntSubarrNotSet += cnt * (cnt + 1) / 2; 
  
                cnt = 1; 
            } 
        } 
  
        // For last element of vec 
        cntSubarrNotSet += cnt * (cnt + 1) / 2; 
  
        // If vec is empty then cntSubarrNotSet 
        // should be 0 and not 1 
        if (vec.size() == 0) 
            cntSubarrNotSet = 0; 
  
        // Variable to store count of subarrays 
        // whose bitwise OR will have i-th bit set 
        int cntSubarrIthSet = totalSubarrays - cntSubarrNotSet; 
  
        s += cntSubarrIthSet * pow(2, i); 

*/
void solve(){
	vector<int> a= {34,3,54,54,34};

}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t=1; while(t--) solve();
    return 0;
}