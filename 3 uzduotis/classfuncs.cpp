#include "imports.h"

stud::stud(string str) {
	std::istringstream ss(str);
	ss >> name >> lname;
	int in;
    while(ss >> in) if(in <= 10 || in > 0) nd.push_back(in);
    if(nd.size() > 1) {
  		exam = nd.back();
    	nd.pop_back();
	}
	else if(nd.size() == 1) {
		exam = nd.back();
		nd.back() = 0;
	}
	else {
		exam = 0;
		nd.push_back(0);
	}
	Average();
	Median();
}

float stud::Final(float avg, float m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

void stud::Average() {
	avg = Final(std::accumulate(nd.begin(), nd.end(), 0.0)/nd.size(), exam);
}

void stud::Median() {
    int i = nd.size()/2-1;
    sort(nd.begin(), nd.end());
    if(nd.size()%2 == 0) {
        medAvg = Final((nd[i]+nd[i+1])/2.0, exam);
    }
    else medAvg = Final(nd[i], exam);
}

stud& stud::operator = (const stud& st){
	name = st.name;
	lname = st.lname;
	nd = st.nd;
	avg = st.avg;
	medAvg = st.medAvg;
	exam = st.exam;
}
bool stud::operator == (stud& st){
	if(name==st.name && lname==st.lname) return true;
	else return false;
}
bool stud::operator != (stud st){
	if(name==st.name && lname==st.lname) return false;
	else return true;
}
bool stud::operator > (stud st){
	if(avg>st.avg) return true;
	else return false;
}
bool stud::operator < (stud st){
	if(avg<st.avg) return true;
	else return false;
}
bool stud::operator <= (stud st){
	if(avg<=st.avg) return true;
	else return false;
}
bool stud::operator >= (stud st){
	if(avg>=st.avg) return true;
	else return false;
}

std::ostream& operator << (std::ostream& fr, stud& st) {
	fr <<setw(18)<<std::left<<st.getName()<<setw(18)<<std::left<<st.getLname();
	fr <<std::setw(19)<<std::left<<st.getAvg()<<setw(16)<<std::left<<st.getMed()<<endl;
}
