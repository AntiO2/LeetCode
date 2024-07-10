#include <vector>
using namespace std;
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long ans = 0;
        int len = nums.size();
        int l = 0;
        while(l < len - 1) {
            if(nums[l] >= nums[l+1]) {
                break;
            }
            l++;
        }
        if(l==len-1) {
            return 1LL * len * (len + 1) /2;
        }
        // del: [0, N], [1,N]...[l,N], [l+1,N]
        ans += l + 2;

        for(int r = len - 1;;) {
            while(l >= 0 &&nums[r] <= nums[l]) {
                --l;
            }
            ans += l + 2;
            --r;
            if(nums[r] >= nums[r+1]) {
                break;
            }
        }
        return ans;
    }
};