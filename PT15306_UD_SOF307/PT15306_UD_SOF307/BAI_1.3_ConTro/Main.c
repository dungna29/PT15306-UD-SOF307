#include <stdio.h>
/*
 * + Bộ nhớ máy tính
 *		- Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi 1 ô nhớ có kích thước là 1 Byte.
 *		- RAM dùng để chứa một phần hệ điều hành, các lệnh chương trình, các dữ liệu....
 *		- Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi
 *		- Địa chỉ của value được lưu trữ ở hệ hệ thập lục phân (hexadecimal) một byte hầu như luôn luôn được định nghĩa là chứa tám			chữ số nhị phân.
 *		- Mỗi ô nhớ của RAM đều có một địa chỉ. Thông thường, mỗi ô nhớ là một byte (8 bit); tuy nhiên hệ thống lại có thể đọc ra hay		ghi vào nhiều byte (2, 4, 8 byte) một lúc.
 *	+ Khi chương trình biên dịch
 *		- Dành ra riêng một vùng nhớ với địa chỉ duy nhất để lưu biến đó
 *		- Liên kết địa chỉ ô nhớ đó với tên biến
 *		- Khi gọi tên biến nó sẽ truy xuất tự động đế ô nhớ đã liên kết với tên biến bởi có nhiều ô nhớ
 */


 /*
  * Con trỏ trong lập trình C
  * + Định nghĩa:
  *		- Địa chỉ của biến là một con số
  *		- Ta có thể tạo biến khác để lưu địa chỉ của biến này trên con trỏ
  *		- Vậy con trỏ sẽ sẽ lưu vị trí của cái biến đó
  *		- Các vùng nhớ có thể có các kiểu dữ liệu khác nhau bởi vậy con trỏ có thể trỏ đến các kiểu dữ liệu khác nhau
  *		- CON TRỎ KHÔNG CÓ KIỂU DỮ LIỆU BỞI CON TRỎ CHỈ TỎ ĐẾN ĐỊA CHỈ THÌ ĐỊA CHỈ NÀO CŨNG GIỐNG NHAU CHỨ KO CÓ KIỂU ĐỊA CHỈ LÀ SỐ NGUYÊN, FLOAT......
  *
  *
  * + Công thức dùng: (Giống như biến, biến con trỏ muốn sử dụng cũng cần được khai báo)
  *				<Kiểu dữ liệu>*  <tên con trỏ>;
  *
  *	+ Khởi tạo con trỏ:
  *		- Khi mới khai báo biến con trỏ được đặt ở địa chỉ nào đó không biết trước.
  *			- Chứa giá trị không xác định
  *			- trỏ đến vùng nhớ không biết trước
  *
  *		- Đặt địa chỉ của biến vào con trỏ sử dụng toán tử &
  *				<tên con trỏ> = &<tên biến>
  *
  *	+ Kích thước của con trỏ:
  *		- Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau:
  *			- Môi trường MD-DOS(16 BIT): 2 Bytes(64KB) - Con trỏ tốn 2 Bytes
  *			- Môi trường WINDOWS(32 || 64 BIT): 4 Bytes(4GB)
  *
  *  - Toán tử & dùng để truy xuất địa chỉ
  *  - Truy xuât/ Trỏ đến đia chỉ đó để lấy giá trị địa chỉ đó lên thì dùng dấu *<Tên con trỏ>
  *
  *
  *  LƯU Ý: KHÔNG NÊN SỬ DỤNG CON TRỎ KHI CHƯA ĐƯỢC KHỞI TẠO. KẾT QUẢ SẼ KHÔNG LƯỜNG TRƯỚC ĐƯỢC.
  */
void khaiBaoVaKhoiTaoConTro()
{
	int* ptr1;//Khai báo 1 con trỏ pointer tên là ptr1 trỏ đến vùng nhớ có kiểu int.
	double* ptr2; /*Pointer to double*/
	float* ptr3;/*Pointer to float*/
	int* ptr4, a;//ptr4 là con trỏ nhưng a lại là biến.
	char* ch1;/*Pointer to Character*/
	//Lưu ý: Mỗi con trỏ nên khai báo trên 1 dòng
	/*
	 * Ví dụ 1: Khai báo một biến không nhất thiết phải có giá trị nhưng nó sẽ vẫn phải có địa chỉ
	 */
	int b = 4;
	int c = 7;
	printf("Dia Chi Cua Bien-------------------------\n");
	printf("Dia chi cua bien b co kieu HEX trong ram la %p \n", &b);//Dấu & giúp lấy địa chỉ của biến
	printf("Dia chi cua bien c co kieu HEX trong ram la %p \n", &c);
	printf("Gia tri cua c ram la %d \n", c);
	//%p là để in ra một đia chỉ có kiểu HEX
	printf("--------------------------------------\n");

	/*
	 * Ví dụ 2: Làm việc với con trỏ
	 */
	int* ptr5;//Khởi tạo con trỏ
	int* ptr6 = NULL;//Khởi tạo con trỏ với địa chỉ NULL là con trỏ không trỏ đi đâu cả

	ptr5 = &b;//Gán địa chỉ cho con trỏ ptr5 của biến b
	//Có thể hiểu con trỏ đang trỏ đến địa chỉ của ô nhớ biến b

	//Muốn xem giá trị của địa chỉ con trỏ đang trỏ đến dùng toán tử *
	printf("Dia Chi Cua con tro sau khi tro-------------------------\n");
	printf("Dia chi cua con tro ptr5 dang tro den b la: %p \n", ptr5);
	printf("Gia tri con tro ptr5 dang tro den b la: %d \n", *ptr5);//* dùng để lấy value tại địa chỉ ô nhớ thông qua con trỏ
	printf("Dia chi cua bien b co kieu HEX trong ram la %p \n", &b);
	printf("--------------------------------------\n");

	//
	*ptr5 = 9;//Gán giá trị mới vào ô địa chỉ mà con trỏ đang trỏ là b
	printf("Gan gia tri vao dia chi con tro dang tro-------------------------\n");
	printf("Gia tri cua b ram la %d \n", b);		
	printf("--------------------------------------\n");
	
}
int main()
{
	khaiBaoVaKhoiTaoConTro();
}