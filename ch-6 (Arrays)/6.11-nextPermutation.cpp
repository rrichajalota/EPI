/* Compute the next permutation. Leetcode- Question 31. 
** Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
**
**  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
**  The replacement must be in-place, do not allocate extra memory.
**
**  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
**  1,2,3 → 1,3,2
**  3,2,1 → 1,2,3
**  1,1,5 → 1,5,1
**  SOLUTION. 
**  E.g. Given an array <6, 2, 1, 5, 4, 3, 0>.
**  Find k-1 such that p[k-1]< p[k] and entries after k-1 appear in decreasing order. In our case, k-1= 2 which has value 1.
**  Find the minimum value that is greater than p[k-1] after index k. So min value > 1 is 3.
**  Swap the two values. Resulting array - <6, 2, 3, 5, 4, 1, 0> The array after k-1 is still in decreasing order.
**  Now reverse the sequence from index k. Final array- <6, 2, 3, 0, 1, 4, 5> 
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int k= nums.size()-1;          
       
       while (k > 0 && nums[k-1] >= nums[k]){
           --k;
       }
       if (k==0)
            reverse(nums.begin(),nums.end());
        else{
            for (int i= nums.size()-1; i>k-1; --i){
                if (nums[k-1]<nums[i]){
                    swap(nums[k-1],nums[i]);
                    break;
                }
            }
            // now reverse the numbers from k to nums.size()-1 to get the least number of the new permutation
            
                reverse(nums.begin()+k,nums.end());
        }
    }
};

