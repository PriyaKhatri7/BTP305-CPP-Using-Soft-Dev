// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/14/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter = '\0'; //this ling fixes the unresolved error because it's static

Utilities::Utilities()
{
	setFieldWidth(1); //default 1
}

void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth; //--sets the field width of the current object to the value of the parameter
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField; //--returns the field width of the current object
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string tmpstr;
	
	size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1); //This function uses the delimiter to extract the next token from str starting at next_pos.
	size_t len = (next_delimiter_pos - next_pos); //get the length

	tmpstr = str.substr(next_pos, len); //store in temp. copy string to object. creating substr starting at next_pos

	/* the point if this function it to search between delimiters to extract the token aka string
	so first u need to find the position of the delimiters
	then i can extract the token in between 2 delimiters*/
	next_pos = next_pos + tmpstr.length() + 1; //next position changes to...

	//if (tmpstr.find(m_delimiter) != std::string::npos) { //If a delimiter exist then extract data, else assume ur are on last part of string line and extract last bit of data
		//{
	if (m_widthField < tmpstr.length())
	{
		m_widthField = tmpstr.length(); //update the currobj's widthfield is the currvalue is less than size of the token extracted
	}
	//tmpstr = tmpstr.substr(0, tmpstr.find(m_delimiter));
	//more = true; //sets more to true; 

	if (tmpstr.empty()) {
		throw std::string("No data between delimiters!"); //exception if there are two delimiters with no token between them
		more = false; //false otherwise.
	}
	else
	{
		//tmpstr = tmpstr.substr(0, tmpstr.length());
		more = true;
		return tmpstr;
	}
	

	return tmpstr;
}

void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter; //--sets the delimiter for this class to the character received
}

char Utilities::getDelimiter()
{
	return m_delimiter; //--returns the delimiter character.
}

Utilities::~Utilities()
{
}
