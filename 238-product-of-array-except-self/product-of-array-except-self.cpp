class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> products(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            products[i + 1] = products[i] * nums[i];
        }
        int product = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            products[i] *= product;
            product *= nums[i];
        }
        return products;
    }
};