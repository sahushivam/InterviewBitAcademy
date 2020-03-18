/**
 *   author: sahushivam
 *   created: 06 July 2019 (Saturday)  19:22:32
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct node
{
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(NULL), right(NULL) {}
};
int findIndex(int *inorder,int i,int j,int val)
{	
	for (auto b = i; b<=j; ++b)
        if (inorder[b] == val)
            return b;

    return -1;

}
node* makeTree(int* &inorder, int* &postorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    node* n = new node(postorder[p--]);
    if (i==j){
        return n;
    }
    int in = findIndex(inorder, i, j, n->val);
    if(in==-1) {return NULL;}
    n->right = makeTree(inorder, postorder, in+1, j, p);
    n->left = makeTree(inorder, postorder, i, in-1, p);
    return n;
}
void pre(node *root,std::vector<int> &v)
{
	if(root)
	{
		v.push_back(root->val);
		pre(root->left,v);
		pre(root->right,v);
	}
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
     cin>>n;
    int *inorder=new int[n];
    int *preorder=new int[n];
    int *postorder=new int[n];
    for (int i=0; i<n;++i) {
        cin>>preorder[i];
    }
    for (int i=0; i<n;++i)  
        cin>>postorder[i];
    for (int i=0; i<n;++i)  
        cin>>inorder[i];
    int p=n-1;
    node *head=makeTree(inorder,postorder,0,n-1,p);
    std::vector<int> v;
    pre(head,v);
    bool flag=true;
    for(int i=0;i<n && i<v.size();i++)
    {
    	if(v[i]!=preorder[i])
    	{
    		flag=false;break;
    	}
    }
    if(flag && v.size()==n)
    	cout<<"yes\n";
    else
    	cout<<"no\n";
return 0;
}