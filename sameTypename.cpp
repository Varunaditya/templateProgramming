//A program that checks whether the two typenames passed are same or not using template meta programming
//Author: Varunaditya Jadwal

#include<type_traits>

template<typename T, typename U>
	struct sameTypename{
		enum {value = false};
	};

template<typename T>
	struct sameTypename<T, T>{
		enum {value = true};
	};

int main(){
	// cout << extractType<int>::type ;//<< "\n";
	static_assert(sameTypename<int, int>::value, "Test #1 Failed!");
	static_assert(!sameTypename<int, char>::value, "Test #2 Failed!");
	static_assert(sameTypename<char, char>::value, "Test #3 Failed!");
	static_assert(sameTypename<long, long>::value, "Test #4 Failed!");
	static_assert(!sameTypename<int, long>::value, "Test #5 Failed!");
	static_assert(!sameTypename<float, int>::value, "Test #6 Failed!");
	return 0;
}