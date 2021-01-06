/*Priya Khatri | 110149176 | pkhatri4@myseneca.ca
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
const int MAX_NUM_RECORD_OBJECTS = 7;
using namespace std::literals;

namespace sdds
{
	class TimedEvents
	{
		char* t_records; //statically allocated array of record objects.
		int t_numofrecordsstored; //currently stored
		int time_point = std::chrono::steady_clock::time_point();

	public:
		TimedEvents();
	};
}

#endif // !SDDS_TIMEDEVENTS_H
