#include<stdio.h>
#include<conio.h>
#include<string.h>
int table[128];
void shifttable(char p[],int m)
{
  int i;
  for(i=0;i<128;i++)
    table[i]=m;
  for(i=0;i<m-1;i++)
    table[p[i]]=m-1-i;
}
int horspoolmatch(char p[],int m,char t[],int n)
{
  int i,k;
  shifttable(p,m);
  for(i=m-1;i<n;i+=table[t[i]])
  {
    k=0;  
    while(k<m&&p[m-1-k]==t[i-k])
      k++;
    if(k==m)
      return i-m+1;
  }
  return -1;
}
void main()
{
  char t[100],p[50];
  int m,n,pos;
  clrscr();
  printf("\nEnter the text made up of alphabets of all possible 128 characters:\n");
  gets(t);
  printf("\nEnter the pattern: ");
  gets(p);
  n=strlen(t);
  m=strlen(p);
  pos=horspoolmatch(p,m,t,n);
  if(pos==-1)
    printf("Pattern not found");
  else
    printf("Pattern found at index %d",pos);
  getch();
}
