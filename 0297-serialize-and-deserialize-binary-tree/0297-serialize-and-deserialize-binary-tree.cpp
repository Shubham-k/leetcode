/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        string str;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
                str += to_string(curr->val);
            } else {
                str += "#";
            }
            str += ',';
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // For left node
            getline(ss, str, ',');
            if (str == "#") {
                curr->left = NULL;
            } else {
                TreeNode* root = new TreeNode(stoi(str));
                curr->left = root;
                q.push(root);
            }

            // For right node
            getline(ss, str, ',');
            if (str == "#") {
                curr->right = NULL;
            } else {
                TreeNode* root = new TreeNode(stoi(str));
                curr->right = root;
                q.push(root);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));