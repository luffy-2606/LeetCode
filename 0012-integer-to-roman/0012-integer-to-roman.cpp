#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        for(int i = 0; i < 13; i++) 
        {  
            while(num >= values[i]) 
            {
                roman = roman + symbols[i];
                num = num - values[i];
            }
        }
        
        return roman;
    }
};