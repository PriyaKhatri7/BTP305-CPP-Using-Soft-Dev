// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/14/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station()
{
	s_currItems = 0;
}

Station::Station(const string& station)
{
	s_currItems = 0; //set empty

	Utilities tmp; //object local in function
	
	bool more = true; 
	size_t next_pos = 0;
	
	for (auto i = 0; i < 4; ++i) //4 fields
	{
		if (more)
		{
			switch (i)
			{
			case 0: s_name = tmp.extractToken(station, next_pos, more);
				break;
			case 1: s_serialNum = std::stoi(tmp.extractToken(station, next_pos, more));
				break;
			case 2: s_currItems = std::stoul(tmp.extractToken(station, next_pos, more));
				break;
			case 3:s_desc = tmp.extractToken(station, next_pos, more);
				break;
			}

			//now update the width to max val for station and utilities
			if (tmp.getFieldWidth() > m_widthField)
			{
				m_widthField = tmp.getFieldWidth();
			}
		}
		else
			break;
	}
	id_generator++; //(not)counter for display
	s_id = id_generator;
	/*possibly scrap this and redo
	size_t next_pos = station.find(tmp.getDelimiter());
	s_name = station.substr(0, next_pos);
	s_serialNum = stoul(tmp.extractToken(station, next_pos, more)); // extract token and convert from string to ulong
	s_currItems = stoi(tmp.extractToken(station, next_pos, more));
	//s_desc = m_utility.extractToken(station, next_pos, more);

	// update the utility fieldWidth with the largest name's length
	if (tmp.getFieldWidth() < s_name.length())
	{
		tmp.setFieldWidth(s_name.length());
	}*/
}

const std::string& Station::getItemName() const 
{
	return s_name; //- returns the name of the current Station object
}

unsigned int Station::getNextSerialNumber() 
{
	return s_serialNum++; //– returns the next serial number to be used on the assembly line and increments m_serialNumber
}

unsigned int Station::getQuantity() const 
{
	return s_currItems; //– returns the remaining quantity of the current Station object
}

void Station::updateQuantity() 
{
	if (getQuantity() > 0) 
	{
		s_currItems -= 1; //– subtracts 1 from the available quantity; should not go below 0.
	}
	//or can i just say...
	//--s_currItems;
}

void Station::display(std::ostream& os, bool full) const
{
	/*os << setw(3) << "[00" << s_id << "] Item: " << s_name << "[" << s_serialNum << "Quantity : " << s_currItems << "Description : " << s_desc << endl;

	if (full == false)
	{
		os << setw(3) << "[" << s_id << "] Item : " << s_name << "[" << s_serialNum << endl;
	}*/

	os << setw(3) << "[00" << s_id << "] Item: " << std::setw(13) << std::left << fixed << getItemName();
	os << "[" << std::setw(6) << std::setfill('0') << std::right << s_serialNum << "]" << std::setfill(' ');

	full ? os << " Quantity: " << std::setw(13) << std::left << s_currItems <<
		"Description: " << s_desc << std::endl : os << std::endl; //practising conditional ? and :
}

Station::~Station()
{
}

