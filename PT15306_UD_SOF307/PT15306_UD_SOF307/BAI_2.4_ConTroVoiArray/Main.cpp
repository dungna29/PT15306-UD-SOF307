#include <stdio.h>
#include <stdlib.h>//Trong c++ thì dùng new và delete còn trong c sẽ là malloc reloc

/*
 * Con trỏ và mảng một chiều
 *		+ Định nghĩa:
 *			-Tên mảng arr là một hằng con trỏ không thể thay đổi giá trị của hằng này
 *			- Giá trị của arr là địa chỉ phần tử đầu tiên của mảng.
 *		+ Khi sử dụng con trỏ chúng ta sẽ cấp phát động cho mảng 1 chiều trở thành mảng động.
 *
 *		+ Công thức:
 *		<tên mảng> == &array[0];
 *
 *		+ Phép toán số học trên con trỏ:
 *			+n + * sizeof(<kiểu dữ liệu>)
 *			Có thể sử dụng toán tử gộp += hoặc ++
 *		+ Phép so sánh: So sánh địa chỉ giữa 2 con trỏ (Thứ tự ô nhớ)
 *			- == != > < >= <=
 *
 *	Lưu ý: Không thể thực hiện các phép toán * / % cho con trỏ
 *
 */
void nhapMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap vao a[%d] : ", i);
		//scanf_s("%d", &a[i]); //Cách 1
		// scanf_s("%d", &i[a]); //Cách 2
		scanf_s("%d", a);
		a++;
	}
}
void inMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//printf_s("%d \t", i[a]);//Cách 1
		printf_s("%d \t", *a);//Cách 2
		a++;
	}
}
void xoaPhanTu(int*& a, int& n, int viTriXoa)
{
	for (int i = viTriXoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;//Trừ đi byte
	//Hàm Realloc(): Thay đổi kích thước của bộ nhớ được cấp phát
	// (int*) ép kiểu
	a = (int*)realloc(a, n * sizeof(int));//Tính theo byte

}

void themPhanTu(int*& a, int& n, int viTriThem, int giaTriThem)
{
	//Xin cấp phát trước
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for (int i = n - 1; i > viTriThem; i--)
	{
		a[i] = a[i - 1];
	}
	a[viTriThem] = giaTriThem;
}
int main()
{

	int arrNumber[3], * parrNumber;
	//Cách 1
	//parrNumber = arrNumber;//Ngầm định hiểu là địa chỉ của ô nhớ đầu tiên
	
	//Cách 2:
	//parrNumber = &arrNumber[0];	//Địa chỉ của ô nhớ đầu tiên
	
	
	//Cách làm cũ
	int arr[50];//Cách làm cũ
	
	//Cách triển khai mảng động
	int n;//= 4 byte
	do
	{
		printf_s("Nhap so luong phan tu: \n");
		scanf_s("%d", &n);
		if (n < 0)
		{
			printf_s("== So luong ban nhap khong hop le== \n");
		}
	} while (n < 0);
	
	//CÚ PHÁP CẤP PHÁT DỘNG vùng nhớ
	/*
	 * Mảng động khác biệt duy nhất là hàm thêm và hàm xóa
	 */
	int* a = NULL;//Khởi tạo con trỏ a có địa chỉ bằng NULL
	//Sử dụng hàm Malloc để cấp phát bộ nhớ
	
	//a = (int*)malloc(n * sizeof(int*));//ten con tro = (kieudulieu*)malloc(soluongonho * sizeof(kieudulieu))
	//a = (int*)calloc(n, n * sizeof(int*));
	
	a = new int[n];
	//malloc không gán giá trị ban đầu
	//Calloc sẽ gán giá trị mặc định các ô nhớ
	
	
	//Phần 1: Nhập mảng
	nhapMang(a, n);
	inMang(a, n);
	//xoaPhanTu(a, n, 1);
	//themPhanTu(a, n, 1, 99);
	printf_s("\n");
	inMang(a, n);
	if (a != NULL)
	{
		//free(a);//Giải phóng bộ nhớ
		//Nếu không giải phóng ô nhớ sẽ tốn rất nhiều tài nguyên của máy tính
		delete []a;
	}

	//Quiz 2: Câu 3
	// int myArr[5] = { 1, 2, 3, 4, 5 };
	// int value = *(myArr + 2);
	// printf_s("%d", value);
}