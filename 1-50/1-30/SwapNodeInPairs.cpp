
// Swap node in pairs
shared_ptr<ListNode> swapPairs(shared_ptr<ListNode> head) {
    if (!head || head->next == nullptr)
        return head;
    shared_ptr<ListNode> dummy = std::make_shared<ListNode>(1);
    dummy->next = head;
    shared_ptr<ListNode> prev = dummy, p0 = dummy->next, p1 = p0->next;
    while (p0 && p0->next) {
        p1 = p0->next;
        prev->next = p1;
        shared_ptr<ListNode> tmp = p1->next;
        p1->next = p0;
        p0->next = tmp;
        prev = p0;
        p0 = prev->next;
    }

    return dummy->next;
}


shared_ptr<ListNode> merge2lists(shared_ptr<ListNode> l1, shared_ptr<ListNode> l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    shared_ptr<ListNode> dummy = std::make_shared<ListNode>(1), pt = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            pt->next = l1;
            l1 = l1->next;
        } else {
            pt->next = l2;
            l2 = l2->next;
        }
        pt = pt->next;
    }
    pt->next = l1 ? l1 : l2;
    return dummy->next;
}

shared_ptr<ListNode> mergeKLists(vector<shared_ptr<ListNode>> &lists) {
    if (lists.empty()) return nullptr;

    shared_ptr<ListNode> mergedk = lists[0];

    for (int i = 1; i < lists.size(); ++i) {
        mergedk = merge2lists(mergedk, lists[i]);
    }
    return mergedk;
}
