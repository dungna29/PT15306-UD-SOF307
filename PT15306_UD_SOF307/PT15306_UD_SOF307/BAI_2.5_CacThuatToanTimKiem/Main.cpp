#include <stdio.h>

int getMax(int a[], int n)
{
	int max = a[0];//Coi giá trị ở index 0 là số lớn nhất
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])//Nếu max nhỏ hơn giá trị trong mảng thì gán lại cho max
		{
			max = a[i];
		}
	}
	return max;
}
int getMin(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

//Tìm kiếm tuần tự vét cạn(Exhaustive Linear)
// n là điều kiện dừng vòng lặp
int LinearExhaustive(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

//Tìm kiếm tuần tự lính canh (Sentinel Linear)
int LinearSentinel(int a[], int n, int x) {
	a[n] = x;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	printf("Nhap so luong phan tu: ");
	scanf_s("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
	int x;
	printf("Nhap gia tri phan tu can tim kiem: ");
	scanf_s("%d", &x);
	int i = LinearSentinel(a, n, x);
	if (i == -1) {
		printf("Khong tim thay x trong mang A\n");
	}
	else {
		printf("Vi tri x trong mang A la: %d\n", i + 1);
		//Tại sao lại xuất i+1 ở đây
	}
	return 0;

}