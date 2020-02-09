#include <iostream>
#include <vector>

using namespace std;

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  // your code goes her
  sort(grantsArray.rbegin(),grantsArray.rend());
  
  int n=grantsArray.size(); int sum=0;
  
  for(int i=0;i<n;i++) sum+=grantsArray[i];
  int i;
  double ans=grantsArray[0];
  if(sum<=newBudget) return ans;
  double diff=sum-newBudget;
  for(i=0;i<n-1;i++)
  {
    diff -= (i+1)*(grantsArray[i] - grantsArray[i+1]);  
    if(diff<=0)
      break;
  }
    
  int remElemenets = i;
  if(i == n-1) i = n-2;
  //cout<<grantsArray[i+1]<<" "<< diff<<" "<<i;
  ans = grantsArray[i+1] + ((-diff)/float(remElemenets+1));
  return ans;
}

int main() {
  vector<int> arr={2,4};
  
  // cout<< findGrantsCap(arr,3);
  return 0;
}
// 2, 4
//  4, 2
// 3 
     #include <iostream>
#include <vector>

using namespace std;

// x 
// sum( max(x, ans) ) for all x in array  = newBudget


double calculateSum(vector<int> grants, double cap){
  double ans = 0;
  for(int x: grants){
    ans += min(cap, (double)x);
  }
  return ans;
}

// 2 3 100 100 100

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  sort(grantsArray.begin(), grantsArray.end());
  int len = grantsArray.size();
  
  double cap = (double) newBudget / len;  // 38
  
  int currentSum = calculateSum(grantsArray, cap); // 154
  int left = 0; 
  
  int targetBudget = newBudget;
  
  while(currentSum < targetBudget){  // 2 50 100 120 1000
    
   for(int j = left; j < len; j++){
     if(cap <= grantsArray[j]){
       left = j;  // 1
       break;
     }
     else{
       newBudget -= grantsArray[j];
     }
   }
  
   cap = (double)(newBudget) / (len - left);  // 47.0
   currentSum = (int)calculateSum(grantsArray, cap);  //190
    
  } 
  
  return cap;
  
}

int main() {
  
  cout << findGrantsCap({1, 100, 50, 120, 2000}, 190) << endl;
  return 0;
}
