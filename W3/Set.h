/*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* Priya Khatri | 110149176 | pkhatri4@myseneca.ca | Oct 13, 2020
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds
{
	template<class T, unsigned int N>//t: type of any element in the collection | n: max num of elements in the collection
	class Set
	{
		T m_list[N];
		size_t m_numElementsInArray = 0;
	public:
		size_t size() const { return m_numElementsInArray; }
		const T& operator[](size_t idx) const { return m_list[idx]; }
		void operator+=(const T& item)
		{
			// check if there's capacity, if so, add the 'item' into the collection
			if (m_numElementsInArray < N)
			{
				m_list[m_numElementsInArray] = item;
				m_numElementsInArray++;
			}
			//otherwise does nothing
		}
	};

}

#endif // !SDDS_SET_H