#ifndef _HELPERS
#define _HELPERS

#include <unordered_set>
#include <cmath>
#include <bitset>

#include "./read_input.h"
#include "./show_output.h"
#include "../structs/nfa.h"
#include "./closure.h"

using namespace std;
// To append two sets
void append_sets(unordered_set<int> &first, unordered_set<int> second)
{
    unordered_set<int>::iterator itr;
    for (itr = second.begin(); itr != second.end(); itr++)
    {
        first.insert(*itr);
    }
}

#endif