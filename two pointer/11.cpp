//Find online
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}


//my code, 08/26/2016, using two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int h = 0, w = 0; 
        while(left < right) {
            h = min(height[left], height[right]);
            w = right - left;
            result = max(result, h * w);
            while(left < right && height[left] <= h) {
                ++left;
            }
            while(left < right && height[right] <= h) {
                --right;
            }
        }
        return result;
    }
};


//my code. 09/02/2016
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int wide = right - left;
        int high = min(height[left], height[right]);
        int max_con = wide * high;
        while(left < right) {
            while(left < right && height[left] <= high) {
                ++left;
            }
            while(left < right && height[right] <= high) {
                --right;
            }
            wide = right - left;
            high = min(height[left], height[right]);
            if(max_con < wide * high) {
                max_con = wide * high;
            }
        }
        return max_con;
    
    }
};