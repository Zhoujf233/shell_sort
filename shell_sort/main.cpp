//
//  main.cpp
//  shell_sort
//
//  Created by JF Zhou on 2019/8/19.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

//void shell_sort(int* arr, int size)
//{
//    int gap,i,j;
//    int temp;
//    for(gap = size >> 1; gap > 0; gap = gap >> 1)
//    {
//        for(i = gap; i < size; i++)
//        {
//            temp = arr[i];
//            for(j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
//            {
//                arr[j + gap] = arr[j];
//            }
//            arr[j + gap] = temp;
//        }
//    }
//}

//希尔排序
//void shell_sort(int* arr, int size)
//{
//    int i,j,gap;
//    for(gap = size / 2; gap > 0; gap /= 2)//步长
//    {
//        for(i = 0; i < gap; i++)//直接插入排序
//        {
//            for(j = i + gap; j < size; j += gap)
//            {
//                if(arr[j] < arr[j - gap])
//                {
//                    int temp = arr[j];
//                    int k = j - gap;
//                    while(k >= 0 && arr[k] > temp)
//                    {
//                        arr[k + gap] = arr[k];
//                        k -= gap;
//                    }
//                    arr[k + gap] = temp;
//                }
//            }
//        }
//    }
//}

//优化1
//void shell_sort(int* arr, int size)
//{
//    int j,gap;
//    for(gap = size / 2; gap > 0; gap /= 2)
//    {
//        for(j = gap; j < size; j++)//从数组第gap个元素开始
//        {
//            if(arr[j] < arr[j - gap])//每个元素与自己组内的数据进行直接插入排序
//            {
//                int temp = arr[j];
//                int k = j - gap;
//                while(k >= 0 && arr[k] > temp)
//                {
//                    arr[k + gap] = arr[k];
//                    k -= gap;
//                }
//                arr[k + gap] = temp;
//            }
//        }
//    }
//}

//优化2
void swap(int *a, int *b)//交换两数
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int* arr, int size)
{
    int i,j,gap;
    for(gap = size / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < size; i++)
        {
            for(j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
            {
                swap(arr[j], arr[j + gap]);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {89,22,-3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    shell_sort(arr, size);
    
    cout << "希尔排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
