/**
 *   author: sahushivam
 *   created: 13 August 2019 (Tuesday)  12:54:18
**/
//The recurrence relation to this problem has similarity to that of edit distance problem,
//so can we relate those two problem. Why the solution works for subsquare matrix and not for subrectangle matrix

//dp[i][j]=min(dp[i][j-1],(left), dp[i-1][j](top),dp[i-1][j-1](top-left)+1

//Approach-
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

return 0;
}

//Varient- 	1-	Maximum sub-square matrix where the sides are 1;
//			2- 	Maximum submatrix where corners are 1
//			3-	Maximum sub-rectangle matrix which is all 1's


//1- State dp[i][j] will state jth consecutive 1's in row and i will indicate ith consecutive 1's in column
//if(mat[i][j]==0) dp[i][j]=(0,0)
// else dp[i][j]=
