/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/


ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            ListNode *curr = *list;
            //watch the pointer here whereas the
            //does not have the pointer.
            *list = (*list)->next;
            free(cur);
        }
        else
        {
            //this is like list = &(head->next);
            list = &(*list)->next;
        }
    }

    return head;
}