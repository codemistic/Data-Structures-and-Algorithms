class Solution {
    public int romanToInt(String s) {
        int len = s.length();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            int cur = getValue(ch);
            if (i < len - 1 && cur < getValue(s.charAt(i + 1))) {
                ans -= cur;
            } else {
                ans += cur;
            }
        }

        return ans;
    }

    private int getValue(char ch) {
        int ans = 0;
        switch (ch) {
            case 'I':
                ans = 1;
                break;

            case 'V':
                ans = 5;
                break;

            case 'X':
                ans = 10;
                break;

            case 'L':
                ans = 50;
                break;

            case 'C':
                ans = 100;
                break;

            case 'D':
                ans = 500;
                break;

            case 'M':
                ans = 1000;
                break;

            default:
                break;
        }

        return ans;
    }
}