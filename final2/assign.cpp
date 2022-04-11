#include <iostream>
#include <string>
#include <utility>
#include "assign.h"

using namespace std;

Assign::Assign(string str, double value)
{
	    m_title = str;
	    m_value = value;
	    for (auto i = 0; i < 123; ++i)
		        m_data[i] = static_cast<long long>(i * value);
	}

Assign & Assign::update()
{
	    for (auto it = m_data.begin(); it != m_data.end(); ++it)
		* it += 5;
	    return *this;
	}

double Assign::getData(size_t step) const
{
	    double sum = 0;
	    for (auto i = step; i < m_data.size(); i += step)
		        sum += m_data[i];
	    return sum;
	}

ostream & Assign::log() const
{
	    clog << m_title << " : " << m_value << "\n\t";
	    for (auto& elem : m_data)
		        clog << elem << ", ";
	
		    return clog << '\n';
	}