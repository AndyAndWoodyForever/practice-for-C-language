#include <stdio.h>
#include<string.h>
 
// 交换两个字符的值
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 递归函数，用于生成全排列
// str: 要进行排列的字符串
// start: 起始索引
// end: 结束索引
void func(char *str, int start, int end)
{
    // 递归的出口：当起始索引等于结束索引时，
    // 说明一个完整的排列已经生成，打印出来
    if (start == end)
    {
        printf("%s ", str);
        return;
    }

    // 循环，从起始索引到结束索引
	int i = start;
    for (; i <= end; i++)
    {
        // 交换当前起始位置的字符和循环中当前位置的字符
        swap(&str[start], &str[i]);

        // 递归调用，对下一个位置的字符进行排列
        func(str, start + 1, end);

        // 回溯：将字符交换回来，恢复到交换前的状态，
        // 以便进行下一次循环的排列
        swap(&str[start], &str[i]);
    }
}

int main()
{
    // 定义一个字符数组
    char str[] = "abc";
    // 调用函数生成并打印全排列
    func(str, 0, strlen(str)-1);

    return 0;
}
