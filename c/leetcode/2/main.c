#include <stdio.h>
#include "p2.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);


int main(void) {
    /* first linked list */
    struct ListNode n1, n2, n3, n4, n5, n6, n7, n8;
    n1.val = 9;
    n2.val = 9;
    n3.val = 9;
    n4.val = 9;
    n5.val = 9;
    n6.val = 9;
    n7.val = 9;
    n8.val = 9;
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = NULL;

    /* second linked list */
    struct ListNode m1, m2, m3, m4;
    m1.val = 9;
    m2.val = 9;
    m3.val = 9;
    m4.val = 9;
    
    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = NULL;


    struct ListNode *l = addTwoNumbers(&n1, &m1);
    struct ListNode *tmp = l;

    while (1) {
        printf("%d\n", tmp->val);
        if (tmp->next == NULL)
            break;
        tmp = tmp->next;
    }

    return 0;
}

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    int l1_num = convert_to_int(l1);
//    int l2_num = convert_to_int(l2);
//
//    int sum = l1_num + l2_num;
//
//    int p = 1;
//    while (1) {
//        int current_num = sum % power(10, p);
//
//        if (current_num == sum)
//            break;
//
//        p += 1;
//    }
//
//    struct ListNode *l = convert_to_list(&sum);
//    return l;
//}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *resultList = (struct ListNode*) malloc(sizeof(struct ListNode));


    return resultList;
}

