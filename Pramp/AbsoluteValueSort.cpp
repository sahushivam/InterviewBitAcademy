#import <iostream>
#import <vector>
#include <algorithm>
//country?
using namespace std;

bool comp(int i,int j)
{
  if(abs(i)==abs(j))
  {
    return i<j;
  }
  else
  {
    return abs(i)<abs(j);
  }
}
void merge(int low,int high, vector<int> &a)
{
  int range= high-low+1;
  vector<int> temp(range);
  int mid=(low)+(high-low)/2;
  int i=0, j=mid+1;
  int index=0;
  while(i<=mid && j<=high)
  {
    if(comp(a[i],a[j]))
    {
      temp[index++]=a[i++];
    }
    else
    {
      temp[index++]=a[j++];
    }
  }
  while(i<=mid)
  {
    temp[index++]=a[i++];
  }
  while(j<=high)
  {
    temp[index++]=a[j++];
  }
  for(int i=0;i<range;i++)
  {
    a[low++]=temp[i];
  }
}

void mergeSort(int low,int high, vector<int>&a)
{
  if(low<high)
  {
    int mid=low+(high-low)/2;
    mergeSort(low,mid,a);
    mergeSort(mid+1,high,a);
    merge(low,high,a);
  }
}

vector<int> absSort(const vector<int>& arr)
{
	// your code goes here
  vector<int> a(arr.begin(),arr.end());
  mergeSort(0,arr.size()-1,a);
  return a;
  
}

int main() 
{
	return 0;
}

/*




*/
