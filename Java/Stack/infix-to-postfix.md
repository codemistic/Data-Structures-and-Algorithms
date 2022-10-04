# Infix Notation

Infix is the day to day notation that we use of format A + B type. The general form can be classified as (a op b) where a and b are operands(variables) and op is Operator.

# Postfix Notation

Postfix is notation that compiler uses/converts to while reading left to right and is of format AB+ type. The general form can be classified as (ab op) where a and b are operands(variables) and op is Operator.

## Code

``` 
import java.util.Stack;

public class InfixtoPostfix {
	public static void main(String[] args) {
		String exp = "a+b*(c^d-e)^(f+g*h)-i";
		System.out.println(infixToPostfix(exp));
	}
	public static int Precidense(char ch) {
		switch (ch){
      case '+':
      case '-':
			  return 1;
	
      case '*':
      case '/':
        return 2;

      case '^':
        return 3;
		}
		return -1;
	}
	
	public static String infixToPostfix(String exp) {
		String result = "";
		Stack<Character> stack = new Stack<>();
		
		for (char c:exp.toCharArray()) {
			if (Character.isLetterOrDigit(c))
				result += c;
			else if (c == '(')
				stack.push(c);
			else if (c == ')') {
				while (!stack.isEmpty() && stack.peek() != '(')
					result += stack.pop();
					stack.pop();
			}
			else {// an operator is encountered
				while (!stack.isEmpty() && Precidense(c) <= Precidense(stack.peek()))
					result += stack.pop();	
				stack.push(c);
			}
	
		}
		while (!stack.isEmpty()){
			if(stack.peek() == '(')
				return "Invalid Expression";
			result += stack.pop();
		}
		return result;
	}
}
```
