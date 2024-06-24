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
for (char ch : infix) {
if (isalnum(ch)) { // Operand
postfix += ch;
} else if (ch == '(') {
s.push(ch);
} else if (ch == ')') {
while (!s.empty() && s.top() != '(') {
postfix += s.top();
s.pop();
}
s.pop(); // Discard '('
} else { // Operator
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
    string expressions[] = {
        "a + b"
    };

    for (const string& infix : expressions) {
        string postfix = infixToPostfix(infix);
        cout << "Infix: " << infix << ", Postfix: " << postfix << endl;
    }

    return 0;
}
