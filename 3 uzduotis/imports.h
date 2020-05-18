#include <fstream>
#include <iostream>
#include <iomanip>
//#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <random>
#include <chrono>
#include <algorithm>
#include "vector.h"

using std::string;
using std::vector;
using std::deque;
using std::list;
using std::cout;
using std::endl;
using std::setw;
using std::sort;

/// Abstrakti klasė, sauganti duomenis apie mokinio (stud) vardą ir pavardę.
class human {
protected:
	string name, lname;
	/// Virtuali funkcija, paverčianti klasę abstrakčia.
	virtual float Final(float avg, float m) = 0;
};

/// Studento klasė.
///
/// Paveldėja vardą ir pavardę iš human klasės.
/// Saugo pažymius ir egzamino balus.
class stud : human {
	float medAvg, avg;
	int exam;
	Vector<int> nd;
public:
    /// Default konstruktorius, jei nereikia nuskaityti duomenų iš failo.
	stud() {}
	/// Konstruktorius, kuriam perduodama skaityti viena failo eilutė.
	///
	/// Eilutėje yra vardas, pavardė, namų darbų pažymiai ir egzamino balas (paskutinis).
	/// Duomenys atskirti tarpais.
	/// Konstruktoriuje pagal medianą ir vidurkį apskaičiuojami finaliniai pažymiai.
	stud(string);
	/// Default destruktorius. Nedirbama su dinamine atmintimi, tad nieko papildomai trinti nereikia.
	~stud() {}
		/// Skaičiuoja vidurkį ir jį perduoda Final() funkcijai.
	void Average();
	/// Skaičiuoja medianą ir ją perduoda Final() funkcijai.
	void Median();
	/// Suskaičiuoją galutinį pažymį pagal formulę 0.4*avg + 0.6*exam
	float Final(float avg, float m);
	/// Gražina vardą.
	inline string getName() { return name; }
	/// Gražina pavardę.
	inline string getLname() { return lname; }
	/// Gražina pažymį pagal medianą.
	inline float getMed() { return medAvg; }
	/// Gražina pažymį pagal vidurkį.
	inline float getAvg() { return avg; }
	/// Prilygina visas reikšmes kitai stud klasei
	stud& operator =  (const stud&);
	/// Tikrina ar vardas ir pavardė yra viendi.
	bool operator == (stud&);
	/// Tikrina ar nesutampa vardas arba pavardė.
	bool operator != (stud);
	/// Tikrina kuris pažymys pagal vidurkį yra mažesnis.
	bool operator >  (stud);
	/// Tikrina kuris pažymys pagal vidurkį yra didesnis.
	bool operator <  (stud);
	/// Tikrina kuris pažymys pagal vidurkį yra nedidesnis.
	bool operator <= (stud);
	/// Tikrina kuris pažymys pagal vidurkį yra nemažesnis.
	bool operator >= (stud);
	/// Parašo vardą, pavardę ir galutinius pažymius iš Average() ir Median() su šiai programai tinkamais tarpais.
	friend std::ostream& operator << (std::ostream&, stud&);
};

/// Timer klasė, skirta patogiasniam laiko skaičiavimui
class timer{
	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration<double> length;
	public:
    /// Konstruktorius, kuris paleidžia laikmatį.
	timer() { start =  std::chrono::high_resolution_clock::now(); }
	/// Funkcija, apskaičiuojanti praėjusį laiką.
	void stop() {
		end =  std::chrono::high_resolution_clock::now();
		length = std::chrono::duration_cast<std::chrono::duration<double>>(end-start);
	}
	/// Funkcija, išvedanti praėjusį laiką.
	double duration() { return length.count(); }
};

//inOut.cpp
void CreateInput(int, int);
void FileInput(Vector<stud>&, string);
void FileInput(deque<stud>&, string);
void FileInput(list<stud>&, string);
void CmdInput(Vector<stud>&);
void Output2file(Vector<stud>&, string);
void Output2file(deque<stud>&, string);
void Output2file(list<stud>&, string);
void OutputTime(int, timer, timer, timer, timer, timer);
string whichFile(int);

//gradeGen.cpp
bool cmprName(stud&, stud&);
void Pick(Vector<stud>&, Vector<stud>&);
void ImprovedPick(Vector<stud>&, Vector<stud>&);
void Pick(deque<stud>&, deque<stud>&);
void Pick(list<stud>&, list<stud>&);
void Ask(bool&, int&);
void Run(Vector<stud>&, Vector<stud>&, bool);
void Run(deque<stud>&, deque<stud>&);
void Run(list<stud>&, list<stud>&);
