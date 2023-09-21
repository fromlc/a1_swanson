//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// W_painting_calculator.cpp 
// 
// William Swanson
// W Paints
// September 17, 2023
//
// - prompts the user If their tired or not and the area they need to paint
// - calculates and displays the amount of time it would take to paint it in hours
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "ansi_colors.h"

#include <iostream>
#include <iomanip>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constants
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const double SPEED_TIRED = 200;
const double SPEED_NOT_TIRED = 400;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// local function prototypes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_paint_speed();
double get_area();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// entry point
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {

	//greets the user the when they open the program
	cout << "Hello W! Welcome to your painting calculator.\n";

	// main app loop until user quits
	while (true) {

		// paint speed depends on user tired or not
		double paint_speed = get_paint_speed();

		// square feet to paint
		double area = get_area();

		// calculates painting hours to precision 1 decimal place
		cout << FG_GREEN << setprecision(1) << fixed
			<< "It will take you " << area / paint_speed
			<< " hour(s) to paint " << area << " square feet.\n"
			<< RESET;

		//quit check
		cout << "\nDo you want to quit the program? (y/n) ";
		char quit;
		cin >> quit;

		//checks if the first charater of user's input is 'Y' or 'N'
		if (toupper(quit) == 'Y')
			break;

	} // main app loop until user quits

	//says goodbye to the user before ending the program
	cout << "Goodbye W and thank you for using your painting calculator. Please come again!\n";

	return(0);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns painting speed based on user input 'y' or 'n'
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_paint_speed() {

	// input validation loop
	while (true) {

		string buffer;

		// user's input into buffer string
		cout << "\nAre you tired today? (y/n) ";
		cin >> buffer;

		// force upper case for char input validation
		char tired = toupper(buffer.at(0));

		if (tired == 'Y')
			return SPEED_TIRED;     // terminate validation loop

		if (tired == 'N')
			return SPEED_NOT_TIRED; // terminate validation loop

		// flush console io buffer
		cout << endl << "I don't understand, please type y or n.\n";

	} // input validation loop
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns number of square feet to paint
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_area() {

	cout << "What is the number of square feet that you need to paint today?\n";
	string buffer;
	cin >> buffer;

	// strtod() does not throw exceptions
	return strtod(buffer.c_str(), nullptr);
}