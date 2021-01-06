#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string c_tag;
		std::string c_maker;
		std::string c_condition; // a car can be new, used or broken in need of repairs
		int c_speed;

	public:
		Car();
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(std::string s);
	};
}
#endif // !SDDS_CAR_H
