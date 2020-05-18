#include "vector.h"
#include <iostream>
#include <chrono>

using std::cout;
using std::endl;

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

int main() {
	// Pradėti v1 užpildymo laiko matavimą
	timer stdVec;
	unsigned int sz = 100000000;  // 100000000
	std::vector<int> v1;
	for (int i = 1; i <= sz; ++i)
	  v1.push_back(i);
	// Baigti v1 užpildymo laiko matavimą
	stdVec.stop();

	// Pradėti v2 užpildymo laiko matavimą
	timer myVec;
	Vector<int> v2;
	for (int i = 1; i <= sz; ++i)
	  v2.push_back(i);
	// Baigti v2 užpildymo laiko matavimą
	myVec.stop();
	cout << "std::vector: " << stdVec.duration() << "s\nVector.h: " << myVec.duration() << '\n';
}