#include <iostream>

using namespace std;

double root(double x, unsigned int n) 
{
  // your code goes here
  
  
  
  
  //can't hear you
  double low =0, high=x;
  if(x>=1)
    low=1;
    
  double error = 0.001;
  double ans=low;
  double err;
  do
  {
    
    double mid = low + (high-low)/2;
    double curr=1;
    for(int i=0;i<n;i++)
    {
      curr=curr*mid;
      if(curr<0 || curr>x)
      {
        high=mid;
        continue;
      }
    }
    ans=mid;
    if(curr>x)
    {
      high=mid;
    }
    else
    {
      low=mid;
    }
    err = (curr - x); 
    if(err<0) err=-err;
    
  }while(err>error); 
  return ans;
}

int main() {
  double x=7;
  unsigned int n=3;
  cout<<root(7,3);
  return 0;
}


/*
7 3
low =1
high=7
mid=3.5
3.5 * 3.5 * 3.5

*/

