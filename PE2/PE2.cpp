#include <stdio.h>

int main() {
	//print hello world
	printf("hello, world \n");

	//calculate seconds in december (days * hours * mins * sec)
	int decemberSec = 31 * 24 * 60 * 60;
	printf("Seconds in december: %i \n", decemberSec);
	//area of radius 6.2 circle (pi to 5 decimal places)
	double circleArea = 3.14159 * (6.2 * 6.2);
	printf("Area of a 6.2 radius circle: %f \n", circleArea);

	//integer division
	int oddNum = 5;
	//this prints as 2. 2.5 would round up to 3, so C++ must truncate int division like C#
	printf("int 5 divided by 2 in C++: %i \n", oddNum / 2);
		return 0;
}