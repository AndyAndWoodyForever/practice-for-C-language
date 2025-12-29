#include<stdio.h>
int main(){
printf("         ");
int i=1;
for (;i<=9;i++){
	printf("%6d   ",i);
}
printf("\n");
int t=1;
for (;t<=9;t++){
	printf("%6d   ",t);
	int k=1;
	for(;k<=t;k++){
		printf("%6d   ",k*t);
	}
	printf("\n");
	
	}



return 0;
}
