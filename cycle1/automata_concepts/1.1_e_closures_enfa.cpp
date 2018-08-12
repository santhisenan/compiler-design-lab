#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "./structs/nfa.h"
#include "./header_files/read_input.h"
#include "./header_files/closure.h"
#include "./header_files/show_output.h"

using namespace std;

void find_all_e_closures(nfa n) {

    unordered_set <int> :: iterator it;
    
    for(int i = 0; i < n.states; i++) {
        unordered_set <int> closure;
        find_e_closure(n, i, closure);

        if(!closure.empty()) {
            cout << i << ": ";
            for( it = closure.begin(); it != closure.end(); it++) {
                cout << *it + 1 << " ";
            }
            cout << endl;
        }
        closure.clear();
    }
}

int main() {
    nfa n;
    read_transition_table(n);
    // print_table(n);
    find_all_e_closures(n);
    return 0;    
}