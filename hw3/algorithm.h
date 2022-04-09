#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <numeric>
#include <stdexcept>

namespace MySpace{


template <class X>
void swap(X & x, X & y){
	X tmp=x;
	x=y;
	y=tmp;
}


template<class Ran>
void sort(Ran begin, Ran end)
{
//	std::cout << "sort...\n";
	for(Ran i=begin;i!=end;i++)
		for(Ran j=begin;j+1+(i-begin)!=end;j++)
			if(*j>*(j+1))
				swap(*j,*(j+1));
}


template<class T>
T median(std::vector<T> vec){
//	std::cout << "median...\n";
	typedef typename std::vector<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}


template<class T>
T average(std::vector<T> vec){
//	std::cout << "average...\n";
	//TODO
	return accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
}


template <class In, class X> 
In find(In begin, In end, const X&x){
//	std::cout << "find...\n";
	//TODO
	while (begin != end && *begin != x)
		++begin;
	return begin;
}


template <class In, class Out, class X> 
Out remove_copy(In begin, In end, Out dest, const X&x){
//	std::cout << "remove_copy...\n";
	//TODO
	while (begin != end){
		if (*begin != x)
			*dest++ = *begin++;
		else
			begin++;
	}
	return dest;
}


template <class In, class Out, class F> 
Out transform(In begin,In end, Out dest, F func){
//	std::cout << "transform...\n";
	//TODO
	while (begin != end){
		*dest++ = func(*begin++);
	}
	return dest;
}

}
#endif
