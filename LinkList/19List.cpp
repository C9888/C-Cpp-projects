//
// Created by 20143 on 2025/8/27.
//设线性表L=(a1~an)采用带头结点的单链表保存，链表中的结点定义如下：
//typedef struct node (
//  int data;
//  struct node* next;
//  ）NODK;
//  请设计一个空间复杂度为O（1）归时间上尽可能高效的算法，重新排列中的各结点，得 到线性表L=(a1,an,a2,an-1,……)。要求:
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LList;
//带头结点尾插法
void inster_tail_LList(LList &L) {
    L=(LList)malloc(sizeof(LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LList s,r=L;
    while (x!=99999) {
        s=(LList)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}
//找栈表中间节点，并设置为L2链表
void find_middle(LList &L,LList &L2) {
    L2=(LList)malloc(sizeof(LNode));
    LList pcur,ppre;
    ppre=pcur=L->next;
    while (pcur) {
        pcur=pcur->next;
        if (pcur==NULL) {
            break;
        }
        pcur=pcur->next;
        if (pcur==NULL) {
            break;
        }
        ppre=ppre->next;
    }
    L2->next=ppre->next;//由L2指向后面一半链表
    ppre->next=NULL;//取前一半链表为L

}
//将L2链表逆置
void reverse(LList L2) {
    LList r ,s,t;
    r=L2->next;
    if (r==NULL) {
        return;//链表为空
    }
    s=r->next;
    if (s==NULL) {
        return;
    }
    t=s->next;
    while (t) {
        s->next=r;
        r=s;
        s=t;
        t=t->next;
    }
    s->next=r;
    L2->next->next=NULL;
    L2->next=s;
}
//将链表L和L2一次存入链表L里面
void merge(LList L,LList L2) {
    LList pcur,p,q;
    pcur=L->next;
    p=pcur->next;
    q=L2->next;
    while (p!=NULL&&q!=NULL) {
        pcur->next=q;
        q=q->next;
        pcur=pcur->next;
        pcur->next=p;
        p=p->next;
        pcur=pcur->next;
    }
    if (q!=NULL) {
        pcur->next=q;
    }else if (p!=NULL) {
        pcur->next=p;
    }

}
void printLList(LList L) {
    LList p=L->next;
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    LList L;
    inster_tail_LList(L);
    printLList(L);
    LList L2=NULL;
    find_middle(L,L2);
    printf("---------------------\n");
    printLList(L);
    printLList(L2);
    printf("---------------------\n");
    reverse(L2);
    printLList(L2);
    printf("---------------------\n");
    merge(L,L2);
    free(L2);
    printLList(L);
    return 0;

}