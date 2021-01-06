#include <ios> //skipws
#include "Utilities.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* tmpVehicle = nullptr; //in object is passed is the tag
		char tmpTag = '\0'; //check the tag variable
		std::string tmp = "";
		char delimiter = ',';

		in >> std::skipws >> tmpTag; //skipws is to skip as many whitespace as needed that are read from stream  
		
		//check if everything is valid
		bool valid = tmpTag == 'c' || tmpTag == 'C' || tmpTag == 'r' || tmpTag == 'R'; 
		
		if(valid)
		{	
			if (tmpTag == 'c' || tmpTag == 'C')
			{
				in >> std::skipws >> delimiter;
				tmpVehicle = new Car(in); //dyn instance of type Car - make object
			}
			else if (tmpTag == 'r' || tmpTag == 'R')
			{
				tmpVehicle = new Racecar(in); //make a instance of type Racecar
			}
		}
		else
		{	
			in.unget(); //Attempts to decrease the current location in the stream by one character
			std::getline(in, tmp);
			throw tmpTag;
		}
		//return tmpVehicle;
	}
}