/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | Oct 13, 2020 */
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iomanip>
#include <iostream>
#include "Pair.h"
namespace sdds
{
	template<typename K, typename V>
	class PairSummable : public Pair <K, V>
	{
		static V p_initialSum; //inital value
		static size_t p_min_width; //min field 

	public:
		PairSummable()
		{
			//leave empty. will set.
		}

		PairSummable(const K& key, const V& value = p_initialSum) : Pair<K, V>(key, value) //base constructor
		{
			if (p_min_width < key.size()) //update the width ONLY if necessary
			{
				p_min_width = key.size();
			}
		}

		PairSummable<K, V>& operator+=(const PairSummable<K, V>& PairSum)
		{
			if (this->key() == PairSum.key()) //if both are the same
			{
				//return a ref to the current obj
				*this = PairSummable(this->key(), this->value() + PairSum.value());
			}
			return *this; //deref. otherwise do nothing
		}

		void display(std::ostream& os) const
		{
			os << setw(p_min_width) << left;
			Pair<K, V>::display(os);
			os << right;
		}
	};
	template<typename K, typename V> //template before each time
	size_t PairSummable<K, V>::p_min_width = 0; //initial value for summ is 0
	template<>
	std::string PairSummable<std::string, std::string>::p_initialSum = ""; //initial value for summ is empty string
	template<>
	int PairSummable<std::string, int>::p_initialSum = 0; 
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& PairSum) //for the operator
	{
		// basically the same as += up
		if (PairSum.key() == this->key() && this != &PairSum)
		{
			if (value() == "") //check within the validation
			{
				*this = PairSummable(this->key(), this->value() + PairSum.value());
			}
			else
			{
				*this = PairSummable(this->key(), this->value() + ", " + PairSum.value()); //makes sure it's concats
			}
		}
		return *this;
	}
}
#endif // !SDDS_PAIRSUMMABLE_H
