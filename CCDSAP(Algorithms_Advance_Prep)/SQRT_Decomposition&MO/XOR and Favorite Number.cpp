/**
 *   author: sahushivam
 *   created: 01 December 2019 (Sunday)  21:57:12
 *	 MO's algorithm
 * 	 https://codeforces.com/problemset/problem/617/E
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

#define N 2111111
#define A 1111111
#define BLOCK 1453 // ~sqrt(N) and make it constant to make division operation faster
 
int cnt[A], a[N], ans[N], answer = 0;

void init()
{
	for(int i=0;i<A;i++) cnt[i]=0;
	for(int i=0;i<N;i++) a[i]=0;
	for(int i=0;i<N;i++) ans[i]=0;
}
void add(int idx)
{
	answer -= (long long)cnt[a[idx]]*(long long)cnt[a[idx]]*(long long)a[idx];
	cnt[a[idx]]++;
	answer += (long long)cnt[a[idx]]*(long long)cnt[a[idx]]*(long long)a[idx];
}
void remove(int idx)
{
	answer -= (long long)cnt[a[idx]]*(long long)cnt[a[idx]]*(long long)a[idx];
	cnt[a[idx]]--;
	answer += (long long)cnt[a[idx]]*(long long)cnt[a[idx]]*(long long)a[idx];
}
struct Query{
	int l,r,idx;
};
bool compare(Query a,Query b)
{
	if(a.l/BLOCK != b.l/BLOCK) 
		return a.l/BLOCK < b.l/BLOCK;
	else return a.l/BLOCK % 2 ? (a.r < b.r) : (a.r > b.r);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n=1,qu;
    init();
    cin>>n>>qu;
    for(int i=0;i<n;i++) cin>>a[i];
	vector<Query> queries(qu);
	for(int i=0;i<qu;i++){
		cin>>queries[i].l>>queries[i].r;
		queries[i].l--; queries[i].r--;
		queries[i].idx=i;
	}
	sort(queries.begin(),queries.end(),compare);
	int cur_l=0, cur_r=-1;
	for(Query q:queries)
	{
		int L=q.l, R=q.r;
		while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }	
        ans[q.idx] = answer;
    }
    for(int i=0;i<qu;i++)
    	cout<<ans[i]<<endl;
return 0;	
}