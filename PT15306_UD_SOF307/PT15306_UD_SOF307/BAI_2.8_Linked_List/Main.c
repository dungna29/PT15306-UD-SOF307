#include<stdio.h>
#include<stdlib.h>
/*
 * Danh sách liên kết đơn là một tập hợp các Node được phân bố động, được sắp xếp theo cách sao cho mỗi Node chứa “một giá trị”(Data) và “một con trỏ”(Next). Con trỏ sẽ trỏ đến phần tử kế tiếp của danh sách liên kết đó. Nếu con trỏ mà trỏ tới NULL, nghĩa là đó là phần tử cuối cùng của linked list.
 *
 * Danh sách các kiểu danh sách liên kết:
		- Danh sách liên kết đơn(Single linked list): Chỉ có sự kết nối từ phần tử phía trước tới phần tử phía sau.
		- Danh sách liên kết đôi(Double linked list): Có sự kết nối 2 chiều giữa phần tử phía trước với phần tử phía sau
		- Danh sách liên kết vòng(Circular Linked List): Có thêm sự kết nối giữa 2 phần tử đầu tiên và phần tử cuối cùng để tạo thành vòng khép kín.
 */
struct LinkedList {
    int data;
    struct LinkedList* next;
};

typedef struct LinkedList* node; //Từ giờ dùng kiểu dữ liệu LinkedList có thể thay bằng node cho ngắn gọn

node CreateNode(int value) {
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value; // Gán giá trị cho Node
    return temp;//Trả về node mới đã có giá trị
}

node AddTail(node head, int value) {
    node temp, p;// Khai báo 2 node tạm temp và p
    temp = CreateNode(value);//Gọi hàm createNode để khởi tạo node temp có next trỏ tới NULL và giá trị là value
    if (head == NULL) {
        head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
    }
    else {
        p = head;// Khởi tạo p trỏ tới head
        while (p->next != NULL) {
            p = p->next;//Duyệt danh sách liên kết đến cuối. Node cuối là node có next = NULL
        }
        p->next = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
    }
    return head;
}


node AddHead(node head, int value) {
    node temp = CreateNode(value); // Khởi tạo node temp với data = value
    if (head == NULL) {
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }
    else {
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}

node AddAt(node head, int value, int position) {
    if (position == 0 || head == NULL) {
        head = AddHead(head, value); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }
    else {
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        node p = head;
        while (p != NULL && k != position) {
            p = p->next;
            ++k;
        }

        if (k != position) {
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định chèn cuối
            // Nếu bạn không muốn chèn, hãy thông báo vị trí chèn không hợp lệ
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }
        else {
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

node DelHead(node head) {
    if (head == NULL) {
        printf("\nCha co gi de xoa het!");
    }
    else {
        head = head->next;
    }
    return head;
}

node DelTail(node head) {
    if (head == NULL || head->next == NULL) {
        return DelHead(head);
    }
    node p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    p->next = p->next->next; // Cho next bằng NULL
    // Hoặc viết p->next = NULL cũng được
    return head;
}

node DelAt(node head, int position) {
    if (position == 0 || head == NULL || head->next == NULL) {
        head = DelHead(head); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }
    else {
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        node p = head;
        while (p->next->next != NULL && k != position) {
            p = p->next;
            ++k;
        }

        if (k != position) {
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định xóa cuối
            // Nếu bạn không muốn xóa, hãy thông báo vị trí xóa không hợp lệ
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }
        else {
            p->next = p->next->next;
        }
    }
    return head;
}

int Get(node head, int index) {
    int k = 0;
    node p = head;
    while (p != NULL && k != index) {
        p = p->next;
    }
    return p->data;
}

int Search(node head, int value) {
    int position = 0;
    for (node p = head; p != NULL; p = p->next) {
        if (p->data == value) {
            return position;
        }
        ++position;
    }
    return -1;
}

node DelByVal(node head, int value) {
    int position = Search(head, value);
    while (position != -1) {
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}

void Traverser(node head) {
    printf("\n");
    for (node p = head; p != NULL; p = p->next) {
        printf("%5d", p->data);
    }
}

node InitHead() {
    node head;
    head = NULL;
    return head;
}

int Length(node head) {
    int length = 0;
    for (node p = head; p != NULL; p = p->next) {
        ++length;
    }
    return length;
}

node Input() {
    node head = InitHead();
    int n, value;
    do {
        printf("\nNhap so luong phan tu n = ");
        scanf_s("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; ++i) {
        printf("\nNhap gia tri can them: ");
        scanf_s("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}



int main() {
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);

    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2);
    Traverser(head);

    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1);
    Traverser(head);

    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 5);
    printf("\nTim thay tai chi so %d", index);

    printf("\nBan co the thu them nhe!");

}