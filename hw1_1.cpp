#include <algorithm>
#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main() { 
	//TODO
	//读入学生姓名
	cout<<"Please enter your first name: ";
	string name;
	cin>>name;
	cout<<"Hello, "<<name<<"!"<<endl;

	//输入期中期末成绩
	cout<<"Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin>>midterm>>final;

	//输入平时成绩
	cout<<"Enter all your homework grades, followed by end-of-file: ";
	vector<double>homework;
	double x;
	while(cin>>x){
		homework.push_back(x);
	}
	//检查homework是否为空
	typedef vector<double>::size_type vec_sz;
	vec_sz size=homework.size();
	if (size==0){
		cout<<endl<<"You must enter your grades."<<"Please try again."<<endl;
		return 1;
	}
	//对成绩排序
	sort(homework.begin(),homework.end());
	//计算中值
	vec_sz mid=size/2;
	double median;
	median=(size%2==0)?(homework[mid]+homework[mid-1])/2:homework[mid];
	//输出
	streamsize prec=cout.precision();
	cout<<"Your final grade is "<<setprecision(3)<<0.2*midterm+0.4*final+0.4*median<<setprecision(prec)<<endl;

	return 0; 
} 
