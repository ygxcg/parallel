#include<iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;

int main() {
    long long start, end, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    int c = 10;
    int n = 10000;
    // ��̬�����ڴ�
    int* sum = new int[n];
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)a[i] = 1;
    QueryPerformanceCounter((LARGE_INTEGER*)&start);
    ////ƽ���㷨
    //for (int i = 0; i < c; i++) {
    //    for (int i = 0; i < n; i++) {
    //        sum[i] = 0;
    //        for (int j = 0; j < n; j++) {
    //            sum[i] += matrix[j][i] * a[j];
    //        }
    //    }
    //}
    //QueryPerformanceCounter((LARGE_INTEGER*)&end);

    //�Ż��㷨
    for (int rep = 0; rep < c; rep++) {
        for (int i = 0; i < n; i++) sum[i] = 0; // ��ʼ��sum
        for (int j = 0; j < n; j++) {          
            for (int i = 0; i < n; i++) {      
                sum[i] += matrix[j][i] * a[j]; 
            }
        }
    }

}