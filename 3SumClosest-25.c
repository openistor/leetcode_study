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

int threeSumClosest(int* nums, int numsSize, int target) 
{
    int i, upper,mid,lower;
    int ret;
    int min = (1<<30);
    
    quicksort(nums, 0, numsSize-1);
    for(lower=0; lower < numsSize-2; lower++) {
        if ((*(nums+lower) - target) > min)
            break;
        
        for(mid=lower+1; mid < numsSize-1; mid++) {
            for(upper=mid+1; upper < numsSize; upper++) {
                i = *(nums+lower)+ *(nums+mid)+*(nums+upper);
                if ((i-target) > min)
                    break;
                
                if (abs(i-target) <= min) {
                    min =abs(i-target);
                    ret = i;
                }
            }
        }
    }
    
    return ret;
}
