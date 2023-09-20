/* LRC Comments
*		- Variable names start with a lowercase letter,
*			or with an underscore in special situations
* 
*		- It's much easier to work with char input than string input.
*		  Here, validation would be a simple comparison to 'y' or 'n'.
*		  And From the user's point of view, typing one character is much
*		  easier than trying to type a string correctly.
*
*		  When your app is simple, char input is the way to go.
* 
*       - Consider using a range-based for loop to work with strings.
* 
*       - Make your error messages softer. Humans make typos all the time,
*         no need to stress users out.
*/

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
//#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constants
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const double SPEED_TIRED = 200;
const double SPEED_NOT_TIRED = 400;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// local function prototypes
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool all_alpha(string& buffer);
double get_paint_speed();
double get_area();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// entry point
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {

    string buffer;

    //greets the user the when they open the program
    cout << "Hello W! Welcome to your painting calculator.\n";

    // main app loop until user quits
    while (true) {

        // paint speed depends on user tired or not
        double paint_speed = get_paint_speed();

        // set cin exception behavior
        cin.exceptions(istream::failbit | istream::badbit);
        // https://stackoverflow.com/questions/12754486/test-cin-exception

        // square feet to paint
        double area = get_area();

        // calculates painting hours to precision 1 decimal place
        cout << FG_GREEN;
        cout << "It will take you " << setprecision(1) << fixed
            << area / paint_speed << " hour(s) to paint " << area << " square feet.\n";
        cout << RESET;

        //quit check
        cout << "\nDo you want to quit the program? (y/n) ";
        char quit;
        cin >> quit;

        //checks if the first charater of user's input is 'Y' or 'N'
        if (toupper(quit) == 'Y')
            break;
        /* LRC
        *       Notice you don't need an else if after a break statement
        */
    } // main app loop until user quits

    //says goodbye to the user before ending the program
    cout << "Goodbye W and thank you for using your painting calculator. Please come again!\n";

    return(0);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// returns true if string non-empty and all characters are alpha
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool all_alpha(string& buffer) {

    if (!buffer.length())
        return false;

    for (char ch : buffer) {
        if (!isalpha(ch)) {		// C++ library function
            cout << "I don't understand, please type y or n.\n";
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns painting speed based on user input 'y' or 'n'
// #TODO validates string input, only char needed
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_paint_speed() {

    string buffer;

    // input validation loop
    while (true) {

        // user's input into buffer string
        cout << "\nAre you tired today? (y/n) ";
        cin >> buffer;

        /* LRC
        *		When you need to validate a string, a range-based for loop
        *		makes it much easier.
        *
        *		Each loop iteration processes the next string character.
        */

        // only process non-empty string input
        if (all_alpha(buffer)) {

            // force upper case for char input validation
            char tired = toupper(buffer.at(0));

            if (tired == 'Y')
                return SPEED_TIRED;     // terminate validation loop

            if (tired == 'N')
                return SPEED_NOT_TIRED; // terminate validation loop

            cout << "I don't understand, please type y or n.\n";
            continue;                   // ask if tired again
        }
    } // input validation loop
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// - returns number of square feet to paint
// - validates numeric input with cin exceptions
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double get_area() {

    // get number of square feet to paint
    while (true) {

        // get number of square feet to paint
        cout << "What is the number of square feet that you need to paint today?\n";

        try {
            double area;
            cin >> area;
            return area;          // terminate loop on numeric input
        }
        catch (istream::failure e) {
            cerr << "I don't understand, please type a number.\n";
        }
    }
}