#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{ 
	//TODO
	//读入名字
	cout<<"Please enter the names: ";
	vector<string>names;
	string x;
	int count,i;
	while(cin>>x){
		++count;
		names.push_back(x);
	}
	//找到最长和最短的名字长度
	int max=0,min=names[0].size();
	for(i=0;i<names.size();i++){
		if(names[i].size()>max){
			max=names[i].size();
		}
		if(names[i].size()<min){
			min=names[i].size();
		}
	}
	//找到最长和最短名字的位置
	vector<int>maxflag,minflag;
	for(i=0;i<names.size();i++){
		if(names[i].size()==max){
			maxflag.push_back(i);	
		}
		if(names[i].size()==min){
			minflag.push_back(i);
		}
	}
	//找到最长和最短名字
	vector<string>longestnames;
	vector<string>shortestnames;
	int n;
	for(i=0;i<maxflag.size();i++){
		n=maxflag[i];
		x=names[n];
		longestnames.push_back(x);
	}
	for(i=0;i<minflag.size();i++){
		n=minflag[i];
		x=names[n];
		shortestnames.push_back(x);
	}
	cout<<"longest:";
	for(i=0;i<longestnames.size();i++)
		cout<<longestnames.at(i)+"  ";
	cout<<endl;
	cout<<"shortest:";
	for(i=0;i<shortestnames.size();i++)
		cout<<shortestnames.at(i)+" ";
	return 0; 
}
