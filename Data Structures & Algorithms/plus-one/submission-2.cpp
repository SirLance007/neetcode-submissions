class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // Reset current digit to 0 and continue the carry-over process
        }
        // If all digits were 9, we need an extra digit at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
