#ifndef _NFA
#define _NFA

#include <vector>
#include <unordered_set>
using namespace std;

struct nfa
{
    int states, alphabets;
    vector<vector<unordered_set<int> > > table; // to store the transition table
};

#endif