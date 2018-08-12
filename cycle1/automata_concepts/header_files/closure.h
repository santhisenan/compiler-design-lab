#ifndef _closure_h
#define _closure_h


#include <unordered_set>
using namespace std;

void find_e_closure(nfa n, int state, unordered_set<int> &closure)
{
    unordered_set<int> toStates = n.table[state][0];
    closure.insert(state);
    if (toStates.find(-1) != toStates.end())
    {
        return;
    }
    else
    {
        unordered_set<int>::iterator itr;
        for (itr = toStates.begin(); itr != toStates.end(); itr++)
        {
            if (find(closure.begin(), closure.end(), *itr) == closure.end())
            {
                closure.insert(*itr);
            }
            find_e_closure(n, *itr, closure);
        }
    }
}

#endif