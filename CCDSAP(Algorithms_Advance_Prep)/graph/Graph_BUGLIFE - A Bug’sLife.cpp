/**
 *   author: sahushivam
 *   created: 07 July 2019 (Sunday)  20:07:54
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*This function is used to find whether a 
given graph is bi-partite using a modified
BFS traversal*/
int BFS(vector<int> graph[],int n)
{
   bool visited[n+1] = {0};
   int colour[n+1];
   int node,flag=0;
   
   memset(visited,0,sizeof(visited));
   memset(colour,-1,sizeof(colour));
   
   for(int k=1; k<=n ;++k)
   {
      
      if(!visited[k])
      {
         queue<int> q;
         q.push(k);
         colour[k] = 1;
         while(!q.empty())
         {
            node =    q.front();
            q.pop();
            visited[node] = 1;
            for(int i=0; i<graph[node].size() ;++i)
            {
               /*if the node is untouched previosuly*/
               if(colour[graph[node][i]] == -1)
                  colour[graph[node][i]] = !colour[node];//root will be 1 and then 0 and 1...
               /*If two adjacent nodes have same color*/   
               else if  (colour[graph[node][i]] == colour[node])
               {
                  flag = 1;
                  break;
               }
               /*To process further*/
               if(!visited[graph[node][i]])
                  q.push(graph[node][i]);
            }
            if(flag)
               break;
         }
      }
      if(flag)
         break;
   }   
   return flag;
}
int main() {
   ios::sync_with_stdio(false);
   
   int t,n,m,u,v;
   int cc = 0; //Case Counter
   
   cin>>t;
   while(t--)
   {
      cc++;
      cin>>n>>m;
      vector<int> graph[n+1];
      for(int i=0; i<m; ++i)
      {
         cin>>u>>v;
         graph[u].push_back(v);
         graph[v].push_back(u);
      }
      cout<<"Scenario #"<<cc<<":\n";
      
      if(BFS(graph,n))
         cout<<"Suspicious bugs found!\n";
      else
         cout<<"No suspicious bugs found!\n";
   }
   return 0;
}