#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct nfa {
        int states, alpha;
	vector <int> final_state;
	vector <vector <int> > tt;
};


void print_closure(vector <int> closure) {
	vector <int> :: iterator itr;
	itr = closure.begin();
	//cout << ;
	for(; itr != closure.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
}


vector<int>  find_closure(nfa a, int state) {
	vector <int> closure;
	if(find(a.final_state.begin(), a.final_state.end(), state) != a.final_state.end()) {
		return closure;
	}
	for(int i = 0; i < a.states; i++) {
		if(a.tt[state][0] != -1) {
			closure.push_back(a.tt[state][0]);
			vector <int> subpart;
			subpart = find_closure(a, a.tt[state][0]);
			closure.insert(closure.end(), subpart.begin(), subpart.end());
		}
	}
	sort(closure.begin(), closure.end());
	closure.erase(unique(closure.begin(), closure.end()), closure.end());
	return closure;
}


int main() {
	nfa a;
	int states, alpha, toState, noFinal;
	vector <vector <int> > table;
	vector <int> final;
	cout << "Enter the number of states and alphabets" << endl; 
	cin >> states >> alpha;
	a.states = states;
	a.alpha = alpha;

	for(int i = 0; i < states; i++) {
		vector <int> temp;
		for(int j = 0; j < alpha; j++) {
			cin >> toState;
			temp.push_back(toState);
		}
		table.push_back(temp);
	}

	a.tt = table;
	cout << "Enter the final states" << endl;
	cin >> noFinal;
	for(int i = 0; i < noFinal; i++) {
		cin >> toState;
		final.push_back(toState);
	}
	a.final_state = final;

//	int state;
//	cin >> state;

	for(int l = 0; l < states; l++){
		vector <int> closure;
		closure = find_closure(a, l);
		cout << l << " :" ;
        	print_closure(closure);
		closure.empty();
	} 
	return 0;

}

