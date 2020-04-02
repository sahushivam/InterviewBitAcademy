struct compare { 
    bool operator()(struct ListNode* a, struct ListNode* b) 
    { 
        return a->val > b->val; 
    } 
}; 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    struct ListNode* head = NULL, *last;
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for(int i=0;i<A.size();i++) pq.push(A[i]);
    while (!pq.empty()) { 
        struct ListNode* top = pq.top(); 
        pq.pop();
        if (top->next != NULL)  //next will also be a containder
        	pq.push(top->next); 
        if (head == NULL) { 
            head = top; 
            last = top; 
        } 
        else { 
            last->next = top; 
            last = top; 
        } 
    } 
    return head; 
}