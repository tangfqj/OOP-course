#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;

bool fgrade(const Student_info& s){
	return grade(s.midterm, s.final, s.homework)<60;
}

list<Student_info> extract_fails(list<Student_info> & students)
{
	//TODO
	list<Student_info> fail;
	list<Student_info>::iterator iter=students.begin();
	while(iter!=students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter=students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}


int main() 
{ 
	//TODO
	list<Student_info> students;
	Student_info record;
	string::size_type maxlen=0;
	
	while(read(cin, record)){
		maxlen=max(record.name.size(), maxlen);
		students.push_back(record);
	}
	//sort(students.begin(),students.end(),compare);
	list<Student_info> fail=extract_fails(students);
	fail.sort();

	for(list<Student_info>::const_iterator iter=fail.begin(); iter!=fail.end(); ++iter){
		cout << iter->name <<string(maxlen+3-iter->name.size(),' ');
		try{
			double final_grade=grade(iter->midterm, iter->final, iter->homework);
			streamsize prec=cout.precision(3);
			cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec) << endl;
		}catch(domain_error e){
			cout << e.what();
		}
	}
	cout << endl;
	return 0; 
}
