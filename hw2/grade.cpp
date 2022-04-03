#include <vector>
#include <stdexcept>
#include <math.h>
#include "grade.h"
#include "median.h"

using namespace std;

//TODO
double grade(double midterm, double final, double homework){
    double score;
    score=0.2*midterm+0.4*final+0.4*homework;
    if(floor(score)+0.5>score){
        return floor(score)+1;
    }
    else if (floor(score)+0.5==score){
        return score;
    }
    else{
        return floor(score)+0.5;
    }
}

double grade(double midterm, double final, const vector<double>& hw){
    if (hw.size()==0)
        throw domain_error("student has done no homework");
    int i, total=0;
    double t;
    double average;
    for(i=0; i<hw.size(); i++){
        total+=hw[i];
        t++;
    }
    average=total/t;
    return grade(midterm, final, (0.4*median(hw)+0.6*average));
}
