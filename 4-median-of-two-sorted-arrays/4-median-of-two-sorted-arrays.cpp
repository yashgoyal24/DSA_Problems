class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(auto it:nums2)
            nums1.push_back(it);
        sort(nums1.begin(),nums1.end());
        
        // find median now from nums1
        
        int mid=(0+nums1.size()-1)/2;
        if(nums1.size()%2==0) // even
            return (double)(nums1[mid]+nums1[mid+1])/2.0;
        return nums1[mid];
        
    }
};