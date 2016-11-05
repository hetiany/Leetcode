#include <iostream>  
using namespace std; 

//增量为2的shell排序的时间代价可以达到θ(n的3/2次方)，有的增量可以达到θ(n的7/6次方)，很接近θ(n)
void ShellSort(int *a, int len)  
{  
    int h = 1;  
    while( h<len )   
        h = 3*h + 1;  
    while( h>0 )  
    {  
        for (int j=h; j<len; j++)  
        {  
            int key = a[j];  
            int i = j-h;  
            while( i>=0 && a[i]>key )  
            {  
                a[i+h] = a[i];  
                i = i-h;  
            }  
            a[i+h] = key;  
        }  
        h  = h/3;  
    }  
}

int main()  
{  
    int array[5]={3,1,2,5,4};  
    ShellSort(array,5);  
    for(int i=0;i<5;i++)  
        cout<<array[i]<<"  ";  
    cout<<endl;  
    return 0;  
}