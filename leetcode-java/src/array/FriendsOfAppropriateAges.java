package array;

import java.lang.reflect.Array;
import java.util.Arrays;

public class FriendsOfAppropriateAges {
}

class Solution {
    public int numFriendRequests(int[] ages) {
        int ans = 0;
        int n = ages.length;
        Arrays.sort(ages);
        int left = 0, right = 0;
        for(int age: ages) {
            if(age < 15) {
                continue;
            }
            while (ages[left] <= 0.5 * age + 7) {
                ++left;
            }
            while(right + 1 < n && ages[right + 1] <= age) {
                ++right;
            }
            ans += right - left;
        }
        return ans;
    }
}