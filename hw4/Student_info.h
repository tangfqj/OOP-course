#ifndef GUARD_Student_info
#define GUARD_Student_info

// TODO

#include <iostream>
#include <string>
#include <vector>

//struct student_info{
//    std::string name;
//    double midterm, final;
//    std::vector<double> homework;
//
//    std::istream& read(std::istream&);
//    double garde() const;
//};

class Student_info{
public:
    Student_info();//构造一个空的Student_info对象
    Student_info(std::istream&);//读一个流从而构造一个对象
    bool vaild() const{ return ! homework.empty();}//检查对象是否为空
    double grade() const;
    std::istream& read(std::istream& );
    std::string name() const {return n;}//存取器：容许对一部分数据结构的进行访问
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

std::istream& read_hw(std::istream&, std::vector<double>&);
//std::istream& read(std::istream&, Student_info&);


#endif
