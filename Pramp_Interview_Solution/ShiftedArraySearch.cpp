#include <iostream>
#include <vector>

using namespace std;


int findPivot(const vector<int> &arr)
{
  int n=arr.size();
  int low=0, high=n-1;
  while(low<=high) //0 1 2
  {
    int mid = (low+high)/2;
    if(mid==0 && arr[mid+1]<arr[mid]) //9 0 8
    { 
      return mid+1;
    }
    else if(mid==n-1 && arr[mid-1]>arr[mid])
    {
      return mid; //8 9 0
    }
     
    else if(arr[mid-1]>arr[mid] && arr[mid]<arr[mid+1])
    {
      return mid; //9 0 8
    }
    else if(arr[mid]>arr[mid-1])
    {
      low=mid+1;
    }
    else
    {
      high=mid-1;
    }   
  }
  return 0;
}

int binary_search(const vector<int> &arr,int low,int high,int num)
{
  while(low<=high)
  {
    int mid=low+(high-low)/2;
    if(arr[mid]==num)
      return mid;
    else if(arr[mid]<num)
    {
      low = mid+1; 
    }
    else
      high = mid-1; 
  }
  return -1;
}
int shiftedArrSearch( const vector<int>& arr, int num ) 
{
  // your code goes here let me restart and come back you can keep coding
  int pivot = findPivot(arr);
  int search1 = binary_search(arr, 0,pivot,num);
  int n=arr.size();
  if(search1==-1)
  {
    search1=binary_search(arr, pivot,n-1,num);
  }
  return search1;
}

int main() {
  vector<int> shiftArr = {1,2,3,4,5,0}; int num = 0;
  cout<<shiftedArrSearch(shiftArr, num);
  return 0;
}
