#include <stdio.h>

void bubble_sort(int arr[], int sz) {

	// ȷ��ð�������������10�����������9�ˣ����һ��
	// ���ñȽ�

	// ע�⣬���鴫�ε�ʱ�򣬴��ݵĲ�����������
	// ���ʱ�����������������Ԫ�ص�ַ�����ܼ�����������
	// �Ĵ�С
	// int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++) {
		
		// ÿһ�˵�ð������
		// ��ʵ˵���˾���ÿһ����Ҫ�ȽϵĶ���
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