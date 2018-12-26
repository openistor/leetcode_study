/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int partition(int *array, int left, int right, int *index)
{
    int mid = left;
    int lower, upper;
    int tmp, target;
    
    lower = left+1;
    upper = right;
    mid = left;
    target = *(array+mid);
    
    while (lower < upper)  {
        if (*(array+lower) > target) {
            tmp = *(array+lower);
            *(array+lower) = *(array+upper);
            *(array+upper) = tmp;
            
            tmp = *(index+lower);
            *(index+lower) = *(index+upper);
            *(index+upper) = tmp;
            
            upper--;
        } else {
            lower ++;
        }
    }
    
    if (*(array+lower) > target) {
        lower --;
    }
    tmp = *(array+lower);
    *(array+lower) = *(array+mid);
    *(array+mid) = tmp;
            
    tmp = *(index+lower);
    *(index+lower) = *(index+mid);
    *(index+mid) = tmp;
    
    return lower;
}

void quicksort(int *array, int left, int right, int *index) 
{
    int mid;
    
    if (left >= right)
        return;
   
    mid = partition(array, left, right, index);
    quicksort(array,left,mid-1, index);
    quicksort(array,mid+1,right,index);
    
}


int* twoSum(int* nums, int numsSize, int target) {
    int *lower, *upper, t1, t2, i;
    int *ret;
    int tmp;
    int *copy = malloc(numsSize*sizeof(int));
    
    for (i=0;i<numsSize;i++)
        *(copy+i) = i;
    
    ret = malloc(2*sizeof(int));
    
    quicksort(nums, 0, numsSize-1 , copy);    

    lower = nums;
    upper = nums+numsSize-1;
       
    while (lower < upper) {
        if ((*lower + *upper)==target) {
            *ret = *(copy+(lower-nums));
            *(ret+1) = *(copy+(upper-nums));
            break;
        } else if ((*lower + *upper) > target) {
            upper--;
        } else {
            lower++;
        }
    }
    
    return ret;
}
