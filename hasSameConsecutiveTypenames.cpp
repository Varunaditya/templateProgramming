//A program that checks whether the two consecutive typenames passed are same or not using template meta programming
//Author: Varunaditya Jadwal

#include<type_traits>

template <typename T>
	struct remove_cv {
		using type = T;
	};

template <typename T>
	struct remove_cv<const T> {
		using type = T;
	};

template <typename T>
	struct remove_cv<volatile T> {
		using type = T;
	};

template <typename T, typename U>
	struct sameTypename{
		enum {value = false};
	};

template <typename T>
	struct sameTypename<T, T>{
		enum {value = true};
	};

template <typename ...args> 
	struct hasSameConsTypenames{
		enum  {value = false};
	};
template <typename T, typename U, typename ...args> 
	struct hasSameConsTypenames<T, U, args...>{
		enum {value = sameTypename<typename remove_cv<T>::type, typename remove_cv<U>::type>::value || hasSameConsTypenames<U, args...>::value};
	};

int main(){
	static_assert(!hasSameConsTypenames<int, char, double>::value, "Test #1 Failed!");
	static_assert(!hasSameConsTypenames<int, char, double>::value, "Test #2 Failed!");
	static_assert(hasSameConsTypenames<int, int, double>::value, "Test #3 Failed!");
	static_assert(hasSameConsTypenames<int, const int, double>::value, "Test #4 Failed!");
	static_assert(hasSameConsTypenames<int, double, const double>::value, "Test #5 Failed!");
	static_assert(hasSameConsTypenames<int, double, double>::value, "Test #6 Failed!");
	static_assert(hasSameConsTypenames<int, char, volatile char, double>::value, "Test #7 Failed!");
	static_assert(hasSameConsTypenames<int, char, char, double>::value, "Test #8 Failed!");
	static_assert(!hasSameConsTypenames<int>::value, "Test #9 Failed!");
	static_assert(!hasSameConsTypenames<>::value, "Test #10 Failed!");
	return 0;
}