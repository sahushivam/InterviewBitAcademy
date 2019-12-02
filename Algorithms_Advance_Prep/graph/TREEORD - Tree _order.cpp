/**
 *   author: sahushivam
 *   created: 06 July 2019 (Saturday)  17:27:47
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool checktree(int *preorder,int *inorder, int *postorder, int len) {
    if (len== 0)
        return 1;
    if (len == 1)
        return (preorder[0] == inorder[0]) && (inorder[0] == postorder[0]);
    int idx = -1;
    for (int i = 0; i < len; ++i)
        if (inorder[i] == preorder[0]) {
            idx = i;
            break;
        }
    if (idx == -1)
        return 0;
    int ret1 = checktree(preorder + 1, inorder, postorder, idx);
    int ret2 = checktree(preorder + idx + 1, inorder + idx + 1, postorder + idx, len - idx - 1);
    return (ret1 && ret2);
}
void solve() {
    int n;
    cin>>n;  
    int *inorder=new int[n];
    int *preorder=new int[n];
    int *postorder=new int[n];
    for (int i=0; i<n;++i)  
        cin>>preorder[i];
    for (int i=0; i<n;++i)  
        cin>>postorder[i];
    for (int i=0; i<n;++i)  
        cin>>inorder[i];
    if(checktree(preorder,inorder,postorder,n))
        cout<<"yes\n";
   	else
   		cout<<"no\n";
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) solve();
return 0;
}