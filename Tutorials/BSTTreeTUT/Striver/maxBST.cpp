class NodeValue {
public:
    int maxValue;  // size of largest BST in this subtree
    int minNode;   // minimum value in this subtree
    int maxNode;   // maximum value in this subtree

    NodeValue(int maxValue, int minNode, int maxNode) {
        this->maxValue = maxValue;
        this->minNode = minNode;
        this->maxNode = maxNode;
    }
};

class Solution {
private:
    NodeValue helper(Node *root) {
        if (root == NULL) {
            // Empty tree: size=0, min=+INF, max=-INF
            return NodeValue(0, INT_MAX, INT_MIN);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If current node is a valid BST root
        if (root->data > left.maxNode && root->data < right.minNode) {
            int currSize = left.maxValue + right.maxValue + 1;
            int smallest = min(root->data, left.minNode);
            int largest = max(root->data, right.maxNode);
            return NodeValue(currSize, smallest, largest);
        }

        // If invalid, return the size of the largest BST found so far
        return NodeValue(max(left.maxValue, right.maxValue), INT_MIN, INT_MAX);
    }

public:
    int largestBst(Node *root) {
        return helper(root).maxValue;
    }
};
