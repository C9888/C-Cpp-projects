#include <stdio.h>


#define MAXSIZE 100
typedef int ElemType;
typedef struct LinearList {
        ElemType data[MAXSIZE];
        int len;
}LinearList;

bool insterList(LinearList *L, int i ,ElemType e) {
        if (L->len==MAXSIZE) return false;
        if (i<1 ||i>L->len+1) return false;
        for (int j=L->len;j>=i;j--) {
                L->data[j]=L->data[j-1];
                L->data[j-1]=e;

        }
        L->len++;
        return true;
}
bool deleteList(LinearList *L,int i,ElemType e) {
        if (L->len==0)return false;
        e=L->data[i-1];
        for (int j=i;j<L->len;j++) {
                L->data[j-1]=L->data[j];

        }
        L->len--;
        return true;
}
void PrintList(LinearList L) {
        for (int i = 0; i < L.len; i++) {
                printf("%d ", L.data[i]);
        }
        printf("\n");
}

int main() {
        LinearList L;
        L.len=4;
        L.data[0]=1;
        L.data[1]=2;
        L.data[2]=4;
        L.data[3]=5;
        insterList(&L,3,3);
        printf("%d\n",L.len);
        PrintList(L);
        deleteList(&L,1,2);
        printf("%d\n",L.len);
        PrintList(L);
        return 0;


}