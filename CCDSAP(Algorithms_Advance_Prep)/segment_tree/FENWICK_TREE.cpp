/**
 *   author: sahushivam
 *   created: 26 August 2019 (Monday)  11:50:22
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000009
#define INF 1e18
#define first F
#define second S
#define push_back PB
#define make_pair MP


//Before going for Binary Indexed tree to perform operations over range, one must confirm that the operation or the function is:

//Associative. i.e f(f(a, b), c) = f(a, f(b, c)) this is true even for seg-tree

Has an inverse

int coversion(int *arr);

int table[10000];

void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int j)
{
	int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

return 0;
}


//counting inversion
int coversion(int *arr)
{
	int n=arrs.ize();
	auto maxi=max_element(arr,arr+n);
	for(int i=0;i<n+1;i++)
		table[i]=0;
	int inversion_count=0;
	for(int i=n-1;i>=0;i--)
	{
		inversion_count+=query(arr[i]-1);
		update(arr[i],1);
	}
	return inversion_count;

}

//given heights and number of people of that height, and you have n such pairs, find height of kth smallest person 

		

