#include<stdio.h>
#include<conio.h>
int weight[10],val[10],v[10][10];
int max(int a,int b)
{
  return (a>b)?a:b;
}
int knapsack(int n,int w)
{
  int i,j;
  for(i=0;i<=n;i++) 
  {
    for(j=0;j<=w;j++) 
    {
      if(i==0||j==0)
        v[i][j]=0;
      else if(j-weight[i]>=0)
        v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-weight[i]]);
      else
        v[i][j]=v[i-1][j];
    }
  }
  return v[n][w];
}
void optimalsubset(int n,int w)
{
  int i,j;
  for(i=n,j=w;i>=1&&j>0;i--)  
  {
    if(v[i][j]!=v[i-1][j])
    {
      printf("Item %d\n",i);
      j-=weight[i];
    }
  }
}
void main()
{
  int n,w,value,i,j;
  clrscr();
  printf("Enter the no. of items: ");
  scanf("%d",&n);
  printf("Enter the weights of each item\n");
  for(i=1;i<=n;i++)
    scanf("%d",&weight[i]);
  printf("Enter the values of each item\n");
  for(i=1;i<=n;i++)
    scanf("%d",&val[i]);
  printf("Enter the knapsack capacity: ");
  scanf("%d",&w);
  value=knapsack(n,w);
  printf("Solution of knapsack problem\n");
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=w;j++)
      printf("%d\t",v[i][j]);
    printf("\n"); 
  }
  printf("\nThe maximum value is %d",value);
  printf("\nThe items of an optimal subset are\n");
  optimalsubset(n,w);
  getch();
}
