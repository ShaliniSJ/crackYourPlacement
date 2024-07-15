// https://leetcode.com/problems/create-binary-tree-from-descriptions/

class Solution {
public:

    void create_bt(TreeNode* parent,unordered_map<int,pair<int,int>>& mp){
        if(!parent)return ;
        if(mp[parent->val].first)parent->left = new TreeNode(mp[parent->val].first);
        if(mp[parent->val].second)parent->right = new TreeNode(mp[parent->val].second);
        create_bt(parent->left,mp);
        create_bt(parent->right,mp);
    }

    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        // construct adjacent 
        int n = d.size();
        unordered_map<int,pair<int,int>>mp;
        unordered_set<int>st;
        for(int i=0;i<d.size();i++){
            if(d[i][2]) mp[d[i][0]].first = d[i][1];
            else mp[d[i][0]].second = d[i][1];
            st.insert(d[i][0]);
            st.insert(d[i][1]);
        }
        TreeNode* parent = new TreeNode(0);
        for(int i=0;i<n;i++){
            st.erase(d[i][1]);
        }
        parent->val = *st.begin();
        create_bt(parent,mp);
        return parent;
    }
};