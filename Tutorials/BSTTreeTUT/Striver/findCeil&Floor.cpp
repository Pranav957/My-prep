class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        while(root)
        {
            if(root->data==x)
            {
                ceil=root->data;
                return ceil;
            }
            
            if(x>root->data)
             root=root->right;
            else
            {
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
    }
};
****************************************************************
int findCeil(Node* root, int x) {
    if (!root) return -1;

    if (root->data == x) {
        return root->data;
    }

    if (root->data < x) {
        // ceil must be in the right subtree
        return findCeil(root->right, x);
    }

    // root->data > x → candidate ceil
    int ceil = findCeil(root->left, x);
    return (ceil >= x) ? ceil : root->data;
}
**********************************************flooR*****************************************
  class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int floor=-1;
        while(root)
        {
            if(root->data==x)
            {
                 floor=root->data;
                 return floor;
            }
             
             if(root->data<x)
              {
                  floor=root->data;
                 root=root->right;
              }
             else
              root=root->left;
        }
        
        return floor;
    }
};
