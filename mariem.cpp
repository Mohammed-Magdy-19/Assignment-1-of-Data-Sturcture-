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

};


// Qes2
int main() {
    string s;
    cout << "enter array like [1,2,3]:" << endl;
    getline(cin, s);

    vector<int> arr;
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

    vector <int > result(size, -1);
    Stack st(size);
    for (int i = 0; i < size; i++)
        result[i] = -1;

    for (int i = 0; i < size * 2; i++) {

        while (!st.isEmpty() && arr[st.peek()] < arr[i % size]) {
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
        if (i < size - 1) {
            cout << ",";
        }
    }
    cout << "]";

}