// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name; //name of customer
	std::string m_product; //name of product being assembled
	unsigned int m_cntItem; //ciunt of number of items for customers order
	Item** m_lstItem = nullptr; //dyn allocated array of pointers. resource the class will manage
	static size_t m_widthField; //max width of field, used for display
public:
	CustomerOrder();
	CustomerOrder(const std::string& record);

	//copy constructors
	CustomerOrder& operator=(const CustomerOrder& source) = delete; //copy assignment
	CustomerOrder& operator=(CustomerOrder&& source) noexcept; //check copy assignment
	
	CustomerOrder(const CustomerOrder& src); //copy
	CustomerOrder(CustomerOrder&& src) noexcept; //copy noexcept specifies it could throw exceptions
	
	~CustomerOrder();

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};
#endif // !CUSTOMERORDER_H