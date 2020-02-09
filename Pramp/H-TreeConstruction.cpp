/*
(x,y), length, depth
        3       2
    |        
    |
    ---(x,y)---
https://en.wikipedia.org/wiki/H_tree
//reducing (dividing) the length of the line segments drawn at each stage by √2.



*/
#include <iostream>


void drawLine(int x1,int y1,int x2,int y2)
{
  std::cout<<x1<<" "<<y1<<" to "<<x2<<" "<<y2<<'\n';
}
void drawHTree(double x,double y,double length,int depth)
{
  if(depth==0) return;
  double x0 = x-length/2;
  double x1 = x+length/2;
  double y0 = y-length/2;
  double y1 = y+length/2;
  
  //draw 3 segment
  drawLine(x0,y0,x0,y1);//left segment
  drawLine(x1,y0,x1,y1);//right segment
  drawLine(x0,y,x1,y);//connecting segment
  
  double newLength=length/1.414;
  drawHTree(x0,y0,newLength,depth-1);
  drawHTree(x0,y1,newLength,depth-1);
  drawHTree(x1,y0,newLength,depth-1);
  drawHTree(x1,y1,newLength,depth-1);
}
int main()
{
    std::cout << "Practice makes Perfect!" << std::endl;
    drawHTree(0,0,2,1);
  return 0;
}


//time complex: O(4^depth) space-complexity-o(depth)


//t(n)=4*t(n-1)
