#!/usr/bin/python
#my code
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
        	return False
        while n > 1:
        	if n & 1:
        		return False
        	else:
        		n >>= 1
        return True


#jiuzhang
class Solution:
    """
    @param n: An integer
    @return: True or false
    """
    def checkPowerOf2(self, n):
        # write your code here
        ans = 1
        for i in xrange(31):
        #both of them are correct
        #for i in range(31):
            if ans == n:
                return True
            ans = ans << 1
 
        return False


# def isPowerOfTwo(n):
#     """
#     :type n: int
#     :rtype: bool
#     """
#     if n < 1:
#     	return False
#     while n > 1:
#     	if n & 1:
#     		return False
#     	else:
#     		n >>= 1
#     return True

#a = Solution()
#a.isPowerOfTwo(2)
#print isPowerOfTwo(5) 


# print "abc"
# def foo():   
#     str="function"   
#     print(str);   

# if __name__=="__main__":   
#     print("main")   
#     foo()