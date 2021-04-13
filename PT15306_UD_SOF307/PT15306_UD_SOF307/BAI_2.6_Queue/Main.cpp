#include <stdio.h>
/*
 * Hàng đợi(tiếng anh: Queue) là một cấu trúc dữ liệu dùng để lưu giữ các đối tượng theo cơ chế FIFO (viết tắt từ tiếng Anh: First In First Out), nghĩa là “vào trước ra trước”.
 *
 * Trong cấu trúc hàng đợi(queue), ta chỉ có thể thêm các phần tử vào một đầu của queue(giả sử là cuối), và cũng chỉ có thể xóa phần tử ở đầu còn lại của queue(tạm gọi là đầu). Như vậy, ở một đầu không thể xảy ra hai hành động thêm và xóa đồng thời.

	Như vậy, với cấu trúc Hàng đợi(Queue), chúng ta có các chức năng sau:
	1. EnQueue: Thêm phần tử vào cuối(rear) của Queue.
	2. DeQueue: Xóa phần tử khỏi đầu(front) của Queue. Nếu Queue rỗng thì thông báo lỗi.
	3. IsEmpty: Kiểm tra Queue rỗng.
	4. Front: Lấy giá trị của phần tử ở đầu(front) của Queue. Lấy giá trị không làm thay đổi Queue.

	Để cài đặt được Queue, chúng ta sẽ cần sử dụng các biến như sau:
	1. queue[]: Một mảng một chiều mô phỏng cho hàng đợi
	2. arraySize: Số lượng phần tử tối đa có thể lưu trữ trong queue[]
	3. front: Chỉ số của phần tử ở đang đầu queue. Nó sẽ là chỉ số của phần tử sẽ bị xóa ở lần tiếp theo
	4. rear: Chỉ số của phần tử tiếp theo sẽ được thêm vào cuối của queue
 */


#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
    //deQueue is not possible on empty queue
    deQueue();

    //enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    // 6th element can't be added to because the queue is full
    enQueue(6);

    display();

    //deQueue removes element entered first i.e. 1
    deQueue();

    //Now we have just 4 elements
    display();

    return 0;
}

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}

void deQueue() {
    if (front == -1)
        printf("\nQueue is Empty!!");
    else {
        printf("\nDeleted : %d", items[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to print the queue
void display() {
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}