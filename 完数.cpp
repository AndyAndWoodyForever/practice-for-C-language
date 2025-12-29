#include<stdio.h>
#include<math.h>
/*输入一个正整数n，输出[1,n]之间的所有完数。
完数的定义：除自身外的因子之和等于它本身。

例如：28=1+2+4+7+14，因此28是完数。
*/
	int n;
	int k,i=0;
	int fact[200];
	int count;
	int judge(int n);
int main(){
	scanf("%d",&n);
	judge(n);
	return 0; 
} 

int judge(int n){
	int t=1;
	for(;t<=n;t++){
	count=0;
	for(k=1;k<=t/2+1;k++){
		if(t%k==0){
			fact[i++]=k;
			count+=k;
		}
	}
	if(t==count){
		printf("%d是完数\n",t);
	}
}
}
