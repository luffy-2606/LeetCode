class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false; 

        int digits = 0;
        int temp = x;

        while (temp > 0) 
        {
            digits++;
            temp = temp / 10;
        }

        temp = x;
        int* arr = new int[digits];

        for (int k = 0; k < digits; k++) 
        {
            arr[k] = temp % 10;
            temp = temp / 10;
        }

        for (int i = 0, j = digits - 1; i < j; i++, j--) 
        {
            if (arr[i] != arr[j]) 
            {
                delete[] arr; 
                return false;
            }
        }

        delete[] arr;
        return true;
    }
};
