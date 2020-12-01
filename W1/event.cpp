#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"
using namespace std;

size_t g_sysClock; //size_t for when you don't wanna give negative numbers

namespace sdds
{
	Event::Event()
	{ 
		e_desc = nullptr;
		e_time = 0;
	}

	void Event::display() const
	{
		static int counter = 1;

		size_t hh = 00, mm = 00, ss = 00; //initalize to fix err

		//seconds = hh * 3600 + mm * 60 + ss;
		hh = e_time / 3600;
		mm = (e_time - (hh * 3600)) / 60;
		ss = (e_time - (hh * 3600) - (mm * 60));

		if (e_desc == nullptr)
		{
			cout << setw(3) << setfill(' ') << counter << ". "
			 << "[ No Event ]\n";
		}
		else
		{
			cout << setw(3) << setfill(' ') << counter << ". "
				<< setw(2) << setfill('0') << hh << ":"
				<< setw(2) << setfill('0') << mm << ":"
				<< setw(2) << setfill('0') << ss << 
				" -> " << e_desc << endl;
		}
		counter++;
	}

	void Event::setDescription(const char* desc)
	{
		if (desc != nullptr)
		{
			e_time = g_sysClock;
			
			if (e_desc != nullptr)
			{
				e_desc = nullptr; //set empty
			}
			delete[] e_desc;
			e_desc = new char[strlen(desc) + 1];
			strcpy(e_desc, desc); //current instance
		}
		else
		{
			e_desc = nullptr;
		}
 
	}

	Event::Event(const Event& other) //copy constructor
	{
		e_desc = nullptr; //this is so the assignment doesn't crash
		*this = other;
	}

	Event& Event::operator=(const Event& other) //copy assignment
 	{
		//checking self assignment
		if (this != &other)
		{
			this->e_time = other.e_time; //shallow copy
			
			delete[] e_desc;

			if (other.e_desc != nullptr)
			{
				e_desc = new char[strlen(other.e_desc) + 1];  //allocate new mem
				strcpy(e_desc, other.e_desc);
			}
			else
			{
				e_desc = nullptr;
			}
		}
		
		return *this;
	}

	Event::~Event()
	{
		delete[] e_desc;
		e_desc = nullptr;
	}
}