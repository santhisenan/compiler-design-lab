#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct nfa {
    int states, alphabets;
    vector <vector < vector <int> > > table; 
};

void find_all_e_closures_helper(nfa n, int state, vector <int> &closure) {
    vector <int> toStates = n.table[state][0];
    if(toStates[0] == -1) {
        return;
    }
    else {
        vector <int>::iterator itr;
        for(itr = toStates.begin(); itr != toStates.end(); itr++) {
            closure.push_back(*itr);
            find_all_e_closures_helper(n, *itr, closure);
        }
    }
}

void find_all_e_closures(nfa n) {
    vector <vector <int> > allClosures;
    vector <int> :: iterator it;
    for(int i = 0; i < n.states; i++) {
        vector <int> closure;
        find_all_e_closures_helper(n, i, closure);

        if(!closure.empty()) {
            vector <int> :: iterator itor;
            itor = unique(closure.begin(), closure.end());
            closure.resize(distance(closure.begin(), itor));
            
            cout << "State " << i << ": ";
            for( it = closure.begin(); it != closure.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
        else {
            cout << "Empty" << endl;
        }
    }
}


int main() {
    nfa a;
    return 0;
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
                toStates.push_back(-1);
            } else {
                while(number--) {
                    cin >> state;
                    toStates.push_back(state);
                }
            }
            row.push_back(toStates);
        }
        n.table.push_back(row);
    }
    // find_all_e_closures(n);
    return 0;    
}