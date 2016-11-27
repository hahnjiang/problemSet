#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* carry(ListNode* l, int p) {
        ListNode* head = l;
        while (l != NULL) {
            l->val += p;
            p = l->val / 10;
            l->val %= 10;
            if (l->next == NULL && p != 0) {
                l->next = new ListNode(p);
                p = 0;
            }
            l = l->next;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *p1 = NULL, *p2 = NULL;
        int p = 0;
        while (l1 != NULL && l2 != NULL) {
            p = l1->val + l2->val + p;
            l1->val = p % 10;
            p = p / 10;

            p1 = l1;
            p2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 == NULL && p != 0) {
            p1->next = new ListNode(p);
        }
        if (l1 == NULL && l2 != NULL) {
            l2 = carry(l2, p);
            if (p1 == NULL) {
                l1 = l2;
                head = l1;
            } else {
                p1->next = l2;
            }
        }
        if (l2 == NULL && l1 != NULL) {
            l1 = carry(l1, p);
        }
        return head;
    }
};

int main() {}
