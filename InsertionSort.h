//
// Created by wangzy on 2018/2/2.
//

#ifndef SELECTIONSORT_INSERTIONSORT_H
#define SELECTIONSORT_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

template <typename T>
void insertionSort(T arr[],int n){
    for(int i = 1;i < n;i++){
        //判断插入位置
        //循环条件:当当前位置比前面有序序列 当前位置小的话 循环继续
        //而对比选择排序来说,选择排序每次需要遍历到最后一个元素  理论上来说 插入排序更快
        for(int j = i;j > 0 && arr[j] < arr[j - 1];j--)
            swap(arr[j],arr[j - 1]);
    }
}

#endif //SELECTIONSORT_INSERTIONSORT_H