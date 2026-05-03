// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>mini;
        for(int i=0;i<arr.size();i++)
        {
            int sum=0;
            for(int j=i;j<arr.size();j++)
            {
                sum=sum+arr[j];
                if(mini.size()<k)
                {
                    mini.push(sum);
                }
                else
                {
                    if(mini.top()<sum)
                    {
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }
};

class Solution {
  public:
  int search(vector<int>&inorder,int val)
  {
      for(int i=0;i<inorder.size();i++)
      {
          if(inorder[i]==val)
          {
              return i;
          }
      }
      return -1;
  }
  Node* helper(vector<int> &inorder, vector<int> &preorder,int &preidx,int left,int right)
  {
      if(left>right)return nullptr;
      Node* root=new Node(preorder[preidx]);
      int val=preorder[preidx];
      int index=search(inorder,val);
      preidx++;
      root->left=helper(inorder,preorder,preidx,left,index-1);
      root->right=helper(inorder,preorder,preidx,index+1,right);
      return root;
      
  }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int left=0;
        int right=inorder.size()-1;
        int preidx=0;
        Node* ans=helper(inorder,preorder,preidx,left,right);
        return ans;
        
    }
};