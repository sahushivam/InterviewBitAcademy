/**
 *   author: sahushivam
 *   created: 09 August 2019 (Friday)  14:43:42
**/



// Approach 

// Let count(i,j) be the number of valid ways of filling the first i positions such that there are j more brackets of type '[' than of type ']'. Valid ways would mean that it is the prefix of a matched  bracket expression and that the locations at which we have enforced '[' brackets have been satisfied. It is easy to see that count(2N,0) is the final answer we need.

// The base case of the DP is that count(1,1)=1. You have to fill the first position with a '[' bracket, and there is only way to do this. count(1,i)=0 for i>1.

// The recurrence for i>1 is:
// count(i,0) = count(i-1,1)
// count(i,j) = count(i-1,j-1) + count(i-1,j+1) for j>0 a) when bracket is ) and b when it is opening

// If i is a location where we have enforced a '[' bracket, the recurrence changes to:
// count(i,0) = 0
// count(i,j) = count(i-1,j-1) for j>0

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

 
#define REP(i,n) for(int i=0;i<n;i++)
 int dp[50][50];
 
int main(){
    //freopen("input.txt", "r", stdin);
    int d;
    cin>>d;
    while(d--){
        int n; cin>>n;
        int k; cin>>k;
        memset(dp,0,sizeof(dp));
        set<int> s;
        REP(i,k){
            int x; cin>>x; s.insert(x);
        }    
        for( int i=1;i<=2*n;i++){
            for( int j=0;j<=i;j++){
                if(i==1){
                    if(j==1)dp[i][j]=1;
                    else dp[i][j]=0;
                }else{
                    if(s.find(i)!=s.end()){
                        dp[i][j] = ((j==0)?0:dp[i-1][j-1]);
                    }else{
                        dp[i][j] = dp[i-1][j+1] + ((j==0)?0:dp[i-1][j-1]);
                    }
                }
            }
        }
        cout<<dp[2*n][0]<<endl;
    }
}