#include <iostream>
#include <string>
using namespace std;

class stack {
    public: 
        unsigned char stk[10];
        int top;

        // THe constructor
        stack() {
            top = 0;
        }

        // Pop function
        char pop() {
            if(top != 0) {
                top--;
                return stk[top];
            } 
            else {
                return '!'; //Return an ! if the pop operation is unsuccessful
            }
        }

        // Push function
        char push(char data) {
            if(top != 9) {
                stk[++top] = data;
                return data;
            }
            else {
                return '!'; //Return an ! if the push operation is unsuccessful
            }
        }

        // Function to get the size of the stack
        int size() {
            return top;
        }

        // Function to return the top most element in the stack
        char topElement() {
            if(top == 0) {
                return '!'; //Return an ! if the stack is empty
            }
            else {
                return stk[top-1];
            }
        }
    
        // Function to display the stack
        void display() {
            if(top == 0) {
                cout << "\n The stack is empty!";
            }

            // Prints the stack
            for(int i = 0; i < top; i++) {
                cout << stk[i];
            }
        }
};

int main() {
    stack S;
    int ip = 0, inputLength;
    string input;

    // Read the input
    cout << "Enter the input string!";
    cin >> input;

    // Append a $ to the end of the input
    input.append("$");

    // Push $ to the stack
    S.push('$');

    while(true) {
        inputLength = input.length();
        if(input[ip] != '$') {
            S.push(input[ip]);
            S.display();
            for(int f = 0; f < inputLength; f++) {
                cout << input[f];
            }
            // cout << input;
            cout << "\t Shift \n\n";
            ip++;

            // If the element pushed into the stack is an identifier, pop the 
            // element and push E

            if(S.topElement() == 'i') {
                S.pop();
                S.push('E');
                S.display();
                // cout << input;
                for (int f = 0; f < inputLength; f++) {
                    cout << input[f];
                }
                cout << "\t Reduction \n\n";
            }
        }
        else {
            if((S.size() == 2) && (S.topElement() == 'E')) {
                cout << "\n Accept" << endl;
                exit(0);
            }
            else {
                if(S.topElement() == 'E') {
                    S.pop();
                    char currentElement = S.pop();
                    if (currentElement == '+' | currentElement == '-' | 
                        currentElement == '*' | currentElement == '/') {
                            if(S.topElement() == 'E') {
                                S.pop();
                                S.push('E');
                                S.display();
                                // cout << input;
                                for (int f = 0; f < inputLength; f++) {
                                    cout << input[f];
                                }
                                cout << "\t Reduce \n\n";
                            }
                            else {
                                cout << "Error \n";
                                exit(0);
                            }
                        }
                }
            }
        }
    }
    return 0;
}