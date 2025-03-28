#include<iostream>
#include <windows.h>
#include<cmath>
#include<stdlib.h>
using namespace std;

int* a;
void f(int n) {
	if (n == 1)return;
	else {
		for (int i = 0; i < n / 2; i++) {
			a[i] = a[n - i - 1];
		}
		n /= 2;
		f(n);
	}
}
int main() {
	long long start, end, freq;
	int b = 17;
	int n = pow(2, b);
	//int*a;
	int c = 50000;//重复次数
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 1;
	}
	cout << "n=" << n << "=2的" << b << "次方" << endl;
	cout << "重复次数" << c << endl;
	int sum, sum1, sum2, sum3;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	//----------------平凡算法，逐个累加
	//QueryPerformanceCounter((LARGE_INTEGER*)&start);
	//for (int i = 0; i < c; i++) {
	//	sum = 0;
	//	for (int j = 0; j < n; j++)
	//		sum += a[j];
	//}
	//QueryPerformanceCounter((LARGE_INTEGER*)&end);


	//超标量优化
	//------------两路链式--------------
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&start1);
	//for (int j = 0; j < c; j++) {
	//	sum1 = 0; sum2 = 0;
	//	for (int i = 0; i < n; i += 2) {
	//		sum1 += a[i];
	//		sum2 += a[i + 1];
	//	}
	//	sum3 = sum1 + sum2;
	//}
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&end1);


	////二重循环方式实现递归-------------------------------------
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&start2);
	//for (int j = 0; j < c; j++)
	//	for (int m = n; m > 1; m /= 2)
	//		for (int i = 0; i < m / 2; i++) {
	//			a[i] = a[i * 2] + a[i * 2 + 1];
	//		}
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&end2);


	////递归函数----------------------------------------------
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&start3);
	//for (int i = 0; i < c; i++) {
	//	f(n);
	//}
	// 	QueryPerformanceCounter((LARGE_INTEGER*)&end3);



	return 0;
}