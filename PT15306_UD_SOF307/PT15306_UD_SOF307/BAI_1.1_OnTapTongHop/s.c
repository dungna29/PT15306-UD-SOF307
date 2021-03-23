#include <stdio.h>
/*
 * A. Cấu trúc dữ liệu vào giải thuật (Data Structure & Algorithms)
 *
 * - Cấu trúc dữ liệu(Data Structure) là cách lập trình để lưu trữ dữ liệu để dữ liệu có thể được sử dụng một cách hiệu quả. Hầu hết mọi ứng dụng doanh nghiệp đều sử dụng nhiều kiểu cấu trúc dữ liệu khác nhau theo cách này hay cách khác, vì nó mang lại nhiều lợi ích rất lớn không chỉ cho việc lưu t
 *
 * rữ dữ liệu.
 *
 * - Thuật toán(Algorithms) là một thủ tục từng bước, xác định một tập hợp các lệnh được thực hiện theo một thứ tự nhất định để có được đầu ra mong muốn. Các thuật toán thường được tạo độc lập với các ngôn ngữ cơ bản, tức là một thuật toán có thể được triển khai bằng nhiều ngôn ngữ lập trình(C/C++, Java, Python, PHP…)
 *
 * B. Tại sao phải học
 * - Khi các ứng dụng ngày càng phức tạp và nhiều dữ liệu, có ba vấn đề phổ biến mà các ứng dụng phải đối mặt ngay bây giờ.
 *		+ Tìm kiếm dữ liệu – Tìm kiếm một sản phẩm nào đó trong cả tỉ tỉ dữ liệu càng ngày càng lớn. Khi dữ liệu phát triển, tìm kiếm sẽ trở nên chậm		hơn. Vì vậy cần CTDL & GT để nâng cao hiệu suất hơn.
		+ Tốc độ bộ xử lý – Tốc độ bộ xử lý mặc dù rất cao nhưng sẽ bị giới hạn nếu dữ liệu tăng lên đến hàng tỷ dữ liệu.
		+ Nhiều yêu cầu – Vì hàng nghìn người dùng có thể tìm kiếm dữ liệu đồng thời trên một máy chủ web, ngay cả máy chủ nhanh cũng bị lỗi trong khi tìm kiếm dữ liệu.

   C. Cần ôn tập lại các kiến thức sau:
 *		+ Kiến thức về mảng trong C
 *		+ Thuật toán sắp xếp
 *		+ Thuật toán đệ quy
 *		+ Struc trong C
 *		+ Con trỏ trong C
 *
 */
// void KhaiBaoMangBai1()
// {
// 	//1. Khai báo mảng
// 	//Cách dùng:
// 	// <kiểu dữ liệu> <arr + tên mảng>[] = {giá trị 1,giá trị 2...}; 
// 	// <kiểu dữ liệu> <arr + tên mảng>[kích thước mảng số nguyên];
//
// 	//Khởi tạo 1 mảng
// 	double arrDiemJavas[] = { 8.6,8.9,9.2 };
// 	int arrNumber[] = { 5,2,3,1,0,9 };
// 	int arrTemp[5];
//
// 	//Gán giá trị cho mảng
// 	//arrTemp = 5; - Không chạy được vì ko xác được vị trí cần lưu giá trị
// 	arrTemp[0] = 5;
// 	printf("%d \n", arrTemp[0]);
// 	//In các giá trị trong mảng
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%d ", arrNumber[i]);
// 	}
// 	
// }

void thuatToanNoiBot()
{
	
	int arrNumber[] = {8,9,6,2};
	
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arrNumber[i]);
	}

	//Thuật toán sắp xếp
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (arrNumber[i] > arrNumber[j])
			{
				int temp = arrNumber[i];
				arrNumber[i] = arrNumber[j];
				arrNumber[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arrNumber[i]);
	}
	
}

int main()
{
	return 0;
}