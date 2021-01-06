#include <iostream>
#include "Racecar.h"
using namespace std;

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		in >> m_booster;
	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*" << endl;
	}

	double Racecar::topSpeed() const
	{
		//come back to and see why it's saying inaccessible
		return (Car::topSpeed() * m_booster) + Car::topSpeed();
	}
}
