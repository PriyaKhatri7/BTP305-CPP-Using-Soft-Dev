// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/21/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include "Utilities.h"
#ifndef STATION_H
#define STATION_H

class Station
{
	//char array means string
	//c style char array means char array

	int s_id; //the id of a station
	std::string s_name; //the name of the item handled that the station(array of characters)
	std::string s_desc; //the description of the station(array of characters)
	unsigned int s_serialNum; //the next serial number to be assigned to an item at this station(integer)
	int s_currItems; //the quantity of current items left in stock(integer)

	//statc data
	static size_t m_widthField; //-- max characters required to print to screen the item name, serial number and quantity for any object of type Station
	static size_t id_generator; //-- a variable used to generate IDs for new instances of type Station.Every time a new instance is created, the current value of the id_generator is stored in the instance, and id_generator is incremented

public:
	Station();
	Station(const std::string& station);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
	~Station();
};

#endif // !STATION_H