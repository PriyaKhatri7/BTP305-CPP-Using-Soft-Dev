#include <iostream>
#include "A.h"
using namespace std;

int main()
{
    int arrI[6]{ 0, 1, 2, 3, 4, 5 };
    cout << process(arrI[6]) << endl;
    
    A arrA[4]{ {1.2}, {2.3}, {3.4}, {4.5} };
    cout << process(arrA[6]) << endl;
    }

//midterm - function template
/*template<typename T, typename... etc>
string within(const T& val, const etc&... other) //needs to be a reference value because it needs to match the overloaded function in the argument list in main
{
    if (val != 0)
    {
        
        cout << "First element: " << sizeof...(other) << endl; //sizeof ... shows us the size of the pack of "something"/ group of pack
        find(val);
    }
    else
    {
        return -1;
        cout << "No elements match" << endl;
    }
}
//specialization for string
template<>  //denotes specialization
string within(const <string> val) {}
//int within<string[], int, double>(int a, double b)
//{
  //  return a, b;
//}

int main()
{
    std::string str[]{ "yes", "no", "who", "when", "why" };
    int a[]{ 1, 2, 3, 4, 5 };
    double b[]{ 1.1, 2.2, 3.3, 4.4, 2.2 };

    auto i = within(str, std::string("who"), std::string("why"), 5);
    std::cout << i << std::endl;

    i = within(a, 3, 5, sizeof a / sizeof(int));
    std::cout << i << std::endl;

    i = within(b, 2.2, 3.3, sizeof b / sizeof(double));
    std::cout << i << std::endl;
}*/

//midterm 3 sample
/*template<typename insertAtEnd>

int main()
{
    {
        int* arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1); // 1
        arrI = insertAtEnd(arrI, 1, 5); // 1, 5
        arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
        delete[] arrI;
    }
    {
        double* arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
        arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
        delete[] arrD;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');// a\0
        arrC = insertAtEnd(arrC, 1, 'b');// ab\0
        arrC = insertAtEnd(arrC, 2, 'c');// abc\0
        cout << arrC;
        delete[] arrC;
    }
}

/*Define a family of functions (a templated function) named insertAtEnd that inserts in a dynamically-allocated array of elements of any type another
element at the end (resize the array). The function should receive as parameters:

the dynamically-allocated array
the size of the array
the element to insert
The function should return the resulted array.

Specialize the function for the type char. In this specialization the array must be null-terminated; the size parameter doesn’t count the null-byte.

The client code listed below uses your templated function, and should not contain memory leaks. The comments next to each statement shows the content the array
should have after the statement is executed.
*/

//Lecture 3
//#include <typeinfo>
//#include <iomanip>//setw
/*template<typename T> //#2 make a template of this overloading instead for easier code. change int and double to T
void print(T val) //(int val) overloading #1
{
    cout << "\33[38;2;0;255;0m" << typeid(val).name() << "\33[0m  "; //adding colour code green
    cout << " Value is: " << val << endl; 
    val.DoSomethingInteresting(); //why is this line not complaing? this function doesn't exists?
    //^^ when instantiated it's known at run-time. it will check if this is whatever type showing in main(int or float)
    * it won't work because it's not matching of type T and if you look in the output message it will show that you need
    * dosomethinginteresting to be of a float type but it's not so this is an error
    * 
}

/*void print(T val) //(double val) overloading #1
{
    cout << "Value is: " << val << endl;
}


int main()
{
    //print(4); //part of overloading 
    //print<int>(4); //i can do this if i wanna be explicit
    //print<float>(4); //i can also do this if i want to and it will set the int to a float with no problem
    //print(4.4); //part of overloading

    //cout << typeid(cout).name() << endl;
}*/

//another example
/*template<typename T, int N = 10> //can also specify values. receive int as a parameter
void print(T val)
{
    T arr[N]; //can do this so it will figure out how much memory to allocate here
    cout << "\33[38;2;0;255;0m" << setw(N) << typeid(val).name() << "\33[0m  ";
    cout << " Value is: " << val << endl;
}


int main()
{
    constexpr int size = 20;
    print(4);
    //print<int, size>(4);
    print<double, size>(4.4);
    //unless i do something like this... ^^^ because it's a constexpr so that is ok
    //print<int, 10>(4); //10 cannot be a variable it has to be a number specified like if i did int size = 3; print<int, size>(4)...can't do that because it won't be known at compile time
    //print(4); //compilor doesn't know what N is so i need to be explicit so i do this^^
    

}*/

//midterm p2
/*#include <iostream>
enum class PassengerType
{
    Child,
    Youth,
    Adult,
    Senior,
    None
};

struct Passenger
{
    const static unsigned short max_name_len{ 16 };
    char name[max_name_len + 1]{ };
    PassengerType type{ PassengerType::None };
};

class Bus : public Passenger
{
    Passenger* p; //dynamically allocate array of pointers to passenger objects
    unsigned int max_capacity;
    unsigned int curr_capacity;

public:
    Bus()
    {
        max_capacity = 50;
        curr_capacity = 0;
    }

    Bus(unsigned int max)
    {
        if (curr_capacity <= 50)
        {
            Bus Max = Bus(max); //this is the max num the bus can hold. storing in obj Bus
        }
    }

    void boardBus(char name, PassengerType* type)
    {
        if (max_capacity < 50 ) // if the bus is not full
        {
            Passenger* tmpArr = new Passenger[curr_capacity + 1];

            for (auto i = 0; i < max_capacity; i++)
            {
                tmpArr[i] = p[i];
                tmpArr = PassengerType::Child;
                tmpArr = PassengerType::Youth;
                tmpArr = PassengerType::Adult;
                tmpArr = PassengerType::Senior;
                tmpArr = PassengerType::None;
            }
            tmpArr[curr_capacity++]; // update the count

            delete[] p;

            p = tmpArr;
            ++curr_capacity;
        }
        return;
    }

    void display() const
    {
        double fee = 0;
        if (PassengerType.curr_capacity == "chidren")
        {
            std::cout << fee << "$0";
        }
        else if(PassengerType.curr_capacity == "youth")
        {
            std::cout << fee << "$1.25";
        }
        else if(PassengerType.curr_capacity == "adult")
        {
            std::cout << fee << "$2.50";
        }
        else if (PassengerType.curr_capacity == "seniors")
        {
            std::cout << fee << "$0";
        }
    }
}; */

//instructions for p2 midterm
/*Create a class Bus that has an dynamically allocated array of pointers to Passenger objects
a non negative interger value that is the max capacity of the bus
a non negative interger value that is the current capacity of the bus

public member functions

default constructor : max size is set to 50
1 arg constructor : max size is passed as parameter
boardbus : check for the next empty spot in the busand assign a nameand a PassengerType to that index

there was a chart that gave passengertypesand fair amounts
Child = $0
Youth = $1.25
Adult = $2.50
Senior = $0

display : display the type and Fare for each typeand the total Fare for everyone on the bus.*/