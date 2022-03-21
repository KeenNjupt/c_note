#include<iostream>
#include<vector>
#include<cmath>

#pragma pack(1) //#pragma pack(n)设置按照n个字节对齐，n位2的幂次，n为1时表示不对齐；对齐的字节数取min(元素默认对齐数,n)
struct notalignA{ // #pragma pack() 表示清除当前的字节对齐设置，恢复默认设置
    char c;       // 默认字节设置为 元素的偏移量为元素字节数的整数倍（包括0），即sizeof(x)的整数倍
    int a;        // 最终结构体的大小必须为最大元素字节数的整数倍或n的整数倍（如果由pragma(n)的话)
    int b;
    int e;
    int* f;
};
#pragma pack()


struct l{
    char c; // 偏移量为0
    double t; // 偏移量为8，之前的c占一个字节，t占8个字节，则t的下一个有效偏移量为8，c后的7个字节填充为空
    int a;    // 偏移量为16
};            // 最终 struct l占据24个字节，没设置n则结构体大小必须为最大元素字节数的整数倍，即8的整数倍

#pragma pack(4) //设置字节对齐为4
struct A{
    char c; // 偏移量为0
    int a;  // 偏移量为4
    int b;  // 偏移量为8
    int e;  // 偏移量为12
    char f; // 偏移量为16
    struct l g; // 偏移量为20,原本g作为struct l变量，其偏移量为结构体成员中字节对齐的最大值8，但pack(4)使其偏移量为4的倍数即可
}; //最终 struct A占据44个字节


using namespace std;


union B{
    int a;
    char c[4];
};


int main(){
    struct A i;
    struct l j;
    cout<<sizeof(A)<<endl;
    cout<<sizeof(l)<<endl;
    
    cout<<(unsigned long long)(&j.a)-(unsigned long long)(&j)<<endl;
    
    cout<<(unsigned long long)(&i.c)-(unsigned long long)(&i)<<endl;
    cout<<(unsigned long long)(&i.a)-(unsigned long long)(&i)<<endl;
    cout<<(unsigned long long)(&i.b)-(unsigned long long)(&i)<<endl;
    cout<<(unsigned long long)(&i.e)-(unsigned long long)(&i)<<endl;
    cout<<(unsigned long long)(&i.f)-(unsigned long long)(&i)<<endl;
    cout<<(unsigned long long)(&i.g)-(unsigned long long)(&i)<<endl;

    

    // 大端存储： 以字节为单位数据高位放在地址低位，小端存储：数据低位放在地址低位
    // 数据 0x12 34 56 78, 12为数据最高位、78为数据最低位
    // 大端存储 12 34 56 78 ，地址由低到高
    // 小端存储 78 56 34 12 ,地址由低到高

    // union B j;
    // j.a = 0x02FFFFFF;
    // cout<<(int)(j.c[3])<<endl;

    char c;
    short a = 0x00FF;
    c = a; // c拿到a的最低位字节数据
    if(c==0x00){
        cout<<"大端"<<endl;
    }
    else cout<<"小端"<<endl;

    return 0;
}

