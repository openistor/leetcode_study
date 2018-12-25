/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int i, j;
    int *ret;
    
    ret = malloc(2*sizeof(int));
    for (i=0;i<numsSize-1;i++) {
        for (j=i+1; j < numsSize; j++) { 
            if ((*(nums+i) + *(nums+j)) == target ) {
                *ret = i;
                *(ret+1) = j;
                return ret;
            }
                        
        }
    }
    return 0;
    
}
