#include <iostream> 
#include <vector> 
using namespace std; 


//Find online, merge sort
/*void merge_array(vector<int> &nums, int b, int m, int e) {
    int lb = b, rb = m + 1, tb = 0;
    vector<int> temp(e - b + 1);
    while (lb <= m && rb <= e) {
        if (nums[lb] < nums[rb]) {
            temp[tb++] = nums[lb++];
        } else {
            temp[tb++] = nums[rb++];
        }
    }

    while (lb <= m) {
        temp[tb++] = nums[lb++];
    }
    
    while (rb <= e) {
        temp[tb++] = nums[rb++];
    }

    for (int i = b;i <= e; i++) {
        nums[i] = temp[i - b];
    }
}

void merge_sort(vector<int> &nums, int b, int e) {
    int m = (b + e) / 2;
    if (b < e) {
        merge_sort(nums, b, m);
        merge_sort(nums, m + 1, e);
        merge_array(nums, b, m, e);
    }
}*/




//my code, merge sort

/*void merge_array(vector<int> & nums, int left, int mid, int right) {
    
    int l = left, m = mid + 1, r = right, temp = 0;

    vector<int> store(r - l + 1);

    while(l <= mid && m <= r) {
        if(nums[l] <= nums[m]) {
            store[temp++] = nums[l++];
        } else {
            store[temp++] = nums[m++];
        }
    }

    while(l <= mid) {
        store[temp++] = nums[l++];
    }

    while(m <= right) {
        store[temp++] = nums[m++];
    }

    for(int i = left; i <= right; ++i) {
        nums[i] = store[i - left];
    }
}


void merge_sort(vector<int>& nums, int left, int right) {
    int mid = left + (right - left) / 2;
    if(left < right){
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge_array(nums, left, mid, right);
    }
}*/

//my code, merge sort
void merge_array(vector<int>& nums, int left, int mid, int right) {
    vector<int> store(right - left + 1);
    int l = left, m = mid + 1, r = right, temp = 0;
   
    while(l <= mid && m <= r) {
        if(nums[l] <= nums[m]) {
            store[temp++] = nums[l++];
        } else {
            store[temp++] = nums[m++];
        }
    }

    while(l <= mid) {
        store[temp++] = nums[l++];
    }

    while(m <= right) {
        store[temp++] = nums[m++];
    }

    for(int i = left; i <= right; ++i) {
        nums[i] = store[i - left];
    }
}


void merge_sort(vector<int>& nums, int left, int right) {    
    if(left < right) {     
        int mid = left + (right - left) / 2;  
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge_array(nums, left, mid, right);
    }
}




//10/04/2016, merge sort
void merge_array(vector<int>& num, int right, int mid, int left) {
    vector<int> store(right - left + 1);
    int m = mid + 1, l = left, temp = 0;
    while(l <= mid && m <= right) {
        if(num[l] <= num[m]) {
            store[temp++] = num[l++];
        } else {
            store[temp++] = num[m++];
        }
    }
    while(l <= mid) {
        store[temp++] = num[l++];
    }
    while(m <= right) {
        store[temp++] = num[m++];
    }

    for(int i = left; i <= right; ++i) {
        num[i] = store[i - left];
    }

}


void merge_sort(vector<int>& num, int left, int right) {
    if(left < right) {
        int mid= left + (right - left) / 2;
        merge_sort(num, left, mid);
        merge_sort(num, mid + 1, right);
        merge_array(num, left, mid, right);
    }
}   



int main() {  
    vector<int> nums = {3,1,2,5,4,4,7,5,8,10,6};  
    //vector<int> temp(nums.size());
    merge_sort(nums, 0, nums.size() - 1); 

    for(int i = 0; i < nums.size(); i++) { 
        cout << nums[i] << "  ";
    }

    cout << endl;  
    return 0;  
}