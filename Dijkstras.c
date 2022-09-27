#include<stdio.h>
#include<conio.h>
void dijkstra(int n,int v,int cost[10][10],int dist[10])
{
  int i,k,count,visited[10],min;
  for(i=1;i<=n;i++) 
  {
    visited[i]=0;
    dist[i]=cost[v][i];
  }
  visited[v]=1;
  dist[v]=0;
  count=2;
  while(count<n)
  {
    min=999;
    for(i=1;i<=n;i++)
    {
      if(dist[i]<min&&!visited[i])
      {
        min=dist[i];
        k=i;
      }
    }
    visited[k]=1;
    count++;
    for(i=1;i<=n;i++)
      if(!visited[i])
        if(dist[i]>dist[k]+cost[k][i])
          dist[i]=dist[k]+cost[k][i];
  }
}
void main()
{
  int n,v,i,j,cost[10][10],dist[10];  
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
  printf("\nEnter source vertex: ");
  scanf("%d",&v);
  dijkstra(n,v,cost,dist);
  printf("Shortest paths are\n");
  for(i=1;i<=n;i++)
  if(i!=v)
    printf("%d->%d\tcost=%d\n",v,i,dist[i]);
  getch();
}
