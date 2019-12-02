/**
 *   author: sahushivam
 *   created: 13 August 2019 (Tuesday)  10:41:40
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

//Approach- Brutefoece approach is to either take it or leave an element

int BruteforceLIS(int arr[], int i, int n, int prev)
{
    // Base case: nothing is remaining
    if (i == n)
        return 0;
 
    // case 1: exclude the current element and process the
    // remaining elements
    int excl = LIS(arr, i + 1, n, prev);
 
    // case 2: include the current element if it is greater
    // than previous element in LIS
    int incl = 0;
    if (arr[i] > prev)
        incl = 1 + LIS(arr, i + 1, n, arr[i]);
 
    // return maximum of above two choices
    return max(incl, excl);
}

int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

return 0;
}

//Varient- Longest increasing subsequence with largest sum
