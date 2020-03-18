#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2) 
{
  
  vector<int> ans;
  int N=arr1.size();
  int M=arr2.size();
  
  for(int i=0;i<N;i++)
  {
    int element=arr1[i];
    if(binary_search(arr2.begin(),arr2.end(),element)==true)
    {
      ans.push_back(element);
      //cout<<binary_search(arr2.begin(),arr2.end(),element);
    }
  }
  return ans;
}

int main() {
   vector<int> arr1 = {1, 2, 3, 5, 6, 7}, arr2 = {3, 6, 7, 8, 20};
  vector<int> ans=findDuplicates(arr1,arr2);
  for(int i: ans)
  {
   cout<<i<<" ";
  }
  return 0;
}



