#!/usr/bin/python
#jiu zhang
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #hash用于建立数值到下标的映射
        hash = {}
        #循环nums数值，并添加映射
        for i in range(len(nums)):
            if target - nums[i] in hash:
                return [hash[target - nums[i]], i]
            hash[nums[i]] = i
        #无解的情况
        return [-1, -1]



#my code, 10/12/2016
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #hash用于建立数值到下标的映射
        hash = {}
        list = []
        #循环nums数值，并添加映射
        for i in range(len(nums)):
            if target - nums[i] in hash:
                list = [hash[target - nums[i]], i]
                return list    
            hash[nums[i]] = i
        #无解的情况
        return list
        