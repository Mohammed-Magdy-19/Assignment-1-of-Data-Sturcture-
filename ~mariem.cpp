#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Vector {
    int* data;
    int length;
    int capacity;
public:
    Vector() {
        capacity = 2;
        length = 0;
        data = new int[capacity];
    }
    void push_back(int v) {
        if (length == capacity) {
            capacity *= 2;
            int* Newdata = new int[capacity];
            for (int i = 0; i < length; i++) {
                Newdata[i] = data[i];

            }
            delete[]data;
            data = Newdata;
        }
        data[length++] = v;
    }
    int size() {
        return length;
    }
    int& operator [](int index) {
        if (index < 0 || index >= length) {
            cout << "Index not exist \n";
    
        }
        return data[index];
    }
    ~Vector() {
        delete[] data;
    }
};

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


    //Q2 Function 
    void nextGreaterElement() {

        string s;

        cout << "enter array like [1,2,3]:" << endl;
        getline(cin, s);

        Vector arr;

        int num = 0;
        bool building = false;

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {

                num = num * 10 + (s[i] - '0');
                building = true;
            }

            else {

                if (building) {
                    arr.push_back(num);
                    num = 0;
                    building = false;
                }
            }
        }

        int size = arr.size();

        Vector result;
        for (int i = 0; i < size; i++) {
            result.push_back(-1);
        }

        Stack st(size);

        for (int i = 0; i < size * 2; i++) {

            while (!st.isEmpty() &&
                arr[st.peek()] < arr[i % size]) {

                result[st.peek()] = arr[i % size];
                st.pop();
            }

            if (i < size) {
                st.push(i);
            }
        }

        cout << "result: [";

        for (int i = 0; i < size; i++) {

            cout << result[i];

            if (i < size - 1)
                cout << ",";
        }

        cout << "]" << endl;
    }

};
int main() {
    int choice;

    cout << "1- Calculator" << endl;
    cout << "2- Next Greater Element" << endl;

    cin >> choice;
    cin.ignore();

    Stack s(100);

    if (choice == 1)
        s.calculator();

    else if (choice == 2)
        s.nextGreaterElement();

}