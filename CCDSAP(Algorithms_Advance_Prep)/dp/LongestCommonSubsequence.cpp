/**
 *   author: sahushivam
 *   created: 09 August 2019 (Friday)  15:38:25
**/

// dp[i][j] indicate the ith maximum subsequence of ith length of first string and jth length of 
//second string

//Application 
//The longest common subsequence problem forms the basis of data comparison programs such as the diff utility and use in field of bioinformatics. 
//It is also widely used by revision control systems such as Git.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

//Task-1
int recursive(string s1,string s2,int m,int n)
{
	if(m<0 || n<0) return 0;
	if(s1[m]==s2[n]) return 1+recursive(s1,s2,m-1,n-1);
	return max(recursive(s1,s2,m-1,n),recursive(s1,s2,m,n-1));
}

//Task-2
int iterative(string s1,string s2,int m,int n,int **dp)
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0|| j==0) {dp[i][j]=0; continue;}
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

//Task 3- To print LCS string
string LCS(string s1,string s2,int m,int n,int **dp)
{
	if(m==0||n==0) return "";

	if(s1[m-1]==s2[n-1]) return LCS(s1,s2,m-1,n-1,dp)+s1[m-1];

	if(dp[m-1][n]>dp[m][n-1]) return LCS(s1,s2,m-1,n,dp);
	else return LCS(s1,s2,m,n-1,dp);
}
//Task 4 To print all longest common subsequence

//Approach-If in the matrix left and top are of same value then LCS can be formed by considering
// 			them too.


//Variant of LCS
//1- Longest Common Substring (if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1 else dp[i][j]=0
//2- Longest Palindromic subsequence(LCS of string and its reverse)
//3- Longest Repeated Substring - LCS(X,X) if(i==j) dp[i][j]=0 
											//else if(A[i]==A[j]) dp[i][j]=dp[i-1][j-1]+1
											//else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
//4- Diff Utility- 

	// Input-	string X = “XMJYAUZ”;
	// 			string Y = “XMJAATZ”;
	// OUtput-  X M J -Y A -U +A +T Z 

	//Approach
	// to solve this problem. The idea is to find a longest sequence of characters that is present in both original sequences 
	//in the same order. 
	//From a longest common subsequence it is only a small step to get diff-like output –
// Function to display the differences between two strings


//5-Shortest common supersequence is similar to LCs except we take min(dp[i-1][j] ,dp[i][j-1]) if X[i]!=Y[j] 
//6- Edit distance if(X[i]==Y[j]) dp[i][j]=dp[i-1][j-1]+1 else dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])

void diff(string X, string Y, int m, int n,int**dp)
{
	// if last character of X and Y matches
	if (m > 0 && n > 0 && X[m - 1] == Y[n - 1])
	{
		diff(X, Y, m - 1, n - 1,dp);
		cout << "  " << X[m - 1];
	}

	// current character of Y is not present in X
	else if (n > 0 && (m == 0 || dp[m][n - 1] >= dp[m - 1][n]))
	{
		diff(X, Y, m, n - 1,dp);
		cout << " +" << Y[n - 1];
	}

	// current character of X is not present in Y
	else if (m > 0 && (n == 0 || dp[m][n - 1] < dp[m - 1][n]))
	{
		diff(X, Y, m - 1, n,dp);
		cout << " -" << X[m - 1];
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s1,s2;
    int m,n;
    cin>>s1>>s2;
    m=s1.length();
    n=s2.length();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++) dp[i]=new int[n+1];
    cout<<iterative(s1,s2,m,n,dp)<<endl;
    cout<<recursive(s1,s2,m-1,n-1);
    cout<<LCS(s1,s2,m,n,dp);
return 0;
}