//A program that evauates the factorial of a number using template programming
//Author: Varunaditya Jadwal

#include<iostream>
using namespace std;

template<unsigned int n> struct factorial{
	enum {value = n * factorial<n-1>::value};
};

template<> struct factorial<0>{
	enum {value = 1};
};

int main(){
	cout << factorial<8>::value << "\n";
	return 0;
}