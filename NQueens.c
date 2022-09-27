#include<stdio.h>
#include<conio.h>
int x[10];
int place(int k,int i)
{
  int j;
  for(j=1;j<k;j++)
    if(x[j]==i||(abs(x[j]-i)==abs(j-k)))
      return 0;
  return 1;
}
void nqueens(int k,int n)
{
  int i,j;
  for(i=1;i<=n;i++)
  {
    if(place(k,i))  
    {
      x[k]=i;
      if(k==n)
      {
        printf("\nSolution is\n");
        for(j=1;j<=n;j++)
          printf("%2d",x[j]);
      }
      else
        nqueens(k+1,n);
    }
  }
}
void main()
{
  int n;
  clrscr();
  printf("Enter no. of queens: ");
  scanf("%d",&n);
  if(n==0||n==2||n==3)
    printf("No solutions\n");
  else
    nqueens(1,n);
  getch();
}
