//
// Created by 20143 on 2025/8/15.
//
#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node* next;
}Node,*LiList;
//头插法
void insterLiList(LiList &L) {
    L=(LiList)malloc(sizeof(Node));//分配头节点空间

    L->next= NULL;
    ElemType x;
    scanf("%d",&x);//输入需要插入的数据
    LiList s;

    while (x!=99999) {

        s=(LiList)malloc(sizeof(Node));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }

}
//尾插法
void inster_tail_LiList(LiList &L) {
    L=(LiList)malloc(sizeof(Node));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LiList s,r=L;
    while (x!=99999) {
        s=(LiList)malloc(sizeof(Node));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}
void printLiList(LiList L) {
    LiList p=L->next;
    while (p!=NULL) {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    LiList L;
    // insterLiList(L);
    inster_tail_LiList( L);
    printLiList(L);
    return 0;

}