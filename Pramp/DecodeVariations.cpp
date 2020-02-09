#import <iostream>
#import <string>
#include <vector>
using namespace std;

int decodeVariations(const string& S)
{
	// your code goes here
  int n= S.size();
  int prev=1;
   int prev_prev=1;
    int curr;
  for(int i=2;i<=n;i++)
  {
    if(S[i-2]>'0' && S[i-1]!='0'){
      curr=prev;
    }
    else
    {
      curr=0;
    }
    if((S[i-2]=='1') || (S[i-2]=='2' && S[i-1]<'7'))
      curr+=prev_prev;
    prev_prev=prev;
    prev=curr;
  }
  return curr;
}

int main() 
{          
  string s="1270";
  cout<<decodeVariations(s);
	return 0;
}

/*

 1270
 
 dp[0]=1;
 dp[1]=1;
 dp[2]=

dp[0] = 1
dp[1] = 1
dp[2] = 1 //26 dp[2]=dp[2]+dp[0] =2 

1262
dp[0] = 1
dp[1] = 1
dp[2] =



https://www.facebook.com/careers/jobs/139542177014172/

/
