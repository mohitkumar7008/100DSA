// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> mini;
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
<<<<<<< HEAD
class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code here
        int s = 0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            mid = s+(e-s)/2;
            if(arr[mid]==key) return true;
            if(arr[s]==arr[mid] && arr[e]==arr[mid]){
                s++;
                e--;
                continue;
            }
            if(arr[s]<=arr[mid]){
                if(arr[s]<=key && arr[mid]>=key){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                if(arr[mid]<=key && arr[e]>=key){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return false;
    }
};
class Solution {
  public:
  void merge(vector<int>&arr,int &left,int &right, int &mid,vector<int>&temp)
  {
      int i=left;
      int j=mid+1;
      while(i<=mid&&j<=right)
      {
          if(arr[i]>arr[j])
          {
              temp.push_back(arr[j]);
              j++;
          }
          else
          {
              temp.push_back(arr[i]);
              i++;
          }
      }
      while(i<=mid)
      {
          temp.push_back(arr[i]);
          i++;
      }
      while(j<=right)
      {
          temp.push_back(arr[j]);
          j++;
      }
      for(int i=0;i<temp.size();i++)
      {
          arr[i+left]=temp[i];
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        vector<int>temp;
        merge(arr,l,r,mid,temp);
    }
};

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++)
            {
                map[nums[i]]++;
            }
     for(int i=0;i<nums.size();i++)
        {
            if(map[nums[i]]==1 && nums[i]%2==0)
                return nums[i];
        }

        return -1;
    }
};
=======
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int lv=temp.second.second;
            nodes[hd][lv].push_back(temp.first->data);
            if(temp.first->left)
            {
                q.push(make_pair(temp.first->left,make_pair(hd-1,lv+1)));
            }
            if(temp.first->right)
            {
                q.push(make_pair(temp.first->right,make_pair(hd+1,lv+1)));
            }
        }
        for(auto i : nodes)
        {
            vector<int> col;   // column vector
            for(auto j : i.second)
            {
                for(auto k : j.second)
                {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  void solve(Node* root,int sum,int &maxSum,int len,int &maxLen)
  {
      if(root==NULL)
      {
           if(len>maxLen)
          {
              maxLen=len;
              maxSum=sum;
          }
          else if (len==maxLen)
          {
              maxSum=max(sum,maxSum);
          }
         
          return;
      }
      sum=sum+root->data;
      solve(root->left,sum,maxSum,len+1,maxLen);
      solve(root->right,sum,maxSum,len+1,maxLen);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int sum=0;
        int len=0;
        int maxSum=0;
        int maxLen=0;
        solve(root,sum,maxSum,len,maxLen);
        
        return maxSum;
       
    }
};
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int l=0;
        int m=0;
        int h=arr.size()-1;
        while(m<=h)
        {
            if(arr[m]==0)
            {
                swap(arr[l],arr[m]);
                l++;
                m++;
            }
            else if(arr[m]==2)
            {
                swap(arr[m],arr[h]);
                h--;
            }
            else
            {
                m++;
            }
        }
    }
};
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return;
        
        grid[r][c] = 0;
        
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
            if(grid[i][n-1]==1){
                dfs(grid,i,n-1);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i);
            }
            if(grid[m-1][i]==1){
                dfs(grid,m-1,i);
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {dwwwwd
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> m;
        int rowStart=0;
        int colStart=0;
        int rowEnd=matrix.size()-1;
        int colEnd=matrix[0].size()-1;
        while(rowStart<=rowEnd&&colStart<=colEnd)
        {
            for(int i=colStart;i<=colEnd;i++)
            {
                m.push_back(matrix[colStart][i]);
            }
            rowStart++;
            if(rowStart>rowEnd)break;
            for(int i=rowStart;i<=rowEnd;i++)
            {
                m.push_back(matrix[i][colEnd]);
            }
            colEnd--;
             if(colStart>colEnd)break;
            for(int i=colEnd;i>=colStart;i--)
            {
                m.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
             if(rowStart>rowEnd)break;
            for(int i=rowEnd;i>=rowStart;i--)
            {
                m.push_back(matrix[i][colStart]);
            }
            colStart++;
             if(colStart>colEnd)break;        
        }
        return m;
    }  
    
};

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        vector<int>presum(arr.size(),0);
        int count=0;
        presum[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
          presum[i]=presum[i-1]+arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            if(presum[i]==k)
            {
                count++;
            }
            int val=presum[i]-k;
            if(mp.find(val)!=mp.end())fw
            {
                count+=mp[val];
            }ffv
            mp[presum[i]]++;
        }
        return count;
    }
};
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        
        int pivot=-1;
        int temp;
        int index;
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                pivot=i;
                break;
            }
        }
        if(pivot==-1)
        {
            reverse(arr.begin(),arr.end());
            return;
        }
        int mini;
        for(int i=arr.size()-1;i>pivot;i--)
        {
            if(arr[i]>arr[pivot])
            {
                swap(arr[i],arr[pivot]);
                break;
            }
        }
        
        int i=pivot+1;
        int j=arr.size()-1;
        while(i<=j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int resmax;
        int prefixSum=0;
        for(int i=0;i<arr.size();i++)
        {
            prefixSum+=arr[i];
            if(prefixSum==k)
            {
                resmax=i+1;
            }
            else if(mp.find(prefixSum-k)!=mp.end())
            {
                resmax=max(resmax,i-mp[prefixSum-k]);
            }
            if(mp.find(prefixSum)==mp.end())
            {
                mp[prefixSum]=i;
            }
        }
        return resmax;
    }
};
mohit kamboj
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int first=INT_MIN;
        int second=INT_MIN;
        int fc=0;
        int sc=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==first)
            {
                fc++;
            }
            else if(arr[i]==second)
            {
                sc++;
            }
            else if(fc==0)
            {
                first=arr[i];
                fc=1;
            }
            else if(sc==0)
            {
                second=arr[i];
                sc=1;
            }
            else
            {
                fc--;
                sc--;
            }
        }
        // if(fc==sc)
        // {
        //     return {fc};
        // }
        fc=0;
        sc=0;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
         if(first==arr[i])fc++;
         else if(second==arr[i])sc++;
        }
        if(fc>arr.size()/3)ans.push_back(first);
        if(sc>arr.size()/3)ans.push_back(second);
         
         sort(ans.begin(),ans.end());
         return ans;
    }
};gjggiu
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        { if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int p=j+1;
                int q=n-1;
                while(p<q)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[p]+nums[q];
                    if(sum>target)
                    {
                        q--;
                    }
                    else if(sum<target)
                    {
                        p++;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                        q--;
                        while(p<q&&nums[p]==nums[p-1])
                        {
                            p++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            // if(i>0&&arr[i]==arr[i-1])continue;
            int j=i+1;
            int k=arr.size()-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target)
                {
                    k--;
                }
                else if(sum<target)
                {
                    j++;
                }
                else
                {
                    return true;
                }
                // while(j<k&&arr[j-1]==arr[j])
                // {
                //     j++;
                // }
            }
        }
        return false;
    }
};
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        
        vector<int>ans;
        if(n==0)return {};
        ans.push_back(1);
        if(n==1)return ans;
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<ans.size();j++)
            {
                temp.push_back(ans[j-1]+ans[j]);
            }
            temp.push_back(1);
            ans=temp;
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int bestBuy=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>bestBuy)
            {
                maxProfit=max(maxProfit,prices[i]-bestBuy);
            }
            bestBuy=min(prices[i],bestBuy);
        }
        return maxProfit;
    }
};
class Solution {
  public:
  int merge(vector<int>&arr,int st,int mid,int end)
  {
      int i=st;
      int j=mid+1;
      vector<int>temp;
      int count=0;
      while(i<=mid&&j<=end)
      {
          if(arr[i]<=arr[j])
          {
              temp.push_back(arr[i]);
              i++;
          }
          else
          {
              temp.push_back(arr[j]);
              j++;
              count=count+mid+1-i;
          }
      }
      while(i<=mid)
      {
          temp.push_back(arr[i]); i++;
          
      }
      while(j<=end)
      {
          temp.push_back(arr[j]);
          j++;
      }
      for(int i=0;i<temp.size();i++)
      {
          arr[i+st]=temp[i];
      }
      return count;
  }
  int mergesort(vector<int>&arr,int st,int end)
  {
      if(st<end)
      {
          int mid=st+(end-st)/2;
          int leftinversion=mergesort(arr,st,mid);
          int rightinversion=mergesort(arr,mid+1,end);;
          int countinversion=merge(arr,st,mid,end);
          return countinversion+leftinversion+rightinversion;
          
      }
      return 0;
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergesort(arr,0,arr.size()-1);
    }
};qwd
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        if(arr.size()==1)
        {
            return arr;
        }
        sort(arr.begin(),arr.end());
            vector<vector<int>>ans;
            ans.push_back(arr[0]);
            for(int i=1;i<arr.size();i++)
            {
                if(arr[i][0]<=ans.back()[1])
                {
                    ans.back()[1]=max(ans.back()[1],arr[i][1]);
                }
                else
                {
                    ans.push_back(arr[i]);
                }
            }
    return ans;
    }
};
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int gap=(a.size()+b.size()+1)/2;
        int m=b.size();
        while(gap>0)
        {
            int i=0;
            int j=gap;
            while(j<n+m)
            {
                if(j<n&&a[i]>a[j])
                {
                    swap(a[i],a[j]);
                }
                else if(i<n&&j>=n&&a[i]>b[j-n])
                {
                    swap(a[i],b[j-n]);
                }
                else if(i>=n &&b[i-n]>b[j-n])
                {
                    swap(b[i-n],b[j-n]);
                }
            i++;
            j++;
            }
            if(gap==1)break;
            gap=(gap+1)/2;
        }
    }
};




class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            } 
            else {
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                count++;
            }
        }

        return count;
    }
};
class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d=d%arr.size();
        int e=arr.size()-d;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+e);
        reverse(arr.begin()+e,arr.end());
    }
};

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        vector<int>ans;
        int top=0;
        int bottom=mat.size()-1;
        int left=0;
        int right=mat[0].size()-1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=bottom)
            for(int i=right;i>=left;i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            if(left<=right)
            for(int i=bottom;i>=top;i-- )
            {
                ans.push_back(mat[i][left]);
            }
            left++;
            
        }
        return ans;
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<endl;
        // }
        // return {};
    }
};hhh