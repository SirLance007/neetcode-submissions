class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        int position = count - n -1;
        temp = head;
        if(position < 0){
            return head->next;
        }
        for(int i = 0; i<position ; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
