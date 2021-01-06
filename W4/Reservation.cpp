#include <iostream>
#include <iomanip>
#include <string>
#include "Reservation.h"

using namespace std;
namespace sdds
{
	Reservation::Reservation()
	{
		m_reservation_id = "";
		m_nameOfReservation = "";
		m_email = "";
		m_numOfPeople = 0;
		m_day = 0;
		m_hour = 0;
	}

	Reservation::Reservation(const std::string& res) : Reservation()
	{
		//assign each part to the right variable
		size_t id_delimiter = res.find(':'); //find() to look for a delimiter
		int id_start = res.find_first_not_of(" ", 0); //find_first_not_of and last are built in for spaces
		int id_end = res.find_last_not_of(" ", id_delimiter - 1);
		int id_length = (id_end - id_start) + 1;
		string id = res.substr(id_start, id_length); //starting index or string ur extracting, how many index. u gotta take each string as a whole and split it up
		m_reservation_id = id;
		//string s; s.erase(std::find(s.begin(), s.end(), ' ')); //don't use this line because thats what find_first_not_of and last of is for

		//for name
		size_t name_delimiter = res.find(',', id_delimiter + 1); //find() to look for a delimiter
		int name_start = res.find_first_not_of(" ", 0); //find_first_not_of and last are built in for spaces
		int name_end = res.find_last_not_of(" ", name_delimiter - 1);
		int name_length = (name_end - name_start) + 1;
		string name = res.substr(name_start, name_length);
		m_nameOfReservation = name;

		//email
		size_t email_delimiter = res.find(',', name_delimiter + 1); //find() to look for a delimiter
		int email_start = res.find_first_not_of(" ", 0); //find_first_not_of and last are built in for spaces
		int email_end = res.find_last_not_of(" ", email_delimiter - 1);
		int email_length = (email_end - email_start) + 1;
		string email = res.substr(email_start, email_length);
		m_email = email;

		//party size
		size_t people_delimiter = res.find(',', email_delimiter + 1); //find() to look for a delimiter
		int people_length = (people_delimiter - email_delimiter);
		string people1 = res.substr(email_delimiter, people_length);
		int people2 = std::stoi(people1);//string to integer. we don't use first of and last of because we aren't looking for a string, looing for a number
		m_numOfPeople = people2;

		//day
		size_t day_delimiter = res.find(',', people_delimiter + 1); //find() to look for a delimiter
		int day_length = (day_delimiter - people_delimiter);
		string day1 = res.substr(day_delimiter + 1, day_length - 1);
		int day2 = std::stoi(day1); 
		m_day = day2;

		//time hour
		size_t time_delimiter = res.find(",", day_delimiter + 1);
		int time_length = (time_delimiter - day_delimiter);
		string time1 = res.substr(day_delimiter + 1, time_length - 1);
		int time2 = std::stoi(time1);
		m_hour = time2;

		
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		
		if (res.m_hour >= '6' && res.m_hour <= '9')
		{
			os << left << "Reservation " << res.m_reservation_id << ": ";
			os << setw(11) << right << res.m_nameOfReservation << "<" << res.m_email << ">"
				<< "Breakfast on day " << res.m_day << " @ " << res.m_hour << ":" << " for " << res.m_numOfPeople << " people.\n";
		}
		else if (res.m_hour >= '11' && res.m_hour <= '3')
		{
			os << left << "Reservation " << res.m_reservation_id << ": ";
			os << setw(11) << right << res.m_nameOfReservation << "<" << res.m_email << ">"
				<< "Lunch on day " << res.m_day << " @ " << res.m_hour << ":" << " for " << res.m_numOfPeople << " people.\n";
		}
		else if (res.m_hour >= '5' && res.m_hour <= '9')
		{
			os << left << "Reservation " << res.m_reservation_id << ": ";
			os << setw(11) << right << res.m_nameOfReservation << "<" << res.m_email << ">"
				<< "Dinner on day " << res.m_day << " @ " << res.m_hour << ":" << " for " << res.m_numOfPeople << " people.\n";
		}
		else
			os << left << "Reservation " << res.m_reservation_id << ": ";
			os << setw(11) << right << res.m_nameOfReservation << "<" << res.m_email << ">"
			<< "Drinks on day " << res.m_day << " @ " << res.m_hour << ":" << " for " << res.m_numOfPeople << " people.\n";
		return os;
	}


	/*
	* overload the insertion operator to insert the content of a reservation object into an ostream object:

			the name on the reservation should be printed on a field of size 10, aligned to the right
			the email on the reservation (including the characters < and >) should be printed on a field of size 20, aligned to the left.
			this operator should insert the endline character before returning control.
	*/
}