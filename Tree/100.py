# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#my code, 10/11/2016
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if (not p and not q):
            return True
        if (p and q):
            if (p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)):
                return True
            else:
                return False
        return False;


#Find online, Indentation error ????
class Solution(object):
    def isSameTree(self, p, q):   
	    if p and q:
	    	return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
	    return p is q


#Find online, correct
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return p and q and p.val == q.val and all(map(self.isSameTree, (p.left, p.right), (q.left, q.right))) or p is q