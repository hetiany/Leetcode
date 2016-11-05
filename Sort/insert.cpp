#include <iostream>  
using namespace std;  
  
/*交换函数，作用是交换数组中的两个元素的位置*/  
void swap(int array[],int i,int j)  
{  
    int tmp=array[i];  
    array[i]=array[j];  
    array[j]=tmp;  
}  
  
/*插入排序, end to front*/  
//最差情况下，直接插入排序的最大时间代价为θ(n²)，最小时间代价为θ(n)，平均时间代价为θ(n²)
/*void InsertSort(int array[],int n)  
{  
    for(int i=1;i<n;i++)  
    {  
        for(int j=i;j>0;j--)  
        {  
            if(array[j-1]>array[j])  
                swap(array,j,j-1);  
            else  
                break;  
        }  
    }  
} */ 
  

//another version 
void InsertSort(int *a, int len) {  
    for (int i = 1; i < len; i++) {  
        int key = a[i];  
        int j = i - 1;  
        while (j >= 0 && a[j] > key) {  
            a[j + 1] = a[j];  
            j--;  
        }  
        a[j + 1] = key;  
    }  
} 

int main() {  
    int array[] = {3, 1, 2, 5, 3, 4, 7, 7, 6};  
    int n = sizeof(array) / sizeof(int);  
    InsertSort(array, n);
    for(int i = 0; i < n; i++) {
       cout << array[i] << "  ";  
    }       
    cout << endl;  
    return 0;  
}