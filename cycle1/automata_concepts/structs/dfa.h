#ifndef _DFA
#define _DFA

#include <vector>
#include <unordered_set>
#include <bitset>
using namespace std;

struct dfa
{
    int alphabets;
    bitset<128> states;
    vector<vector<bitset <128> > > table; // to store the transition table
};

#endif