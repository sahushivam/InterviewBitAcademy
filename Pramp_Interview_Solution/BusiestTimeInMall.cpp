#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data ) 
{
  // your code goes here
  int n=data.size();
  int maxi=0;
  int max_timestamp=data[0][0];
  int curr=0;
  for(int i=0;i<n;i++)
  {
    int curr_time = data[i][0];
    int No = data[i][1];
    int entry_exit = data[i][2];
    if(entry_exit==1)
    {
      curr= curr+No;
    }
    else
    {
      curr=curr-No;
      curr=max(0,curr);
    }
    if(maxi<curr && i+1<n && curr_time != data[i+1][0])
    {
      maxi=curr;
      max_timestamp= curr_time;
    }  
    if(maxi<curr && i==n-1)
    {
      maxi=curr;
      max_timestamp= curr_time;
    }
  }
  return max_timestamp;
}

int main() {
  
  vector<vector<int>> data = { {1487799425, 14, 1}, 
                      {1487799425, 4,  0},
                      {1487799425, 2,  0},
                      {1487800378, 10, 1},
                      {1487801478, 18, 0},
                      {1487801478, 18, 1},
                      {1487901013, 1,  0},
                      {1487901211, 7,  1},
                      {1487901211, 7,  0} };
  cout<<findBusiestPeriod(data);
  return 0;
}
