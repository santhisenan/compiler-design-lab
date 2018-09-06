#ifndef _NFA_TO_DFA
#define _NFA_TO_DFA

#include <vector>
#include <unordered_set>
#include "../../structs/nfa.h"
#include "../../structs/dfa.h"
#include "../closure.h"

void nfa_to_dfa(nfa n, dfa &m)
{
    m.alphabets = n.alphabets;
    for(int i = 0; i < n.alphabets; i++) {
        vector <bitset <10> > DFARow;
        for(int j = 0; j < n.states; j++) {
            unordered_set <int> eClosure;
            find_e_closure(n, j, eClosure);
            bitset <10> toStatesDFA(0);
            for(int k = 0; k < eClosure.size(); k++) {
                unordered_set <int> toStates;
                toStates = n.table[i][k];
                unordered_set <int> :: iterator itr;
                for(itr = toStates.begin(); itr != toStates.end(); itr++) {
                    if(*itr != -1) {
                        toStatesDFA.set(*itr);
                    }
                }
            }
            DFARow.push_back(toStatesDFA);
        }
        m.table.push_back(DFARow);
    }
}

#endif