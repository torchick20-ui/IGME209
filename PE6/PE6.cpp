// PE6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void passByValue(int xValue)
{
    xValue = 30;
}

void passByReference(int& xReference)
{
    xReference = 40;
}

void passByPointer(int* xPointer)
{
    *xPointer = 50;
}



int main()
{
    
    int myInteger = 10;
    int* myPointer;
    myPointer = &myInteger;
    *myPointer = 20;

    std::cout << myInteger << " is myInteger's value!\n";

    
    passByValue(myInteger);
    std::cout << myInteger << " is myInteger's value!\n";
    //This directly passes in the int to by xValue's value, but does not affect myInt itself, rather making a new int variable at a different address with a copy of myInt's value. Nothing effectively happens to myInt.
    //myInt is still 20

    
    passByReference(myInteger);
    std::cout << myInteger << " is myInteger's value!\n";
    //this passes the address. This makes xReference like another name for myInt within the function, as opposed to xValue being like a disconnected copy of it.
    //xReference is getting the original memory location of myInt and overwriting it there, causing it to make a permanent change unlike xValue.
    //myInt is now 40.

    
    passByPointer(myPointer);
    std::cout << myInteger << " is myInteger's value!\n";
    //This affects the value of myInt by deference. This is telling the function to go to myInt's address and alter the value stored there, the * is saying to target the value at the address to assign the 50.
    //The value of myInt becomes 50.
     
    
    //I am a bit shakey on the difference between how pass by pointer works vs passing by reference, but reference does not need the * operator to modify the data at the address, 
    // the value can be referenced implicitly, and a pointer can be changed to point to somewhere else in memory to do things like iterate over arrays.
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
