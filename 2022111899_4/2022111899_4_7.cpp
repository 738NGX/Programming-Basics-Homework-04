#include<iostream>
using namespace std;

template<class T1> void selectSort(T1 arr[],int len);
template<class T2> void printArray(T2 arr[],int len);

/**
 * @brief 支持整型、实型、字符型的选择排序的函数模板
 * 
 * @param arr 数组
 * @param len 数组长度
 */
template<class T1> void selectSort(T1 arr[],int len){
    int lh,rh,k,tmp;
    for(lh=0;lh<len;lh++){
        rh=lh;
        for(k=lh;k<len;k++){
            if(arr[k]<arr[rh])
                rh=k;
        }
        tmp=arr[lh];
        arr[lh]=arr[rh];
        arr[rh]=tmp;
    }
}

/**
 * @brief 打印整型、实型、字符型数组的函数模板
 * 
 * @param arr 数组
 * @param len 数组长度
 */
template<class T2> void printArray(T2 arr[],int len){
    cout<<"\n";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{ 
    int intarr[10]={20,18,7,19,9,8,2,12,10,1};
    float floatarr[12]={9.1,1.9,8.2,7.3,6.4,3.7,5.5,4.6,2.8,5.8,4.6,2.9};
    char chararr[8]= {'C','d','e','x','B','D','A','a'};
 
    selectSort(intarr,10);
    cout << "the sorted float array:";
    printArray(intarr,10);
    selectSort(floatarr,12);
    cout << "the sorted float array:";
    printArray(floatarr,12);
    selectSort(chararr,8);
    cout << "the sorted float array:";
    printArray(chararr,8);
    return 0;
}