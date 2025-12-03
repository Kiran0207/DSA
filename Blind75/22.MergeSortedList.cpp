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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newLL=new ListNode(-1);
        ListNode* tempHead=newLL;
        while(list1!= NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                newLL->next=new ListNode(list1->val);
                list1=list1->next;
                newLL=newLL->next;
            }
            else 
            {
                newLL->next=new ListNode(list2->val);
                list2=list2->next;
                newLL=newLL->next;
            }
        }
        while(list1!=NULL)
        {
            newLL->next=new ListNode(list1->val);
            list1=list1->next;
            newLL=newLL->next;
        }
        while(list2!=NULL)
        {
            newLL->next=new ListNode(list2->val);
            list2=list2->next;
            newLL=newLL->next;
        }
        return tempHead->next;
    }
};
