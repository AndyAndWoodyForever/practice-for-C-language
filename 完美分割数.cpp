#include<stdio.h>
#include<math.h>
/*一个正整数如果能恰好分成连续的若干个正整数之和，就称为"完美分割数"。例如：
15 = 1+2+3+4+5（5个连续数）
15 = 4+5+6（3个连续数）
15 = 7+8（2个连续数）
输入一个正整数n，输出它所有的完美分割方案（至少要有2个数相加）。
输入： 一个正整数n (10 ≤ n ≤ 100)
输出： 所有的分割方案
*/


int main(){
	int n;
	scanf("%d",&n); 
	int k;
	int i,count=0;
	for(k=2;k<=sqrt(2*n);k++){
		if ((2 * n) % k != 0) {
            continue; // k不是2n的因数，跳过
        }
        if((2*n/k-k+1)%2==0&&(2*n/k-k+1)>0){
		printf("n=");
        	for(i=(2*n/k-k+1)/2;count<k-1;i++,count++){
        		printf("%d+",i);
			}
			printf("%d\n",i);
		}
		count=0;
	}
	return 0;
} 
