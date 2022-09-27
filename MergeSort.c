#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define maxsize 30000
#define NTIMES 5000
void merge(int a[],int low,int mid,int high)
{
int i,j,k;
int b[maxsize];
i=low;
j=mid+1;
k=low;
while(i<=mid&&j<=high)
{
if(a[i]<=a[j])
b[k++]=a[i++];
else b[k++]=a[j++];
}
while(i<=mid)
b[k++]=a[i++];
while(j<=high)
b[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=b[i];
}
void mergesort(int a[],int low,int high)
{
  int mid;
  if(low<high)  
  {
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
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
    mergesort(a,0,n-1);
    end=clock();
    runtime+=((end-start)/CLK_TCK);
  }
  runtime/=NTIMES;
  printf("Sorted elements are\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\nAvg runtime = %lfs",runtime);
  getch();
}
