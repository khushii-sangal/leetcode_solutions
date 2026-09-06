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
 /*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0,mid=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        mid=(count/2);
        temp=head;
        for(int i=0;i<mid;i++)
        temp=temp->next;

        return temp;
    }
    
};
*/

// optimised approach slow and fast 

class Solution
{
    public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }
};