/*
Priya Khatri | 110149176 | pkhatri4 | 10-28-2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string c_name;
		T* c_items; //dyn allo. resizing it whne a new item is added
		size_t c_sizeArr[];

		void (*func)(const Collection<T>&, const T&);//func is the name of the pointer and accepts 2 Coll and T as params and always initialize
	
	public:
		Collection(std::string name)
		{
			name = c_name;
			c_items[0] = 0;
			c_sizeArr = 0;
		}

		Collection(const Collection& src) = delete; //copy constructor
		Collection& operator=(const Collection& src) = delete; //copy assignment operator

		~Collection()
		{
			delete[] c_items;
			c_items = nullptr;
		}

		const std::string& name() const
		{
			return c_name;
		}

		size_t size() const
		{
			return c_items;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			//called when an item is added to the collection.
			Collector(T theItems) : c_items{ theItems } {} //stores in c_items
		}

		Collection<T>& operator+=(const T& item)
		{
			if (item.c_item > 0 && item.c_name != "") //check valid obj
			{
				T* tmpT = new T[c_name + 1]; //create new array

				T(auto i = 0; i < c_name; i++)
				{
					tmpT[i] = c_sizeArr[i];
				}
				tmpT[c_sizeArr] = item; //update the count
				delete[] c_sizeArr;

				c_sizeArr = tmpT; //switch to bigger array
				++c_items; //update the size
			}
			return *this;
		}

		T& out_of_range& operator[](size_t idx) const
		{
			if (std::string str1 = std::to_string())
			{
				throw "Bad index" << idx. "].Collection has " << c_sizeArr << " items." << endl;
			}
			else
				return c_items[idx];
		}

		T* operator[](std::string title) const
		{
			if (c_items == nullptr || c_items == "")
			{
				return nullptr;
			}
		}


	};
}
#endif // !SDDS_COLLECTION_H
