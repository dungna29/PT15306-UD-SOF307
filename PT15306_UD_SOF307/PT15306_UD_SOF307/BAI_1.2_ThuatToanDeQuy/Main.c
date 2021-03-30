#include <stdio.h>

void inMangRamNaHinhDeQuy(int arrTemp[],int i) {	
	if (i < 4)
	{
		printf("%d ", arrTemp[i]);
		i++;
		inMangRamNaHinhDeQuy(arrTemp,i);
	}
	
}

int main() {
	int arrNumber[] = { 5,8,9,6 };

	//Cách 1: Dùng for
	/*for (int i = 0; i < 4; i++)
	{
		printf("%d ",arrNumber[i]);
	}*/

	//Cách 2: Dùng vòng lặp While
	//int i = 0;
	/*while (i < 4)
	{
		printf("%d ", arrNumber[i]);
		i++;
	}*/

	//Cách 3: Dùng vòng lặp Do While
	//int i = 0;
	//do
	//{
	//	
	//	printf("%d ", arrNumber[i]);
	//	i++;
	//} while (i < 4);

	//Cách 4: Sử dụng đệ quy
	inMangRamNaHinhDeQuy(arrNumber,0);

}