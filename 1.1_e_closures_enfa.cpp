#include "iostream"
#include "vector"
#include "unordered_set"
#include "algorithm"
using namespace std;

struct nfa {
    int states, alphabets; 
    vector <vector <unordered_set <int> > > table; // to store the transition table
};

void print_table(nfa a) {
    unordered_set <int> :: iterator itr;
    for(int i = 0; i < a.states; i++) {
        cout << i + 1<< " :: ";
        for(int j = 0; j < a.alphabets; j++) {
            unordered_set <int> states = a.table[i][j];
            for(itr = states.begin(); itr != states.end(); itr++) {
                cout << *itr + 1 << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
}
void find_all_e_closures_helper(nfa n, int state, unordered_set <int> &closure) {
    unordered_set <int> toStates = n.table[state][0];
    closure.insert(state);
    if(toStates.find(-1) != toStates.end()) {
        return;
    }
    else {
        unordered_set <int>::iterator itr;
        for(itr = toStates.begin(); itr != toStates.end(); itr++) {
            if(find(closure.begin(), closure.end(), *itr) == closure.end()) {
                closure.insert(*itr);
            }
            find_all_e_closures_helper(n, *itr, closure);
        }
    }
}

void find_all_e_closures(nfa n) {

    // vector <unordered_set <int> > allClosures;
    unordered_set <int> :: iterator it;
    
    for(int i = 0; i < n.states; i++) {
        unordered_set <int> closure;
        find_all_e_closures_helper(n, i, closure);
    
        if(!closure.empty()) {
            cout << i << ": ";
            for( it = closure.begin(); it != closure.end(); it++) {
                cout << *it + 1 << " ";
            }
            cout << endl;
        }
        closure.clear();
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
        vector < unordered_set <int> > row;
        for(int j = 0; j < n.alphabets; j++) {
            unordered_set <int> toStates;
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
    // print_table(n);
    find_all_e_closures(n);
    return 0;    
}