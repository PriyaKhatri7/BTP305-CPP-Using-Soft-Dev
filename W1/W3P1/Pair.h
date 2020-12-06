/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | Oct 13, 2020
*/

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <ostream>
using namespace std;
namespace sdds
{
	template<typename K, typename V>
	class Pair
	{
		K m_key;
		V m_value;
	public:
		Pair() : m_key{}
			, m_value{} {} //default. leaves the object in SES

		Pair(const K& key, const V& value) : m_key(key) //copies the values referred to by the parameters into the instance variables
			, m_value(value) {}

		const K& key() const { return m_key; } //returns the key component of the pair
		const V& value() const { return m_value; } //returns the value component of the pair
		virtual void display(ostream& os) const //don't forget to update. CONST!
		{
			os << m_key << " : " << m_value << endl;
		}
	};

	template<typename K, typename V>
	ostream& operator<<(ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}
#endif // !SDDS_PAIR_H