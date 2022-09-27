#include<stdio.h>
#include<conio.h>
int parent[10];
void main()
{
  int mincost=0,cost[10][10];
  int n,i,j,ne,min,a,b,u,v; 
  clrscr();
  printf("Enter no. of vertices of graph: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    parent[i]=0;
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
  ne=1;
  printf("The edges of minimal spanning tree are\n");
  while(ne<n) 
  {
    for(i=1,min=999;i<=n;i++)
      for(j=1;j<=n;j++)
        if(cost[i][j]<min)
        {
          min=cost[i][j];
          a=u=i;
          b=v=j;
        }
    while(parent[u])
      u=parent[u];
    while(parent[v])
      v=parent[v];
    if(v!=u)
    {
      printf("\n%d.Edge (%d,%d) : %d",ne++,a,b,min);
      mincost+=min;
      parent[b]=a;
    }
    cost[a][b]=cost[b][a]=999;
  }
  printf("\nMincost= %d",mincost);
  getch();
}
