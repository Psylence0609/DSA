def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            head = None
            return head
        slow = head
        fast = head
        while fast!=None:
            if fast.next != None:
                fast = fast.next.next
                if fast == None or fast.next == None:
                    slow.next = slow.next.next
                    break
                else:
                    slow = slow.next
                # print(slow.val)
                # print(fast.val)
        return head