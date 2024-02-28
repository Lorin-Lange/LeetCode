////////////////////////////////////////////////////
//                    LeetCode                    //
//                   1. Two Sum                   //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(nums[0]));
    for(int i = 0; i < numsSize; i++) {
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target && i != j) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return 0;
}