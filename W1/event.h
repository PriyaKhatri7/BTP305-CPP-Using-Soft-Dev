#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern size_t g_sysClock; //global. only positives

namespace sdds
{
	class Event
	{
		char* e_desc; //event description
		size_t e_time; //time when the event starts

	public:
		Event();
		void display() const;
		void setDescription(const char*);
		Event(const Event& other); //copy constructor
		Event& operator=(const Event& other); //copy assignment
		~Event();
	};
}

#endif // !SDDS_EVENT_H