// 用法一：直接使用
#include<stdio.h>

void f(int i){
    printf("in f(), %d\n",i);
}
int main(){
    void (*pf)(int) = f;// pf是一个指向f()的函数指针
    printf("%p\n",f);
    printf("%p\n",pf);
    f(10);
    (*pf)(20);//调用f()
    return 0;
}

//用法二：实现根据用户输入来调用相应的函数
#include<stdio.h>

void f(int i){
    printf("in f(), %d\n",i);
}
void g(int i){
    printf("in g(), %d\n",i);
}
void h(int i){
    printf("in h(), %d\n",i);
}
int main(){
    void(*fa[])(int) = {f,g,h};//fa[]为函数指针数组
    int i;
    scanf("%d",&i);
    if(i>=0&&i<sizeof(fa)/sizeof(fa[0])){
        (*fa[i])(0);// i为0，1，2 分别调用f(),g(),h()
    }
    return 0;
}
//在一个函数中调用另一个函数，将函数指针作为参数传入另一个函数
#include<stdio.h>

int plus(int a, int b){
    return a+b;
}
int minus(int a, int b){
    return a-b;
}
void cal(int(*fp)(int,int),int a, int b){
    printf("%d\n",(*fp)(a,b));
}
int main(){
    cal(plus,2,3);
    cal(minus,5,2);
    return 0;
}
