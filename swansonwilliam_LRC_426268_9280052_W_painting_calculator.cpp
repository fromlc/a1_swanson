//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// W_painting_calculator.cpp 
// 
// William Swanson
// W Paints
// September 17, 2023
// 
// Modified by Prof. Linda C
//
// - prompts the user If their tired or not and the area they need to paint
// - calculates and displays the amount of time it would take to paint it in hours
// 
// Thanks to StackOverflow for regex code:
// https://stackoverflow.com/questions/36319706/c-regex-equivalent-for-stringfind
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "ansi_colors.h"

#include <iomanip>
#include <iostream>
#include <regex>

//using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const double SPEED_TIRED = 200;
const double SPEED_NOT_TIRED = 400;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constants
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// get_stream_char() max digits to cin including '\n'
const int MAX_CIN_CHARS = 16;
// get_stream_char() reports non-alpha input as this
const char CHAR_INPUT_UNKNOWN = '?';
// pattern for regex compare with area input
const std::string REGEX_FLOATING_POINT = "^[0-9]+[.]?[0-9]*$";

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// local function prototypes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// returns first char of input line
char get_stream_char();
// returns 'Y', 'N', or CHAR_INPUT_UNKNOWN
char get_command_char();
// returns square feet per hour user can paint
double get_paint_speed();
// returns square feet of area to paint
double get_input_area();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// entry point
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {

	//greets the user the when they open the program
	std::cout << "Hello W! Welcome to your painting calculator.\n";

	// loop until user quits
	while (true) {

		// paint speed depends on user tired or not
		double paint_speed = get_paint_speed();
		double area = get_input_area();

		// calculates painting hours to precision 1 decimal place
		std::cout << FG_GREEN << std::setprecision(1) << std::fixed
			<< "\nIt will take you " << area / paint_speed
			<< " hour(s) to paint " << area << " square feet.\n"
			<< RESET;

		//quit check: assume non 'Y' input means quit
		std::cout << "\nCalculate another job? (y/n) ";

		// terminate app loop on first charater of user's input is NOT 'Y'
		if (get_command_char() != 'Y')
			break;

	} // loop until user quits

	//says goodbye to the user before ending the program
	std::cout << "\nGoodbye W and thank you for using your painting calculator."
		<< " Please come again!\n";

	return(0);
}

//------------------------------------------------------------------------------
// - returns the first char in std::cin stream
//------------------------------------------------------------------------------
char get_stream_char() {

	char user_input[MAX_CIN_CHARS];
	std::cin.getline(user_input, MAX_CIN_CHARS);

	// clear std::cin error flags
	std::cin.clear();

	return user_input[0];
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - when input is alpha, returns user first char in upper case
// - otherwise, returns '?'
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
char get_command_char() {

	char ch = get_stream_char();

	return isalpha(ch) ? toupper(ch) : CHAR_INPUT_UNKNOWN;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns painting speed based on user input 'y' or 'n'
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_paint_speed() {

	// input validation loop
	while (true) {

		// user's input into buffer string
		std::cout << "\nAre you tired today? (y/n) ";
		char tired = get_command_char();

		if (tired == 'Y')
			return SPEED_TIRED;     // terminate validation loop

		if (tired == 'N')
			return SPEED_NOT_TIRED; // terminate validation loop

		std::cerr << FG_CYAN 
			<< "Please type y or n in upper or lower case.\n" 
			<< RESET;

	} // input validation loop
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns number of square feet to paint
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_input_area() {

	char user_input[MAX_CIN_CHARS];		// std::cin buffer for getline()
	std::string str_input;				// put input in string for regex

	// input validation loop for floating point format
	while (true) {

		std::cout << "\nWhat is the number of square feet that you need to paint today? ";

		std::cin.getline(user_input, MAX_CIN_CHARS);
		
		// clear std::cin's error flags to allow more input
		std::cin.clear();

		// #TODO Regex expression does not allow commas in fp input
		std::string pattern(REGEX_FLOATING_POINT);

		// Get the regex object 
		std::regex rx(pattern);

		// User input is string input to regex object
		str_input = user_input;

		// Count the number of matches inside the iterator
		std::ptrdiff_t number_of_matches = std::distance(
			std::sregex_iterator(str_input.begin(), str_input.end(), rx),
			std::sregex_iterator());

		// One match means well-formed floating point number
		if (number_of_matches == 1)
			break;

		std::cerr << FG_CYAN
			<< "Please enter a floating point number with no commas.\n"
			<< RESET;

		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// return floating point value that matches regex pattern
	return strtod(user_input, nullptr);
}
