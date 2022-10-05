//Program to check for Balanced Brackets in Java

import java.util.Stack;

public class BalancedBrackets {
    public static boolean isBalanced(String expression) {
        Stack<Character> bracketStack = new Stack<>();
        int n = expression.length();
        for(int i = 0 ; i < n ; i++){
            char bracket = expression.charAt(i);
            if(isNotB(bracket)) continue;
            if(isOpeningB(bracket)) bracketStack.push(bracket);
            else{
                if(!bracketStack.isEmpty() && validOpeningB(bracket) != bracketStack.peek()) return false;
                else bracketStack.pop();
            }
        }
        return bracketStack.isEmpty();
    }
    static boolean isNotB(char bracket){
        return !("(){}[]".contains(bracket + ""));
    }
    static boolean isOpeningB(char bracket){
        return "({[".contains(bracket + "");
    }
    static char validOpeningB(char bracket){
        if(bracket == ')') return '(';
        if(bracket == '}') return '{';
        if(bracket == ']') return '[';
        return '\0';
    }
}