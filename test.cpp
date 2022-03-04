#include <stdio.h>

void bubble_sort(int arr[], int sz) {

	// 确定冒泡排序的趟数，10个数字则就是9趟，最后一个
	// 不用比较

	// 注意，数组传参的时候，传递的不是整个数组
	// 这个时候的数组名仅仅是首元素地址！不能计算整个数组
	// 的大小
	// int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++) {
		
		// 每一趟的冒泡排序
		// 其实说白了就是每一趟需要比较的对数
		for (int j = 0; j < sz - 1 - i; j++) {

			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {

	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}