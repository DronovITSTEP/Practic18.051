#pragma once
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
	T1 first;
	T2 second;

	Pair() : first{T1()}, second{T2()}{}
	Pair(const T1& x, const T2& y): first{x}, second{y}{}

	void display() {
		cout << "(" << first << ", " << second << ")";
	}
	bool operator==(const Pair& pair) {
		return first == pair.first && second == pair.second;
	}
	bool operator !=(const Pair& pair) {
		return !(this == pair);
	}
};
