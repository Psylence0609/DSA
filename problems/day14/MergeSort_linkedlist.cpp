// Very Important

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void push(node **head, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void Split(node *source, node **front, node **back)
{
    node *fast;
    node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL; // Very important step to break the list
}
node *SortedMerge(node *a, node *b)
{
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    node *ans = NULL;

    if (a->data <= b->data)
    {
        ans = a;
        ans->next = SortedMerge(a->next, b);
    }
    else
    {
        ans = b;
        ans->next = SortedMerge(a, b->next);
    }
    return ans;
}
void MergeSort(node **head)
{
    node *head_temp = *head;
    node *a;
    node *b;

    if (head_temp == NULL || head_temp->next == NULL)
        return;

    Split(head_temp, &a, &b);

    MergeSort(&a);
    MergeSort(&b);
    *head = SortedMerge(a, b);
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = NULL;

    push(&head, 7);
    push(&head, 10);
    push(&head, 3);
    push(&head, 8);
    push(&head, 4);
    push(&head, 5);

    MergeSort(&head);
    cout << "Sorted List is\n";
    printList(head);
}