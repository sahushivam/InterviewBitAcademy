/*
You are given a read only array of n integers from 1 to n.  Each integer appears exactly once except A which appears twice and B which is missing. Return A and B.  */

//Approach 1- Sort the number 
//Approach 2-Use Map
//Approach 3- Use sum of square and sum of all number from 1-n formula


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    long long sq=(n*(n+1)*(2*n+1))/6;
    long long s=(n*(n+1))/2;
    long long sum=0;
    long long sqsum=0;
    for(long long i=0;i<n;i++)
    {
        sum+=A[i];
        sqsum+=(long long)A[i]*A[i];
    }
    long long x=sq-sqsum;
    long long y=s-sum;
    long long z=(long long)(x/y);
    vector<int> ans;
    ans.push_back((int)(abs((z-y)/2)));
    ans.push_back((int)(abs((y+z)/2)));

    //sort(ans.begin(),ans.end());
    return ans;

}

