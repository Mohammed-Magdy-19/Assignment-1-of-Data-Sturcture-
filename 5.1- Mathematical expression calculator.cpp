#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Stack {

    int top;
    int size;
    int* newstack;

public:
    Stack(int s) {
        this->size = s;
        newstack = new int[this->size];
        top = -1;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return top == size - 1;
    }
    void push(int n) {
        if (isFull()) {
            cout << "stack overFlow";
            return;
        }
        top++;
        newstack[top] = n;

    }
    int pop() {
        if (isEmpty()) {
            cout << "stack underFlow doesn’t contain any number";
            return -1;
        }
        int x = newstack[top];
        top--;
        return x;
    }
    void print() {
        if (isEmpty()) {
            cout << "stack underFlow doesn’t contain any number";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << newstack[i];
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "stack is empty";
            return -1;
        }
        return newstack[top];
    }
    ~Stack() {
        delete[]newstack;
    }
    //Q1 Function 
    void calculator() {

        int result = 0;
        int sign = 1;
        int num = 0;

        string s;

        cout << "enter equation" << endl;
        getline(cin, s);

        Stack st(s.length());

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ' || s[i] == '"')
                continue;

            else if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            else if (s[i] == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            else if (s[i] == '(') {

                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {

                result += sign * num;
                num = 0;

                int prevSign = st.pop();
                int prevResult = st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;

        cout << "result = " << result << endl;
    }

};
int main() {

    cout << "Mathematical expression calculator\n" << endl;
    Stack s(100);
    s.calculator();

    return 0;
}
