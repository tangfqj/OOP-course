#include "Student_info.h"

using namespace std;

//TODO
istream& read(istream & is, Student_info &s){
		is >> s.name >> s.midterm >> s.final;
		read_hw(is, s.homework);
		return is;
	}
istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}