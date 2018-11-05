//A program to check whether two numbers are same or different using template meta programming
//Author: Varunaditya Jadwal

#include<type_traits>

template<unsigned x, unsigned y>
	struct isSame{
		enum {value = false};
	};

template<unsigned x>
	struct isSame<x, x>{
		enum {value = true};
	};

int main(){
	static_assert(isSame<8,8>::value, "Test case #1: Failed!");
	return 0;
}