#include <list>
#include <vector>
#include "Vehicle.h"

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

namespace sdds
{
	
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles; //a vector that store all the vehicles available at this autoshop
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			//for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i)
			for (std::vector<Vehicle*>::iterator i = m_vehicles.begin(); i < m_vehicles.end(); ++i)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
	
}
#endif // !SDDS_AUTOSHOP_H

