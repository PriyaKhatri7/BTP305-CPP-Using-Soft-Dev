// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"
using namespace std;

Workstation::Workstation(const std::string& str) : Station::Station(str)
{
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) //runs a sungle cycle of assembly line for the current station
{
//	size_t max = m_orders.size(); //max size
//	size_t count = 0; //might not need anymore...comment for now

	if (!m_orders.empty())
	{
		if (m_orders.back().isItemFilled(Station::getItemName()) == false)
		{
			m_orders.back().fillItem(*this, os); //this fills the order in the front at the current workstation
		}
	/*	if (m_pNextStation != nullptr)
		{
			*this->m_pNextStation += move(m_orders.back());
			m_orders.pop_back();
		}
		count++;*/
	}
}

bool Workstation::moveOrder()
{
	//if the first order doesn't need service then move it to the next
	if (!m_orders.empty())
	{
		if (m_orders.back().isItemFilled(Station::getItemName()) == true)
		{
			if (m_pNextStation != nullptr)
			{
				m_pNextStation->m_orders.push_front(move(this->m_orders.back()));
				m_orders.pop_back();
				return true;
			}
		}
	}
	return false;
}

void Workstation::setNextStation(Station& station)
{
	m_pNextStation = static_cast<Workstation*>(&station); //I needed to make sure to use static cast
}

const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
	if (!m_orders.empty() && m_orders.back().isOrderFilled()) //if the q is empty
	{
		order = move(m_orders.back()); //if the order at the front of the q is complete the function removes from the q
		m_orders.pop_back(); //place it in the parameter^^
		return true;
	}
	return false;
}

void Workstation::display(std::ostream& os) const
{
	if (m_pNextStation != nullptr)
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
	else
		os << getItemName() << " --> END OF LINE" << endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& order)
{
	m_orders.push_front(std::move(order)); //move customer back on customerorder q
	return *this;
}