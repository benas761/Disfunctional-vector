#include "imports.h"


int main() {
    bool inChoice; int typeChoice;
	Ask(inChoice, typeChoice);
	if(inChoice) {
		if(typeChoice == 0) {
			Vector<stud> good, bad;
			cout << "Neoptimizuotas rinkimas - 0, optimizuotas - 1\n";
			bool pickChoice;
			std::cin >> pickChoice;
			Run(good, bad, pickChoice);
		}
		else if(typeChoice == 1) {
			deque<stud> good, bad;
			Run(good, bad);
		}
		else {
			list<stud> good, bad;
			Run(good, bad);
		}
	}
	else {
		Vector<stud> x;
		CmdInput(x);
		Vector<stud> good, bad;
		std::sort(x.begin(), x.end(), cmprName);
        Output2file(x, "cmdOutput.txt");
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : x) cout << it;
	}
	return 0;
}
