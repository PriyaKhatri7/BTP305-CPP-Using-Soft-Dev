#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H

#include <iostream>
#include <chrono>

const int MAX_NUM_RECORDS = 7;

namespace sdds
{
	class TimedEvents
	{
		int m_record[10]; //statically allocated array of record objs
		int m_recordsStored;
		std::chrono::steady_clock::time_point m_start;
		std::chrono::steady_clock::time_point m_end;

		struct //anonymous struct - has no name
		{
			std::string m_name;
			std::string m_time;
			std::chrono::steady_clock::duration m_duration;
		};

	public:
		TimedEvents();
		void startClock();
		void stopClock();

	};
}
#endif // !TIMEDEVENTS_H