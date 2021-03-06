/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | 10-28-2020
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{

	class Book
	{
		std::string b_author;
		std::string b_title;
		std::string b_countryPub;
		int b_yearPub;
		double b_price;
		std::string b_desc; //a short summary of the book
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(); //this should allow customers to update the price
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& book); //insertion operator

	};
	template<typename T>
	void fixSpelling(T spellChecker)
	{
		//calls the overloaded operator() on instance spellchecker, passing it to the book description 
		spellChecker operator(std::string& b_desc); //**double check if this is right
	}
}
#endif // !BOOK_H