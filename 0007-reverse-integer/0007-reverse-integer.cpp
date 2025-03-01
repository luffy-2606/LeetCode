class Solution {
public:
    int reverse(int x) {
        int temp =x, newNum=0, val;

        for(int i=0; temp!=0; i++)
        {
            val = (temp%10);
            temp = temp/10;
            if (newNum > INT_MAX / 10 || (newNum == INT_MAX / 10 && val > 7))
                return 0;
            if (newNum < INT_MIN / 10 || (newNum == INT_MIN / 10 && val < -8))
                return 0;
            newNum = newNum * 10 + val;
        }


        return newNum;
        
        
        
    }
};