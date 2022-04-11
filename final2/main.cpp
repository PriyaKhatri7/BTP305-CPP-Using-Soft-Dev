#include <iostream>
#include <algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<forward_list>
using namespace std;
struct Device
{
    std::string model;
    std::string maker; // the brand of the device
    double price = 0.0;
};

void handleElectronics(const std::vector<Device>device)
{
    find_first_of(device.begin(), device.end(), device.begin(), device.end(), [](Device d) {
        if (d.model != "Samsung")
        {
            return d;
        }
        else
        {
            d.model = nullptr;
            cout << "All Samsung" << endl;

        }
        return d;
        });

    transform(device.begin(), device.end(), device.begin(), [](Device& d2) {
       if(d2.model == "Samsung")
            return d2.price * 0.9;
        });

    for_each(device.begin(), device.end(), [](Device d3) {
        cout << "The model is: " << d3.model << " and the Price is: " << d3.price; });

    auto average = accumulate(device.begin(), device.end(), 0) / device.size();
    {
        cout << average <<" is Average\n";
    }

    sort(device.begin(), device.end(), [](const Device d4, const Device d5)
        {
            if (d4.maker == d5.maker)
            {
                return d4.price > d5.price;
            }
        });
}