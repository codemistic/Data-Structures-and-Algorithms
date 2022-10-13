# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        dummy1 = dummy2 = head
        
        len_LL = 0
        
        while head:
            len_LL += 1
            head=head.next
        
        head = dummy1
        
        if n == len_LL:
            head = head.next
            return head
        
        target_length = 1
        
        while target_length < (len_LL-n):
            target_length += 1
            head = head.next
            
        
        if head:
            head.next = head.next.next
        
        return dummy1
