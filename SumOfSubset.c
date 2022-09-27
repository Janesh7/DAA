#include<stdio.h>
#include<conio.h>
int x[10],a[10],sum,n,i,j,flag=0,count=0;
void sos(int s,int k,int r)
{
  x[k]=1;
  if(s+a[k]==sum) 
  {
    printf("\nSubset %d: ",++count);
    flag=1;
    for(i=0;i<=k;i++)
      if(x[i])
        printf("%3d",a[i]);
  }
  else if(s+a[k]+a[k+1]<=sum)
    sos(s+a[k],k+1,r-a[k]);
  if((s+r-a[k]>=sum)&&(s+a[k+1]<=sum))
  {
    x[k]=0;
    sos(s,k+1,r-a[k]);
  }
}
void main()
{
  int r=0,s,temp;
  clrscr();
  printf("Enter no. of elements: ");
  scanf("%d",&n);
  printf("Enter the elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
  printf("After sorting, elements are: \n");
  for(i=0;i<n;i++)  
    printf("%d ",a[i]);
  printf("\nEnter the required sum: "); 
  scanf("%d",&sum);
  for(i=0;i<n;i++)
  {
    x[i]=0;
    r+=a[i];
  }
  if(r<sum)
  {
    printf("\nNo subset possible");
    flag=1;
  }
  else  
    sos(0,0,r);
  if(flag==0)
    printf("\nNo subset possible");
  getch();
}
