#include "imports.h"

void CreateInput(int n, int m) {
	std::random_device rd;
	std::mt19937 mt0(rd());
	std::uniform_int_distribution<int> grades(1, 10);
	std::ofstream fr("generated.txt");
	fr << setw(33) << std::left << "Vardas" << setw(30) << std::left << "Pavarde";
	for(int j = 0; j < m; j++) fr << setw(3) << std::right << j+1 << "nd";
	fr << setw(5) << "egz." << endl;
	for(int i=1; i<=n; i++) {
		fr << "Vardas" << setw(27) << std::left << i;
		fr << "Pavarde" << setw(26) << std::left << i;
		for(int j = 0; j < m+1; j++) fr << setw(5) << grades(mt0);
		fr << endl;
	}
	fr.close();
}

void FileInput(Vector<stud> &x, string input) {
	string str;
	std::ifstream fd(input);
	getline(fd, str); // Praleidzia pirma linija
	while(getline(fd, str)) {
		stud temp(str);
		x.push_back(temp);
	}
	fd.close();
}

void FileInput(deque<stud> &x, string input) {
	string str;
	std::ifstream fd(input);
	getline(fd, str); // Praleidzia pirma linija
	while(getline(fd, str)) {
		stud temp(str);
		x.push_back(temp);
	}
	fd.close();
}

void FileInput(list<stud> &x, string input) {
	string str;
	std::ifstream fd(input);
	getline(fd, str); // Praleidzia pirma linija
	while(getline(fd, str)) {
		stud temp(str);
		x.push_back(temp);
	}
	fd.close();
}

void CmdInput(Vector<stud> &x) {
	using std::cin;
	string str;
    getline(cin, str);  // Ignoruoja pasilikusi \n (getline, nes ignore tarpus priskaiciuoja)
	cout << "Iveskite mokiniu vardus, pavardes ir pazymius (egzamino pazymys paskutinis, vienas mokinys - viena eilute)\nNorint baigti iveskite tuscia eilute.\n";
	while(getline(cin, str)) {
		if(str == "") break;
		stud temp(str);
		x.push_back(temp);
	}
}

void Output2file(Vector<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud it : x) fr << it;
	fr.close();
}

void Output2file(deque<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud it : x) fr << it;
	fr.close();
}

void Output2file(list<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud it : x) fr << it;
	fr.close();
}

void OutputTime(int i, timer fileGen, timer fileRead, timer pick, timer sortName, timer out) {
	cout << std::setprecision(5) << std::fixed << "| " << setw(9) << std::left << std::fixed << i << "|  " << setw(11) << fileGen.duration() << "| " << setw(10) << fileRead.duration() << "| ";
	cout << setw(11) << pick.duration() << "| " << setw(11) << sortName.duration() << "| " << setw(8) << out.duration() << "| " << setw(8) << fileGen.duration()+fileRead.duration()+pick.duration() << "|\n";
}

string whichFile(int n) {
	std::ifstream infile("kursiokai.txt");
	if (infile.good()) return("kursiokai.txt");
	else {
		infile.close();
		CreateInput(n, 5); // Kiek mokiniu, kiek namu darbu
		return("generated.txt");
	}
}
