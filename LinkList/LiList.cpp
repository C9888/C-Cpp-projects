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
void insterLiList(LiList &L) {//LiList &L为引用外部的L变量传入参数值
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

//按位查找
LiList GetElements(LiList L,int searchPos) {
    int i=0;
    if (searchPos<=0) {
        return NULL;
    }
    while (L&&i<searchPos) {
        L=L->next;
        i++;
    }
    return L;
}
//按值查找
int LocalElements(LiList L,int val) {
    if (val==99999) {
        return NULL;
    }
    int i=0;
    while (L) {
        L=L->next;
        i++;
        if (L->data==val) {
            return i;
        }
    }
}
//删点，删除第i个位置
bool delete_LiList(LiList &L) {
    int i;
    printf("请输入删除的位置\n");
    scanf("%d",&i);
    if (i<=0) return false;
    LiList temp=L;
    for (int j=0;j<i+1;j++) {
        if (temp==NULL) {
            printf("删除位置不存在");
            return false;
        }
        temp=temp->next;
    }
    if (i == 1) {
        LiList toDelete = L;
        L = toDelete->next;  // 更新头指针
        free(toDelete);  // 释放删除的节点
        return true;
    }//当删除第一个位置的元素时，需要修改头指针
    LiList q=GetElements(L,i-1);//找要删除节点的前一个节点
    LiList p=q->next;        //找要删除的节点
    q->next=p->next;
    free(p);
    return true;

}
LiList Listmid_inster(LiList L,int i,ElemType *e) {
    printf("请输入插入数据的位置和数值:\n");
    scanf("%d",&i);
    scanf("%d",e);
    if (i<=0||*e==99999) return 0;
    LiList s;
    s=(LiList)malloc(sizeof(Node));
    s->data=*e;

    LiList temp = L;
    for (int j = 0; j < i - 1; j++) {
        if (temp == NULL) {  // 防止位置越界
            printf("位置超出链表范围\n");
            free(s);  // 释放内存
            return L;
        }
        temp = temp->next;
    }

    // 插入节点
    s->next = temp->next;
    temp->next = s;
    return L;
}
void printLiList(LiList L) {

    LiList p=L->next;
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    LiList L,search;
    int searchs;
    // insterLiList(L);
    printf("输入插入链表的数据:\n");
    inster_tail_LiList( L);
    printLiList(L);

    // search=GetElements(L,1);
    // if (search!=NULL) {
    //     printf("successful\n");
    //     printf("%d\n",search->data);
    // }
    // searchs=LocalElements(L,4);
    // if (searchs!=NULL) {
    //     printf("successful too\n");
    //     printf("%d\n",searchs);
    // }
    // ElemType e;
    // int i=0;
    // Listmid_inster(L,i,&e);
    // printLiList(L);
    delete_LiList(L);
    printLiList(L);
    return 0;

}