#include <iostream>
#include <vector>
#include<map>
using namespace std;
// 4   8
vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  // your code goes here
  map<int,int> mp;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    mp[arr[i]]=i;
  }
  vector<int> ans;
  for(int i=n-1;i>=0;i--)
  {
    int search= limit-arr[i];
    if(arr[i]==search)
    {
      if(mp.find(search) !=mp.end() && mp[search]!=i)
      {
        ans.push_back(i);
        ans.push_back(mp[search]);
        sort(ans.rbegin(),ans.rend());
        return ans; 
      }
    }
    else if(mp.find(search)!=mp.end())
    {
      ans.push_back(i);
      ans.push_back(mp[search]);
      sort(ans.rbegin(),ans.rend());
      return ans;   
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {4, 6, 10, 15, 16}; int lim = 21;
  arr=getIndicesOfItemWeights(arr,lim);
  for(int i: arr) cout<<i<<" ";
  return 0;
}
