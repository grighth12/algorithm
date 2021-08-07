/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addingNumber = 0;
        ListNode* answer = new ListNode();

        ListNode* oneP = l1;
        ListNode* twoP = l2;
        ListNode* nowP = answer;

        while(oneP->next != nullptr && twoP->next != nullptr){
            int sum = oneP->val + twoP->val + addingNumber;

            addingNumber = sum /10;
            nowP->val = sum %10;

            oneP = oneP->next;
            twoP = twoP->next;
            nowP->next = new ListNode();
            nowP = nowP->next;
        }

        int sum = oneP->val + twoP->val +addingNumber;
        addingNumber = sum /10;
        nowP->val = sum%10;

        // oneP 업데이트
        while(oneP->next != nullptr){
            oneP = oneP->next;
            nowP->next = new ListNode();
            nowP = nowP->next;

            int sum = oneP->val + addingNumber;
            addingNumber = sum / 10;
            nowP->val = sum%10;
        }
        if(addingNumber == 1){
            nowP->next = new ListNode(1);
        }


        // twoP 업데이트
        while(twoP->next != nullptr){
            twoP = twoP->next;
            nowP->next = new ListNode();
            nowP = nowP->next;

            int sum = twoP->val + addingNumber;
            addingNumber = sum / 10;
            nowP->val = sum%10;
        }

        if(addingNumber == 1){
            nowP->next = new ListNode(1);
        }
        return answer;
    }
};
