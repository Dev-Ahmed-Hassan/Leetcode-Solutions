// Yeah!! my best one so far... Damn!!
// You just find the target from the binary search!
// Then check for other values on left or right depending on left-most or right-most

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result (2,-1);
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        int leftidx = -1, rightidx = -1;
        // left most
        while(start <= end)
        {
            if(nums[mid] == target)
            {
                leftidx = mid;
                end = mid-1;
                mid = start + (end-start)/2;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
                mid = start + (end-start)/2;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
                mid = start + (end-start)/2;
            }
        }
        result[0] = leftidx;
        

        // right most
        start = 0; end = nums.size()-1; mid = start + (end-start)/2;
        while(start <= end)
        {
            if(nums[mid] == target)
            {
                rightidx = mid;
                start = mid+1;
                mid = start + (end-start)/2;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
                mid = start + (end-start)/2;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
                mid = start + (end-start)/2;
            }
        }
        result[1] = rightidx;
        
        return result;
        
    }
};