#include "imports.h"

bool cmprName(stud &a, stud &b) { return a.getName() < b.getName(); }
bool cmprTo5(stud &a) { return a.getAvg()<5; }
bool cmprRev(stud &a, stud &b) { return a.getAvg() > b.getAvg(); }

void Pick(Vector<stud>& x, Vector<stud>& bad) {
    sort(x.begin(), x.end(), cmprRev);
    while(cmprTo5(x.back())) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void ImprovedPick(Vector<stud>& x, Vector<stud>& bad) {
    std::copy_if(x.begin(), x.end(), std::back_inserter(bad), cmprTo5);
    x.erase(
        std::remove_if(x.begin(), x.end(), cmprTo5),
        x.end());
}

void Pick(deque<stud>& x, deque<stud>& bad) {
    sort(x.rbegin(), x.rend());

    while(x.back().getAvg()<5) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void Pick(list<stud>& x, list<stud>& bad) {
    x.sort([](stud& a, stud& b) { return a.getAvg() > b.getAvg(); });
    while(cmprTo5(x.back())) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void Ask(bool& inChoice, int& typeChoice){
    cout << "Dirbti su komandine eilute - 0, dirbti su failu - 1" << endl;
    std::cin >> inChoice;
    if(inChoice) {
        cout << "Su kokiu tipu dirbti?\n0 - Vector | 1 - Deque | 2 - List\n";
        std::cin >> typeChoice;
    }
}

void Run(Vector<stud>& good, Vector<stud>& bad, bool pickChoice){
    string input = whichFile(0);
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            if(!pickChoice) Pick(good, bad);
            else   ImprovedPick(good, bad);
            pick.stop();

            timer sortName;
            sort(good.begin(), good.end(), cmprName);
            sort(bad.begin(), bad.end(), cmprName);
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        if(!pickChoice) Pick(good, bad);
        else   ImprovedPick(good, bad);

        sort(good.begin(), good.end(), cmprName);
        sort(bad.begin(), bad.end(), cmprName);

        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");

        cout << "Nepatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : bad) cout << it;
        cout << "\nPatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : good) cout << it;

        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}

void Run(deque<stud>& good, deque<stud>& bad){
    string input = whichFile(0); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            Pick(good, bad);
            pick.stop();

            timer sortName;
            sort(good.begin(), good.end(), cmprName);
            sort(bad.begin(), bad.end(), cmprName);
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        Pick(good, bad);

        sort(good.begin(), good.end(), cmprName);
        sort(bad.begin(), bad.end(), cmprName);

        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");

        cout << "Nepatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : bad) cout << it;
        cout << "\nPatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : good) cout << it;

        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}

void Run(list<stud>& good, list<stud>& bad){
    string input = whichFile(0); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            Pick(good, bad);
            pick.stop();

            timer sortName;
            good.sort(cmprName);
            bad.sort(cmprName);
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        Pick(good, bad);

        good.sort(cmprName);
        bad.sort(cmprName);

        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");

        cout << "Nepatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : bad) cout << it;
        cout << "\nPatenkinami:\n";
        cout<<setw(18)<<std::left<<"Vardas"<<setw(18)<<std::left<<"Pavarde"<<"Galutinis (Vid.) / Galutinis (Med.)\n"<<"------------------------------------------------------------\n";
        for(stud& it : good) cout << it;

        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}
