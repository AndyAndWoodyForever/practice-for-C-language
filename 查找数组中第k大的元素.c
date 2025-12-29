#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

int partition(int nums[], int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
	int j = left;
    for (; j < right; j++) {
        if (nums[j] > pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[right]);
    return i + 1;
}

int find(int nums[], int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int partitionIndex = partition(nums, left, right);
        if (partitionIndex == k - 1)
            return nums[partitionIndex];
        else if (partitionIndex < k - 1)
            left = partitionIndex + 1;
        else
            right = partitionIndex - 1;
    }
    return nums[left];
}

int main(){
	int nums[]={3,6,1,5,2,8};
	printf("%d",find(nums,6,3));
	return 0;
}
