class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long num = 0;

        // Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i >= s.size()) {
            return 0;
        }

        // Check for sign
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Skip leading zeros
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        // Process digits to form the number
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            long long new_num = num * 10 + digit;

            // Check for overflow
            if (sign == 1 && new_num > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && new_num > static_cast<long long>(INT_MAX) + 1) {
                return INT_MIN;
            }

            num = new_num;
            i++;
        }

        // Apply the sign
        num *= sign;

        // Clamping to the 32-bit integer range
        if (num > INT_MAX) {
            return INT_MAX;
        } else if (num < INT_MIN) {
            return INT_MIN;
        }

        return static_cast<int>(num);
    }
    
};