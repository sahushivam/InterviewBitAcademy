
#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<vector<int>> findPairsWithGivenDifference( const vector<int>& a, int k) 
{
  map<int,int> mp;
  for(int i=0;i<a.size();i++)
  {
    mp[a[i]]++;
  }
  vector<vector<int>> ans;
  for(int i=0;i<a.size();i++)
  {
    int y=a[i];
    int x=y+k;
    if(mp.find(x)!=mp.end())
    {
      vector<int> p;
      p.push_back(x);
      p.push_back(y);
      ans.push_back(p);
    }
  }
  return ans;
}
// [0, -1, -2, 2, 1]
// y=0 x=0+1; [1,0]
// y=-1 x=-1+1 [0,-1]
int main() {
  return 0;
}
