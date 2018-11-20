#include <iostream>
#include <string>
using namespace std;

class Stack {
    char stk[50];
    int top;

    public:
    Stack() {
        top = -1;
    }

    char push(char ch) {
        if(top == 49) {
           return '!';
        } 
        else {
            top++;
            stk[top] = ch;
        }
    }

    char pop() {
        if(top == -1) {
            return '!';
        }
        else {
            char temp = stk[top];
            top--;
            return temp;
        }
    }

    void printStack() {
        if(top == -1) {
            cout << "Empty!";
        }
        else {
            for(int i = 0; i <= top; i++) {
                cout << stk[i];
            }
        }
        cout << " ";
    }
};

void shift() {
    
}

int main() {
    string inputString;
    Stack S;

    cout << "Enter the string" << endl;
    cin >> inputString;
    inputString.append("$");
    int inputLength = inputString.length();

    S.push('$');

    cout << "Stack \t Input \t Action" << endl;

    int i = 0;
    while(i <= inputLength) {
        shift();
    }
}