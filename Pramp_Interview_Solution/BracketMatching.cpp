#include <iostream>
#include <string>
using namespace std;
int bracketMatch( const string& text ) 
{
    int n=text.size();
    int counter=0;
    int openingneed=0;
    for(int i=0;i<n;i++)
    {
      if(text[i]=='(')
      {
        counter++;
      }
      else
      {
        counter--;
      }
      if(counter<0)
      {
        openingneed++;
        counter=0;
      }
    }
    return counter+openingneed;
}

int main(){
  string text="())(";
  cout<<bracketMatch(text);
  return 0;
}


function bracketMatch(text):
    diffCounter = 0
    ans = 0
    n = text.length

    for i from 0 to n-1:
        if ( text[i] == '(' ):
            diffCounter += 1
        else if ( text[i] == ')' ):
            diffCounter -= 1
        if ( diffCounter < 0 ):
            diffCounter += 1
            ans += 1

    return ans + diffCounter
    //
    //https://www.linkedin.com/in/senolcolakatnucleuss/
    
    
    //2:30

