/**
 *   author: sahushivam
 *   created: 27 December 2019 (Friday)  22:04:25
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

string printRLE(string str) 
{ 
    int n = str.length(); 
    string ans="";
    for (int i = 0; i < n; i++) { 
  
        // Count occurrences of current character 
        int count = 1; 
        while (i < n - 1 && str[i] == str[i + 1]) { 
            count++; 
            i++; 
        } 
  
        // Print character and its count 
       ans+= str[i]+to_string(count); 
    } 
    return ans;
} 
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    string s1=printRLE(s);
    if(s1.length()<n)
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