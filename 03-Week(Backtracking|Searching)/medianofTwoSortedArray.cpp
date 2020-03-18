double Solution::findMedianSortedArrays(const vector<int> &input1, const vector<int> &input2) {
    if (input1.size() > input2.size()) {
            return findMedianSortedArrays(input2, input1);
        }
        int x = input1.size();
        int y = input2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? INT_MIN : input1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : input1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }

    
}