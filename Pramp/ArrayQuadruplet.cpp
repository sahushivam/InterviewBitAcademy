#include <iostream>
#include <vector>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &a, int s) 
{
  // your code goes here
  vector<int> arr(a.begin(),a.end());
  sort(arr.begin(),arr.end());
  int n=arr.size();
  vector<int> ans;
  if(n<4) return ans;
  for(int i=0;i<n-3;i++)
  {
    for(int j=i+1;j<n-2;j++)
    {
      int search = s- (arr[i]+arr[j]);
      int low=j+1, high=n-1;
      while(low<high)
      {
        if(arr[low]+arr[high]<search)
        {
          low++;
        }
        else if(arr[low]+arr[high]>search)
        {
          high--;
        }
        else
        {
          ans.push_back(arr[i]);
          ans.push_back(arr[j]);
          ans.push_back(arr[low]);
          ans.push_back(arr[high]);
          //cout<<i<<" "<<j<<" ";
          return ans;
          //https://leetcode.com/problems/4sum/discuss/8565/Lower-bound-n3
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<int> a ={4,4,4,4};
  int s=16;
  return 0;
}





