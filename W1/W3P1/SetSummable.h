/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | Oct 13, 2020
*/
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"

namespace sdds
{
	template<typename T, unsigned int N>
	class SetSummable : public Set <T, N>
	{
		//don't explicitely put the constructor and operator+=
	public:
		T accumulate(const std::string& filter) const 
		{
			T SetSumm(filter); //1 arg constructor
			for (unsigned int i = 0; i < N; i++) //interate in a for loop
			{
				if (filter == (*this)[i].key())
				{
					SetSumm += (*this)[i]; //interate over collection
				}
			}
			return SetSumm; //return to the client
		}
	};
}
#endif // !SDDS_SETSUMMABLE_H
