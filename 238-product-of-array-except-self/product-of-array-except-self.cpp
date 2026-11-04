class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zeros = 0, firstZeroIdx = -1;
        vector<int> products(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            products[i + 1] = products[i] * nums[i];
            if (nums[i] == 0) {
                zeros++;
                if (firstZeroIdx == -1) {
                    firstZeroIdx = i;
                }
            }
        }
        if (nums[n - 1] == 0) {
            zeros++;
            firstZeroIdx = firstZeroIdx == -1 ? n - 1 : firstZeroIdx;
        }
        if (zeros >= 2) {
            return vector<int>(n, 0);
        }
        if (zeros == 1) {
            vector<int> vec(n, 0);
            vec[firstZeroIdx] = products[firstZeroIdx];
            for (int i = firstZeroIdx + 1; i < n; ++i) {
                vec[firstZeroIdx] *= nums[i];
            }
            return vec;
        }
        int product = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            products[i] *= product;
            product *= nums[i];
        }
        return products;
    }
};