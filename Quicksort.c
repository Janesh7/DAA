#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define maxsize 30000
#define NTIMES 5000
int partition(int a[],int low,int high)
{
  int p,i,j,temp;
  p=a[low];
  i=low+1;
  j=high;
  while(1)
  {
    while(a[i]<=p&&i<high)
      i++;
    while(a[j]>p&&j>=low)
      j--;
    if(i<j)
    {
      temp=a[j];
      a[j]=a[i];
      a[i]=temp;
    }
    else
    {
      temp=a[j];
      a[j]=a[low];
      a[low]=temp;
      return j;
    }
  }
}
void quicksort(int a[],int low,int high)
{
  int s;
  if(low<high)
  {
    s=partition(a,low,high);
    quicksort(a,low,s-1);
    quicksort(a,s+1,high);
  }
}
void main()
{
  int a[maxsize],n,i,k;
  clock_t start,end;
  double runtime=0;
  clrscr();
  printf("Enter the size of array: ");
  scanf("%d",&n);
  for(k=0;k<NTIMES;k++)
  {
    srand(1);
    for(i=0;i<n;i++)
    a[i]=rand();
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    runtime+=(end-start)/CLK_TCK;
  }
  runtime/=NTIMES;
  printf("Sorted elements are\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\nAvg runtime = %lfs",runtime);
  getch();
}
