Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
        ListNode *l3 = new ListNode(0); //decalre a list to store sum and traverse through 
        ListNode *head = l3; //store thr new list to the head, and head will point to 0 
        int carry=0;
        int sum=0;
        while(carry || l1 || l2) //instead of using and operator to check if bth l1 and l2 are present we do or and check if either are present and add their values if present or add zero. This way even if either list are shorter the remaning will be added or if there's a carry that'll be added 
        {
            sum = (carry + (l1? l1->val : 0) + (l2?l2->val:0)); //sum = carry + l1&l2 val if exists or else 0 if doesnt exist
            l3->next = new ListNode(sum%10); //store the right most val in the sum by %
            l3=l3->next;
            carry = sum/10; //store the carry in carry var
            if(l1) l1=l1->next; //now if l1 exist move to next 
            if(l2) l2=l2->next; //now if l2 exist move to next 
        }
        return head->next; //return head->next as it points to l3's first node wiht value stored
    }
};


//------------java
/**
Time complexity : O(\max(m, n))O(max(m,n)). Assume that mm and nn represents the length of l1l1
 and l2l2 respectively, the algorithm above iterates at most \max(m, n)max(m,n) times.

Space complexity : O(\max(m, n))O(max(m,n)). The length of the new list is at most
 \max(m,n) + 1max(m,n)+1.
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode(0);
        ListNode head = l3;
        int sum=0,carry=0;
        while(l1!=null || l2!=null || carry!=0){
            sum = (carry + (l1!=null ?l1.val:0) + (l2!=null ?l2.val:0));
            l3.next = new ListNode(sum%10);
            l3=l3.next;
            carry = sum/10;
            if(l1!=null) l1=l1.next;
            if(l2!=null) l2=l2.next;
        }
        return head.next;
    }
}