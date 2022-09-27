#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
  return (a<b)?a:b;
}
void floyds(int a[10][10],int n)
{
  int i,j,k;
  for(k=0;k<n;k++)  
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
void main()
{
  int cost[10][10],i,j,n;
  clrscr();
  printf("Enter size of cost matrix:");
  scanf("%d",&n);
  printf("\nEnter cost matrix\n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&cost[i][j]);
  floyds(cost,n);
  printf("\nAll pair shortest path is \n");
  for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
      printf("%d ",cost[i][j]);
    printf("\n");
  }
  getch();
}
