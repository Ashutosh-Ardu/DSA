//
class Solution
{
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int> res;
        int mn = min(x,y);
        int mx = max(x,y);
        
        while(root){
            if(root->data < mn){
                res.push_back(root->data);
                root = root->right;
            }
            else if(root->data > mx){
                res.push_back(root->data);
                root = root->left;
            }
            else{
                res.push_back(root->data);
                if(k > res.size()) return -1;
                return res[res.size()-k];
            }
        }
        return -1;
    }
};
