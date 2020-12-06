// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/21/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iomanip>
using namespace std;

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& record) : CustomerOrder()
{
	
	Utilities utility; //utility object - extract the tokens and populate the current instance
	bool more = true;
	size_t next_pos = 0;
	string tmp = record;

	//extraction first... customer name
	m_name = utility.extractToken(tmp, next_pos, more);
	
	//order name -- Gaming pc
	m_product = utility.extractToken(tmp, next_pos, more);

/*	for (auto i = 0; i < 2; ++i) //2 fields for whatever is above...
	{
		if (more)
		{
			switch (i)
			{
			case 0: m_name = utility.extractToken(record, next_pos, more);
				break;
			case 1: m_product = utility.extractToken(record, next_pos, more);
				break;
			}
		}
	}*/
	//list of items for order for atleast 1 item
	m_cntItem = count(record.begin(), record.end(), utility.getDelimiter()) - 1;
	delete[] m_lstItem;
	m_lstItem = nullptr;
	m_lstItem = new Item* [m_cntItem]; //pointer Item
	
	if (m_cntItem >= 1)
	{
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			string tmpline = utility.extractToken(tmp, next_pos, more); //displays the cpu part
			m_lstItem[i] = new Item(tmpline);
		}
	}
	if (m_widthField < utility.getFieldWidth()) //was messing me up on placement...do this at the end
	{
		m_widthField = utility.getFieldWidth();
	}
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& source) noexcept
{
	if (this != &source) 
	{
		/*m_name = std::move(source.m_name);
		m_product = std::move(source.m_product);
		m_cntItem = source.m_cntItem;
		m_lstItem = std::move(source.m_lstItem);*/

		m_name = source.m_name;
		m_product = source.m_product;

		delete[] m_lstItem;

		m_cntItem = source.m_cntItem;
		m_lstItem = source.m_lstItem;

		source.m_lstItem = nullptr;
		source.m_name = "";
		source.m_product = "";
		source.m_cntItem = 0;
	}

	return *this;
}

CustomerOrder::CustomerOrder(const CustomerOrder& src)
{
	throw std::string("ERROR: Cannot make copies.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
	m_lstItem = nullptr;
	*this = std::move(src); // already checks to make sure if this != &src
}

CustomerOrder::~CustomerOrder()
{
	for (auto i = 0u; i < m_cntItem; ++i)
	{
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const
{
	for (size_t i = 0; i < m_cntItem; ++i)
		if (!m_lstItem[i]->m_isFilled)
			return false;

	return true; //returns true if all the items in the order have been filled
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	for (size_t i = 0; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_itemName == itemName)
		{
			if (!m_lstItem[i]->m_isFilled) //returns the Item::m_isFilled of the item specified as a parameter.
				return false;
		}
	}
	return true; //If the item doesn't exist in the order, return true.
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++) //contains atleast 1 element
	{
		if (m_lstItem[i]->m_itemName == station.getItemName()) //has item at station
		{
			if (station.getQuantity() < 0)
			{
				os << "Unable to fill " << m_name << ", " << m_product << "[" << station.getItemName() << "]" << endl;
			}

			if (station.getQuantity() > 0)
			{
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();

				os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
			}
			
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	
	for (auto i = 0u; i < m_cntItem; ++i)
	{
		os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] " <<
			setfill(' ') << std::left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
			<< (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
	}
}
