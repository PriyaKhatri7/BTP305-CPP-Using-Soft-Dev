#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster; //%(stores as a number between 0 and 1) and Racecar can boost its top speed
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H
