#include <iostream>  
using namespace std; 


//最差时间复杂度：O(n^2)
//最优时间复杂度：O(n^2)
//平均时间复杂度：O(n^2)
//稳定性：不稳定
void SelectSort(int *a, int len)  
{  
    for (int i=0; i<len-1; i++)  
    {  
        int k = i;  
        int key = a[i];  
        for (int j=i+1; j<len; j++)  
        {  
            if (a[j]<key)  
            {  
                k = j;  
                key = a[j];  
            }  
        }  
        if (k!=i)  
            swap(a[i], a[k]);  
    }  
}


int main()  
{  
    int array[5]={3,1,2,5,4};  
    SelectSort(array,5);  
    for(int i=0;i<5;i++)  
        cout<<array[i]<<"  ";  
    cout<<endl;  
    return 0;  
}