#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct nfa {
    int states, alphabets; 
    vector <vector <vector <int> > > table; // to store the transition table
};

void find_all_e_closures_helper(nfa n, int state, vector <int> &closure) {
    vector <int> toStates = n.table[state][0];
    if(toStates[0] == -1) {
        return;
    }
    else {
        vector <int>::iterator itr;
        for(itr = toStates.begin(); itr != toStates.end(); itr++) {
            cout << *itr << endl;
            closure.push_back(*itr);
            find_all_e_closures_helper(n, *itr, closure);
        }
    }
}

void find_all_e_closures(nfa n) {
    vector <int> closure;
    find_all_e_closures_helper(n, 0, closure);
    cout << closure.size();
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
            // cout << "Enter the number of states for state " << i << "and transition " << j << "combination" << endl;
            cin >> number;
            
            if(number == 0) {
                // If there is no transition for the state and for the given  
                // alphabet, store -1 in the transition table
                toStates.push_back(-1);
            } else {
                // cout << "Enter the states" << endl;
                while(number--) {
                    cin >> state;
                    toStates.push_back(state);
                }
            }
            row.push_back(toStates);
        }
        n.table.push_back(row);
    }
    find_all_e_closures(n);
    return 0;    
}