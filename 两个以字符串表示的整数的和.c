#include <string.h>
#include<stdio.h>


void add(char* num1, char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;
    // 修正循环条件：处理所有位和进位
    while (i >= 0 || j >= 0 || carry != 0) {
        // 修正条件冗余
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        // 修正：数字转字符
        result[k] = (sum % 10) + '0';
        carry = sum / 10;
        k++, i--, j--;
    }
    // 修正：循环结束后再添加结束符
    result[k] = '\0';
    int len = strlen(result);
    // 修正反转逻辑：交换到中间位置
    for (i = 0; i < len / 2; i++) {
        char temp = result[i];
        result[i] = result[len - i - 1];
        result[len - i - 1] = temp;
    }
}


int main(){
	char num1[]="11223";
	char num2[]="22334";
	char result[1024];
	add(num1,num2,result);
	printf("%s",result);
}
