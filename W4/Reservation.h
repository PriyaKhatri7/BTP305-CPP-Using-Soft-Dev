/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Priya Khatri | 110149176 | pkhatri4@myseneca.ca | 10/14/2020 */
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <ostream>
namespace sdds
{
	class Reservation
	{
		std::string m_reservation_id; //array of chars = string literal
		std::string m_nameOfReservation; 
		std::string m_email; //used to send confirmation that the reservation can be honored or cannot
		size_t m_numOfPeople; //people in the party. can't be negative
		size_t m_day; //when the party expects to come (for simplicity, the day is an integer between 1 and 31)
		size_t m_hour; //when the party expects to come (for simplicity, the hour is an integer between 1 and 24)
	public:
		Reservation(); 
		Reservation(const std::string& res);

		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
	
}
#endif // !SDDS_RESERVATIONS_H
