#include <stdio.h>
/*
 * Trong khoa học máy tính, một ngăn xếp (còn gọi là bộ xếp chồng, tiếng Anh: Stack) là một cấu trúc dữ liệu trừu tượng hoạt động theo nguyên lý “vào sau ra trước” (Last In First Out (LIFO). Tức là, phần tử cuối cùng được chèn vào ngăn xếp sẽ là phần tử đầu tiên được lấy ra khỏi ngăn xếp.
 *
    Push: Thêm một phần tử vào đỉnh của ngăn xếp, số phần tử của ngăn xếp tăng lên 1.
    Pop: Xóa bỏ phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp giảm đi 1.
    Top: Lấy giá trị của phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp không thay đổi.
    IsEmpty: Kiểm tra ngăn xếp trống hay không. Ngăn xếp trống là ngăn xếp không có phần tử nào.
    IsFull: Kiểm tra ngăn xếp đã đầy hay chưa. Thao tác này không phải lúc nào cũng có.
    Size: Lấy số lượng phần tử stack đang có.
 */
int top = -1;
/*
 *  Kiểm tra stack đầy(IsFull)
    Hàm này sẽ kiểm tra xem stack hiện tại đã đầy hay chưa. Nếu chỉ số top của stack đang bằng với capacity - 1, tức stack đã đầy.
 */
bool IsFull(int capacity) {
    if (top >= capacity - 1) {
        return true;
    }
    else {
        return false;
    }
}
/*
 * Kiểm tra stack rỗng(IsEmpty)
Nếu như stack đang không có phần tử nào, ta sẽ gán chỉ số top = -1 để đánh dấu. Như vậy, để kiểm tra stack có đang rỗng hay không rất đơn giản. Ta chỉ cần so sánh giá trị top có phải -1 hay không mà thôi.
 */
bool IsEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}
/*
 * Thêm phần tử vào đỉnh stack(Push)
Chúng ta sẽ chỉ có thể push(thêm phần tử) vào đỉnh stack khi stack chưa đầy. Nếu stack đầy, chúng ta sẽ đưa ra thông báo và không thực hiện push. Ngược lại, ta sẽ tăng top lên một đơn vị và gán giá trị cho phần tử tại chỉ số top.
 */
void Push(int stack[], int value, int capacity) {
    if (IsFull(capacity) == true) {
        printf("\nStack is full. Overflow condition!");
    }
    else {
        ++top;
        stack[top] = value;
    }
}
/*
 * Xóa phần tử khỏi đỉnh stack(Pop)
Chúng ta sẽ chỉ có thể pop(xóa phần tử) khỏi đỉnh stack khi stack không trống. Nếu stack trống, chúng ta sẽ đưa ra thông báo và không thực hiện pop. Ngược lại, ta sẽ giảm giá trị top đi một đơn vị.
 */
void Pop() {
    if (IsEmpty() == true) {
        printf("\nStack is empty. Underflow condition!");
    }
    else {
        --top;
    }
}

/*
    Lấy giá trị phần tử ở đỉnh stack(Top)
    Để lấy giá trị phần tử ở đỉnh stack, ta có thao tác rất đơn giản: *
 */
int Top(int stack[]) {
    return stack[top];
}
/*
 * Lấy số lượng phần tử stack đang có(Size)
 */
int Size() {
    return top + 1;
}

int main() {
    int capacity = 3;
    int top = -1;
    int stack[3];

    // Thêm 1 phần tử vào Stack
    Push(stack, 5, capacity);

    printf("\nKich Thuoc Size Stack = %d", Size());

    Push(stack, 10, capacity);
    Push(stack, 24, capacity);

    printf("\nKich Thuoc Size Stack = %d", Size());

    // As the stack is full, further pushing will show an overflow condition.
    Push(stack, 12, capacity);

    //Accessing the top element
    printf("\nGia tri cau phan tu dau Stack la = %d", Top(stack));

    //Removing all the elements from the stack
    for (int i = 0; i < 3; i++)
        Pop();
    printf("\nKich Thuoc Size Stack = %d", Size());

    //As the stack is empty , further popping will show an underflow condition.
    Pop();
}