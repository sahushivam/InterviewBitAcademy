/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  20:31:10
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
#define N 100005
vector<int> spf(N);
vector<int> prime(N,true);
// count the number of divisors for i, i*i we can get
// if for i it is (p+1)(q+1)....(r+1) then for i*i it will be (2p+1)(2q+1)...(2r+1) 
void seive()
{
	spf[0]=1; spf[1]=1; spf[2]=2;
	for(int i=2;i<N;i+=2) spf[i]=2;
	
	prime[0]=prime[1]=false;
	
	for(int i=3;i<N;i+=2)
	{
		if(prime[i])
		{
			spf[i]=i;
			for(int j=i;j<N;j+=i){
				prime[j]=false;
				if(!spf[j]) spf[j]=i;
			}
		}
	}
}

vector<int> divisorCount[N*100];
void count()
{
	 for(int i = 1; i < N; i ++){
        int j = i;
        vector<int> coefficients;
        while(j > 1){
            int divisors = 0;
            int D = spf[j];
            //cout<<j<<" ";
            while(j%D == 0){
                j = j/D;
                divisors++;
            }
            coefficients.push_back(divisors);
        }
        int s = 1;
        for(int j : coefficients)
            s = s*(2*j+1);
        divisorCount[s].push_back(1LL * i * i);
    }
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    seive(); count();
    //for(int i=1;i<100;i++) cout<<i<<" "<<spf[i]<<" \n";
    while(t--)
    {
    	int K,L,R;
    	cin>>K>>L>>R;
    	int result = (int)(upper_bound(divisorCount[K].begin(), divisorCount[K].end(), R) - divisorCount[K].begin())
        - (int)(lower_bound(divisorCount[K].begin(), divisorCount[K].end(), L) - divisorCount[K].begin());
        cout<<result<<'\n';
    }
return 0;
}