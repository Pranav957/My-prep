// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<bits/stdc++.h>
void helper(BinaryTreeNode<int> *node, int depth, int parent, unordered_map<int, pair<int, int>> &m) {
  if (!node)
    return;
  m[node->data] = {depth, parent};
  helper(node->left, depth + 1, node->data, m);
  helper(node->right, depth + 1, node->data, m);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    unordered_map<int, pair<int, int>> m;
    helper(root, 0, -1, m);
    return m[p].first == m[q].first && m[p].second != m[q].second;
}
