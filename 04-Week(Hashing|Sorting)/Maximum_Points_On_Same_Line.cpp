/*
Given two array of integers A and B describing a pair of (A[i], B[i]) 
coordinates in 2-D plane. A[i] describe x coordinates of the ith point in 2D plane
whereas B[i] describes the y-coordinate of the ith point in 2D plane.
*/
int gcd (int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(a*-1, b);
    if (b < 0) return gcd(a, b*-1);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}

int Solution::solve(vector<int> &A, vector<int> &B) {
   int result = 0;
for(int i = 0; i < A.size(); i++){
    int samePoint = 1;
    unordered_map<double, int> map;
    for(int j = i + 1; j < A.size(); j++){
        if(A[i] == A[j] && B[i]== B[j]){
            samePoint++;
        }
        else if(A[i]== A[j]){
            map[INT_MAX]++;
        }
        else{
            double slope = double(B[i] - B[j]) / double(A[i] - A[j]);
            map[slope]++;
        }
    }
    int localMax = 0;
    for(auto it = map.begin(); it != map.end(); it++){
        localMax = max(localMax, it->second);
    }
    localMax += samePoint;
    result = max(result, localMax);
}
return result;
}
