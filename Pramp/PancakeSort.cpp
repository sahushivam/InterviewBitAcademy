#include <iostream>
#include <vector>

using namespace std;


void flip(vector<int> &arr,int k)
{
  reverse(arr.begin(),arr.begin()+k);
}
int findMinIndex(vector<int> &arr,int end)
{
  int mini=arr[0];
  int minindex=0;
  for(int i=1;i<end;i++)
  {
    if(arr[i]<mini)
    {
      mini=arr[i];
      minindex=i;
    }
  }
  return minindex;
}
vector<int> pancakeSort( const vector<int>& a ) 
{
  int n=a.size();
  vector<int> arr;
  for(auto i: a)
  {
    arr.push_back(i);
  }
  for(int i=0;i<n;i++)
  {
    int smallestIndex = findMinIndex(arr,n-i);
    flip(arr,smallestIndex+1);
    flip(arr,n-i);
    
  }
  flip(arr,n);
  return arr;
}

int main() {
  return 0;
}





