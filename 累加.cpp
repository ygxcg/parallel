#include<iostream>
#include <sys/time.h>
#include<cmath>
using namespace std;
double get_time() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec * 1e-6;  // 返回秒级时间
}
int*a;
void f(int n){
    if(n==1)return;
    else{
        for(int i=0;i<n/2;i++){
            a[i]=a[n-i-1];
        }
        n/=2;
        f(n);
    }
}
int main(){
    int b=17;
    int n=pow(2,b);
    //int*a;
    int c=10000;//重复次数
    a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=1;
    }
    cout<<"n="<<n<<"=2的"<<b<<"次方"<<endl;
    cout<<"重复次数"<<c<<endl;
     int sum,sum1,sum2,sum3;
    //平凡算法，逐个累加
    double start=get_time();
    for(int i=0;i<c;i++){
        sum=0;
        for(int j=0;j<n;j++)
        sum+=a[j];}
    double end=get_time();
    cout << "---平凡算法" << endl
         << "总时间: " << (end - start) << " 秒" << endl
         << "每次计算时间: " << (end - start) / c << " 秒" << endl;
    //超标量优化
    //两路链式
    double start1=get_time();
    for(int j=0;j<c;j++){
        sum1=0;sum2=0;
        for (int i = 0;i < n; i += 2) {
            sum1 += a[i];
            sum2 += a[i + 1]; }
            sum3=sum1+sum2;
    }
    double end1=get_time();
    cout << "---优化算法-多链路式" << endl
         << "总时间: " << (end1 - start1) << " 秒" << endl
         << "每次计算时间: " << (end1 - start1) / c << " 秒" << endl;   
    //二重循环方式实现递归
    double start2=get_time();
    for(int j=0;j<c;j++)
        for(int m=n;m>1;m/=2)
            for(int i=0;i<m/2;i++){
                a[i]=a[i*2]+a[i*2+1];
            }
            double end2=get_time();
            cout << "---递归-二重循环" << endl
                 << "总时间: " << (end2 - start2) << " 秒" << endl
                 << "每次计算时间: " << (end2 - start2) / c << " 秒" << endl;
 //递归函数
double start3=get_time();
for(int i=0;i<c;i++){
    f(n);
}
              double end3=get_time();
            cout << "---递归函数" << endl
                 << "总时间: " << (end3 - start3) << " 秒" << endl
                 << "每次计算时间: " << (end3 - start3) / c << " 秒" << endl;
    


    return 0;
}
// aarch64-linux-gnu-g++ -static -o jia_arm 累加.cpp && qemu-aarch64 ./jia_arm 
