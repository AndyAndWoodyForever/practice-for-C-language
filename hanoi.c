#include <stdio.h>

int move(int m,char from,char to);
int hanoi(int n,char A,char C,char B);
int sum=0;

int  main()
 {
 int n;
 printf("请输入搬动的盘子数：");
 scanf("%d",&n);
 printf("搬动%d个盘子的过程如下：\n",n);
 hanoi(n,'A','C','B');
 printf("%d",sum) ;
 return 0;
 }
 
 
int move(int m,char from,char to)
 {
 //(sum)++;
 printf("%d号盘子从%c针搬到%c针。\n",m,from,to);
 }
 
 
int hanoi(int n,char A,char C,char B)
 {if(1==n) 
 move(n,A,C);
 else{
 hanoi(n-1,A,B,C);
 move(n,A,C);
 hanoi(n-1,B,C,A);
 }
 }
