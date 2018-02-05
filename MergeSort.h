//
// Created by wangzy on 2018/2/5.
//

#ifndef SELECTIONSORT_MERGESORT_H
#define SELECTIONSORT_MERGESORT_H
#include <iostream>

//将arr[l,...,mid]和arr[mid+1,...,r]两部分进行归并
template <typename T>
void __merge(T arr[],int left,int mid,int right){
    T aux[right-left+1];
    for( int i = left;i <= right;i++)
        aux[i - left] = arr[i];
    int i = left,j = mid+1;
    for(int k = left;k <= right;k++){
        //先进行数组下标合法性的判断
        if(i > mid){
            arr[k] = aux[j-left];
            j++;
        }else if(j > right){
            arr[k] = aux[i-left];
            i++;
        }
        //如果i在[left,mid],并且j在[mid+1,right]中,然后进行数组合并
        else if(aux[i-left] < aux[j -left]){
            arr[k] = aux[i - left];
            i++;
        }
        else{
            arr[k] = aux[j-left];
            j++;
        }
    }

}

//递归使用归并排序,对arr[l,...,r]的范围进行排序
template <typename T>
void __mergeSort(T arr[],int left,int right){
    if(left >= right)
        return;
    int mid = left+(right-left)/2;
    __mergeSort(arr,left,mid);
    __mergeSort(arr,mid+1,right);
    __merge(arr,left,mid,right);
}

template <typename T>
void mergeSort(T arr[],int n){
    __mergeSort(arr,0,n-1);
}
#endif //SELECTIONSORT_MERGESORT_H
