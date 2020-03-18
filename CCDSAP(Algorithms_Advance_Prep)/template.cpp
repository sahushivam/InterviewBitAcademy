// for(int i=0;i<n;i++)
//     {
//     	for(auto j:gp2[i])
//     	{
//     		if(comp[i]==comp[j]) continue;
//     		if(gp3[comp[i]].find(comp[j])==gp3[comp[i]].end())
//     		{
//     			gp3[comp[i]].insert(comp[j]);
//     		}
//     	}
//     }

// //toposort
// signed main(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);
//     int t=1;
//     int n,m; cin>>n>>m;
//     vector<int> indegree(n,0);
//     priority_queue<int,vector<int> ,greater<int> >pq;
//     for(int i=0;i<m;i++)
//     {
//     	int a,b;
//     	cin>>a>>b;
//     	a--; b--;
//     	gp[a].PB(b);
//     	indegree[b]++;
//     }
//     for(int i=0;i<n;i++){
//     	if(indegree[i]==0){
//     		pq.push(i);
//     	}
//     }
//     while(!pq.empty())
//     {
//     	int p=pq.top();
//     	ans.push_back(p);
//     	pq.pop();
//     	for(auto i: gp[p])
//     	{
//     		indegree[i]--;
//     		if(!indegree[i])
//     			pq.push(i);
//     	}
//     }
//     if(ans.size()!=n)
//     {
//     	cout<<"Sandro fails.";
//     }
//     else
//     {
//     	for(auto i: ans) cout<<i+1<<" ";
//     }
// return 0;
// }
// //segmented seive
// vector<int> segmented_seive(int l,int r)
// {
// 	vector<int> isPrime(r-l+1,true);
// 	for(int i=0;primes[i]*primes[i]<=r;i++)
// 	{
// 		int curr_prime=primes[i];
// 		int base=(l/curr_prime)*curr_prime;
// 		if(base<l) base+=curr_prime;

// 		for(int j=base;j<=r;j+=curr_prime)
// 		{
// 			isPrime[j-l]=false;
// 		}
		
// 		if(base==curr_prime)
// 			isPrime[base-l]=true;
// 	}
// 	return isPrime;
// }

// ///lazy propogation

// void update(int s,int e,int l,int r,int val,int n)
// {
// 	if(lazy[n]!=0)
// 	{
// 		tree[n]+=(e-s+1) * lazy[n];
// 		if(s!=e)
// 		{
// 			lazy[2*n]+=lazy[n];
// 			lazy[2*n+1]+=lazy[n];
// 		}
// 		lazy[n]=0;
// 	}
// 	if(s>e || l>r || r<s || l>e) return;
// 	if(s>=l && e<=r)
// 	{
// 		tree[n] += (e-s+1) * val;
//         if(s != e)
//         {
//             lazy[n*2] += val;
//             lazy[n*2+1] += val;
//         }
//         return;
// 	}
// 	int mid=(s+e)/2;
// 	update(s,mid,l,r,val,2*n);
// 	update(mid+1,e,l,r,val,2*n+1);
// 	tree[n]=tree[2*n]+tree[2*n+1];
// }

// int query(int s,int e,int l,int r,int n)
// {
// 	if(s>e || r<s || l>e) return 0;
// 	if(lazy[n]!=0)
// 	{
// 		tree[n]+=(e-s+1)* lazy[n];
// 		if(s!=e)
// 		{
// 			lazy[2*n]+=lazy[n];
// 			lazy[2*n+1]+=lazy[n];
// 		}
// 		lazy[n]=0;
// 	}
// 	if(s>=l && e<=r){
//         return tree[n];
// 	}
// 	int mid=(s+e)/2;
// 	int p1=query(s,mid,l,r,2*n);
// 	int p2=query(mid+1,e,l,r,2*n+1);
// 	return p1+p2;
// }
// //segment tree
// void build(int node, int start, int end)	//can take tree and array
// {
//     if(start == end)
//     {
//         // Leaf node will have a single element
//         tree[node] = A[start];
//     }
//     else
//     {
//         int mid = (start + end) / 2;
//         // Recurse on the left child
//         build(2*node, start, mid);
//         // Recurse on the right child
//         build(2*node+1, mid+1, end);
//         // Internal node will have the sum of both of its children
//         tree[node] = tree[2*node] + tree[2*node+1];
//     }
// }

// void update(int node, int start, int end, int idx, int val)
// {
//     if(start == end)
//     {
//         // Leaf node
//         A[idx] += val;
//         tree[node] += val;
//     }
//     else
//     {
//         int mid = (start + end) / 2;
//         if(start <= idx and idx <= mid)
//         {
//             // If idx is in the left child, recurse on the left child
//             update(2*node, start, mid, idx, val);
//         }
//         else
//         {
//             // if idx is in the right child, recurse on the right child
//             update(2*node+1, mid+1, end, idx, val);
//         }
//         // Internal node will have the sum of both of its children
//         tree[node] = tree[2*node] + tree[2*node+1];
//     }
// }

// int query(int node, int start, int end, int l, int r)
// {
//     if(r < start or end < l)
//     {
//         // range represented by a node is completely outside the given range
//         return 0;
//     }
//     if(l <= start and end <= r)
//     {
//         // range represented by a node is completely inside the given range
//         return tree[node];
//     }
//     // range represented by a node is partially inside and partially outside the given range
//     int mid = (start + end) / 2;
//     int p1 = query(2*node, start, mid, l, r);
//     int p2 = query(2*node+1, mid+1, end, l, r);
//     return (p1 + p2);
// }