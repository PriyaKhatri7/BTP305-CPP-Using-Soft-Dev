/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | 10-28-2020
*/
#include <iostream>
#include <string>
#include "Book.h"
#include <iomanip>
using namespace std;

namespace sdds
{
	Book::Book()
	{
		b_author = "";
		b_title = "";
		b_countryPub = "";
		b_yearPub = 0;
		b_price = 0.0;
		b_desc = "";
	}

	const std::string& Book::title() const
	{
		return b_title;
	}

	const std::string& Book::country() const
	{
		return b_countryPub;
	}

	const size_t& Book::year() const
	{
		return b_yearPub;
	}

	double& Book::price() //making this not a const allows the user's to update the price ***
	{
		return b_price; //allows client code to update the price
	}

	Book::Book(const std::string& strBook)
	{
		//extracts the information about the book from the string by parsing it and stores the information in the object's attributes. 
		
		//author
		size_t author_delimiter = strBook.find(',');
		int author_start = strBook.find_first_not_of(" ", 0); //take out any spaces
		int author_end = strBook.find_last_not_of(" ", author_delimiter - 1);
		int author_length = (author_end - author_start) + 1;
		string author = strBook.substr(author_start, author_length);
		this->b_author = author; //assigning it so it will display properly

		//title
		size_t title_delimiter = strBook.find(',', author_delimiter + 1);
		int title_start = strBook.find_first_not_of(" ", author_delimiter + 1);
		int title_end = strBook.find_last_not_of(" ", title_delimiter - 1);
		int title_length = (title_end - title_start) + 1;
		string title = strBook.substr(title_start, title_length);
		this->b_title = title;

		//country
		size_t country_delimiter = strBook.find(',', title_delimiter + 1);
		int country_start = strBook.find_first_not_of(" ", title_delimiter + 1);
		int country_end = strBook.find_last_not_of(" ", country_delimiter - 1);
		int country_length = (country_end - country_start) + 1;
		string country = strBook.substr(country_start, country_length);
		this->b_countryPub = country;

		//price
		size_t price_delimiter = strBook.find(',', country_delimiter + 1);
		int price_start = strBook.find_first_not_of(" ", country_delimiter + 1);
		int price_end = strBook.find_last_not_of(" ", price_delimiter - 1);
		int price_length = (price_end - price_start) + 1;
		string price1 = strBook.substr(price_start, price_length);
		double price2 = stod(price1);
		this->b_price = price2;

		//year - don't need first and last but double check in testing for spaces and shit
		size_t year_delimiter = strBook.find(',', price_delimiter + 1);
		int year_start = strBook.find_first_not_of(" ", price_delimiter + 1);
		int year_end = strBook.find_last_not_of(" ", year_delimiter - 1);
		int year_length = (year_end - year_start) + 1;
		string year1 = strBook.substr(year_start, year_length);
		int year2 = stoi(year1);
		this->b_yearPub = year2;

		//description
		size_t desc_delimiter = strBook.find('.', year_delimiter + 1); //. because this is what we're trying to look for in the file and . is at the end
		int desc_start = strBook.find_first_not_of(" ", year_delimiter + 1);
		int desc_end = strBook.find_last_not_of(" ", desc_delimiter);
		int desc_length = (desc_end - desc_start) + 1;
		string desc = strBook.substr(desc_start, desc_length);
		this->b_desc = desc;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << setw(20) << book.b_author << " | ";
		os << setw(22) << book.b_title << " | ";
		os << setw(5) << book.b_countryPub << " | ";
		os << setw(4) << book.b_yearPub << " | ";
		os << setw(6) << fixed << setprecision(2) << book.b_price << " | ";
		os << book.b_desc << endl;

		return os;
	}

}