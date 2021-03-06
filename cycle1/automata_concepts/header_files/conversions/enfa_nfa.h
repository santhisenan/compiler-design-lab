#ifndef _ENFA_TO_NFA
#define _ENFA_TO_NFA

#include <unordered_set>
#include <vector>

#include "../../structs/nfa.h"
#include "../../structs/dfa.h"
#include "../closure.h"
#include "../helpers.h"

// To convert e-NFA to NFA
void enfa_to_nfa(nfa n, nfa &m)
{
    m.states = n.states;
    m.alphabets = n.alphabets;

    int s = n.states, a = n.alphabets;

    for (int i = 0; i < s; i++)
    {
        vector<unordered_set<int> > row;

        // Insert -1 to alphabet epsilon
        unordered_set<int> nullState;
        nullState.insert(-1);
        row.push_back(nullState);
        nullState.clear();

        // Find the e Closure of the current state and store in eClosure
        unordered_set<int> eClosure;
        unordered_set<int>::iterator itr;
        find_e_closure(n, i, eClosure);

        for (int j = 1; j < a; j++)
        {
            unordered_set<int> temp, tempClosure, toStates;
            unordered_set<int>::iterator it;
            for (itr = eClosure.begin(); itr != eClosure.end(); itr++)
            {
                temp = n.table[*itr][j];
                if (!temp.empty())
                {
                    for (it = temp.begin(); it != temp.end(); it++)
                    {
                        // cout << "Hello" << *it << endl;
                        if (*it != -1)
                        {
                            find_e_closure(n, *it, tempClosure);
                            append_sets(toStates, tempClosure);
                        }
                    }
                }
            }
            if (toStates.empty())
            {
                toStates.insert(-1);
            }
            row.push_back(toStates);
            toStates.clear();
        }
        m.table.push_back(row);
        row.clear();
    }
}


#endif