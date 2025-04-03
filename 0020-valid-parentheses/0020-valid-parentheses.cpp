class Solution {
public:
    bool isValid(string s) {
        bool* arr = new bool[s.length()](); // Initialize all to false

        for (int i = 0; i < s.length(); i++) {
            if (!arr[i]) {
                char cur = s[i];
                if (cur == ')' || cur == '}' || cur == ']') { // Unmatched closing
                    delete[] arr;
                    return false;
                }

                char find;
                if (cur == '(') find = ')';
                else if (cur == '{') find = '}';
                else if (cur == '[') find = ']';
                else { // Invalid character
                    delete[] arr;
                    return false;
                }

                bool found = false;
                int open = 1; // Track nested brackets
                for (int j = i + 1; j < s.length(); j++) {
                    if (!arr[j]) {
                        if (s[j] == cur) open++; // Nested opening
                        else if (s[j] == find) open--; // Nested closing

                        if (open == 0) { // Found matching closing bracket
                            // Check if brackets between i and j are balanced
                            int temp_open = 0;
                            bool balanced = true;
                            for (int k = i + 1; k < j; k++) {
                                if (!arr[k]) {
                                    if (s[k] == '(' || s[k] == '{' || s[k] == '[') temp_open++;
                                    else temp_open--;
                                    if (temp_open < 0) { // Unmatched closing inside
                                        balanced = false;
                                        break;
                                    }
                                }
                            }
                            if (balanced && temp_open == 0) {
                                arr[i] = true;
                                arr[j] = true;
                                found = true;
                                break;
                            }
                        }
                    }
                }
                if (!found) {
                    delete[] arr;
                    return false;
                }
            }
        }

        // Final check for unmatched brackets
        for (int i = 0; i < s.length(); i++) {
            if (!arr[i]) {
                delete[] arr;
                return false;
            }
        }
        delete[] arr;
        return true;
    }
};