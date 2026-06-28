#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
        Algorithm Step by Step:
        1. Initialize variables: 
           - 'i' for traversing the string.
           - 'sign' to keep track of the number's sign (1 for positive, -1 for negative). Default is 1.
           - 'result' to store the accumulated integer value.
           - 'n' for the length of the string.
        2. Ignore Leading Whitespaces:
           - Iterate through the string while the character at index 'i' is a space (' '). Increment 'i'.
        3. Determine the Sign:
           - Check if the current character at 'i' is '-' or '+'.
           - If it's '-', set 'sign' to -1.
           - If it's '+' or '-', increment 'i' by 1 to move to the next character. 
           - Note: Only one sign character is processed.
        4. Convert Digits to Integer:
           - Loop while 'i' is within the string length and the character at 'i' is a digit ('0' to '9').
           - Before adding the new digit, check for integer overflow/underflow:
             - If 'result' is strictly greater than INT_MAX / 10, appending any digit will cause overflow.
             - If 'result' is equal to INT_MAX / 10, appending a digit greater than 7 (since INT_MAX ends in 7) will cause overflow.
             - In case of overflow, return INT_MAX if 'sign' is 1, else return INT_MIN.
           - Update 'result' by multiplying it by 10 and adding the integer value of the current digit (s[i] - '0').
           - Increment 'i'.
        5. Return Final Result:
           - Multiply 'result' by 'sign' to apply the appropriate sign and return it.
        */
        
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;
        
        // Step 2: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 3: Determine the sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 4: Convert digits to integer
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            // Check for overflow/underflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Step 5: Return final result
        return result * sign;
    }
};
