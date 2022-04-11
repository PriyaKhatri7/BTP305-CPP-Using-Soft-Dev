// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// 345_w1_Process.cpp
// Chris Szalwinski
// 2018.05.16

#include <iostream>
#include "CString.h"
#include "345_w1_Process.h"

void process(const char* str) {
	sict::CString a(str);
	std::cout << a << std::endl;
}
