class Solution:
              
              

   def maxSubArray(self, nums: list[int]) -> int:
        max_seq = [max(nums),nums[0]]           #max(nums) у видадку якщо всі елементи від'ємні, nums[0] як найбільша послідовність першого елементу
        neg_sum = 0             #розрахунок суми елементів між дадатними елементами
        for i, val in enumerate(nums[:-1]):
             if nums[i + 1] > 0:
                 if (max_seq[max_seq.__len__() -1] + neg_sum > 0):
                     max_seq.append(max_seq[max_seq.__len__() -1] + neg_sum + nums[i + 1])
                 else: max_seq.append(nums[i + 1])
                 neg_sum = 0
             else: neg_sum += nums[i + 1]
        return max(max_seq)