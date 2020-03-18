/**
 *   author: sahushivam
 *   created: 12 November 2019 (Tuesday)  18:47:34
**/
#include<bits/stdc++.h>
using namespace std;
vector <bool> v(100000000,true);
int arr[8000000];
int main()
{
    long long int n = 100000000;
    long int i,j ;
    v[1] = false;
    v[0] = false;
    for(i=4;i<=n;i+=2)
     v[i]=false;
      for(i=3;i*i<=n;i+=2)
     {
           if(v[i])
	         {
	            for(j=i*i;j<=n;j=j+(2*i))
	            v[j] = false;
	         }
     }
       j=0;
       arr[0] = 2;
       for(i=3;i<=n;i+=2)
      {
        if(v[i])
        arr[++j]=i;
       }
       for(i=1;i<=j;i+=100)
      cout<<arr[i-1]<<"\n";
      return 0;
   }