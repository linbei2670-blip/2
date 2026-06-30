#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ShowMenu();
void bubble_sort(int* arr, int n);
void insert_sort(int* arr, int n);
void heap_sort(int* arr, int n);
void heapify(int *arr,int  len,int i);
void merge_sort(int* arr,int left,int right);
void merge(int* arr, int left, int mid, int right);
void quick_sort(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void ShowMenu() {
	printf("\n");
	printf("1. 冒泡排序\n");
	printf("2. 插入排序\n");
	printf("3. 堆排序\n");
	printf("4. 归并排序\n");
	printf("5. 快速排序\n");
	printf("0. 退出\n");
}
void bubble_sort(int* arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insert_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while(j>=0 && arr[j] < key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void heap_sort(int* arr, int n) {
	int len = n;
	for(int i = len / 2 - 1; i >= 0; i--) {
		heapify(arr, len, i);
	}
	for(int i = len - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}
void heapify(int* arr,int len,int root){
	int child = 2 * root + 1;
	int temp = arr[root];
	while (child <= len - 1) {
		if (child + 1 < len && arr[child + 1] < arr[child]) {
			child++;
		}
		if (temp <= arr[child]) {
			break;
		}							
		arr[root] = arr[child];

		root = child;
		child = 2 * child + 1;
	}
	arr[root] = temp;
}
void merge_sort(int* arr,int left,int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		merge_sort(arr, left, mid);

		merge_sort(arr, mid + 1, right);

		merge(arr,left, mid, right);
	}
}
void merge(int* arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	int temp[100];
	while(i<=mid&&j<=right){
		if (arr[i] >= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= right) {
		temp[k++] = arr[j++];
	}
	for(int t = 0; t < k; t++) {
		arr[left + t] = temp[t];
	}
}
void quick_sort(int* arr, int low, int high) {
	if (low < high) {
		int povit = partition(arr, low, high);

		quick_sort(arr, low, povit - 1);

		quick_sort(arr, povit + 1, high);
	}
}
int partition(int* arr, int low, int high) {
	int povit = arr[low];
	while (low < high) {
		while (low < high && arr[high] <= povit) {
			high--;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] >= povit) {
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = povit;
	return low;
}
int main() {
	int choice;
	while (1) {
		srand((unsigned int)time(NULL));
		int n = 10;
		int keywords[10];
		int i;

		for (i = 0; i < n; i++) {
			keywords[i] = rand() % (10000 - (-10000) + 1) + (-10000);
		}
		ShowMenu();
		printf("请输入您的选择 (0-5): ");
		if (scanf("%d", &choice) != 1) {
			printf("\n 输入非法！请输入数字。\n");
			system("pause");
			continue;
		}
		switch (choice) {
		case 1:bubble_sort(keywords, n);
			printf("冒泡排序后的关键字序列为:\n");
			for (i = 0; i < n; i++) {
				printf("%d ", keywords[i]);
			}
			printf("\n");
			system("pause");
			break;
		case 2:insert_sort(keywords, n);
			printf("插入排序后的关键字序列为:\n");
			for (i = 0; i < n; i++) {
				printf("%d ", keywords[i]);
			}
			printf("\n");
			system("pause");
			break;
		case 3:heap_sort(keywords, n);
			printf("插入排序后的关键字序列为:\n");
			for (i = 0; i < n; i++) {
				printf("%d ", keywords[i]);
			}
			printf("\n");
			system("pause");
			break;
		case 4:merge_sort(keywords, 0, n - 1);
			printf("插入排序后的关键字序列为:\n");
			for (i = 0; i < n; i++) {
				printf("%d ", keywords[i]);
			}
			system("pause");
			break;
		case 5:quick_sort(keywords, 0, n - 1);
			for (i = 0; i < n; i++) {
				printf("%d ", keywords[i]);
			}
			system("pause");
			break;
		case 0: printf("退出程序。\n"); return 0;
		default:
			printf("\n 输入非法！请输入0-5之间的数字。\n");
			system("pause");
			break;
		}
	}
}


   