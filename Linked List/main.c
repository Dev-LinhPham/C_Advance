#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Con trỏ lưu địa chỉ của Node có kiểu struct Node
};

typedef struct Node *Node; // ĐN để sử dụng nhiều biến có kiểu struct Node

Node createNode(int value)
{
    Node temp;
    temp = (Node)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = value;
    return temp; // trả về có kiểu dữ liệu Node
}

void push_back(Node *head, int value)
{
    static int flat = 1;
    if (flat)
    {
        *head = NULL;
        flat = 0;
    }
    Node temp = createNode(value);
    Node p = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        p = *head;
        while (p->next != NULL)
        { // Quét lần lượt các phần tử
            p = p->next;
        }
        p->next = temp;
    }
}

int get(Node head, int index)
{
    int i = 0;

    while (head->next != NULL && i != index)
    {
        head = head->next;
        i++;
    }
    return head->data;
}

int size(Node head)
{
    int i = 1;
    while (head->next != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}
// Thay đổi data của node cần nhập
void assign(Node *head, int value, int index)
{
    int i = 0;
    Node p = *head;
    while (p->next != NULL && i != index)
    {
        p = p->next;
        i++;
    }
    p->data = value;
}
// Chèn node mới
void insert(Node *head, int value, int position)
{
    int i = 0;
    Node newNode = createNode(value);
    Node p = *head;
    while (p->next != NULL && i != (position - 1))
    {
        p = p->next;
        i++;
    }
    Node temp = p->next;
    p->next = newNode;
    p = p->next;
    p->next = temp;
}
// Xóa Node cuối cùng của mảng
void pop_back(Node *head)
{
    int i = 0;
    Node p = *head;
    while (p->next != NULL && i != (size(*head) - 2))
    {
        p = p->next;
        i++;
    }
    free(p->next);
    p->next = NULL; // Đặt next của node kế node cuối = NULL
}

void erase(Node *head, int positon)
{
    int i = 0;
    Node p = *head;
    Node temp = NULL;
    if (positon == 0)
    {
        *head = (*head)->next;
        free(p);
    }
    else
    {
        while (p->next != NULL && i != (positon - 1))
        {
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

void hienthi(Node head)
{
    int i = 0;
    while (head->next != NULL)
    {
        printf("arr[%d]: %d\n", i, head->data);
        head = head->next;
        i++;
    }
    printf("arr[%d]: %d\n", i, head->data);
}

int main(int argc, char const *argv[])
{
    Node node1;
    //PUSH BACK
    printf("---PUSH BACK---\n");
    push_back(&node1, 2);
    push_back(&node1, 5);
    push_back(&node1, 7);
    push_back(&node1, 10);

    hienthi(node1);

    printf("size arr: %d\n", size(node1));
    //ASSIGN
    printf("---ASSIGN---\n");

    assign(&node1, 21, 7);

    hienthi(node1);

    printf("size arr: %d\n", size(node1));

    //INSERT
    printf("---INSERT---\n");
    insert(&node1, 70, 2);

    hienthi(node1);

    printf("size arr: %d\n", size(node1));

    //POP BACK
    printf("---POP BACK---\n");
    pop_back(&node1);

    hienthi(node1);

    printf("size arr: %d\n", size(node1));

    //ERASE
    printf("---ERASE---\n");

    erase(&node1, 0);

    hienthi(node1);

    printf("size arr: %d\n", size(node1));
    return 0;
}
