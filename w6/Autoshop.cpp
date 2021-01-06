#include <iostream>
#include "Autoshop.h"
using namespace std;

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle); //pushback will add theVehicle to the last element of the array

		return *this;
		//delete[] theVehicle;
	}

	void Autoshop::display(std::ostream& out) const
	{
		cout << "--------------------------------" << endl;
		cout << "| Cars in the autoshop!        |" << endl;
		cout << "--------------------------------" << endl;

		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			//Car::display(out);
			(*i)->display(cout);
		}
		cout << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop()
	{
		for (Vehicle* vehicle : m_vehicles)
		{
			delete vehicle;
			m_vehicles.clear();
		}
	}

}