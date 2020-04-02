//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//Approach 1- Find how much water is stored above any building(Use o(n) space and time complexity)
//	Find leftmost highest and righmost highest
//	for 1-n water-trapped+=min(l[i],r[i])-height[i]

int Solution::trap(const vector<int> &A) {
    int l[A.size()];
    int r[A.size()];
    l[0]=A[0];
    int n=A.size();
    r[n-1]=A[n-1];
    for(int i=1;i<n;i++)
    {
        l[i]=max(A[i],l[i-1]);
    }
    for(int i=n-2;i>=0;i--)
        r[i]=max(r[i+1],A[i]);
        int water=0;
    for(int i=0;i<n;i++) water+=min(l[i],r[i])-A[i];
    return water;
}


//Approach 2-Here is my idea: 
//instead of calculating area by height*width, 
//we can think it in a cumulative way. In other words, sum water amount of each bin(width=1).
//Set two pointers l and r to the left and right end of height. 
//Then we get the minimum height (minHeight) of these pointers since the level of the water 
//cannot be higher than it. Then we move the two pointers towards the center. 
//If the coming level is less than minHeight, then it will hold some water. 
//Fill the water until we meet some "barrier" (with height larger than minHeight) and update l and r to repeat this process.

int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0, minHeight = 0;
        while (l < r) {
            while (l < r && height[l] <= minHeight) {
                water += minHeight - height[l++];
            }
            while (l < r && height[r] <= minHeight) {
                water += minHeight - height[r--];
            }
            minHeight = min(height[l], height[r]);
        }
        return water;
    }
