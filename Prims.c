#include<stdio.h>
#include<conio.h>
int visited[10];
void main()
{
  int mincost=0,cost[10][10];
  int n,i,j,ne,min,a,b;
  clrscr();
  printf("Enter no. of vertices of graph: ");
  scanf("%d",&n);
  printf("Enter cost matrix\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)   
    {
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0)
        cost[i][j]=999;
    }
  }
  for(i=2;i<=n;i++)
    visited[i]=0;
  visited[1]=1;
  ne=1;
  printf("The edges of minimal spanning tree are\n");
  while(ne<n)
  {
    for(i=1,min=999;i<=n;i++)
      for(j=1;j<=n;j++)
        if(cost[i][j]<min&&visited[i])
        {
          min=cost[i][j];
          a=i;
          b=j;
        }
    if(!visited[a]||!visited[b])
    {
      printf("%d.Edge (%d,%d) : %d\n",ne++,a,b,min);
      mincost+=min;
      visited[b]=1;
    } 
    cost[a][b]=cost[b][a]=999;
  } 
  printf("\nMincost= %d",mincost);
  getch();
}
