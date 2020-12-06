#ifndef LINEMANAGER_H
#define LINEMANAGER_H

// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <deque>
#include <vector>
#include "CustomerOrder.h"
#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine; //A container containing all the references of the Workstation objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled; //A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed; //A queue of customer orders completed
	unsigned int m_cntCustomerOrder; //The number of CustomerOrder objects the assembly line started with.
public:
	LineManager(const std::string& str, std::vector<Workstation*>& ws, std::vector<CustomerOrder>& corders);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const; //display all complete orders
	void displayStations() const;
	void displayStationsSorted() const; //display all stations on the assembly line in the order they are linked.
};
#endif // !LINEMANAGER_H