//Java Program to convert Infix Expression to Prefix
import java.util.Stack;

public class InfixToPrefix {
    public static void main(String[] args) {
        System.out.println("1+2+3 -> " + infix2Prefix("1+2+3"));
        System.out.println("A^B-(C+D) -> " + infix2Prefix("A^B-(C+D)"));
        System.out.println("(P/L+(F*J) -> " + infix2Prefix("(P/L+(F*J)"));
    }
    public static String infix2Prefix(String expression){
        if(!BalancedBrackets.isBalanced(expression)) return "Invalid Expression";
        Stack<Character> operatorStack = new Stack<>();
        StringBuilder prefixExpression = new StringBuilder();
        int n = expression.length();
        for(int i = n - 1 ; i >= 0 ; i--){
            char scanned = expression.charAt(i);
            if(Character.isLetterOrDigit(scanned)) prefixExpression.append(scanned);
            else if(scanned == ')') operatorStack.push(scanned);
            else if(scanned == '('){
                while(!operatorStack.isEmpty() && operatorStack.peek() != ')'){
                    prefixExpression.append(operatorStack.pop());
                }
                if(!operatorStack.isEmpty()) operatorStack.pop();
            }
            else if(operatorStack.isEmpty() || operatorStack.peek() == ')') operatorStack.push(scanned);
            else{
                while(!operatorStack.isEmpty() && precedence(operatorStack.peek()) < precedence(scanned)){
                    prefixExpression.append(operatorStack.pop());
                }
                operatorStack.push(scanned);
            }
        }
        while(!operatorStack.isEmpty()) prefixExpression.append(operatorStack.pop());
        return prefixExpression.reverse().toString();
    }
    static int precedence(char operator){
        if(operator == '^') return 3;
        if(operator == '*' || operator == '/') return 2;
        if(operator == '+' || operator == '-') return 1;
        return 0;
    }
}
