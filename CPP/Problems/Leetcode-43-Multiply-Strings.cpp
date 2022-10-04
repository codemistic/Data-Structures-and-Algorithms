// https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = stoi(num1), n2 = stoi(num2);
        return to_string(n1*n2); 
    }
};