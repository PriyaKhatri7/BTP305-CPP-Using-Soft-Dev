#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"
using namespace std;

namespace sdds
{
	Car::Car()
	{
		c_tag = "";
		c_maker = "";
		c_condition = "";
		c_speed = 0;
	}
	
	string Car::trim(string s)
	{
		char space = ' ';

		while (s.front() == space)
		{
			s = s.substr(1, s.length() - 1);
		}

		while (s.back() == space)
		{
			s = s.substr(0, s.length() - 1);
		}
		return s;
	}

	Car::Car(istream& is)
	{	
		//p2
		string tmp = (""); //temp string - need to grab the first 2 elements of the string 
		string tmpArr[3]{}; //size 3

		for (int i = 0; i < 3; i++)
		{
			getline(is, tmp, ',');
			tmp.erase(0, tmp.find_first_not_of(' '));
			tmpArr[i] = tmp;
		}

		c_maker = trim(tmpArr[0]); //trim the spaces
	
		//the token representing the condition the car is empty (no characters or only blanks):
		//consider that the car is new
		if (tmpArr[1].empty())
			tmpArr[1] = 'n';
		
		//the token representing the condition of the car is a different character than n, u, or b:
		//generate an exception to inform the client that this record is invalid
		if (tmpArr[1].at(0) == 'n' || tmpArr[1].at(0) == 'u' || tmpArr[1].at(0) == 'b')
		{
			c_condition = tmpArr[1].at(0);
		}
		else
		{
			getline(is, tmp);
			throw string("Invalid record!");
		}

		//the token representing the top speed is not a number:
		//generate an exception to inform the client that this record is invalid
		is >> tmpArr[2];

		if (!isdigit(tmpArr[2].at(0))) //isdigit is from ctype.h library
		{
			std::getline(is, tmp);
			throw string("Invalid record!");
		}
		else c_speed = stod(tmpArr[2]);
	}

	std::string Car::condition() const
	{
		string tmpC;
		
		if (c_condition[0] == 'n')
		{
			tmpC = "new";
		}
		else if (c_condition[0] == 'u')
		{
			tmpC = "used";
		}
		else if (c_condition[0] == 'b')
		{
			tmpC = "broken";
		}
		return tmpC;	

		/*	|| tmpUsed[0] == "u" || tmpBroken[0] == "b")
		{
			tmpNew = "new";
			tmpUsed = "used";
			tmpBroken = "broken";
		}*/
	}

	double Car::topSpeed() const
	{
		return c_speed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << setw(10) << right << c_maker << " | ";
		out.width(6); out << left << condition() << " | ";
		out.setf(ios::fixed); out << setprecision(2) << c_speed << ".00 |" << endl;
	}

	
}