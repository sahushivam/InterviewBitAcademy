/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  22:21:04
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
#define N 1000000
vector<int> spf(N);
vector<bool> prime(N,true);

void seive()
{
	spf[0]=1; spf[1]=1; spf[2]=2;
	for(int i=2;i<N;i+=2) spf[i]=2,prime[i]=false;
	
	prime[0]=prime[1]=false;
	prime[2]=true;
	for(int i=3;i<N;i+=2)
	{
		if(prime[i])
		{
			spf[i]=i;
			for(int j=i+i;j<N;j+=i){
				prime[j]=false;
				if(!spf[j]) spf[j]=i;
			}
		}
	}
}

vector<int> ans;
void count()
{
	 for(int i = 1; i < N; i++){
        int j = i;
        vector<int> coefficients;
        bool flag=1;
        while(j > 1){
            int divisors = 1;
            int D = spf[j];
            while(j%D == 0){
                j = j/D;
                divisors++;
            }
            coefficients.push_back(divisors);
        }
        if(coefficients.size()==2){
        	if(prime[coefficients[0]] && prime[coefficients[1]] && coefficients[0]!=coefficients[1])
        		ans.push_back(i);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    seive(); count();
    for(int i=7;i<ans.size();i+=9)
    	cout<<ans[i]<<"\n";
return 0;
}