#import <iostream>
#import <vector>
#import <queue>

using namespace std;
//sahushivam
//
int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
	// your code goes here
  int R=grid.size();
  int C=grid[0].size();
  vector<vector<int>> level(R, vector<int>(C, -1));
  queue<pair<int,int>> q;
  
  q.push({sr,sc});
  int dx[]={0,0,-1,1};
  int dy[]={1,-1,0,0};
  level[sr][sc]=0;
  while(!q.empty())
  {
    pair<int,int> p=q.front();
    q.pop();
    int x=p.first;
    int y=p.second;
    for(int i=0;i<4;i++)
    {
      int visX=x+dx[i];
      int visY=y+dy[i];
      if(visX<R && visX>=0 && visY<C && visY>=0 && grid[visX][visY]==1)
      {
        if(level[visX][visY]==-1){
          q.push({visX,visY});
          level[visX][visY]=level[x][y]+1;
        }
      }
    }
  }
  return level[tr][tc];
}

int main() 
{
	
  vector<vector<int>> grid = {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 0, 1, 1}};
  cout<<shortestCellPath(grid,0,0,2,0);
  return 0;
}
//1 1 1 1  (sr,sc_=(0,0),(tr,rc)=(2,0)
//0 0 0 1
//1 1 1 1
