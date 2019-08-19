//
//  main.cpp
//  shell_sort
//
//  Created by JF Zhou on 2019/8/19.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

void shell_sort(int* arr, int size)
{
    int gap,i,j;
    int temp;
    for(gap = size >> 1; gap > 0; gap = gap >> 1)
    {
        for(i = gap; i < size; i++)
        {
            temp = arr[i];
            for(j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {89,22,3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    shell_sort(arr, size);
    
    cout << "选择排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
