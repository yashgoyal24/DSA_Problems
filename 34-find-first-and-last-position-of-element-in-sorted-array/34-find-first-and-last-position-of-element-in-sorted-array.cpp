class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
           vector<int> answer;
        int first_position=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first_position!=nums.size() && nums[first_position]==target){ 
        answer.push_back(first_position);
        }
        else{
            answer.push_back(-1);
        }
        int last_position=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        
        if(last_position>=0 && nums[last_position]==target){
              answer.push_back(last_position);
        }
        else{
            answer.push_back(-1);
    
        }
    
        return answer;
    }
};