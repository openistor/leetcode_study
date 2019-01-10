static struct data {
        int key;
        int number;
        char ch[4];
    } input[10] = 
{
    { .key = 0, .number = 0, .ch = ""},
    { .key = 1, .number = 0, .ch = ""},        
    { .key = 2, .number = 3, .ch = "abc" },
    { .key = 3, .number = 3, .ch = "def" },    
    { .key = 4, .number = 3, .ch = "ghi" },    
    { .key = 5, .number = 3, .ch = "jkl" },    
    { .key = 6, .number = 3, .ch = "mno" },    
    { .key = 7, .number = 4, .ch = "pqrs"},    
    { .key = 8, .number = 3, .ch = "tuv" },    
    { .key = 9, .number = 4, .ch = "wxyz"},    
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    int digit_len;
    int i,j, repeat;
    int count, total, round;
    char *ptr = digits;
    int  *index;
    char **ptr_1, *ptr_2, *pick;
    
    digit_len = strlen(digits);
    index = malloc(sizeof(int) * digit_len);
    i = count = 0;
    total = 1;
    while (i<digit_len) {
        j = *ptr - '0';
        if ((j>=2) && (j<=9)) {
            total = total * input[j].number;
            *(index+count) = j;
            count++;
        }
        i++;
        ptr++;
    }

    if (count == 0) {
        *returnSize = 0;
        return 0;
    }
    ptr_1 = malloc(total * sizeof(char*));
    for (i=0; i < total; i++) {
        *(ptr_1+i) = malloc(count+1);
        *(*(ptr_1+i)+count) = '\0';
    }
    repeat = total;
    
    for (j = 0; j < count; j ++) {
        repeat = repeat / input[index[j]].number; 
        for (i=0; i<total; i++) {
            pick = input[index[j]].ch;
            round = (i / repeat) ;
            *(*(ptr_1+i)+j) = *(pick + (round - (round/input[index[j]].number) * input[index[j]].number));            
        }
    }

    *returnSize = total ;
    return ptr_1;
    
}
