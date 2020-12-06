// Name: Priya Khatri
// Seneca Student ID: 110149176
// Seneca email: pkhatri4@myseneca.ca
// Date of completion: 11/28/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "LineManager.h"
using namespace std;

LineManager::LineManager(const string& str, std::vector<Workstation*>& station, std::vector<CustomerOrder>& corders) 
	: m_cntCustomerOrder(0)
{
	ifstream file(str); //for linking files (assemble line objects)
	
//	bool more;
//	size_t pos; size_t cnt; size_t formerNo;
	string tmprecord, wstation1, wstation2;
//	Utilities utilies;

	if (!file)
	{
			cerr << "File does not exist!";
	}
	else
	{
		move(corders.begin(), corders.end(), back_inserter(ToBeFilled));
		reverse(ToBeFilled.begin(), ToBeFilled.end());
		copy(station.begin(), station.end(), std::back_inserter(AssemblyLine));

		m_cntCustomerOrder = ToBeFilled.size();

		//while (!file.eof())
		while (std::getline(file, tmprecord))
		{
			//more = true; pos = 0u; cnt = 0u;

			wstation1 = tmprecord.substr(0, tmprecord.find_first_of('|'));

			if (tmprecord.find('|') != std::string::npos)
			{
				wstation2 = tmprecord.substr(tmprecord.find_first_of('|') + 1, tmprecord.length());
			}
			else
			{
				wstation2 = " ";
			}
		
			Workstation* sptr1 = nullptr;
			Workstation* sptr2 = nullptr;

			for (size_t i = 0u; i < station.size(); ++i)
			{
				if (station[i]->getItemName() == wstation1)
				{
					sptr1 = station[i];
					break;
				}
			}

			//if (more)
				//nextStr = utilies.extractToken(record, pos, more);

			/*for (size_t i = 0; i < station.size(); i++)
			{
				if (station[i]->getItemName() == formerStr)
				{
					formerNo = i;
					break;
				}
			}*/

			for (auto j = 0u; j < station.size(); ++j)
			{
				if (station[j]->getItemName() == wstation2)
				{
					sptr2 = station[j];
					break;
				}
			}

			if (sptr2 != nullptr)
			{
				sptr1->setNextStation(*sptr2);
			}

			if (sptr2 == nullptr)
			{
				break;
			}
		}
			/*if (nextStr.size() != 0)
			{
				for (size_t i = 0; i < station.size(); i++)
				{
					if (station[i]->getItemName() == nextStr)
					{
						station[formerNo]->setNextStation(*station[i]);
						break;
					}
				}
			}*/
			/*else
			{
				station[formerNo]->setNextStation(*AssemblyLine[0]);
				AssemblyLine.push_back(station[formerNo]);
			}
		

		for (size_t i = 0; i < corders.size(); i++)
		{
			ToBeFilled.push_back(move(corders[i])); //move objects to back of tobefilled q
		}*/
		wstation1.clear();
		wstation2.clear();
	}
}

bool LineManager::run(std::ostream& os)
{
	//size_t orderNum = ToBeFilled.size();
	static int iterator = 0;
	//ol order = false;
	os << "Line Manager Iteration: " << ++iterator << endl; //os interaction num to see how many times this function has been called

	if (!ToBeFilled.empty())
	{
		Workstation* firstIndex = AssemblyLine.at(5); //starting point
		*firstIndex += move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	for (size_t j = 0u; j < AssemblyLine.size(); ++j) //change order
	{
		AssemblyLine[j]->runProcess(os);
		//AssemblyLine[j]->moveOrder();
		//*AssemblyLine[0] += move(ToBeFilled[j]); //for any customerOrder objects in the to be filled q, start point is assembly
		//Completed.emplace_back(); //avoids extra copy or move operations. appends new element to the end of container
	}

	for (size_t i = 0u; i < AssemblyLine.size(); ++i) //change order
	{
		AssemblyLine[i]->moveOrder();
	}

	for (size_t k = 0; k < m_cntCustomerOrder; ++k)
	{
		//AssemblyLine[k]->runProcess(os);

		//if (k == AssemblyLine.size() - 1)
		if(AssemblyLine[k] != nullptr)
		{
			CustomerOrder tmp;

			/*for (size_t j = 0; j < orderNum; j++)
			{
				AssemblyLine[0]->getIfCompleted(Completed[j]); //complete orders should be moved into the completed q
			}*/
			if (AssemblyLine[k]->getIfCompleted(tmp))
			{
				Completed.push_back(move(tmp));
			}
		}
	}
	
	if (Completed.size() == m_cntCustomerOrder)
	{
		//for (size_t i = 0; i < Completed.size(); i++)
			//Completed[i].display(os);
		return true;
	}

	return false; //if all orders are not filled
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (const auto& i : Completed)
	{
		i.display(os);
	}
}

void LineManager::displayStations() const
{
	//display all stations on the assembly line in the order they 
	//were received from the client

	for (const auto& i : AssemblyLine)
	{
		i->display(cout);
	}
}

void LineManager::displayStationsSorted() const
{
	const Workstation* station1 = nullptr;

	//display all stations on the assembly line in the order they are linked
	for (auto i = 0u; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->getItemName() == "Power Supply")
		{
			station1 = AssemblyLine[i];
			break;
		}
	}

	do
	{
		station1->display(cout);
		station1 = station1->getNextStation();
	} 
	while (station1 != nullptr);
}