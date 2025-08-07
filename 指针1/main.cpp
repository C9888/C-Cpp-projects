#include <iostream>
void modify_point(int* &p,int *q) {
    p=q;
}
void modify_poink(int* k,int *z) {
    k=z;
}
int main() {

    int* p=NULL;
    int* k=NULL;
    int i=10;
    int *q=&i;
    int *z=&i;
    modify_point(p,q);
    modify_poink(k,z);
    printf("after modify_point *p=%d\n",*p);
    printf("after modify_poink *k=%d\n",*k);
    return 0;// TIP 请访问 <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a> 查看 CLion 帮助。此外，您还可以从主菜单中选择“帮助 | 学习 IDE 功能”，尝试 CLion 的交互式课次。
}