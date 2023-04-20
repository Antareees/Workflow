#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


bool isOperator(char sym) {
    if (sym == '+' || sym == '-' || sym == '*' || sym == '/') {
        return true;
    }
    else {
        return false;
    }
}

int getPriority(char sym) {
    if (sym == '+' || sym == '-')
        return 1;
    else if (sym == '*' || sym == '/')
        return 2;
    else
        return 0;
}

string infixToPrefix(stack<char> stack, string infix) {
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((stack.top() != '(') && (!stack.empty())) {
                prefix += stack.top();
                stack.pop();
            }

            if (stack.top() == '(') {
                stack.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (stack.empty()) {
                stack.push(infix[i]);
            }
            else {
                if (getPriority(infix[i]) > getPriority(stack.top())) {
                    stack.push(infix[i]);
                }
                else if (getPriority(infix[i]) == getPriority(stack.top())) {
                    stack.push(infix[i]);
                }
                else {
                    while ((!stack.empty()) && (getPriority(infix[i]) < getPriority(stack.top()))) {
                        prefix += stack.top();
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
            }
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string infix, prefix;
    cout << "Введите математическое выражение: ";
    cin >> infix;
    stack<char> stack;

    prefix = infixToPrefix(stack, infix);
    cout << "Префиксная форма: " << prefix << endl;

    return 0;
}
//  5+(3+(2+4*(3-1)+2)/4+1)*4 
