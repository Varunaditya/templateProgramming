//A program that counts the number of arguments passed using template meta programming
//Note: parameter packing requires support of c++11. compile as 'g++ countArguments.cpp -std=c++11 -o output'
//Author: Varunaditya Jadwal

#include<iostream>

template<typename T, typename...args> //declaring the parameters pack
	struct counter{
		enum {value = 1 + counter<args...>::value}; //unpacking the parameter pack
	};

template<typename T> 
	struct counter<T>{ //template specialization if only one parameter is passed
		enum {value = 1};
	};

int main(){
	std::cout << counter<int, char, long, double, float, unsigned, const int>::value << "\n";
	return 0;
}