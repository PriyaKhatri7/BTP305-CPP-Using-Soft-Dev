// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation : public Station
{
	std::deque<CustomerOrder>m_orders; //– is a double ended queue with new CustomerOrders coming in one sideand exiting out the other once filled.
	Workstation* m_pNextStation = nullptr; //– a pointer to the next station on the assembly line
public:
	Workstation(const std::string& str);

	//make sure workstation cannot be copied or moves
	Workstation(Workstation& src) = delete;
	Workstation(Workstation&& src) = delete;
	Workstation& operator=(Workstation& source) = delete;
	Workstation& operator=(Workstation&& source) = delete;

	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os) const;
	Workstation& operator+=(CustomerOrder&& order);
};
#endif // !WORKSTATION_H