/*

Given an array of integers A, find and return the lexicographically greatest arrangement of A which follows the below rules:
If the size of A is less than 3 it is always possible to rearrange A.
A[i] = A[i-1] + GCD(A[i-1], A[i-2]) for all i > 2, where GCD(x, y) is greatest common factor of x and y.
Return the lexicographically greatest arrangement of A which follows the above rules, if it is not possible to rearrange A according to the above rules return -1.


*/

int gcd(int a,int b)
{
    if(a>b)
        return gcd(b,a);
    else if(a==0 && a==b)
        return 0;
    else if(a==0)
        return b;
    else
        return __gcd(a,b);
}

vector<int> Solution::solve(vector<int> &a) {
  int n;
  n=a.size();
  vector<int> ans;
  int i,flag,ps;
    sort(a.begin(),a.end());
    if (n<3){
        for (i=n-1;i>=0;i--)
             ans.push_back(a[i]);
        return ans;
    }
    else{
        flag=0;
        for (i=2;i<n;i++){
            if(a[i]!=a[i-1]+gcd(a[i-1],a[i-2])){
                flag=1;
                ps=i;
                break;
            }
        }
        if (flag==0){
            if (a[1]==a[0]+gcd(a[0],a[n-1])){		//case for two element are equal
                ans.push_back(a[n-1]);
                for(i=0;i<n-1;i++)
                    ans.push_back(a[i]);
                return ans;
                }
            else{
                for(i=0;i<n;i++)
                    ans.push_back(a[i]);	//all condition is satisfied
                return ans;
                }
            }
        else{
            if (a[1]==a[0]+gcd(a[ps],a[0])){ 	//where a one change can make the permutation
                flag=0;
                for(i=n-1;i>ps+2;i--){
                    if(a[i]!=a[i-1]+gcd(a[i-1],a[i-2])){
                       flag=1;
                       break;
                      }
                    }
               if (flag==0 && ps<n-1){
                   if (a[ps+1]!=a[ps-1]+gcd(a[ps-1],a[ps-2]))
                       flag=1;
               }
               if (flag==0 && ps<n-2){
                   if (a[ps+2]!=a[ps+1]+gcd(a[ps-1],a[ps+1]))
                       flag=1;
               }
             if (flag==0){
                 ans.push_back(a[ps]);
              for(i=0;i<n;i++)
                  if(i!=ps)
                 	ans.push_back(a[i]);
              return ans;
             }
            }
          }
      }
    ans.push_back(-1);
    return ans;
}
//Hint-1) you couldn’t have more than two elements whose freq was more than 1.
//     2) if you had two zeros in the array, the only possible permutation possible was all 0’s