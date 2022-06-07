class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ans;
        vector<int> nums; // to store all the remaining numbers to choose from 
        
        // calculate initial factorial of n-1
        
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        
        // do k-- because we are doinng 0 based indexing
        
        k--;
        
        while(true){
            
            int idx=k/fact;  // index of number to choose
            ans=ans+to_string(nums[idx]); // added to answer
            if(ans.size()==n)
                return ans;
            
            // now remove chosen number from nums vector
            
            nums.erase(nums.begin()+idx);
            
            k=k%fact; // value of new k
            
            fact=fact/nums.size(); // new fact
            
            
        }
        
        
        return ans;
    }
};