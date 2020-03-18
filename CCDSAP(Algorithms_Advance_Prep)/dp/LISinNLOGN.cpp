/**
 *   author: sahushivam
 *   created: 24 August 2019 (Saturday)  15:00:20
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    int lis[n];
    int length=1;
    lis[0]=v[0];
    for(int i=1;i<n;i++)
    {
    	int value=v[i];
    	if(value>lis[length-1])
    	{
    		lis[length++]=value;
    	}
    	else
    	{
    		if(find(lis,lis+length,value)!=lis+length)
    			continue;
    		else{
    			auto it=upper_bound(lis,lis+length,value);
    			*it=value;
    		}
    	}
    }
    for(int i=0;i<length;i++)
    	cout<<lis[i]<<" ";

return 0;
}