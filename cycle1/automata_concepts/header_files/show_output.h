#ifndef _SHOW_OUTPUT_H
#define _SHOW_OUTPUT_H

#include <iostream>
#include <unordered_set>

#include "../structs/nfa.h"

using namespace std;

void print_table(nfa a)
{
    unordered_set<int>::iterator itr;
    for (int i = 0; i < a.states; i++)
    {
        cout << i + 1 << " :: ";
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
#endif