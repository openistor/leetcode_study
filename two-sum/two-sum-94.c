/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int partition(int *array, int left, int right)
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
        
    return lower;
}

void quicksort(int *array, int left, int right) 
{
    int mid;
    
    if (left >= right)
        return;
   
    mid = partition(array, left, right);
    quicksort(array,left,mid-1);
    quicksort(array,mid+1,right);
    
}


int* twoSum(int* nums, int numsSize, int target) {
    int *lower, *upper, i, j;
    int *ret;
    int tmp;
    int *copy = malloc(numsSize*sizeof(int));
    
    memcpy(copy,nums,sizeof(int)*numsSize);
    
    ret = malloc(2*sizeof(int));
    
    quicksort(copy, 0, numsSize-1);    

    lower = copy;
    upper = copy+numsSize-1;
       
    while (lower < upper) {
        if ((*lower + *upper)==target) {
            j=0;
            for(i=0;i<numsSize;i++) {
                if ((*lower==*(nums+i)) || (*upper == *(nums+i))) {
                    *(ret+j)=i;
                    j++;
                }
            }
            break;
        } else if ((*lower + *upper) > target) {
            upper--;
        } else {
            lower++;
        }
    }
    
    return ret;
}
