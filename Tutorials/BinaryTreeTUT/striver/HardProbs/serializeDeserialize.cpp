class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (!root) return "";

    queue<TreeNode*> q;
    q.push(root);
    string str = "";

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            str += "#,";
        } else {
            str += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return str;
}


    // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;

    stringstream ss(data); // Without stringstream → you only get single characters, can’t handle multi-digit or negative
    string val;
    getline(ss, val, ',');
    TreeNode* root = new TreeNode(stoi(val));// stoi works with string only not car
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (getline(ss, val, ',')) {
            if (val != "#") {
                TreeNode* left = new TreeNode(stoi(val));
                node->left = left;
                q.push(left);
            }
        }

        if (getline(ss, val, ',')) {
            if (val != "#") {
                TreeNode* right = new TreeNode(stoi(val));
                node->right = right;
                q.push(right);
            }
        }
    }
    return root;
   }
};
