/*

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,..., AN-1.
Find the minimum sub array Al, Al+1 ,..., Ar so if we sort(in ascending order) that sub array, 
then the whole array should get sorted. If A is already sorted, output -1.
*/


//Approach - let Al .. Ar is unsorted.
//then min(Al, …, Ar) >= max(A0, …, Al-1)
//and max(Al, …, Ar) <= min(Ar+1, …, AN-1)

vector<int> Solution::subUnsort(vector<int> &A){
	vector<int> ans;
	int n = A.size();
	int i = 0, j = n-1;
	while(i< n - 1 and A[i] <= A[i + 1]){
		i++;
	}
	while(j > 0 and A[j] >= A[j - 1]){
		j--;
	}
	if(i == n - 1){ // if array is already sorted, output -1
		ans.push_back(-1);
		return ans;
	}
	int mn = A[i + 1], mx = A[i + 1];
	for(int k = i; k <= j; k++){
		mx = max(mx, A[k]);
		mn = min(mn, A[k]);
	}
	int l = 0, r = n - 1;
	while(A[l] <= mn and l <= i){
	   	l++;
	}
	while(A[r] >= mx and r >= j){
		r--;
	}
	ans.push_back(l);
	ans.push_back(r);
	return ans;
}