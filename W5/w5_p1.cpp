// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"
#include <string>

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		std::ifstream file(argv[1]); //load the collection of books from the file "argv[1]".
		size_t cnt = 0;
		std::string pc; //read the line form the file u need to store it to something
		
		if (!file) //just to make sure the code is right even though it doesn't show in the output
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n"; 
			return 1;
		}
		
		do
		{
			//read one line at a time, and pass it to the Book constructor
			std::getline(file, pc); //getline is reading one at a time - store each book read into the array "library"
			if (file)
			{
				if (pc[0] != '#') //lines that start with "#" are considered comments and should be ignored
				{
					library[cnt] = sdds::Book(pc);
					cnt++;
				}
					
			}

		} while (file);
  
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	auto compLambda = [usdToCadRate, gbpToCadRate](Book& b) //- the expression should receive a single parameter of type "Book&"
	{
		if (b.country() == "US") // if the book was published in US, multiply the price with "usdToCadRate"
		{
			b.price() *= usdToCadRate; //and save the new price in the book object
		}
		else if (b.country() == "UK" && (b.year() >= 1990 && b.year() <= 1999)) //if the book was published in UK between 1990 and 1999 (inclussive),
		{
			b.price() *= gbpToCadRate; //multiply the price with "gbpToCadRate" and save the new price in the book object
		}
		return b.price();
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto& book : library)
	{
		compLambda(book);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}