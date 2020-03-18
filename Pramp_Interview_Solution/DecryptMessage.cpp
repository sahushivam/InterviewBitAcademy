#include <iostream>
#include <string>

using namespace std;

string decrypt( const string& word ) 
{
  int n=word.size();   string decrypt="";
  if(n==0) return decrypt;
  
  
  if(word[0]!='a') decrypt+=(char)(word[0]-1);
  else decrypt+="z";
  int prev=word[0];
  for(int i=1;i<n;i++)
  {
    int curr=word[i];
    curr-=prev;
    while(curr<97)
        curr+=26;
    decrypt+=char(curr);
    prev=word[i];
  }
  return decrypt;
}

int main() {
  string s="dnotq";
  cout<<decrypt(s);
  return 0;
}


/* a-z = (97-122)   
d     n          o         t         q
100   110        111  
99    114        111-110
c     r


319-111= 208
a
97
96+26
z
10+
*/
