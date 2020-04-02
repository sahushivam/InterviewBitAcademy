/*
Find first i from right where A[i]>=A[i+1]
find first j from right that is less than A[i]	
swap(A[j],A[i])
reverse

*/
void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=A.size()-1;
    while (i > 0 && A[i - 1] >= A[i])
    i--;
    if(i==0)
    { 
        sort(A.begin(),A.end());
        return;
    }
    int j=A.size()-1,ch;
    while (A[j] <= A[i - 1])
        j--;
    swap(A[j],A[i-1]);
    reverse(A.begin()+i,A.end());
}