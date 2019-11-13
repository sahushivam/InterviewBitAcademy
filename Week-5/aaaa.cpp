#include<bits/stdc++.h>
using namespace std;
int st(vector<int> &v,int x)
{
	int rt=0;
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		rt+=v[i]^x;
	}

	return rt;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=1;i<10;i++)
	{
		cout<<st(v,i)<<" ";
	}
return 0;
}