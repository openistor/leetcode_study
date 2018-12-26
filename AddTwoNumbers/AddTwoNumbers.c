/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *R_head, *R_last;
    int overflow = 0;
    
    R_last = NULL;
    R_head = NULL;
    while (l1 || l2) {
        if (R_last) {
            R_last->next = malloc(sizeof(struct ListNode));
            R_last = R_last->next;
        } else {
            R_last = malloc(sizeof(struct ListNode));
        }
        R_last->next = NULL;
        
        if (!R_head)
            R_head = R_last;
        R_last->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + overflow;
        overflow = 0;
        if (R_last->val >= 10) {
            R_last->val = R_last->val - 10;
            overflow = 1;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (overflow) {
        R_last->next = malloc(sizeof(struct ListNode));
        R_last = R_last->next;
        R_last->val = 1;
        R_last->next = NULL;
    }
        
    
    return R_head;
}
