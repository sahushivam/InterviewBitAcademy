#include <iostream>
#include <vector>

using namespace std;


int getDifferentNumber( const vector<int>& arr) 
{
  
  vector<int> a(arr.begin(),arr.end());
  int n=arr.size();
  int flag0=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==0){flag0=1; a[i]=1; }
    int k=abs(a[i]);
    if(k<n){
    a[k]=-a[k];
    }
  }
  if(flag0==0) return 0;

  
  for(int i=1;i<n;i++)
  {
    if(a[i]>0 )
      return i;
  }
  return n;
    
}

int main() {
  vector<int> arr={1,0,3,4,5};
  cout<<getDifferentNumber(arr);
  return 0;
}

/*
[0,1,2,3]
[0, -1,-2,-3]

[0,2,3]
[1,3,4]
[-1,3 ,-4]
i=1
i=2;
return 1;


[1, 2,4]
[2, 3, 5]
[2,-3,5] i =0;
[2,-3,-5] i= 1
[2, -3, -5] i =2

[2,-3,-5] //find a index that is positive
i=0 positive

return 0







[4,2,3, 1,0] 
[4,2,3, -1,0] i=0
[4,2,-3, 1,-0] i=1
[4,2,-3, -1,-0]  i=2
[4,-2,-3, -1,0] i=3
[-4,-2,-3, -1,0] i=4
ans=n;
[]

[1,3,0]
[1,-3,0]
[-]






*/
