def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False

def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head
        check = 0
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                check = 1
                break
        if check == 0:
            return None
        while head!=slow:
            head = head.next
            slow = slow.next
        return head