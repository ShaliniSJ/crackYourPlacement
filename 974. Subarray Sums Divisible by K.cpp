// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // when modulo using python it does not produce -ve reminder correctly 
        // infact negative reminder are not possible and not allowed
        // but c++ alows -ve reminders hence must add else statement
        // example tc
        // nums : [-1,2,9] k = 2
        unordered_map<int,int>rem;
        rem[0] = 1;
        int sum = 0;
        int res = 0;
        for(auto x:nums){
            sum += x;
            int diff = sum % k;
            if(diff < 0) diff += k;
            res += rem[diff];
            rem[diff]++;
        }
        return res;
    }
};