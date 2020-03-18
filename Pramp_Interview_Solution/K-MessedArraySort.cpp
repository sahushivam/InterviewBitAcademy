#include <iostream>
#include <vector>
#include<queue>

using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  // your code goes here
  vector<int> a(arr.begin(),arr.end());
  priority_queue<int,vector<int>, greater<int>> pq;
  for(int i=0;i<=k;i++)
  {
    pq.push(arr[i]);
  }
  int n=a.size();
  for(int i=0;i<n;i++)
  {
    a[i]=pq.top();
    pq.pop();
    if(i+k+1<n) 
    {
      pq.push(a[i+k+1]);
    }
  }
  return a;
}

int main() {
  vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9}; int k = 2;
  arr=sortKMessedArray(arr,k);
  for(int i: arr)
    cout<<i;
  return 0;
}

//nlogk + O(n)=O(n)=
//o(k)
