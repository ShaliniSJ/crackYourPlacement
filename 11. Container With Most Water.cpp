// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l=0;
        int r = n-1;
        int maxi = 0;
        while(r > l){
            int len = min(h[l],h[r]);
            len = len*(r - l );
            maxi = max(len, maxi);
            if(h[l] <= h[r] && l < r)l++;
            else r--;
            if(l >= r){
                break;
            } 
        }
        return maxi;
    }
};