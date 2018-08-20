#include <iostream>
#include <unordered_set>
#include <vector>

#include "./structs/nfa.h"
#include "./header_files/helpers.h"
#include "./header_files/read_input.h"
#include "./header_files/closure.h"
#include "./header_files/show_output.h"
#include "./header_files/helpers.h"

using namespace std;

int main() {
    nfa n, m;
    read_transition_table(n);
    nfa_to_dfa(n, m);
    print_table(m);
}