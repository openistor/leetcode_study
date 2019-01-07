bool isMatch(char* s, char* p);

bool isMatch_star(char *s, char *p) {
    char *src, *tmp;
    bool ret = 0;

    src = s;
    
    if (*p == '.') {
        while ((*src>='a') && (*src <='z')) {
            src++;
            ret = isMatch(src, p+2);
    
            if (ret)
                return 1;
        }
        return isMatch(src, p+2);
    }
    
    tmp = src;
    if (*p == *tmp) {
        while (*p == *tmp) {
            tmp++;
            ret = isMatch(tmp, p+2);
    
            if (ret)
                return 1;
        }
    
        ret = isMatch(tmp, p+2);
    
        if (ret)
            return 1;
    }

    return isMatch(src, p+2);
}


bool isMatch(char* s, char* p) {    
    char *pat, *src;
    bool ret;
    
    pat = p;
    src = s;
    
    if ((*pat == '\0') && (*src =='\0'))
        return 1;
    
    if ((*pat>='a') && (*pat <='z')) {
        if (*(pat+1) == '*') {
            ret = isMatch_star(src, pat);
            if (!ret)
                return isMatch(src, pat+2);
            else
                return 1;
        }
        
        if (*src == *pat) 
            return isMatch(src+1, pat+1);
    }


    if (*pat == '.') {
        if (*(pat+1) == '*') {
            ret = isMatch_star(src, pat);
            if (!ret)
                return isMatch(src, pat+2);
            else
                return 1;
        }
        
        pat++;
        if ((*src>='a') && (*src <='z')) {
            src++;
            return isMatch(src,pat);
        }
        return 0;
    }
    
    
    return 0;
}
