#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������ͷ������ڵ�
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// ������β������ڵ�
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// ɾ�������е�ָ��ֵ
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // ���ͷ�ڵ����Ҫɾ���Ľڵ�
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // ����Ҫɾ���Ľڵ�
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // ���δ�ҵ��ڵ�
    if (temp == NULL) return;

    // ɾ���ڵ�
    prev->next = temp->next;
    free(temp);
}

// ��ӡ����
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ������ʾ��
int main() {
    Node* head = NULL;

    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    printf("��������: ");
    printList(head);

    insertAtTail(&head, 4);
    printf("����β����: ");
    printList(head);

    deleteNode(&head, 2);
    printf("ɾ��ֵΪ2�Ľڵ��: ");
    printList(head);

    return 0;
}
