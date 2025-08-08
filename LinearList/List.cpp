#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // �������Ա����󳤶�
typedef int ElemType; // ����Ԫ������

typedef struct {
    ElemType data[MAXSIZE]; // �洢Ԫ�ص�����
    int length;             // ��ǰ���Ա�ĳ���
} SqList;

int ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return 0; // ������λ���Ƿ�Ϸ�
    if (L->length == MAXSIZE) return 0;       // ����Ƿ�����

    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j]; // Ԫ�غ���
    }
    L->data[i - 1] = e; // ����Ԫ��
    L->length++;        // ���³���
    return 1;           // ����ɹ�
}

int ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return 0; // ���ɾ��λ���Ƿ�Ϸ�

    *e = L->data[i - 1]; // ���汻ɾ����Ԫ��
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j]; // Ԫ��ǰ��
    }
    L->length--; // ���³���
    return 1;    // ɾ���ɹ�
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.length = 0; // ��ʼ�����Ա�

    // ����Ԫ��
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);
    printf("��������Ա�: ");
    PrintList(L);

    // ɾ��Ԫ��
    ElemType e;
    ListDelete(&L, 2, &e);
    printf("ɾ��Ԫ�� %d �����Ա�: ", e);
    PrintList(L);

    return 0;
}