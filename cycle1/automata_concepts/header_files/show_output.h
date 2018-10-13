#ifndef _SHOW_OUTPUT_H
#define _SHOW_OUTPUT_H

#include <iostream>
#include <unordered_set>
#include <vector>

#include "../structs/nfa.h"
#include "../structs/dfa.h"

using namespace std;

void print_table(nfa a)
{
    unordered_set<int>::iterator itr;
    for (int i = 0; i < a.states; i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < a.alphabets; j++)
        {
            unordered_set<int> states = a.table[i][j];
            for (itr = states.begin(); itr != states.end(); itr++)
            {
                cout << *itr + 1 << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
}

void print_table_dfa(dfa a)
{
    for(int i = 0; i < a.alphabets; i++) {
        vector <bitset <128> > DFARow;
        vector<bitset<128> >::iterator rowItr;
        DFARow = a.table[i];
        for(rowItr = DFARow.begin(); rowItr != DFARow.end(); rowItr++) {
            bitset <128> DFAState = *rowItr;
            if(DFAState.none()) {
                cout << -1;
                cout << " | ";
                continue;
            }
            for(int j = 0; j < DFAState.size(); j++) {
                if(DFAState[j]) {
                    cout << j << " ";
                }
            }
            cout << " | ";
        }
        cout << endl;
    }
}
#endif