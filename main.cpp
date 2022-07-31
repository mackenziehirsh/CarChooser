#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void merge(int arr[], int left, int m, int right) {
    int x1 = m - left + 1;
    int x2 = right - m;
    int X[x1];
    int Y[x2];
    for (unsigned int i = 0; i < x1; i++) {
        X[i] = arr[left+i];
    }
    for (unsigned int j = 0; j < x2; j++) {
        Y[j] = arr[m+1+j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < x1 && j < x2) {
        if (X[i] <= Y[j]) {
            arr[k] = X[i];
            i++;
        } else {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < x1) {
        arr[k] = X[i];
        i++;
        k++;
    }

    while (j < x2) {
        arr[k] = Y[j];
        j++;
        k++;
    }
}

void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int m = left + (right - left)/2;
        mergeSort(arr,left, m);
        mergeSort(arr,m+1,right);
        merge(arr, left, m, right);
    }
}

