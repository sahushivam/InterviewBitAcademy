#import <iostream>
#import <string>

using namespace std;

bool validateIP(const string& ip)
{
	// your code goes here
  int n=ip.size();
  string str="";
  int countdot=0;
  for(int i=0;i<n;i++)
  {
    if(ip[i]>='0' && ip[i]<='9')
    {
      str+=ip[i];
    }
    else if(ip[i]=='.' && str!="")
    {
      int n1 = stoi(str);
      if(n1<0 || n1>255)
        return false;
      str="";
      countdot++;
    }
    else
    {
      return false;
    }
  }
  int n1=stoi(str);
  if(n1<0 || n1>255)//last case
     return false;
  else if(countdot!=3) return false;

  return true;
}

int main() 
{
  string ip ="123.24.59.499.032";
  cout<<validateIP(ip);
	return 0;
}

/*
192.168.0.1.

192
168



*/
