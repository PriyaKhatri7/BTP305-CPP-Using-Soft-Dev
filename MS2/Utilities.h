// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/21/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities
{
	size_t m_widthField; //--specifying the length of the token extracted; used for display purpose later; default value is 1.
	//^^^ static because nonstatic member reference must be relative to a specific object (setDelimiter)
	static char m_delimiter;
public:
	Utilities();
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
	~Utilities();
};

#endif // !SDDS_UTILITIES_H