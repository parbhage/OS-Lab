//9. optimal page replacement algorithms

#include<stdio.h> 
#include<conio.h> 
int n; 
int main() 
{ 
 int seq[30],fr[5],pos[5],find,flag,max,i,j,m,k,t,s,a; 
 int count=1,pf=0,p=0; 
 float pfr; 
  
 printf("Enter maximum limit of the sequence: "); 
 scanf("%d",&max); 
 printf("\nEnter the sequence: "); 
 for(i=0;i<max;i++) 
  scanf("%d",&seq[i]); 
  printf("\nEnter no. of frames: "); 
  scanf("%d",&n); 
  fr[0]=seq[0]; 
  pf++; 
  printf("%d\t",fr[0]); 
  i=1; 
  while(count<n) 
  { 
   flag=1; 
   p++; 
   for(j=0;j<i;j++) 
   { 
    if(seq[i]==seq[j]) 
    flag=0; 
   } 
   if(flag!=0) 
   { 
    fr[count]=seq[i]; 
    printf("%d\t",fr[count]); 
    count++; 
    pf++; 
   } 
   i++; 
  } 
  printf("\n"); 
  for(i=p;i<max;i++) 
  { 
   flag=1; 
   for(j=0;j<n;j++) 
   { 
    if(seq[i]==fr[j]) 
     flag=0; 
   } 
   if(flag!=0) 

 
   { 
    for(j=0;j<n;j++) 
    { 
     m=fr[j]; 
     for(k=i;k<max;k++) 
     { 
      if(seq[k]==m) 
      { 
       pos[j]=k; 
       break; 
      } 
      else 
       pos[j]=1; 
     } 
    } 
    for(k=0;k<n;k++) 
    { 
     if(pos[k]==1) 
      flag=0; 
    } 
    if(flag!=0) 
     s=findmax(pos); 
    if(flag==0) 
    { 
     for(k=0;k<n;k++) 
     { 
      if(pos[k]==1) 
      { 
       s=k; 
       break; 
      } 
     } 
    } 
    fr[s]=seq[i]; 
    for(k=0;k<n;k++) 
     printf("%d\t",fr[k]); 
    pf++; 
    printf("\n"); 
   } 
  } 
  pfr=(float)pf/(float)max; 
  printf("\nThe no. of page faults are %d",pf); 
  printf("\nPage fault rate %f",pfr); 
   
} 
int findmax(int a[]) 
{ 
 int max,i,k=0; 
 max=a[0]; 
 for(i=0;i<n;i++) 
 { 
  if(max<a[i]) 
  { 
   max=a[i]; 
   k=i; 
  } 
 } 
 return k; 
} 

/*
INPUT 
Enter number of page references -- 10 
Enter the reference string --  1 2 3 4 5 2 5 2 5 1 4 3 

 
Enter the available no. of frames -- 3 
 
OUTPUT 
The Page Replacement Process is – 
 
1  -1 -1  PF No. 1 
1 2 -1  PF No. 2 
1 2  3  PF No. 3 
4 2 3  PF No. 4 
5 2 3  PF No. 5 
5 2 3 
5 2 3 
5 2 1  PF No. 6 
5 2 4  PF No. 7 
5 2 3  PF No. 8 
 
Total number of page faults -- 8 

*/