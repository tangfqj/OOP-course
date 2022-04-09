#include "Student_info.h"
#include <vector>
#include <iostream>
#include <istream>
#include <iomanip>

using namespace std;

//TODO
Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(istream& is) { read(is); }	

istream & read_hw(istream & in, vector<double> & homework){
    if(in){
        homework.clear();
        double x;
        while (in >> x)
            homework.push_back(x);
        in.clear();
    }
    return in;
}
istream & Student_info::read(std::istream & in){
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}
bool compare(const Student_info&x, const Student_info&y){
    return x.name() < y.name();
}
