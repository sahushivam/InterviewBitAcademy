bool board[11][11];
 
bool possible(int n , int row, int colum){
  for(int i=row-1;i>=0;i--)
    if(board[i][colum] == 1)
      return false;
  for(int i=row-1,j=colum-1;j>=0 && i>=0;j--,i--)//dono i and j decrement kr rhe
    if(board[i][j] == 1)
      return false;
  for(int i=row-1,j=colum+1;i>=0 && j<n;i--,j++)//i decrement kr rha aar j badh rha
    if(board[i][j] == 1)
      return false;
  return true;
}

void helpQueen(int n, int row,vector<vector<string> > &ans){
  if(row == n){
    vector<string> v;
    for(int i=0;i<n;i++){
        string an="";
      for(int j=0;j<n;j++){
        if(board[i][j]){
            an=an+"Q";
        }
        else
        {
            an=an+".";
        }
      }
      v.push_back(an);
    }
          ans.push_back(v);
        return;
    }
 
  for(int j=0;j<n;j++){
    if(possible(n,row,j)){
      board[row][j] = 1;
      helpQueen(n,row+1,ans);
      board[row][j] = 0;
    }
  }
  return;
}
void placeNQueens(int n,vector<vector<string> > &ans){
 
    memset(board,0,11*11*sizeof(bool));
      helpQueen(n,0,ans);
}
vector<vector<string> > Solution::solveNQueens(int A) {
 vector<vector<string> > ans;
    if(A==2 || A==3) {
        ans.clear();
        return ans;
    }
    if(A==1)
    {
           vector<string> v;
        v.push_back("Q");
        ans.push_back(v);
        return ans;
    }
    placeNQueens(A,ans);
    return ans;
}