#include <iostream>
#include <vector>
using namespace std;

void my_reverse(vector<char> &ans, int startOfWord, int endOfWord)
{
  while(startOfWord<endOfWord)
  {
    char temp=ans[startOfWord];
    ans[startOfWord++]=ans[endOfWord];
    ans[endOfWord--]=temp;
  }
}
vector<char> reverseWords( const vector<char>& arr ) 
{
  // your code goes here
  vector<char> ans(arr.begin(),arr.end());
  reverse(ans.begin(),ans.end());
  ans.push_back(' ');
  int n=ans.size();
  int startOfWord=0;
  int endOfWord;
  for(int i=0;i<n;i++)
  {
    if(ans[i]==' ')
    {
      endOfWord=i-1;
      my_reverse(ans,startOfWord,endOfWord);
      startOfWord=i+1;
    }
  }
  ans.pop_back();
  return ans;
}

int main() {
  vector<char> arr;
  arr= {'p','e','r','f','e','c','t',' ','m','a','k', 'e', 's', ' ','p','r','a', 'c', 't', 'i', 'c', 'e'};
  vector<char> arr1= reverseWords(arr);
  for(char i: arr1)
    cout<<i;
  return 0;
}

// 

// p e r f e c t  p r a c t i c e

// e c i t c a r  p t e c f r e p

// practice perfect
