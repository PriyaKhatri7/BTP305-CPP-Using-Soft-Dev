/* Find the key code for a keystroke
 * findKeyCode.cpp
 * November 18 2011
 * Chris Szalwinski
 */

#include <cstdio>
#include "console.h"
using namespace cio;

int main() {
    int key;
    char buffer[6];

    console.setPosition(2, 8);
    console << "Find The Key Code Application";
    console.setPosition(5, 8);
    console << "Press a key (q to quit) ";
    console.setPosition(7, 8);
    console << "The Key\'s Code is : ";

    do {
        console.setPosition(7, 31);
        console >> key;
        std::sprintf(buffer, "%4d ", key);
        console.setPosition(7, 28);
        console << buffer;
        if (key == 0 || key == 224) {
            console >> key;
            std::sprintf(buffer, "%3d", key);
            console << buffer;
        } else
            console << "   ";
    } while (key != 'q');

    console.setPosition(9, 8);
    console << "Press any key to quit ";
    console.pause();
}