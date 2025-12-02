class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
            size++;
        }
        ListNode* newHead=head;
        for(int i=0;i<size/2;i++){
            auto currNode=st.top();
            st.pop();
            currNode->next=newHead->next;
            newHead->next=currNode;
            newHead=currNode->next;
        }
        newHead->next=NULL;
    }
};
