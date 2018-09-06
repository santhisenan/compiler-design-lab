#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "./structs/nfa.h"
#include "./header_files/helpers.h"
#include "./header_files/read_input.h"
#include "./header_files/closure.h"
#include "./header_files/show_output.h"
#include "./header_files/conversions/enfa_nfa.h"

using namespace std;

int main() {
    nfa enfa, finalNfa;
    read_transition_table(enfa);
    enfa_to_nfa(enfa, finalNfa);
    print_table(finalNfa);
    return 0;   
}