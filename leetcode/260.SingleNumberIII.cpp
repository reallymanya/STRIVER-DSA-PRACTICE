vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long XORR = 0;
        for (int i = 0; i < n; i++) {
            XORR = XORR ^ nums[i];
        }
        int rightmost = (XORR & (XORR - 1)) ^ XORR;

        int XOR1 = 0;
        int XOR2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost)
                XOR1 = XOR1 ^ nums[i];
            else
                XOR2 = XOR2 ^ nums[i];
        }
        if (XOR1 < XOR2)
            return {XOR1, XOR2};

        return {XOR1, XOR2};
    }