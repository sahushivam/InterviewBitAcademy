/**
 *   author: sahushivam
 *   created: 02 December 2019 (Monday)  10:47:04
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

vector<int> prefix(string s)
{
    int n=s.length();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[i-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;

return 0;
}