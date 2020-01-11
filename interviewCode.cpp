#include <bits/stdc++.h>
using namespace std;
  
// structure for Binary Node
struct Node {
    int key;
    struct Node *right, *left;
};

Node* newNode(int num)
{
    Node* temp = new Node;
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
  
// To create a Tree with n levels. We always
// insert new node to left if it is less than
// previous value.
Node* createNLevelTree(int arr[], int n)
{
    Node* root = newNode(arr[0]);
    Node* temp = root;
    for (int i = 1; i < n; i++) {
        if (temp->key > arr[i]) {
            temp->left = newNode(arr[i]);
            temp = temp->left;
        }
        else {
            temp->right = newNode(arr[i]);
            temp = temp->right;
        }
    }
    return root;
}
  
// Please refer below post for details of this
// function.
// https:// www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
bool isBST(Node* root, int min, int max)
{
    if (root == NULL)
        return true;
  
    if (root->key < min || root->key > max)
        return false;
  
    // Allow only distinct values
    return (isBST(root->left, min,
                  (root->key) - 1)
            && isBST(root->right,
                     (root->key) + 1, max));
}
  
// Returns tree if given array of size n can
// represent a BST of n levels.
bool canRepresentNLevelBST(int arr[], int n)
{
    Node* root = createNLevelTree(arr, n);
    return isBST(root, INT_MIN, INT_MAX);
}
 



//Check if a given Binary Tree is Heap


/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
  
/* This function checks if the binary tree is complete or not */
bool isCompleteUtil (struct Node* root, unsigned int index,
                     unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);
  
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
  
    // Recur for left and right subtrees
    return (isCompleteUtil(root->left, 2*index + 1, number_nodes) &&
            isCompleteUtil(root->right, 2*index + 2, number_nodes));
}
  
// This Function checks the heap property in the tree.
bool isHeapUtil(struct Node* root)
{
    //  Base case : single node satisfies property
    if (root->left == NULL && root->right == NULL)
        return (true);
  
    //  node will be in second last level
    if (root->right == NULL)
    {
        //  check heap property at Node
        //  No recursive call , because no need to check last level
         return (root->key >= root->left->key);
    }
    else
    {
        //  Check heap property at Node and
        //  Recursive check heap property at left and right subtree
        if (root->key >= root->left->key &&
            root->key >= root->right->key)
            return ((isHeapUtil(root->left)) &&
                    (isHeapUtil(root->right)));
        else
            return (false);
    }
}
  
//  Function to check binary tree is a Heap or Not.
bool isHeap(struct Node* root)
{
    // These two are used in isCompleteUtil()
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
  
    if (isCompleteUtil(root, index, node_count) && isHeapUtil(root))
        return true;
    return false;
}







// A recursive function to construct BST from pre[]. preIndex is used
// to keep track of index in pre[].
struct node* constructTreeUtil( int pre[], int* preIndex, int key,
                                int min, int max, int size )
{
    // Base case
    if( *preIndex >= size )
        return NULL;
   
    struct node* root = NULL;
   
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if( key > min && key < max )
    {
        // Allocate memory for root of this subtree and increment *preIndex
        root = newNode ( key );
        *preIndex = *preIndex + 1;
          
        if (*preIndex < size)
        {
            // Contruct the subtree under root
            // All nodes which are in range {min .. key} will go in left
            // subtree, and first such node will be root of left subtree.
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                        min, key, size );

            // All nodes which are in range {key..max} will go in right
            // subtree, and first such node will be root of right subtree.
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                         key, max, size );
        }
    }
   
    return root;
}
  
// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}
  












//Construct a Binary Search Tree from given postorder
struct node* constructTreeUtil(int post[], int* postIndex,
                         int key, int min, int max, int size)
{
    // Base case
    if (*postIndex < 0)
        return NULL;
     struct node* root = NULL;
  
    // If current element of post[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this subtree and decrement
        // *postIndex
        root = newNode(key);
        *postIndex = *postIndex - 1;
  
        if (*postIndex >= 0)
        {
  
          // All nodes which are in range {key..max} will go in right
          // subtree, and first such node will be root of right subtree.
          root->right = constructTreeUtil(post, postIndex, post[*postIndex],
                                          key, max, size );
  
          // Contruct the subtree under root
          // All nodes which are in range {min .. key} will go in left
          // subtree, and first such node will be root of left subtree.
          root->left = constructTreeUtil(post, postIndex, post[*postIndex],
                                         min, key, size );
        }
    }
    return root;
}
  
// The main function to construct BST from given postorder
// traversal. This function mainly uses constructTreeUtil()
struct node *constructTree (int post[], int size)
{
    int postIndex = size-1;
    return constructTreeUtil(post, &postIndex, post[postIndex],
                             INT_MIN, INT_MAX, size);
}
  















Query of type 1 :
Find the range sum on segment tree for output query where range is exit time and entry
time of the rooted tree node. Deduce that the answer is always twice the expected answer
because each node is added twice in segment tree. So reduce the answer by half.

Query of type 2 :
For update query, update the leaf node of segment tree at the entry time and exit time of
the rooted tree node.
Below is the implementation of above approach :
// C++ program for implementation of
// Euler Tour | Subtree Sum.
#include <bits/stdc++.h>
using namespace std;
  
vector<int> v[1001];
vector<int> s;
int seg[1001] = { 0 };

// Value/Weight of each node of tree,
// value of 0th(no such node) node is 0.
int ar[] = { 0, 1, 2, 3, 4, 5, 6 };
  
int vertices = 6;
int edges = 5;
  
// A recursive function that constructs
// Segment Tree for array ar[] = { }.
// 'pos' is index of current node
// in segment tree seg[].
int segment(int low, int high, int pos)
{
    if (high == low) {
        seg[pos] = ar[s[low]];
    }
    else {
        int mid = (low + high) / 2;
        segment(low, mid, 2 * pos);
        segment(mid + 1, high, 2 * pos + 1);
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}
  
/* Return sum of elements in range
   from index l to r . It uses the 
   seg[] array created using segment()
   function. 'pos' is index of current
   node in segment tree seg[].
*/
int query(int node, int start,
          int end, int l, int r)
{
    if (r < start || end < l) {
        return 0;
    }
  
    if (l <= start && end <= r) {
        return seg[node];
    }
  
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start,
                   mid, l, r);
    int p2 = query(2 * node + 1, mid + 1,
                   end, l, r);
  
    return (p1 + p2);

    }
  
/* A recursive function to update the
   nodes which have the given index in
   their range. The following are
   parameters pos --> index of current 
   node in segment tree seg[]. idx -->
   index of the element to be updated.
   This index is in input array. 
   val --> Value to be change at node idx
*/
int update(int pos, int low, int high,
           int idx, int val)
{
    if (low == high) {
        seg[pos] = val;
    }
    else {
        int mid = (low + high) / 2;
  
        if (low <= idx && idx <= mid) {
            update(2 * pos, low, mid,
                   idx, val);
        }
        else {
            update(2 * pos + 1, mid + 1,
                   high, idx, val);
        }
  
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}
  
/* A recursive function to form array
    ar[] from a directed tree .
*/
int dfs(int root)
{
    // pushing each node in vector s
    s.push_back(root);
    if (v[root].size() == 0)
        return root;
  
    for (int i = 0; i < v[root].size(); i++) {
        int temp = dfs(v[root][i]);
        s.push_back(temp);
    }
    return root;


    }
  
// Driver program to test above functions
int main()
{
    // Edges between the nodes
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(6);
    v[2].push_back(5);
    v[3].push_back(4);
  
    // Calling dfs function.
    int temp = dfs(1);
    s.push_back(temp);
  
    // Storing entry time and exit
    // time of each node
    vector<pair<int, int> > p;
  
    for (int i = 0; i <= vertices; i++)
        p.push_back(make_pair(0, 0));
  
    for (int i = 0; i < s.size(); i++) {
        if (p[s[i]].first == 0)
            p[s[i]].first = i + 1;
        else
            p[s[i]].second = i + 1;
    }
  
    // Build segment tree from array ar[].
    segment(0, s.size() - 1, 1);
  
    // query of type 1 return the
    // sum of subtree at node 1.
    int node = 1;
    int e = p[node].first;
    int f = p[node].second;
  
    int ans = query(1, 1, s.size(), e, f);
  
    // print the sum of subtree
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl;
  
    // query of type 2 return update
    // the subtree at node 6.
    int val = 10;
    node = 6;
     e = p[node].first;
    f = p[node].second;
    update(1, 1, s.size(), e, val);
    update(1, 1, s.size(), f, val);
  
    // query of type 1 return the
    // sum of subtree at node 2.
    node = 2;
  
    e = p[node].first;
    f = p[node].second;
  
    ans = query(1, 1, s.size(), e, f);
  
    // print the sum of subtree
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl;
  
    return 0;
}



Output:
Subtree sum of node 1 is : 21
Subtree sum of node 2 is : 17
Time Complexity : O(q*log(n))





// This function clones a given linked list
// in O(1) space
Node* clone(Node *start)
{
    Node* curr = start, *temp;
  
    // insert additional node after
     // every node of original list
    while (curr)
    {
        temp = curr->next;
  
        // Inserting node
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
  
    curr = start;
  
    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        curr->next->random = curr->random->next;
  
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next?curr->next->next:curr->next;
    }
  
    Node* original = start, *copy = start->next;
  
    // save the start of copied linked list
    temp = copy;
  
    // now separate the original list and copied list
    while (original && copy)
    {
        original->next =
         original->next? original->next->next : original->next;
  
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
  
    return temp;
}
  
// Driver code
int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);







    #include <bits/stdc++.h> 
  
int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 
  
/* This function sorts the input array and returns the 
   number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and 
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and call _mergeSortAndCountInv() 
       for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of inversions in left-part, right-part 
      and number of inversions in merging */
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays and returns inversion count in 
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
/* Driver program to test above functions */
int main(int argv, char** args) 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    printf(" Number of inversions are %d \n", mergeSort(arr, 5)); 
    getchar(); 
    return 0; 
} 




// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map. 
#include <bits/stdc++.h> 
using namespace std; 
  
class LRUCache { 
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; // maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
}; 
  
// Declare the size 
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
  
// Refers key x with in the LRU cache 
void LRUCache::refer(int x) 
{ 
    // not present in cache 
    if (ma.find(x) == ma.end()) { 
        // cache is full 
        if (dq.size() == csize) { 
            // delete least recently used element 
            int last = dq.back(); 
  
            // Pops the last elmeent 
            dq.pop_back(); 
  
            // Erase the last 
            ma.erase(last); 
        } 
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 
  
// Function to display contents of cache 
void LRUCache::display() 
{ 
  
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = dq.begin(); it != dq.end(); 
         it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
} 
  
// Driver Code 
int main() 
{ 
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
} 


// mirror of a tree

void mirror(struct node* node) 
{
    if (node) 
    {
        struct node* temp;
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
        /* swap the pointers in this node */
        temp  = node->left;
        node->left  = node->right;
        node->right = temp;
     }
}


// Maximum Width of Binary Tree
// In this method we create a temporary array count[] of size equal to the height of tree. We initialize all values in count as 0. We traverse the tree using preorder traversal and fill the entries in count so that the count array contains count of nodes at each level in Binary Tree.

int getMaxWidth(struct node* root)
{
    int width;
    int h = height(root);

    // Create an array that will store count of nodes at each level
    int *count = (int *)calloc(sizeof(int), h);

     int level = 0;

     // Fill the count array using preorder traversal
     getMaxWidthRecur(root, count, level);

     // Return the maximum value from count array
     return getMax(count, h);
}

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level)
{
     if(root)
    {
         count[level]++;
         getMaxWidthRecur(root->left, count, level+1);
        getMaxWidthRecur(root->right, count, level+1);
    }
}
// UTILITY FUNCTIONS 
// Compute the "height" of a tree -- the number of
//nodes along the longest path from the root node
//down to the farthest leaf node.
//int height(struct node* node)
{
     if (node==NULL)
         return 0;
    else
    {
         /* compute the height of each subtree */
         int lHeight = height(node->left);
         int rHeight = height(node->right);
         /* use the larger one */

        return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
    }
}











//Diameter of a binary tree

int diameter(struct node * tree)
{
    /* base case where tree is empty */
    if (tree == 0)
         return 0; 
     /* get the height of left and right sub-trees */
     int lheight = maxDepth(tree->left);
     int rheight = maxDepth(tree->right);

      /* get the diameter of left and right sub-trees */
      int ldiameter = diameter(tree->left);
      int rdiameter = diameter(tree->right);

      /* Return max of following three
      1) Diameter of left subtree
      2) Diameter of right subtree
      3) Height of left subtree + height of right subtree + 1 */
      return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
// Time Complexity:O(n^2)



// Foldable Binary Tree
// A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable.

bool IsFoldable(struct node *root)
{
     if (root == NULL)
         {  return true;  }

     return IsFoldableUtil(root->left, root->right);
}

/* A utility function that checks if trees with roots as n1 and n2
 are mirror of each other */
bool IsFoldableUtil(struct node *n1, struct node *n2)
{
    /* If both left and right subtrees are NULL,
      then return true */
     if (n1 == NULL && n2 == NULL)
          {  return true;  }

     /* If one of the trees is NULL and other is not,
      then return false */
      if (n1 == NULL || n2 == NULL)
             {  return false; }

      /* Otherwise check if left and right subtrees are mirrors of
       their counterparts */
    return IsFoldableUtil(n1->left, n2->right) && IsFoldableUtil(n1->right, n2->left);
}




// C++ Program to find diagonal 
// sum in a Binary Tree 
#include <iostream> 
#include <stdlib.h> 
#include <map> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* Node = 
            (struct Node*)malloc(sizeof(struct Node)); 
      
    Node->data = data; 
    Node->left = Node->right = NULL; 
  
    return Node; 
} 
  
// root - root of the binary tree 
// vd - vertical distance diagonally 
// diagonalSum - map to store Diagonal  
// Sum(Passed by Reference) 
void diagonalSumUtil(struct Node* root, 
                int vd, map<int, int> &diagonalSum) 
{ 
    if(!root) 
        return; 
          
    diagonalSum[vd] += root->data; 
  
    // increase the vertical distance if left child 
    diagonalSumUtil(root->left, vd + 1, diagonalSum); 
  
    // vertical distance remains same for right child 
    diagonalSumUtil(root->right, vd, diagonalSum); 
} 
  
// Function to calculate diagonal  
// sum of given binary tree 
void diagonalSum(struct Node* root) 
{ 
  
    // create a map to store Diagonal Sum 
    map<int, int> diagonalSum;  
      
    diagonalSumUtil(root, 0, diagonalSum); 
  
    map<int, int>::iterator it; 
        cout << "Diagonal sum in a binary tree is - "; 
      
    for(it = diagonalSum.begin(); 
                it != diagonalSum.end(); ++it) 
    { 
        cout << it->second << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
  
    diagonalSum(root); 
  
    return 0; 
} 


// A C++ program to find bridges in a given undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], 
                    int parent[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              cout << u <<" " << v << endl; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 



// / CPP program to count subarrays having product 
// less than k. 
#include <iostream> 
#include <vector> 
using namespace std; 
   
int countSubArrayProductLessThanK(const vector<int>& a,  
                                           long long k) 
{ 
    const int n = a.size();     
    long long p = 1; 
    int res = 0; 
    for (int start = 0, end = 0; end < n; end++) { 
  
        // Move right bound by 1 step. Update the product. 
        p *= a[end]; 
          
        // Move left bound so guarantee that p is again  
        // less than k. 
        while (start < end && p >= k)  
            p /= a[start++];         
          
        // If p is less than k, update the counter. 
        // Note that this is working even for (start == end): 
        // it means that the previous window cannot grow  
        // anymore and a single array element is the only  
        // addendum. 
        if (p < k) { 
            int len = end-start+1; 
            res += len; 
        } 
    } 
  
    return res; 
} 
   
// Driver Function to count number of 
// such arrays 
int main() 
{ 
    cout << countSubArrayProductLessThanK({1, 2, 3, 4}, 10) 
         << endl; 
    cout << countSubArrayProductLessThanK({1, 9, 2, 8, 6,  
            4, 3}, 100) << endl; 
    cout << countSubArrayProductLessThanK({5, 3, 2}, 16)  
         << endl; 
    cout << countSubArrayProductLessThanK({100, 200}, 100)  
         << endl; 
    cout << countSubArrayProductLessThanK({100, 200}, 101) 
         << endl; 
} 


// A C++ program to print topological sorting of a graph 
// using indegrees. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Class to represent a graph 
class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
  
// The function to do Topological Sort. 
void Graph::topologicalSort() 
{ 
    // Create a vector to store indegrees of all 
    // vertices. Initialize all indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists to fill indegrees of 
    // vertices.  This step takes O(V+E) time 
    for (int u=0; u<V; u++) 
    { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
             in_degree[*itr]++; 
    } 
  
    // Create an queue and enqueue all vertices with 
    // indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store result (A topological 
    // ordering of the vertices) 
    vector <int> top_order; 
  
    // One by one dequeue vertices from queue and enqueue 
    // adjacents if indegree of adjacent becomes 0 
    while (!q.empty()) 
    { 
        // Extract front of queue (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its neighbouring nodes 
        // of dequeued node u and decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) 
    { 
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    // Print topological order 
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort(); 
  
    return 0; 
} 



// A C++ program to print topological sorting of a DAG 
#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
// Class to represent a graph 
class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   // Constructor 
  
     // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 
  
    return 0; 
} 


Time Complexity: The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is O(V+E).

Note : Here, we can also use vector instead of stack. If the vector is used then print the elements in reverse order to get the topological sorting.

Applications:
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers [2].








// A C++ program to find bridges in a given undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], 
                    int parent[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              cout << u <<" " << v << endl; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 




Cut vertices

// A C++ program to find articulation points in an undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void AP();    // prints articulation points 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// The function to do DFS traversal. It uses recursive function APUtil() 
void Graph::AP() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
  
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
            cout << i << " "; 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
  
    return 0; 
} 

Time Complexity: The above function is simple DFS with additional arrays. 
So time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.




LCA

// C++ Program for Lowest Common Ancestor in a Binary Tree 
// A O(n) solution to find LCA of two given values n1 and n2 
#include <iostream> 
#include <vector> 
  
using namespace std; 
  
// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Finds the path from root node to given root of the tree, Stores the 
// path in a vector path[], returns true if path exists otherwise false 
bool findPath(Node *root, vector<int> &path, int k) 
{ 
    // base case 
    if (root == NULL) return false; 
  
    // Store this node in path vector. The node will be removed if 
    // not in path from root to k 
    path.push_back(root->key); 
  
    // See if the k is same as root's key 
    if (root->key == k) 
        return true; 
  
    // Check if k is found in left or right sub-tree 
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    // If not present in subtree rooted with root, remove root from 
    // path[] and return false 
    path.pop_back(); 
    return false; 
} 
  
// Returns LCA if node n1, n2 are present in the given binary tree, 
// otherwise return -1 
int findLCA(Node *root, int n1, int n2) 
{ 
    // to store paths to n1 and n2 from the root 
    vector<int> path1, path2; 
  
    // Find paths from root to n1 and root to n1. If either n1 or n2 
    // is not present, return -1 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
  
    /* Compare the paths to get the first different value */
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create the Binary Tree shown in above diagram. 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5); 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6); 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4); 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4); 
    return 0; 
} 




Method 2 (Using Single Traversal)
The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and 
without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root,
then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, 
we recur for left and right subtree. 
The node which has one key present in its left subtree and the other key present in right subtree is the LCA. 
If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 
  
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}; 
  
// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// This function returns pointer to LCA of two given values n1 and n2. 
// This function assumes that n1 and n2 are present in Binary Tree 
struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree given in the above example 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key; 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key; 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key; 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key; 
    return 0; 
}











// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 
  
// A Tree Node 
struct Node 
{ 
    Node *left, *right, *parent; 
    int key; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->parent = temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with 
   given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key); 
        node->left->parent = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->parent = node; 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
   // Creata a map to store ancestors of n1 
   map <Node *, bool> ancestors; 
  
   // Insert n1 and all its ancestors in map 
   while (n1 != NULL) 
   { 
       ancestors[n1] = true; 
       n1 = n1->parent; 
   } 
  
   // Check if n2 or any of its ancestors is in 
   // map. 
   while (n2 != NULL) 
   { 
       if (ancestors.find(n2) != ancestors.end()) 
           return n2; 
       n2 = n2->parent; 
   } 
  
   return NULL; 
} 
  
// Driver method to test above functions 
int main(void) 
{ 
    Node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    Node *n1 = root->left->right->left; 
    Node *n2 = root->left; 
    Node *lca = LCA(n1, n2); 
  
    printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 
  
    return 0; 
} 








// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 
  
// A Tree Node 
struct Node 
{ 
    Node *left, *right, *parent; 
    int key; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->parent = temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with 
given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        node->left = insert(node->left, key); 
        node->left->parent = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->parent = node; 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// A utility function to find depth of a node 
// (distance of it from root) 
int depth(Node *node) 
{ 
    int d = -1; 
    while (node) 
    { 
        ++d; 
        node = node->parent; 
    } 
    return d; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
    // Find depths of two nodes and differences 
    int d1 = depth(n1), d2 = depth(n2); 
    int diff = d1 - d2; 
  
    // If n2 is deeper, swap n1 and n2 
    if (diff < 0) 
    { 
        Node * temp = n1; 
        n1 = n2; 
        n2 = temp; 
        diff = -diff; 
    } 
  
    // Move n1 up until it reaches the same level as n2 
    while (diff--) 
        n1 = n1->parent; 
  
    // Now n1 and n2 are at same levels 
    while (n1 && n2) 
    { 
        if (n1 == n2) 
            return n1; 
        n1 = n1->parent; 
        n2 = n2->parent; 
    } 
  
    return NULL; 
} 
  
// Driver method to test above functions 
int main(void) 
{ 
    Node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    Node *n1 = root->left->right->left; 
    Node *n2 = root->right; 
  
    Node *lca = LCA(n1, n2); 
    printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 
  
    return 0; 
}








/* C++ Program to find LCA of u and v by reducing the problem to RMQ */
#include<bits/stdc++.h> 
#define V 9               // number of nodes in input tree 
  
int euler[2*V - 1];       // For Euler tour sequence 
int level[2*V - 1];       // Level of nodes in tour sequence 
int firstOccurrence[V+1]; // First occurences of nodes in tour 
int ind;                  // Variable to fill-in euler and level arrays 
  
// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// log base 2 of x 
int Log2(int x) 
{ 
    int ans = 0 ; 
    while (x>>=1) ans++; 
    return ans ; 
} 
  
/*  A recursive function to get the minimum value in a given range 
     of array indexes. The following are parameters for this function. 
  
    st    --> Pointer to segment tree 
    index --> Index of current node in the segment tree. Initially 
              0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment represented 
                  by current node, i.e., st[index] 
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int index, int ss, int se, int qs, int qe, int *st) 
{ 
    // If segment of this node is a part of given range, then return 
    //  the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 
  
    // If segment of this node is outside the given range 
    else if (se < qs || ss > qe) 
        return -1; 
  
    // If a part of this segment overlaps with the given range 
    int mid = (ss + se)/2; 
  
    int q1 = RMQUtil(2*index+1, ss, mid, qs, qe, st); 
    int q2 = RMQUtil(2*index+2, mid+1, se, qs, qe, st); 
  
    if (q1==-1) return q2; 
  
    else if (q2==-1) return q1; 
  
    return (level[q1] < level[q2]) ? q1 : q2; 
} 
  
// Return minimum of elements in range from index qs (quey start) to 
// qe (query end).  It mainly uses RMQUtil() 
int RMQ(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return RMQUtil(0, 0, n-1, qs, qe, st); 
} 
  
// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
void constructSTUtil(int si, int ss, int se, int arr[], int *st) 
{ 
    // If there is one element in array, store it in current node of 
    // segment tree and return 
    if (ss == se)st[si] = ss; 
  
    else
    { 
        // If there are more than one elements, then recur for left and 
        // right subtrees and store the minimum of two values in this node 
        int mid = (ss + se)/2; 
        constructSTUtil(si*2+1, ss, mid, arr, st); 
        constructSTUtil(si*2+2, mid+1, se, arr, st); 
  
        if (arr[st[2*si+1]] < arr[st[2*si+2]]) 
            st[si] = st[2*si+1]; 
        else
            st[si] = st[2*si+2]; 
    } 
} 
  
/* Function to construct segment tree from given array. This function 
   allocates memory for segment tree and calls constructSTUtil() to 
   fill the allocated memory */
int *constructST(int arr[], int n) 
{ 
    // Allocate memory for segment tree 
  
    // Height of segment tree 
    int x = Log2(n)+1; 
  
    // Maximum size of segment tree 
    int max_size = 2*(1<<x) - 1;  //  2*pow(2,x) -1 
  
    int *st = new int[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(0, 0, n-1, arr, st); 
  
    // Return the constructed segment tree 
    return st; 
} 
  
// Recursive version of the Euler tour of T 
void eulerTour(Node *root, int l) 
{ 
    /* if the passed node exists */
    if (root) 
    { 
        euler[ind] = root->key; // insert in euler array 
        level[ind] = l;         // insert l in level array 
        ind++;                  // increment index 
  
        /* if unvisited, mark first occurrence */
        if (firstOccurrence[root->key] == -1) 
            firstOccurrence[root->key] = ind-1; 
  
        /* tour left subtree if exists, and remark euler 
           and level arrays for parent on return */
        if (root->left) 
        { 
            eulerTour(root->left, l+1); 
            euler[ind]=root->key; 
            level[ind] = l; 
            ind++; 
        } 
  
        /* tour right subtree if exists, and remark euler 
           and level arrays for parent on return */
        if (root->right) 
        { 
            eulerTour(root->right, l+1); 
            euler[ind]=root->key; 
            level[ind] = l; 
            ind++; 
        } 
    } 
} 
  
// Returns LCA of nodes n1, n2 (assuming they are 
//  present in the tree) 
int findLCA(Node *root, int u, int v) 
{ 
    /* Mark all nodes unvisited.  Note that the size of 
        firstOccurrence is 1 as node values which vary from 
        1 to 9 are used as indexes */
    memset(firstOccurrence, -1, sizeof(int)*(V+1)); 
  
    /* To start filling euler and level arrays from index 0 */
    ind = 0; 
  
    /* Start Euler tour with root node on level 0 */
    eulerTour(root, 0); 
  
    /* construct segment tree on level array */
    int *st = constructST(level, 2*V-1); 
  
    /* If v before u in Euler tour.  For RMQ to work, first 
       parameter 'u' must be smaller than second 'v' */
    if (firstOccurrence[u]>firstOccurrence[v]) 
       std::swap(u, v); 
  
    // Starting and ending indexes of query range 
    int qs = firstOccurrence[u]; 
    int qe = firstOccurrence[v]; 
  
    // query for index of LCA in tour 
    int index = RMQ(st, 2*V-1, qs, qe); 
  
    /* return LCA node */
    return euler[index]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create the Binary Tree as shown in the diagram. 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
  
    int u = 4, v = 9; 
    printf("The LCA of node %d and node %d is node %d.\n",  
            u, v, findLCA(root, u, v)); 
    return 0; 
} 


Note:

We assume that the nodes queried are present in the tree.
We also assumed that if there are V nodes in tree, then keys (or data) of these nodes are in range from 1 to V.
Time complexity:

Euler tour: Number of nodes is V. For a tree, E = V-1. Euler tour (DFS) will take O(V+E) which is O(2*V) which can be written as O(V).
Segment Tree construction : O(n) where n = V + E = 2*V – 1.
Range Minimum query: O(log(n))
Overall this method takes O(n) time for preprocssing, but takes O(Log n) time for query. 
Therefore, it can be useful when we have a single tree on which we want to perform large number of LCA queries 
(Note that LCA is useful for finding shortest path between two nodes of Binary Tree)

Auxiliary Space:

Euler tour array: O(n) where n = 2*V – 1
Node Levels array: O(n)
First Occurrences array: O(V)
Segment Tree: O(n)
Overall: O(n)




// C++ Implementation of Kosaraju's algorithm to print all SCCs 
#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // An array of adjacency lists 
  
    // Fills Stack with vertices (in increasing order of finishing 
    // times). The top element of stack has the maximum finishing  
    // time 
    void fillOrder(int v, bool visited[], stack<int> &Stack); 
  
    // A recursive function to print DFS starting from v 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
  
    // The main function that finds and prints strongly connected 
    // components 
    void printSCCs(); 
  
    // Function that returns reverse (or transpose) of this graph 
    Graph getTranspose(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (int v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            gr.DFSUtil(v, visited); 
            cout << endl; 
        } 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
  
    return 0; 
} 





Maximise array sum after taking non-overlapping sub-arrays of length K
Given an integer array arr[] of length N and an integer K, the task is to select some non-overlapping sub-arrays
such that each sub-array is exactly of length K,
no two sub-arrays are adjacent and sum of all the elements of the selected sub-arrays is maximum.



// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define maxLen 10 
using namespace std; 
  
// To store the states of dp 
int dp[maxLen]; 
  
// To check if a given state 
// has been solved 
bool v[maxLen]; 
  
// To store the prefix-sum 
int prefix_sum[maxLen]; 
  
// Function to fill the prefix_sum[] with 
// the prefix sum of the given array 
void findPrefixSum(int arr[], int n) 
{ 
    prefix_sum[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefix_sum[i] = arr[i] + prefix_sum[i - 1]; 
} 
  
// Function to find the maximum sum subsequence 
// such that no two elements are adjacent 
int maxSum(int arr[], int i, int n, int k) 
{ 
    // Base case 
    if (i + k > n) 
        return 0; 
  
    // To check if a state has 
    // been solved 
    if (v[i]) 
        return dp[i]; 
    v[i] = 1; 
  
    int x; 
  
    if (i == 0) 
        x = prefix_sum[k - 1]; 
    else
        x = prefix_sum[i + k - 1] - prefix_sum[i - 1]; 
  
    // Required recurrence relation 
    dp[i] = max(maxSum(arr, i + 1, n, k), 
                x + maxSum(arr, i + k + 1, n, k)); 
  
    // Returning the value 
    return dp[i]; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 3, 7, 6 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 1; 
  
    // Finding prefix-sum 
    findPrefixSum(arr, n); 
  
    // Finding the maximum possible sum 
    cout << maxSum(arr, 0, n, k); 
  
    return 0; 
} 










// Program to find if there is a simple path with 
// weight more than k 
#include<bits/stdc++.h> 
using namespace std; 
  
// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 
  
// This class represents a dipathted graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge 
    list< pair<int, int> > *adj; 
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path); 
  
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
    bool pathMoreThanK(int src, int k); 
}; 
  
// Returns true if graph has path more than k length 
bool Graph::pathMoreThanK(int src, int k) 
{ 
    // Create a path array with nothing included 
    // in path 
    vector<bool> path(V, false); 
  
    // Add source vertex to path 
    path[src] = 1; 
  
    return pathMoreThanKUtil(src, k, path); 
} 
  
// Prints shortest paths from src to all other vertices 
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path) 
{ 
    // If k is 0 or negative, return true; 
    if (k <= 0) 
        return true; 
  
    // Get all adjacent vertices of source vertex src and 
    // recursively explore all paths from src. 
    list<iPair>::iterator i; 
    for (i = adj[src].begin(); i != adj[src].end(); ++i) 
    { 
        // Get adjacent vertex and weight of edge 
        int v = (*i).first; 
        int w = (*i).second; 
  
        // If vertex v is already there in path, then 
        // there is a cycle (we ignore this edge) 
        if (path[v] == true) 
            continue; 
  
        // If weight of is more than k, return true 
        if (w >= k) 
            return true; 
  
        // Else add this vertex to path 
        path[v] = true; 
  
        // If this adjacent can provide a path longer 
        // than k, return true. 
        if (pathMoreThanKUtil(v, k-w, path)) 
            return true; 
  
        // Backtrack 
        path[v] = false; 
    } 
  
    // If no adjacent could produce longer path, return 
    // false 
    return false; 
} 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
// Utility function to an edge (u, v) of weight w 
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    int src = 0; 
    int k = 62; 
    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n"; 
  
    k = 60; 
    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n"; 
  
    return 0; 
} 


#include <bits/stdc++.h>
using namespace std;
  
// structure for Binary Node
struct Node {
    int key;
    struct Node *right, *left;
};

Node* newNode(int num)
{
    Node* temp = new Node;
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
  
// To create a Tree with n levels. We always
// insert new node to left if it is less than
// previous value.
Node* createNLevelTree(int arr[], int n)
{
    Node* root = newNode(arr[0]);
    Node* temp = root;
    for (int i = 1; i < n; i++) {
        if (temp->key > arr[i]) {
            temp->left = newNode(arr[i]);
            temp = temp->left;
        }
        else {
            temp->right = newNode(arr[i]);
            temp = temp->right;
        }
    }
    return root;
}
  
// Please refer below post for details of this
// function.
// https:// www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
bool isBST(Node* root, int min, int max)
{
    if (root == NULL)
        return true;
  
    if (root->key < min || root->key > max)
        return false;
  
    // Allow only distinct values
    return (isBST(root->left, min,
                  (root->key) - 1)
            && isBST(root->right,
                     (root->key) + 1, max));
}
  
// Returns tree if given array of size n can
// represent a BST of n levels.
bool canRepresentNLevelBST(int arr[], int n)
{
    Node* root = createNLevelTree(arr, n);
    return isBST(root, INT_MIN, INT_MAX);
}
 



//Check if a given Binary Tree is Heap


/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
  
/* This function checks if the binary tree is complete or not */
bool isCompleteUtil (struct Node* root, unsigned int index,
                     unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);
  
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
  
    // Recur for left and right subtrees
    return (isCompleteUtil(root->left, 2*index + 1, number_nodes) &&
            isCompleteUtil(root->right, 2*index + 2, number_nodes));
}
  
// This Function checks the heap property in the tree.
bool isHeapUtil(struct Node* root)
{
    //  Base case : single node satisfies property
    if (root->left == NULL && root->right == NULL)
        return (true);
  
    //  node will be in second last level
    if (root->right == NULL)
    {
        //  check heap property at Node
        //  No recursive call , because no need to check last level
         return (root->key >= root->left->key);
    }
    else
    {
        //  Check heap property at Node and
        //  Recursive check heap property at left and right subtree
        if (root->key >= root->left->key &&
            root->key >= root->right->key)
            return ((isHeapUtil(root->left)) &&
                    (isHeapUtil(root->right)));
        else
            return (false);
    }
}
  
//  Function to check binary tree is a Heap or Not.
bool isHeap(struct Node* root)
{
    // These two are used in isCompleteUtil()
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
  
    if (isCompleteUtil(root, index, node_count) && isHeapUtil(root))
        return true;
    return false;
}







// A recursive function to construct BST from pre[]. preIndex is used
// to keep track of index in pre[].
struct node* constructTreeUtil( int pre[], int* preIndex, int key,
                                int min, int max, int size )
{
    // Base case
    if( *preIndex >= size )
        return NULL;
   
    struct node* root = NULL;
   
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if( key > min && key < max )
    {
        // Allocate memory for root of this subtree and increment *preIndex
        root = newNode ( key );
        *preIndex = *preIndex + 1;
          
        if (*preIndex < size)
        {
            // Contruct the subtree under root
            // All nodes which are in range {min .. key} will go in left
            // subtree, and first such node will be root of left subtree.
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                        min, key, size );

            // All nodes which are in range {key..max} will go in right
            // subtree, and first such node will be root of right subtree.
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                         key, max, size );
        }
    }
   
    return root;
}
  
// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}
  












//Construct a Binary Search Tree from given postorder
struct node* constructTreeUtil(int post[], int* postIndex,
                         int key, int min, int max, int size)
{
    // Base case
    if (*postIndex < 0)
        return NULL;
     struct node* root = NULL;
  
    // If current element of post[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this subtree and decrement
        // *postIndex
        root = newNode(key);
        *postIndex = *postIndex - 1;
  
        if (*postIndex >= 0)
        {
  
          // All nodes which are in range {key..max} will go in right
          // subtree, and first such node will be root of right subtree.
          root->right = constructTreeUtil(post, postIndex, post[*postIndex],
                                          key, max, size );
  
          // Contruct the subtree under root
          // All nodes which are in range {min .. key} will go in left
          // subtree, and first such node will be root of left subtree.
          root->left = constructTreeUtil(post, postIndex, post[*postIndex],
                                         min, key, size );
        }
    }
    return root;
}
  
// The main function to construct BST from given postorder
// traversal. This function mainly uses constructTreeUtil()
struct node *constructTree (int post[], int size)
{
    int postIndex = size-1;
    return constructTreeUtil(post, &postIndex, post[postIndex],
                             INT_MIN, INT_MAX, size);
}
  















Query of type 1 :
Find the range sum on segment tree for output query where range is exit time and entry
time of the rooted tree node. Deduce that the answer is always twice the expected answer
because each node is added twice in segment tree. So reduce the answer by half.

Query of type 2 :
For update query, update the leaf node of segment tree at the entry time and exit time of
the rooted tree node.
Below is the implementation of above approach :
// C++ program for implementation of
// Euler Tour | Subtree Sum.
#include <bits/stdc++.h>
using namespace std;
  
vector<int> v[1001];
vector<int> s;
int seg[1001] = { 0 };

// Value/Weight of each node of tree,
// value of 0th(no such node) node is 0.
int ar[] = { 0, 1, 2, 3, 4, 5, 6 };
  
int vertices = 6;
int edges = 5;
  
// A recursive function that constructs
// Segment Tree for array ar[] = { }.
// 'pos' is index of current node
// in segment tree seg[].
int segment(int low, int high, int pos)
{
    if (high == low) {
        seg[pos] = ar[s[low]];
    }
    else {
        int mid = (low + high) / 2;
        segment(low, mid, 2 * pos);
        segment(mid + 1, high, 2 * pos + 1);
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}
  
/* Return sum of elements in range
   from index l to r . It uses the 
   seg[] array created using segment()
   function. 'pos' is index of current
   node in segment tree seg[].
*/
int query(int node, int start,
          int end, int l, int r)
{
    if (r < start || end < l) {
        return 0;
    }
  
    if (l <= start && end <= r) {
        return seg[node];
    }
  
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start,
                   mid, l, r);
    int p2 = query(2 * node + 1, mid + 1,
                   end, l, r);
  
    return (p1 + p2);

    }
  
/* A recursive function to update the
   nodes which have the given index in
   their range. The following are
   parameters pos --> index of current 
   node in segment tree seg[]. idx -->
   index of the element to be updated.
   This index is in input array. 
   val --> Value to be change at node idx
*/
int update(int pos, int low, int high,
           int idx, int val)
{
    if (low == high) {
        seg[pos] = val;
    }
    else {
        int mid = (low + high) / 2;
  
        if (low <= idx && idx <= mid) {
            update(2 * pos, low, mid,
                   idx, val);
        }
        else {
            update(2 * pos + 1, mid + 1,
                   high, idx, val);
        }
  
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}
  
/* A recursive function to form array
    ar[] from a directed tree .
*/
int dfs(int root)
{
    // pushing each node in vector s
    s.push_back(root);
    if (v[root].size() == 0)
        return root;
  
    for (int i = 0; i < v[root].size(); i++) {
        int temp = dfs(v[root][i]);
        s.push_back(temp);
    }
    return root;


    }
  
// Driver program to test above functions
int main()
{
    // Edges between the nodes
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(6);
    v[2].push_back(5);
    v[3].push_back(4);
  
    // Calling dfs function.
    int temp = dfs(1);
    s.push_back(temp);
  
    // Storing entry time and exit
    // time of each node
    vector<pair<int, int> > p;
  
    for (int i = 0; i <= vertices; i++)
        p.push_back(make_pair(0, 0));
  
    for (int i = 0; i < s.size(); i++) {
        if (p[s[i]].first == 0)
            p[s[i]].first = i + 1;
        else
            p[s[i]].second = i + 1;
    }
  
    // Build segment tree from array ar[].
    segment(0, s.size() - 1, 1);
  
    // query of type 1 return the
    // sum of subtree at node 1.
    int node = 1;
    int e = p[node].first;
    int f = p[node].second;
  
    int ans = query(1, 1, s.size(), e, f);
  
    // print the sum of subtree
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl;
  
    // query of type 2 return update
    // the subtree at node 6.
    int val = 10;
    node = 6;
     e = p[node].first;
    f = p[node].second;
    update(1, 1, s.size(), e, val);
    update(1, 1, s.size(), f, val);
  
    // query of type 1 return the
    // sum of subtree at node 2.
    node = 2;
  
    e = p[node].first;
    f = p[node].second;
  
    ans = query(1, 1, s.size(), e, f);
  
    // print the sum of subtree
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl;
  
    return 0;
}



Output:
Subtree sum of node 1 is : 21
Subtree sum of node 2 is : 17
Time Complexity : O(q*log(n))





// This function clones a given linked list
// in O(1) space
Node* clone(Node *start)
{
    Node* curr = start, *temp;
  
    // insert additional node after
     // every node of original list
    while (curr)
    {
        temp = curr->next;
  
        // Inserting node
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
  
    curr = start;
  
    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        curr->next->random = curr->random->next;
  
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next?curr->next->next:curr->next;
    }
  
    Node* original = start, *copy = start->next;
  
    // save the start of copied linked list
    temp = copy;
  
    // now separate the original list and copied list
    while (original && copy)
    {
        original->next =
         original->next? original->next->next : original->next;
  
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
  
    return temp;
}
  
// Driver code
int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);







    #include <bits/stdc++.h> 
  
int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 
  
/* This function sorts the input array and returns the 
   number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and 
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and call _mergeSortAndCountInv() 
       for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of inversions in left-part, right-part 
      and number of inversions in merging */
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays and returns inversion count in 
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
/* Driver program to test above functions */
int main(int argv, char** args) 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    printf(" Number of inversions are %d \n", mergeSort(arr, 5)); 
    getchar(); 
    return 0; 
} 




// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map. 
#include <bits/stdc++.h> 
using namespace std; 
  
class LRUCache { 
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; // maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
}; 
  
// Declare the size 
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
  
// Refers key x with in the LRU cache 
void LRUCache::refer(int x) 
{ 
    // not present in cache 
    if (ma.find(x) == ma.end()) { 
        // cache is full 
        if (dq.size() == csize) { 
            // delete least recently used element 
            int last = dq.back(); 
  
            // Pops the last elmeent 
            dq.pop_back(); 
  
            // Erase the last 
            ma.erase(last); 
        } 
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 
  
// Function to display contents of cache 
void LRUCache::display() 
{ 
  
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = dq.begin(); it != dq.end(); 
         it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
} 
  
// Driver Code 
int main() 
{ 
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
} 


// mirror of a tree

void mirror(struct node* node) 
{
    if (node) 
    {
        struct node* temp;
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
        /* swap the pointers in this node */
        temp  = node->left;
        node->left  = node->right;
        node->right = temp;
     }
}


// Maximum Width of Binary Tree
// In this method we create a temporary array count[] of size equal to the height of tree. We initialize all values in count as 0. We traverse the tree using preorder traversal and fill the entries in count so that the count array contains count of nodes at each level in Binary Tree.

int getMaxWidth(struct node* root)
{
    int width;
    int h = height(root);

    // Create an array that will store count of nodes at each level
    int *count = (int *)calloc(sizeof(int), h);

     int level = 0;

     // Fill the count array using preorder traversal
     getMaxWidthRecur(root, count, level);

     // Return the maximum value from count array
     return getMax(count, h);
}

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level)
{
     if(root)
    {
         count[level]++;
         getMaxWidthRecur(root->left, count, level+1);
        getMaxWidthRecur(root->right, count, level+1);
    }
}
// UTILITY FUNCTIONS 
// Compute the "height" of a tree -- the number of
//nodes along the longest path from the root node
//down to the farthest leaf node.
//int height(struct node* node)
{
     if (node==NULL)
         return 0;
    else
    {
         /* compute the height of each subtree */
         int lHeight = height(node->left);
         int rHeight = height(node->right);
         /* use the larger one */

        return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
    }
}











//Diameter of a binary tree

int diameter(struct node * tree)
{
    /* base case where tree is empty */
    if (tree == 0)
         return 0; 
     /* get the height of left and right sub-trees */
     int lheight = maxDepth(tree->left);
     int rheight = maxDepth(tree->right);

      /* get the diameter of left and right sub-trees */
      int ldiameter = diameter(tree->left);
      int rdiameter = diameter(tree->right);

      /* Return max of following three
      1) Diameter of left subtree
      2) Diameter of right subtree
      3) Height of left subtree + height of right subtree + 1 */
      return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
// Time Complexity:O(n^2)



// Foldable Binary Tree
// A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable.

bool IsFoldable(struct node *root)
{
     if (root == NULL)
         {  return true;  }

     return IsFoldableUtil(root->left, root->right);
}

/* A utility function that checks if trees with roots as n1 and n2
 are mirror of each other */
bool IsFoldableUtil(struct node *n1, struct node *n2)
{
    /* If both left and right subtrees are NULL,
      then return true */
     if (n1 == NULL && n2 == NULL)
          {  return true;  }

     /* If one of the trees is NULL and other is not,
      then return false */
      if (n1 == NULL || n2 == NULL)
             {  return false; }

      /* Otherwise check if left and right subtrees are mirrors of
       their counterparts */
    return IsFoldableUtil(n1->left, n2->right) && IsFoldableUtil(n1->right, n2->left);
}




// C++ Program to find diagonal 
// sum in a Binary Tree 
#include <iostream> 
#include <stdlib.h> 
#include <map> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* Node = 
            (struct Node*)malloc(sizeof(struct Node)); 
      
    Node->data = data; 
    Node->left = Node->right = NULL; 
  
    return Node; 
} 
  
// root - root of the binary tree 
// vd - vertical distance diagonally 
// diagonalSum - map to store Diagonal  
// Sum(Passed by Reference) 
void diagonalSumUtil(struct Node* root, 
                int vd, map<int, int> &diagonalSum) 
{ 
    if(!root) 
        return; 
          
    diagonalSum[vd] += root->data; 
  
    // increase the vertical distance if left child 
    diagonalSumUtil(root->left, vd + 1, diagonalSum); 
  
    // vertical distance remains same for right child 
    diagonalSumUtil(root->right, vd, diagonalSum); 
} 
  
// Function to calculate diagonal  
// sum of given binary tree 
void diagonalSum(struct Node* root) 
{ 
  
    // create a map to store Diagonal Sum 
    map<int, int> diagonalSum;  
      
    diagonalSumUtil(root, 0, diagonalSum); 
  
    map<int, int>::iterator it; 
        cout << "Diagonal sum in a binary tree is - "; 
      
    for(it = diagonalSum.begin(); 
                it != diagonalSum.end(); ++it) 
    { 
        cout << it->second << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
  
    diagonalSum(root); 
  
    return 0; 
} 


// A C++ program to find bridges in a given undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], 
                    int parent[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              cout << u <<" " << v << endl; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 



// / CPP program to count subarrays having product 
// less than k. 
#include <iostream> 
#include <vector> 
using namespace std; 
   
int countSubArrayProductLessThanK(const vector<int>& a,  
                                           long long k) 
{ 
    const int n = a.size();     
    long long p = 1; 
    int res = 0; 
    for (int start = 0, end = 0; end < n; end++) { 
  
        // Move right bound by 1 step. Update the product. 
        p *= a[end]; 
          
        // Move left bound so guarantee that p is again  
        // less than k. 
        while (start < end && p >= k)  
            p /= a[start++];         
          
        // If p is less than k, update the counter. 
        // Note that this is working even for (start == end): 
        // it means that the previous window cannot grow  
        // anymore and a single array element is the only  
        // addendum. 
        if (p < k) { 
            int len = end-start+1; 
            res += len; 
        } 
    } 
  
    return res; 
} 
   
// Driver Function to count number of 
// such arrays 
int main() 
{ 
    cout << countSubArrayProductLessThanK({1, 2, 3, 4}, 10) 
         << endl; 
    cout << countSubArrayProductLessThanK({1, 9, 2, 8, 6,  
            4, 3}, 100) << endl; 
    cout << countSubArrayProductLessThanK({5, 3, 2}, 16)  
         << endl; 
    cout << countSubArrayProductLessThanK({100, 200}, 100)  
         << endl; 
    cout << countSubArrayProductLessThanK({100, 200}, 101) 
         << endl; 
} 


// A C++ program to print topological sorting of a graph 
// using indegrees. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Class to represent a graph 
class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
  
// The function to do Topological Sort. 
void Graph::topologicalSort() 
{ 
    // Create a vector to store indegrees of all 
    // vertices. Initialize all indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists to fill indegrees of 
    // vertices.  This step takes O(V+E) time 
    for (int u=0; u<V; u++) 
    { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
             in_degree[*itr]++; 
    } 
  
    // Create an queue and enqueue all vertices with 
    // indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store result (A topological 
    // ordering of the vertices) 
    vector <int> top_order; 
  
    // One by one dequeue vertices from queue and enqueue 
    // adjacents if indegree of adjacent becomes 0 
    while (!q.empty()) 
    { 
        // Extract front of queue (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its neighbouring nodes 
        // of dequeued node u and decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) 
    { 
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    // Print topological order 
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort(); 
  
    return 0; 
} 



// A C++ program to print topological sorting of a DAG 
#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
// Class to represent a graph 
class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   // Constructor 
  
     // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 
  
    return 0; 
} 


Time Complexity: The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is O(V+E).

Note : Here, we can also use vector instead of stack. If the vector is used then print the elements in reverse order to get the topological sorting.

Applications:
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers [2].








// A C++ program to find bridges in a given undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], 
                    int parent[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              cout << u <<" " << v << endl; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 




Cut vertices

// A C++ program to find articulation points in an undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void AP();    // prints articulation points 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// The function to do DFS traversal. It uses recursive function APUtil() 
void Graph::AP() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
  
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
            cout << i << " "; 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
  
    return 0; 
} 

Time Complexity: The above function is simple DFS with additional arrays. 
So time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.




LCA

// C++ Program for Lowest Common Ancestor in a Binary Tree 
// A O(n) solution to find LCA of two given values n1 and n2 
#include <iostream> 
#include <vector> 
  
using namespace std; 
  
// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Finds the path from root node to given root of the tree, Stores the 
// path in a vector path[], returns true if path exists otherwise false 
bool findPath(Node *root, vector<int> &path, int k) 
{ 
    // base case 
    if (root == NULL) return false; 
  
    // Store this node in path vector. The node will be removed if 
    // not in path from root to k 
    path.push_back(root->key); 
  
    // See if the k is same as root's key 
    if (root->key == k) 
        return true; 
  
    // Check if k is found in left or right sub-tree 
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    // If not present in subtree rooted with root, remove root from 
    // path[] and return false 
    path.pop_back(); 
    return false; 
} 
  
// Returns LCA if node n1, n2 are present in the given binary tree, 
// otherwise return -1 
int findLCA(Node *root, int n1, int n2) 
{ 
    // to store paths to n1 and n2 from the root 
    vector<int> path1, path2; 
  
    // Find paths from root to n1 and root to n1. If either n1 or n2 
    // is not present, return -1 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
  
    /* Compare the paths to get the first different value */
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create the Binary Tree shown in above diagram. 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5); 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6); 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4); 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4); 
    return 0; 
} 




Method 2 (Using Single Traversal)
The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and 
without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root,
then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, 
we recur for left and right subtree. 
The node which has one key present in its left subtree and the other key present in right subtree is the LCA. 
If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 
  
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}; 
  
// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// This function returns pointer to LCA of two given values n1 and n2. 
// This function assumes that n1 and n2 are present in Binary Tree 
struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree given in the above example 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key; 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key; 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key; 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key; 
    return 0; 
}











// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 
  
// A Tree Node 
struct Node 
{ 
    Node *left, *right, *parent; 
    int key; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->parent = temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with 
   given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key); 
        node->left->parent = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->parent = node; 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
   // Creata a map to store ancestors of n1 
   map <Node *, bool> ancestors; 
  
   // Insert n1 and all its ancestors in map 
   while (n1 != NULL) 
   { 
       ancestors[n1] = true; 
       n1 = n1->parent; 
   } 
  
   // Check if n2 or any of its ancestors is in 
   // map. 
   while (n2 != NULL) 
   { 
       if (ancestors.find(n2) != ancestors.end()) 
           return n2; 
       n2 = n2->parent; 
   } 
  
   return NULL; 
} 
  
// Driver method to test above functions 
int main(void) 
{ 
    Node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    Node *n1 = root->left->right->left; 
    Node *n2 = root->left; 
    Node *lca = LCA(n1, n2); 
  
    printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 
  
    return 0; 
} 








// C++ program to find lowest common ancestor using parent pointer 
#include <bits/stdc++.h> 
using namespace std; 
  
// A Tree Node 
struct Node 
{ 
    Node *left, *right, *parent; 
    int key; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->parent = temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with 
given key in Binary Search Tree */
Node *insert(Node *node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        node->left = insert(node->left, key); 
        node->left->parent = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->parent = node; 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// A utility function to find depth of a node 
// (distance of it from root) 
int depth(Node *node) 
{ 
    int d = -1; 
    while (node) 
    { 
        ++d; 
        node = node->parent; 
    } 
    return d; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
    // Find depths of two nodes and differences 
    int d1 = depth(n1), d2 = depth(n2); 
    int diff = d1 - d2; 
  
    // If n2 is deeper, swap n1 and n2 
    if (diff < 0) 
    { 
        Node * temp = n1; 
        n1 = n2; 
        n2 = temp; 
        diff = -diff; 
    } 
  
    // Move n1 up until it reaches the same level as n2 
    while (diff--) 
        n1 = n1->parent; 
  
    // Now n1 and n2 are at same levels 
    while (n1 && n2) 
    { 
        if (n1 == n2) 
            return n1; 
        n1 = n1->parent; 
        n2 = n2->parent; 
    } 
  
    return NULL; 
} 
  
// Driver method to test above functions 
int main(void) 
{ 
    Node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    Node *n1 = root->left->right->left; 
    Node *n2 = root->right; 
  
    Node *lca = LCA(n1, n2); 
    printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key); 
  
    return 0; 
}








/* C++ Program to find LCA of u and v by reducing the problem to RMQ */
#include<bits/stdc++.h> 
#define V 9               // number of nodes in input tree 
  
int euler[2*V - 1];       // For Euler tour sequence 
int level[2*V - 1];       // Level of nodes in tour sequence 
int firstOccurrence[V+1]; // First occurences of nodes in tour 
int ind;                  // Variable to fill-in euler and level arrays 
  
// A Binary Tree node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// log base 2 of x 
int Log2(int x) 
{ 
    int ans = 0 ; 
    while (x>>=1) ans++; 
    return ans ; 
} 
  
/*  A recursive function to get the minimum value in a given range 
     of array indexes. The following are parameters for this function. 
  
    st    --> Pointer to segment tree 
    index --> Index of current node in the segment tree. Initially 
              0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment represented 
                  by current node, i.e., st[index] 
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int index, int ss, int se, int qs, int qe, int *st) 
{ 
    // If segment of this node is a part of given range, then return 
    //  the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 
  
    // If segment of this node is outside the given range 
    else if (se < qs || ss > qe) 
        return -1; 
  
    // If a part of this segment overlaps with the given range 
    int mid = (ss + se)/2; 
  
    int q1 = RMQUtil(2*index+1, ss, mid, qs, qe, st); 
    int q2 = RMQUtil(2*index+2, mid+1, se, qs, qe, st); 
  
    if (q1==-1) return q2; 
  
    else if (q2==-1) return q1; 
  
    return (level[q1] < level[q2]) ? q1 : q2; 
} 
  
// Return minimum of elements in range from index qs (quey start) to 
// qe (query end).  It mainly uses RMQUtil() 
int RMQ(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return RMQUtil(0, 0, n-1, qs, qe, st); 
} 
  
// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
void constructSTUtil(int si, int ss, int se, int arr[], int *st) 
{ 
    // If there is one element in array, store it in current node of 
    // segment tree and return 
    if (ss == se)st[si] = ss; 
  
    else
    { 
        // If there are more than one elements, then recur for left and 
        // right subtrees and store the minimum of two values in this node 
        int mid = (ss + se)/2; 
        constructSTUtil(si*2+1, ss, mid, arr, st); 
        constructSTUtil(si*2+2, mid+1, se, arr, st); 
  
        if (arr[st[2*si+1]] < arr[st[2*si+2]]) 
            st[si] = st[2*si+1]; 
        else
            st[si] = st[2*si+2]; 
    } 
} 
  
/* Function to construct segment tree from given array. This function 
   allocates memory for segment tree and calls constructSTUtil() to 
   fill the allocated memory */
int *constructST(int arr[], int n) 
{ 
    // Allocate memory for segment tree 
  
    // Height of segment tree 
    int x = Log2(n)+1; 
  
    // Maximum size of segment tree 
    int max_size = 2*(1<<x) - 1;  //  2*pow(2,x) -1 
  
    int *st = new int[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(0, 0, n-1, arr, st); 
  
    // Return the constructed segment tree 
    return st; 
} 
  
// Recursive version of the Euler tour of T 
void eulerTour(Node *root, int l) 
{ 
    /* if the passed node exists */
    if (root) 
    { 
        euler[ind] = root->key; // insert in euler array 
        level[ind] = l;         // insert l in level array 
        ind++;                  // increment index 
  
        /* if unvisited, mark first occurrence */
        if (firstOccurrence[root->key] == -1) 
            firstOccurrence[root->key] = ind-1; 
  
        /* tour left subtree if exists, and remark euler 
           and level arrays for parent on return */
        if (root->left) 
        { 
            eulerTour(root->left, l+1); 
            euler[ind]=root->key; 
            level[ind] = l; 
            ind++; 
        } 
  
        /* tour right subtree if exists, and remark euler 
           and level arrays for parent on return */
        if (root->right) 
        { 
            eulerTour(root->right, l+1); 
            euler[ind]=root->key; 
            level[ind] = l; 
            ind++; 
        } 
    } 
} 
  
// Returns LCA of nodes n1, n2 (assuming they are 
//  present in the tree) 
int findLCA(Node *root, int u, int v) 
{ 
    /* Mark all nodes unvisited.  Note that the size of 
        firstOccurrence is 1 as node values which vary from 
        1 to 9 are used as indexes */
    memset(firstOccurrence, -1, sizeof(int)*(V+1)); 
  
    /* To start filling euler and level arrays from index 0 */
    ind = 0; 
  
    /* Start Euler tour with root node on level 0 */
    eulerTour(root, 0); 
  
    /* construct segment tree on level array */
    int *st = constructST(level, 2*V-1); 
  
    /* If v before u in Euler tour.  For RMQ to work, first 
       parameter 'u' must be smaller than second 'v' */
    if (firstOccurrence[u]>firstOccurrence[v]) 
       std::swap(u, v); 
  
    // Starting and ending indexes of query range 
    int qs = firstOccurrence[u]; 
    int qe = firstOccurrence[v]; 
  
    // query for index of LCA in tour 
    int index = RMQ(st, 2*V-1, qs, qe); 
  
    /* return LCA node */
    return euler[index]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create the Binary Tree as shown in the diagram. 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
  
    int u = 4, v = 9; 
    printf("The LCA of node %d and node %d is node %d.\n",  
            u, v, findLCA(root, u, v)); 
    return 0; 
} 


Note:

We assume that the nodes queried are present in the tree.
We also assumed that if there are V nodes in tree, then keys (or data) of these nodes are in range from 1 to V.
Time complexity:

Euler tour: Number of nodes is V. For a tree, E = V-1. Euler tour (DFS) will take O(V+E) which is O(2*V) which can be written as O(V).
Segment Tree construction : O(n) where n = V + E = 2*V – 1.
Range Minimum query: O(log(n))
Overall this method takes O(n) time for preprocssing, but takes O(Log n) time for query. 
Therefore, it can be useful when we have a single tree on which we want to perform large number of LCA queries 
(Note that LCA is useful for finding shortest path between two nodes of Binary Tree)

Auxiliary Space:

Euler tour array: O(n) where n = 2*V – 1
Node Levels array: O(n)
First Occurrences array: O(V)
Segment Tree: O(n)
Overall: O(n)




// C++ Implementation of Kosaraju's algorithm to print all SCCs 
#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // An array of adjacency lists 
  
    // Fills Stack with vertices (in increasing order of finishing 
    // times). The top element of stack has the maximum finishing  
    // time 
    void fillOrder(int v, bool visited[], stack<int> &Stack); 
  
    // A recursive function to print DFS starting from v 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
  
    // The main function that finds and prints strongly connected 
    // components 
    void printSCCs(); 
  
    // Function that returns reverse (or transpose) of this graph 
    Graph getTranspose(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (int v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            gr.DFSUtil(v, visited); 
            cout << endl; 
        } 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
  
    return 0; 
} 





Maximise array sum after taking non-overlapping sub-arrays of length K
Given an integer array arr[] of length N and an integer K, the task is to select some non-overlapping sub-arrays
such that each sub-array is exactly of length K,
no two sub-arrays are adjacent and sum of all the elements of the selected sub-arrays is maximum.



// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define maxLen 10 
using namespace std; 
  
// To store the states of dp 
int dp[maxLen]; 
  
// To check if a given state 
// has been solved 
bool v[maxLen]; 
  
// To store the prefix-sum 
int prefix_sum[maxLen]; 
  
// Function to fill the prefix_sum[] with 
// the prefix sum of the given array 
void findPrefixSum(int arr[], int n) 
{ 
    prefix_sum[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefix_sum[i] = arr[i] + prefix_sum[i - 1]; 
} 
  
// Function to find the maximum sum subsequence 
// such that no two elements are adjacent 
int maxSum(int arr[], int i, int n, int k) 
{ 
    // Base case 
    if (i + k > n) 
        return 0; 
  
    // To check if a state has 
    // been solved 
    if (v[i]) 
        return dp[i]; 
    v[i] = 1; 
  
    int x; 
  
    if (i == 0) 
        x = prefix_sum[k - 1]; 
    else
        x = prefix_sum[i + k - 1] - prefix_sum[i - 1]; 
  
    // Required recurrence relation 
    dp[i] = max(maxSum(arr, i + 1, n, k), 
                x + maxSum(arr, i + k + 1, n, k)); 
  
    // Returning the value 
    return dp[i]; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 3, 7, 6 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 1; 
  
    // Finding prefix-sum 
    findPrefixSum(arr, n); 
  
    // Finding the maximum possible sum 
    cout << maxSum(arr, 0, n, k); 
  
    return 0; 
} 










// Program to find if there is a simple path with 
// weight more than k 
#include<bits/stdc++.h> 
using namespace std; 
  
// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 
  
// This class represents a dipathted graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge 
    list< pair<int, int> > *adj; 
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path); 
  
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
    bool pathMoreThanK(int src, int k); 
}; 
  
// Returns true if graph has path more than k length 
bool Graph::pathMoreThanK(int src, int k) 
{ 
    // Create a path array with nothing included 
    // in path 
    vector<bool> path(V, false); 
  
    // Add source vertex to path 
    path[src] = 1; 
  
    return pathMoreThanKUtil(src, k, path); 
} 
  
// Prints shortest paths from src to all other vertices 
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path) 
{ 
    // If k is 0 or negative, return true; 
    if (k <= 0) 
        return true; 
  
    // Get all adjacent vertices of source vertex src and 
    // recursively explore all paths from src. 
    list<iPair>::iterator i; 
    for (i = adj[src].begin(); i != adj[src].end(); ++i) 
    { 
        // Get adjacent vertex and weight of edge 
        int v = (*i).first; 
        int w = (*i).second; 
  
        // If vertex v is already there in path, then 
        // there is a cycle (we ignore this edge) 
        if (path[v] == true) 
            continue; 
  
        // If weight of is more than k, return true 
        if (w >= k) 
            return true; 
  
        // Else add this vertex to path 
        path[v] = true; 
  
        // If this adjacent can provide a path longer 
        // than k, return true. 
        if (pathMoreThanKUtil(v, k-w, path)) 
            return true; 
  
        // Backtrack 
        path[v] = false; 
    } 
  
    // If no adjacent could produce longer path, return 
    // false 
    return false; 
} 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
// Utility function to an edge (u, v) of weight w 
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    int src = 0; 
    int k = 62; 
    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n"; 
  
    k = 60; 
    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n"; 
  
    return 0; 
} 


