#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        
        if (isalnum(ch)) { // Operand
            postfix += ch;
        } 
        else if (ch == '(') { // Opening parenthesis
            s.push(ch);
        } 
        else if (ch == ')') { // Closing parenthesis
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Discard '('
        } 
        else { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    
    cout << "Enter infix expression: ";
    getline(cin, infix);
    
    string postfix = infixToPostfix(infix);
    
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
