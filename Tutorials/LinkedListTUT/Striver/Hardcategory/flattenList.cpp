//BruteForce is to store the all elements in array and then sort array and create new list 

class Solution {
  public:
    Node* helper(Node* head1, Node* head2)
    {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
         
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->data < head2->data)
            {
                res->bottom = head1;
                res = head1;
                head1 = head1->bottom;   
            }
            else
            {
                res->bottom = head2;
                res = head2;
                head2 = head2->bottom;  
            }
        }
         
        if(head1) res->bottom = head1;
        else res->bottom = head2;
         
        return dummyNode->bottom;
    }
    
    Node* flatten(Node* root) {
        if(root == NULL || root->next == NULL)
            return root;
         
        // Flatten the list on the right
        Node* mergeRoot = flatten(root->next);
        
        // Merge current list with the right one
        return helper(root, mergeRoot);
    }
};
