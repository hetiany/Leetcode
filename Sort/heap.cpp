#include <iostream>  
#include <vector>
using namespace std; 

// 堆排序  
//最差时间复杂度：O(nlogn)
//最优时间复杂度：O(nlogn)
//平均时间复杂度：O(nlogn)
//稳定性：不稳定
//???


// 最大堆调整  
/*void MaxHeapify(int *a, int i, int heapSize)  
{  
    int l = (i + 1) * 2 - 1;  
    int r = (i + 1) * 2;  
    int largest;  
  
    if (l <= heapSize && a[l] > a[i])  
        largest = l;  
    else  
        largest = i;  
  
    if (r <= heapSize && a[r] > a[largest])  
        largest = r;  
  
    if (largest != i)  
    {  
        swap(a[i], a[largest]);  
        MaxHeapify(a, largest, heapSize);  
    }  
}  
  
// 创建最大堆  
void BuildMaxHeap(int *a, int len)  
{  
    for (int i = len/2 - 1; i >= 0; i--)  
    {  
        MaxHeapify(a, i, len - 1);  
    }  
}  
  

void HeapSort(int *a, int len)  
{  
    BuildMaxHeap(a, len);  
    for (int i = len - 1; i > 0; i--)  
    {  
        swap(a[0], a[i]);  
        MaxHeapify(a, 0, i - 1);  
    }  
}*/



void heap_adjust(vector<int> &nums, int begin, int end)
{
    //int cur = begin;
    int left = 2 * begin + 1;
    int right = 2 * begin + 2;
    int maxIdx = begin;
    if(left <= end && nums[left] > nums[maxIdx]){
        maxIdx = left;
    }
    if(right <= end && nums[right] > nums[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != begin){
        swap(nums[begin], nums[maxIdx]);
        heap_adjust(nums, maxIdx, end);
    }    
}


void buid_heap(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) { // build max heap
        heap_adjust(nums, i, nums.size() - 1);
    }
    
}

void heap_sort(vector<int> & nums){
    buid_heap(nums);
    int n = nums.size() - 1;
    for(int i = 0; i < nums.size(); ++i){
        swap(nums[0], nums[n]);
        heap_adjust(nums, 0, --n);
    }
}


int main()  
{  
    vector<int> nums = {3,1,2,5,4,4,7,8,5,9,10};  
    heap_sort(nums);  
    for(int i = 0; i < nums.size(); i++) {  
        cout << nums[i] << "  ";
    }  
    cout<<endl;  
    return 0;  
}