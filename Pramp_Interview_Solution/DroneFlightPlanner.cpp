#include <iostream>
#include <vector>

using namespace std;

int calcDroneMinEnergy( const vector<vector<int>>& route ) 
{
  if(route.size()==0) return 0;
  int first=route[0][2];
  int maxi=first;
  for(int i=1;i<route.size();i++)
  {
    maxi=max(maxi,route[i][2]);
  }
  return(maxi-first);
}

int main() {
  return 0;
}
