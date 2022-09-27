#include<stdio.h>
#include<conio.h>
int n,a[10][10],vis[10];
void dfs(int u)
{
  int v;
  vis[u]=1;
  for(v=1;v<=n;v++)
  if(a[u][v]==1&&vis[v]==0);
  dfs(v);
}
void main()
{
  int i,j;
  clrscr();
  printf("\nEnter no.of vertices: ");
  scanf("%d",&n);
  printf("Enter adjacency matrix\n");
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  scanf("%d",&a[i][j]);
  for(i=1;i<=n;i++)
  vis[i]=0;
  for(i=1;i<=n;i++) 
  {
    dfs(i);
    for(j=1;j<=n;j++)
    {
      if(vis[j]!=1)
      {
        printf("%d is not reachable from %d",j,i);
        printf("\nSo graph is not connected");
        getch();
        return;
      }
    }
    for(j=1;j<=n;j++)
      vis[j]=0;
  }
  printf("\nGraph is connected");
  getch();
}
