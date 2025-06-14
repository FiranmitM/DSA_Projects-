
class Solution {
public:
    void buildParentMap(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, parentMap); 

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == k) break;
            currentLevel++;
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && visited.find(current->left) == visited.end()) {
                    visited.insert(current->left);
                    q.push(current->left);
                }

                if (current->right && visited.find(current->right) == visited.end()) {
                    visited.insert(current->right);
                    q.push(current->right);
                }

                if (parentMap.find(current) != parentMap.end()) {
                    TreeNode* parent = parentMap[current];
                    if (visited.find(parent) == visited.end()) {
                        visited.insert(parent);
                        q.push(parent);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
