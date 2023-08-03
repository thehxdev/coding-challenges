#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int power(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++)
        res *= x;

    return res;
}


int convert_to_int(struct ListNode *l) {
    struct ListNode *tmp = l;
    int decimal_num = 0;
    int current_idx = 0;

    while (1) {
        decimal_num += tmp->val * (power(10, current_idx));
        current_idx += 1;

        if (tmp->next == NULL)
            break;

        tmp = tmp->next;
    }

    return decimal_num;
}


struct ListNode *convert_to_list(int *num) {
    struct ListNode *head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *tmp = head;
    int x = 0;

    int i = 1;
    while (1) {
        struct ListNode *n = (struct ListNode*) malloc(sizeof(struct ListNode));

        x = (int)((*num % (power(10, i)) / power(10, i - 1)));
        //n->val = x;
        //n->next = NULL;

        tmp->val = x;
        tmp->next = n;

        if (*num % (power(10, i)) == *num) {
            tmp->next = NULL;
            break;
        }

        i += 1;
        tmp = n;
    }

    return head;
}

