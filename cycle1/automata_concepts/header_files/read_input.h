#ifndef _READ_INPUT
#define _READ_INPUT

#include <iostream>
#include <unordered_set>

#include "../structs/nfa.h"

using namespace std;

void read_transition_table(nfa &n) {
    // Read the number of states and alphabets from the user.
    // Number of alphabets should include epsilon
    cout << "Enter the number of states and alphabets" << endl;
    cin >> n.states >> n.alphabets;

    // Read the transition table from the user.
    for (int i = 0; i < n.states; i++)
    {
        vector<unordered_set<int> > row;
        for (int j = 0; j < n.alphabets; j++)
        {
            unordered_set<int> toStates;
            int number, state;

            // Read the number of states;
            cin >> number;

            if (number == 0)
            {
                // If there is no transition for the state and for the given
                // alphabet, store -1 in the transition table
                toStates.insert(-1);
            }
            else
            {
                while (number--)
                {
                    cin >> state;
                    toStates.insert(state);
                }
            }
            row.push_back(toStates);
        }
        n.table.push_back(row);
    }
}

#endif