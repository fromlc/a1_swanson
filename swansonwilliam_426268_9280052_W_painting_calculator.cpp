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


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// entry point
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	//declares all varbles and stings
	double Paint_Speed, Area;
	char Tired, Quit;
	bool Number_Check, Quit_Check;
	int String_Size;
	string Buffer;

	//greets the user the when they open the program
	cout << "Hello W! Wellocome to your painting calculator.\n";

	//Masterloop
	//used to loop the program if the user indicates
	while (1)
	{

		//Subloop 1.0
		//tired check
		while (1)
		{
			//asks the user if they are tried or not and putts user's input into into Buffer string
			cout << "Are you tired today? (y/n)\n";
			cin >> Buffer;

			//uses Buffer string to only take the first character of the use's input to put in the Tired char while captalizing the that character to limit output
			Tired = toupper(Buffer.at(0));

			//checks if the first charater of user's input is 'Y' or 'N'
			if (Tired == 'Y')
			{
				//sets Paint_Speed double for the approate value for if  the use is tired and breaks out of Subloop 1.0 into Masterloop
				Paint_Speed = 200;
				break;

			}
			else if (Tired == 'N')
			{
				//sets Paint_Speed double for the approate value for if  the use is not tired and breaks out of Subloop 1.0 into Masterloop
				Paint_Speed = 400;
				break;

			}
			else
			{
				//indicates user made an error in their input and drops them back to the begining of Subloop 1.0
				cout << "Error!! Incorrect input, please try again.\n";

			}

		}

		//Subloop 2.0
		//area in and hours out
		while (1)
		{
			//sets Number_Check bool to true and String_Size int to 0, their expected begining values for Subloop 2.0
			Number_Check = true;
			String_Size = 0;

			//asks the number of square feet the user needs to paint and putts user's input into into buffer string
			cout << "What is the number of square feet that you need to paint today?\n";
			cin >> Buffer;

			//Subloop 2.1
			//loop runs while String_Size int is less than the size of the Buffer string to check each charater of the string
			while (String_Size < Buffer.size())
			{

				//checks each charater of the Buffer string is not a number and not the '.'
				if ((!isdigit(Buffer[String_Size])) && Buffer.at(String_Size) != '.')
				{

					//indicates user made an error in their input
					cout << "Error!! Incorrect input, please try again.\n";

					//set Number_check to false to indicate that it isn't valid input 
					Number_Check = false;

					//breaks out of Subloop 2.1 to  have them repeat Subloop 2.0
					break;

				}

				//increments to progress in Subloop 2.1
				String_Size++;

			}

			//checks if you passed the number check
			if (Number_Check)
			{
				//converts Buffer string into a double an sets Area double to it 
				Area = stod(Buffer);

				//calculates the time of it will take in our with the precision 1 decimal place 
				cout << "It will take you " << setprecision(1) << fixed << Area / Paint_Speed << " hour(s).\n";
				
				//breaks out of Subloop 2.0 into Master loop
				break;

			}

		}

		//Subloop 3.0
		//quit check
		while (1)
		{
			//asks the user if they want to quit or not and putts user's input into into Buffer string
			cout << "Do you want to quit the program? (y/n)\n";
			cin >> Buffer;

			//uses Buffer string to only take the first character of the use's input to put in the Quit char while captalizing the that character to limit output
			Quit = toupper(Buffer.at(0));

			//checks if the first charater of user's input is 'Y' or 'N'
			if (Quit == 'Y')
			{

				//sets Quit_check to true and breaks out of Subloop 3.0 into Masterloop
				Quit_Check = true;
				break;

			}
			else if (Quit == 'N')
			{

				//sets Quit_check to false and breaks out of Subloop 3.0 into Masterloop
				Quit_Check = false;
				break;

			}
			else
			{

				//indicates user made an error in their input and drops them back to the begining of Subloop 3.0
				cout << "Error!! Incorrect input, please try again.\n";

			}
		}

		//checks if the user they indicated whether they wanted to quit the program
		if (Quit_Check)
		{
			//breaks out of the Masterloop
			break;

		}
	}

	//says goodbye to the user before ending the program
	cout << "Goodbye W and thank you for using your painting calculator. Please come again!\n";
	return(0);

}


