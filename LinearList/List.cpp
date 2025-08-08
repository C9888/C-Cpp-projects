#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 定义线性表的最大长度
typedef int ElemType; // 定义元素类型

typedef struct {
    ElemType data[MAXSIZE]; // 存储元素的数组
    int length;             // 当前线性表的长度
} SqList;

int ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return 0; // 检查插入位置是否合法
    if (L->length == MAXSIZE) return 0;       // 检查是否已满

    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j]; // 元素后移
    }
    L->data[i - 1] = e; // 插入元素
    L->length++;        // 更新长度
    return 1;           // 插入成功
}

int ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return 0; // 检查删除位置是否合法

    *e = L->data[i - 1]; // 保存被删除的元素
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j]; // 元素前移
    }
    L->length--; // 更新长度
    return 1;    // 删除成功
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    L.length = 0; // 初始化线性表

    // 插入元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);
    printf("插入后线性表: ");
    PrintList(L);

    // 删除元素
    ElemType e;
    ListDelete(&L, 2, &e);
    printf("删除元素 %d 后线性表: ", e);
    PrintList(L);

    return 0;
}