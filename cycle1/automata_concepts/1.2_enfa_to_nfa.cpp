#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "./structs/nfa.h"
#include "./header_files/closure.h"
#include "./header_files/show_output.h"

using namespace std;


void convert_enfa(nfa n) {
    int s = n.states, a = n.alphabets;
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < a; j++) {
            vector <int> states = n.table[i][j];
            vector <int> :: iterator itr;
            for(itr = states.begin(); itr != states.end(); itr++) {

            }
        }
    }

}

int main() {
    nfa n;

    // Read the number of states and alphabets from the user.
    // Number of alphabets should include epsilon
    cout << "Enter the number of states and alphabets" << endl;
    cin >> n.states >> n.alphabets;

    // Read the transition table from the user.
    for(int i = 0; i < n.states; i++) {
        vector < vector <int> > row;
        for(int j = 0; j < n.alphabets; j++) {
            vector <int> toStates;
            int number, state;
            
            // Read the number of states;
            cin >> number;
            
            if(number == 0) {
                // If there is no transition for the state and for the given  
                // alphabet, store -1 in the transition table
                toStates.insert(-1);
            } else {
                while(number--) {
                    cin >> state;
                    toStates.insert(state);
                }
            }
            row.push_back(toStates);
        }
        n.table.push_back(row);
    }
    convert_enfa(n);
    // print_table(n);
    return 0;    
}