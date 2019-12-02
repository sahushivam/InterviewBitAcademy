#include <iostream>
using namespace std;

unsigned long long max1(unsigned long long a,unsigned long long b)
{
  if(a>b)
    return a;
  else 
    return b;
}
int main() {
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      unsigned long long *x=new unsigned long long[n];
      unsigned long long *y=new unsigned long long[n];
      cout<<n;
      for(int i=0;i<n;i++)
      {
          cin>>x[i]>>y[i];
      }
      unsigned long long x1=x[0];
      unsigned long long y1=y[0];
      unsigned long long x2,y2;
      unsigned long long sum=0;
      for(int i=1;i<n;i++)
      {
          x2=x[i];
          y2=y[i];
          long long diff1= x2-x1;
          long long diff2= y2-y1;
          if(diff1<0) diff1=-diff1;
          if(diff2<0) diff2=-diff2;

          long long steps=max1(diff2,diff1);
          sum+=steps;
          x1=x2;
          y1=y2;
      }
      cout<<sum<<'\n';
  }
  return 0;
}