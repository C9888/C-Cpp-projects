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
//ͷ�巨
void insterLiList(LiList &L) {//LiList &LΪ�����ⲿ��L�����������ֵ
    L=(LiList)malloc(sizeof(Node));//����ͷ�ڵ�ռ�

    L->next= NULL;
    ElemType x;
    scanf("%d",&x);//������Ҫ���������
    LiList s;

    while (x!=99999) {

        s=(LiList)malloc(sizeof(Node));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }

}
//β�巨
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

//��λ����
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
//��ֵ����
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
//ɾ�㣬ɾ����i��λ��
bool delete_LiList(LiList &L) {
    int i;
    printf("������ɾ����λ��\n");
    scanf("%d",&i);
    if (i<=0) return false;
    LiList temp=L;
    for (int j=0;j<i+1;j++) {
        if (temp==NULL) {
            printf("ɾ��λ�ò�����");
            return false;
        }
        temp=temp->next;
    }
    if (i == 1) {
        LiList toDelete = L;
        L = toDelete->next;  // ����ͷָ��
        free(toDelete);  // �ͷ�ɾ���Ľڵ�
        return true;
    }//��ɾ����һ��λ�õ�Ԫ��ʱ����Ҫ�޸�ͷָ��
    LiList q=GetElements(L,i-1);//��Ҫɾ���ڵ��ǰһ���ڵ�
    LiList p=q->next;        //��Ҫɾ���Ľڵ�
    q->next=p->next;
    free(p);
    return true;

}
LiList Listmid_inster(LiList L,int i,ElemType *e) {
    printf("������������ݵ�λ�ú���ֵ:\n");
    scanf("%d",&i);
    scanf("%d",e);
    if (i<=0||*e==99999) return 0;
    LiList s;
    s=(LiList)malloc(sizeof(Node));
    s->data=*e;

    LiList temp = L;
    for (int j = 0; j < i - 1; j++) {
        if (temp == NULL) {  // ��ֹλ��Խ��
            printf("λ�ó�������Χ\n");
            free(s);  // �ͷ��ڴ�
            return L;
        }
        temp = temp->next;
    }

    // ����ڵ�
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
    printf("����������������:\n");
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