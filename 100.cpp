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

/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
  void in(Node* root,vector<int>&inorder)
  {
      if(root==nullptr)return;
      in(root->left,inorder);
      inorder.push_back(root->data);
      in(root->right,inorder);
  }
  Node* inordertoBST(int s ,int e,vector<int>&inorder)
  {
      if(s>e)return nullptr;
      int mid=(s+e)/2;
      Node* ans=new Node(inorder[mid]);
      ans->left=inordertoBST(s,mid-1,inorder);
      ans->right=inordertoBST(mid+1,e,inorder);
      return ans;
  }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> inorder;
        in(root,inorder);
        return inordertoBST(0,inorder.size()-1,inorder);
        
    }
};
class Solution {
  public:
  int signum(int a,int b)
  {
      if(a==b)
      {
          return 0;
      }
      if(a<b)
      {
          return 1;
      }
      if(a>b)
      {
          return -1;
      }
  }
  void medianFinder(int element, priority_queue<double>&maxheap,
                    priority_queue<double,vector<double>,greater<double>>&minheap,double &median)
  {
      switch(signum(minheap.size(),maxheap.size()))
      {
          case 0:if(element>median)
                  {
                      minheap.push(element);
                      median=minheap.top();
                  }
                  else
                  {
                      maxheap.push(element);
                      median=maxheap.top();
                  }
                  break;
          case 1:if(element>median)
                  {
                     minheap.push(element);
                     median=(minheap.top()+maxheap.top())/2;
                  }
                  else
                  {
                      minheap.push(maxheap.top());
                      maxheap.pop();
                      maxheap.push(element);
                      median=(minheap.top()+maxheap.top())/2;
                  }
                  break;
          case -1:if(element>median)
                  {
                     maxheap.push(minheap.top());
                     minheap.pop();
                     minheap.push(element);
                     median=(minheap.top()+maxheap.top())/2;
                  }
                  else
                  {
                      maxheap.push(element);
                      median=(minheap.top()+maxheap.top())/2;
                  }
                  break;
                  
                  
      }
  }
    vector<double> getMedian(vector<int> &arr) {
        vector<double>ans;
        priority_queue<double>maxheap;
        priority_queue<double,vector<double>,greater<double>>minheap;
        double median=0;
        for(int i=0;i<arr.size();i++)
        {
            medianFinder(arr[i],maxheap,minheap,median);
            ans.push_back(median);
            
        }
        return ans;
    }
};
