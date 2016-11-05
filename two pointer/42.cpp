//Find online
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, water = 0, lower;
        while (l < r) {
            if(height[l] < height[r]) {
                lower = height[l];
                ++l;
            } else {
                lower = height[r];
                --r;
            }
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};


//my code, 10/19/2016
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, level = INT_MIN, lower = 0;
        if(!height.size()) {
            return water;
        }
        int left = 0, right = height.size() - 1;
        while(left < right) {
            if(height[left] < height[right]) {
                lower = height[left];
                ++left;
            } else {
                lower = height[right];
                --right;
            }
            level = max(lower, level);
            water += level - lower;
        }
        return water;
    }
};