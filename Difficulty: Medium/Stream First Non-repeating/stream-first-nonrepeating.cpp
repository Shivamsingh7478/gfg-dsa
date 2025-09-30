class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char, int> freq;
        string result = "";
        queue<char> q;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            freq[ch]++;
            
            
            q.push(ch);
            
            while(!q.empty() && freq[q.front()] > 1)
            {
                
                    q.pop();
                
            }
            
            if(q.empty())
            {
                result.push_back('#');
            }
            else
            {
                result.push_back(q.front());
            }
        }
        
        return result;
        }
};