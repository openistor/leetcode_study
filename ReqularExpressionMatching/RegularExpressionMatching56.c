bool isMatch(char* s, char* p) {    
    
    if (*s == '\0') {
        if (((*p=='.') || ((*p >='a') && (*p <='z')) )&& (*(p+1)=='*')) 
            return isMatch(s,p+2);
        else if (*p == '\0')
            return 1;
        return 0;   
    }
        
    if (*p == '.') {
        if (*(p+1) =='*') {
            return (isMatch(s,p+2) || isMatch(s+1,p));
        } else {
            return isMatch(s+1,p+1);
        }
    } else if ((*p >='a') && (*p <='z')) {
        if (*(p+1) =='*') {
            if (*s == *p) {
                return (isMatch(s, p+2) || isMatch(s+1,p));
            } else {
                return isMatch(s, p+2);
            }
        } 
        
        if (*p == *s) {
            return isMatch(s+1,p+1);
        }      
        return 0;
    }
    return 0; 
}
