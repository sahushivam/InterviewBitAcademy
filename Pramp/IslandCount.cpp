#include <iostream>
#include <vector>

using namespace std;

vector<long> arrayOfArrayProducts(const vector<int>& arr) 
{
  
  int n = arr.size();
  vector<long> res(n);
  if(n==0) return res;
  if(n<=1) 
  {
    vector<long> a;
    return a;
  }
  vector<long> left(n);
  vector<long> right(n);
  left[0]=1;
  right[n-1]=1;
  
  for(int i=1;i<n;i++)
    left[i]=left[i-1]*arr[i-1]; //left mul prefix
  
  for(int i=n-2;i>=0;i--)
    right[i]=right[i+1]*arr[i+1]; //mul suffix
   
  for(int i=0;i<n;i++)
  {
    res[i]=left[i]*right[i];
  }
  return res;
}

int main() {
  return 0;
}

/*
[8,10,2]

left=[1,8,80]

right[20,2,1]

ans[i]=left[i]*right[i]

return ans


time-complexity-o(n)
space - o(n)
*/
