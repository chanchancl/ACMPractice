// QuckSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int partition(int arr[], int l, int r);
void QuickSort(int arr[], int l, int r)
{
	int mid = 0;
	if (l < r) {
		mid = partition(arr, l, r);
		QuickSort(arr, l, mid - 1);
		QuickSort(arr, mid + 1, r);
	}
}

int partition(int arr[], int l, int r)
{
	int key = arr[l];
	while (l != r) {
		while (l < r && arr[r] >= key) r--;
		arr[l] = arr[r];
		while (l < r && arr[l] <= key) l++;
		arr[r] = arr[l];
	}
	arr[l] = key;
	return l;
}

int main()
{

	int arr[] = { 30,4,2,3,66,55,33,22,33,11,44,22,313,123,31,1,3,3,3 };
	int n = sizeof(arr) / sizeof(arr[0]) - 1;
	QuickSort(arr, 0, n);

	for(int i=0; i < n; i++)
		std::cout << arr[i] << " ";

	return 0;
}

