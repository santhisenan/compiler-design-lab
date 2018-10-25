#include <iostream>
#include <string>
using namespace std;

int i, error;
string input;

void E();
void T();
void F();
void TPrime();
void EPrime();

void E() {
    T();
    EPrime();
}

void T() {
    F();
    TPrime();
}

void EPrime() {
    if(input[i] == '+') {
        i++;
        T();
        EPrime();
    }
}

void TPrime() {
    if(input[i] == '*') {
        i++;
        F();
        TPrime();
    }
}

void F() {
    if(isalnum(input[i])) {
        i++;
    } else if(input[i] == '(') {
        i++;
        E();
        if(input[i] == ')') {
            i++;
        }
        else {
            error = 1;;
        }
    } else {
        error = 1;
    }
}
int main() {
    cout << "Enter an arithmetic expression" << endl;
    cin >> input;
    E();
    if((input.length() == i) && (error == 0)) {
        cout << "Accepted!" << endl;
    } else {
        cout << "Rejected!" << endl;
    }

}