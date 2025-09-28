class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
            {
                dq.push_back(i);
            }
            
            
        }
        
         if(dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                int index = dq.front();
                int element = arr[index];
                ans.push_back(element);
            }
        
        for(int i=k;i<n;i++)
        {
            if(!dq.empty() && i-dq.front() >= k)
            {
                dq.pop_front();
            }
            
            int element = arr[i];
            if(element < 0)
            {
                dq.push_back(i);
            }
            
            if(dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                int index = dq.front();
                int element = arr[index];
                ans.push_back(element);
            }
            
        }
        
        return ans;
    }
};