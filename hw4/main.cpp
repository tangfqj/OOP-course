#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;


int main() 
{ 
	//TODO
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// 读入并存储数据
	while (record.read(cin)){
		if (record.name().size() > maxlen)
			maxlen = record.name().size();
		students.push_back(record);
	}

	// 按照字母顺序排列学生记录
	sort(students.begin(), students.end(), compare);

	// 输出姓名和成绩
	for (std::vector<Student_info>::iterator iter = students.begin(); iter != students.end(); iter++){
		// cout << iter->name() << string(maxlen+1-iter->name().size(), ' ');
		cout << iter->name() << "'s final grade is ";
		try{
			double final_grade = iter->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e){
			cout << e.what();
		}
	}
	return 0; 
}
