#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main()
{
	//Declare Variables
    int radius, option, width, length, height;
    float rectangle_area, circle_area, triangle_area;
    const double PI = 3.14159;

    //User Input
    cout << "1. Calculate the Area of a circle" << endl;
    cout << "2. Calculate the Area of a rectangle" <<  endl;
    cout << "3. Calculate The Area of a triangle" << endl;
    cout << "4. Quit" <<endl;


    while (1==1)
    {
    	cout << "Enter your choice (1-4): ";
        cin >> option;
        cout << endl;

			switch (option)
			{
				case 1:
					cout << "enter the radius of a circle\n";
					cin >> radius;
					circle_area= PI * radius * radius;
					cout << "Circle Area = " << circle_area << endl;
				break;

				case 2:
					cout << "enter the width of a rectangle"<< endl;
					cin >> width;
					cout << "enter the length of the rectangle" << endl;
					cin >> length;

					rectangle_area = width*length;
					cout << "Rectangular Area = " << rectangle_area << endl;
				break;

				case 3:
					cout << "enter the length of a triangle" << endl;
					cin >> length;
					cout << "enter the height of a triangle" << endl;
					cin >> height;

					triangle_area = length * height *0.5;

					cout << "Triangle Area= " << triangle_area << endl;

				break;

				case 4:
					cout << "program quit" << endl;
					return 0;

        }
    }
}
