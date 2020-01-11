//https://www.codechef.com/problems/XORIT
#include <bits/stdc++.h>
using namespace std;
#define int long long
//there are ceil of (R/2) odd number whose least significant bit is 1.
// there are floor(R/2) even number which are odd number in range 1-R/2 multiplied by 2;So the value of their lowest bit is also multiplied by two.
int solve(int n)
{
    int total= (n*(n+1))/2;
    for(int i=1;n;n>>=1,i<<=1)
    {
        total-=(n+1)/2*i; total--; //floor value
    }
    return total;
}
signed main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		cout << solve(r)-solve(l-1) << "\n";
	}
	return 0;
}
