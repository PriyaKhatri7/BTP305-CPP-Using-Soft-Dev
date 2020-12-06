// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		/*compares the elements in the two received lists for common product codes and builds the user - friendly list from the matching pairs.
		For each successful comparison, your function allocates dynamic memory of Product type using that description and the price.
		Your function then validates the Product object and adds it to its list.*/
		
		for (size_t i = 0; i < desc.size(); ++i)
		{
			for (size_t j = 0; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code) //checks both objects
				{
					Product* p = new Product(desc[i].desc, price[j].price); //allocate new mem of Product type
					p->validate(); //validates the object
					priceList += p; //adds to list
					delete p; //deallocate mem for p
				}
			}
		}
		return priceList;
	}

	//using smart pointers
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); ++i)
		{
			for (size_t j = 0; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> p{ new Product(desc[i].desc, price[j].price) };
					p->validate();
					priceList += p;
				}
			}
		}
		return priceList;
	}
}