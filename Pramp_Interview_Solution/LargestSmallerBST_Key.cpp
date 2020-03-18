#include <iostream>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

int findLargestSmallerKey(Node *rootNode, int num) 
{
  // your code goes here
  if(rootNode==NULL)
    return -1;
  if(rootNode-> key<num)
  {
    int ans =findLargestSmallerKey(rootNode->right,num);
    if(ans==-1)
    {
      return rootNode->key;
    }
    else
      return ans;
  }
  else
    return findLargestSmallerKey(rootNode->left,num);
}

int main() {
  Node * root=newNode(20);
  root->left = newNode(9);
  root->right = newNode(25);
  root->left->left=newNode(5);
  root->left->right=newNode(12);
  cout<<findLargestSmallerKey(root,25);
  return 0;
}
