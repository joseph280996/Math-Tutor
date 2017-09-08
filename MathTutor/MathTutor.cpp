//Programmer: Minhyung Jee, Tung Pham, Evgenia Meyer
//Kind: Group Project
//Course: CIT120 T1
//Date: Apr.28.2016
//Description: Math Tutor Group Project


#include<iostream>                                                              //  header files
#include<fstream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

void banner(int month, int day, int year, string kind, string description);     //  banner function
void menu();                                                                    //  menu function including (switch (case))
void first_menu();                                                              //  menu displaying function

void score_sheet();                                                             //  user score function
void addition(int ran1, int ran2);                                              //  addition function
void substraction(int ran1, int ran2);                                          //  substraction function
void multiplication(int ran1, int ran2);                                        //  multiplication function
void integer_division(int ran1, int ran2);                                      //  integer division function
void real_division(double ran1, double ran2);                                   //  real division function
void modulo(int ran1, int ran2);                                                //  modulo function
void seventh_function(int ran1, int ran2, int ran3);                            //  addition & substraction function
void eighth_function(int ran1, int ran2, int ran3);                             //  addition, substraction, & multiplication function
void ninth_function(int ran1, int ran2, int ran3);                              //  addition, substraction, multiplication, & division function
void tenth_function(int ran1, int ran2, int ran3);                              //  all of them function

bool int_Valid(double number);                                                  //  integer input validation to prevent negative and decimal input
bool second_int_Valid(double number);											//	integer input validation to prevent negative and decimal input

char RedoValidation(char& choice);                                             //  character validation when asking the user to re-run the program

double Valid(double num1);                                                      //  integer input validation to force the user to put a number between 1 to 11
double second_Valid(double num1);                                               //  integer input validation to force the user to put a number only a positive number
double getNum(double& number);                                                  //  character validation to prevent the user to put a character for numerical value variables

double round(double value, int digits);											//	rounding function

double userchoice, question_number, answer1;                                    //  double variables
int number1, number2, counter, score1 = 0, score2 = 0;                          //  integer variables
char choice;                                                                    //  character variables

ofstream output;                                                                //  output file ofstream


int main()                                                                      //  main function
{


	output.open("Solution.txt");                                                //  creates "Solution.txt" file to store data
	output << "\t\t**************************************************";
	output << "\n\t\tThis is Math Tutor 2";
	output << "\n\t\tWritten by Minhyung Jee, Tung Pham, Evgenia Meyer";
	output << "\n\t\t*************************************************";


	banner(04, 28, 2016, "Group Project", "This test your Math abilities.");    //  banner function


	do                                                                          //  do-while loop starting point
	{

		first_menu();                                                           //  first menu function is called to display the menu screen

		cout << "\n\n\t\tEnter your Choice : ";                                   //  asking user to make a choice among menu-list

		cin >> userchoice;                                                      //  user inputs a choice
		cin.ignore();


		getNum(userchoice);                                                     //  validation for character input
		Valid(userchoice);                                                      //  validation for negative, decimal values, and range between 1 to 11


		if (userchoice == 11)                                                      //  if user choose 11 from menu, exits the program
		{
			cout << "\n\n\t\tTHANK YOU & GOOD BYE!";

			cout << "\n\n\t\tPress y to re-run this program : ";                  //  asking to re-run this program
			cin >> choice;

			cin.ignore();
		}

		else
		{
			cout << "\n\t\tHow many questions do you want to solve? : ";          //  asking user how many question he/she wants

			cin >> question_number;                                               //  user input number of questions
			cin.ignore();

			getNum(question_number);                                            //  validation for character input

			second_Valid(question_number);                                      //  validation function to force the user to put a value positive integer only

			for (counter = 1; counter <= question_number; counter++)                   //  for-loop continues till "counter" reaches "question number"
				menu();                                                         //  menu function is called "question number" times

			score_sheet();                                                      //  displays user's score

			cout << "\n\n\t\tPress y to re-run this program : ";                  //  asking user if he/she wants to re-run this program

			cin >> choice;
			cin.ignore();
		}

		RedoValidation(choice);                                                 //  validation for redo user input

		system("cls");															// clear screen

	} while (choice == 'y' || choice == 'Y');                                   //  end of do-while loop, which runs again if the user input 'y' or 'Y' for redo option.

	output << "\n\n\t\tTHANK YOU FOR USING OUT MATH TUTOR! GOOD BYE!";
	output.close();                                                             //  file "Solution.txt" closes

	cout << "\n\n\t\tTHANK YOU FOR USING OUR MATH TUTOR! GOOD BYE!";			// ending message to the user
	cout << "\n\t\tPress ENTER to end this program\n";

	cin.get();
	return 0;
}


void banner(int month, int day, int year, string kind, string description)      //  banner function
{

	cout << "\n\t\tDescription: " << description << "\n";
	cout << "\t\tKind: " << kind << "\n";
	cout << "\t\tCourse: CIT120T1 \n";
	cout << "\t\tProgrammer: Minhyung Jee, Tung Pham, Evgenia Meyer \n";
	cout << "\t\tDate: " << month << "/" << day << "/" << year << "\n";
}


bool int_Valid(double number)                                                     //   Positive and whole number integer validation.
{
	bool status;

	if (number >= 1 && number == static_cast<int>(number) && number <= 11)
		status = true;
	else
		status = false;

	return status;
}

bool second_int_Valid(double number)                                                     //   Positive and whole number integer validation.
{
	bool status;

	if (number >= 1 && number == static_cast<int>(number))
		status = true;
	else
		status = false;

	return status;
}


double Valid(double num1)                                                          //   Positive and whole number integer validation.
{

	while (!int_Valid(num1))
	{
		cout << "\n\t\tYou Need to Enter a whole & positive number between [1 and 11]";
		cout << "\n\t\tEnter Your Number Again : ";

		cin >> num1;
		cin.ignore();
	}

	return num1;
}

double second_Valid(double num1)                                                //  Positive and whole number integer validation.
{

	while (!second_int_Valid(num1))
	{
		cout << "\n\t\tYou Need to Enter a whole & positive number";
		cout << "\n\t\tEnter Your Number Again : ";

		cin >> num1;
		cin.ignore();
	}

	return num1;
}



double getNum(double& number)                                                   //  character input validation
{
	while (!cin)
	{
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\n\n\t\tINVALID INPUT!\n" << "\t\tPlease enter a number again : ";
		cin >> number;
		cin.ignore();
	}

	return number;

}

char RedoValidation(char& choice)                                              //  character input validation
{
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cout << "\n\n\t\tINVALID INPUT!\n" << "\t\tPlease enter Y or N : ";
		cin >> choice;
		cin.ignore();
	}
	if (choice == 'n' || choice == 'N')
	{
		cout << "\n\t\tPress ENTER to end this program\n";
		cin.get();
	}

	return choice;

}

void addition(int ran1, int ran2)                                               //  addition function
{

	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t+\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t+\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";

	if (answer1 == (ran1 + ran2))
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (answer1 == (ran1 + ran2))
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << (ran1 + ran2);
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << (ran1 + ran2);
		}
	}


}

void substraction(int ran1, int ran2)                                           //  substraction function
{

	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t-\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t-\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";

	if (answer1 == (ran1 - ran2))
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (answer1 == (ran1 - ran2))
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << (ran1 - ran2);
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << (ran1 - ran2);
		}
	}


}

void multiplication(int ran1, int ran2)                                         //  mulitpication function
{


	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t*\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t*\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";

	if (answer1 == (ran1*ran2))
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (answer1 == (ran1*ran2))
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << (ran1*ran2);
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << (ran1*ran2);
		}
	}


}

void integer_division(int ran1, int ran2)                                       //  integer division function
{

	cout << "\n\n\t\t----------------- IMPORTANT NOTICE -----------------------";
	cout << "\n\n\t\t\t\tTHIS IS INTEGER DIVISION";
	cout << "\n\t\t\tMAKE SURE TO PUT YOUR ANSWER IN INTEGER FORM!\n\n";
	cout << "\t\t----------------------------------------------------------";

	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t/\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t/\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";


	if (static_cast<int>(answer1) == (ran1 / ran2))
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (static_cast<int>(answer1) == (ran1 / ran2))
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << (static_cast<int>(ran1) / static_cast<int>(ran2));
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << (static_cast<int>(ran1) / static_cast<int>(ran2));

		}
	}

}


void real_division(double ran1, double ran2)                                        //  real division function
{

	cout << "\n\n\t\t----------------- IMPORTANT NOTICE -----------------------";
	cout << "\n\n\t\t\tEnter Your Answer in Two Decimal Places";
	cout << "\n\t\tFor DIVISION Provide the Answer to 2 Decimal Places ONLY\n\n";
	cout << "\t\t----------------------------------------------------------";

	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t/\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	double answer = (ran1 / ran2);
	double round_answer = round(answer, 2);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t/\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";



	if (answer1 == round_answer)
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (answer1 == round_answer)
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << round_answer;
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << round_answer;
		}
	}


}


void modulo(int ran1, int ran2)                                                     //  modulous function
{


	cout << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	cout << "\n\t\t\t\t" << ran1;
	cout << "\n\t\t" << "\t%\t" << ran2;
	cout << "\n\t\t\t____________" << "\n\t\t\t\t";

	cin >> answer1;
	cin.ignore();

	getNum(answer1);

	output << "\n\n\n\t\t*****  Question " << counter << " of " << question_number << "  *****\n";
	output << "\n\t\t\t\t" << ran1;
	output << "\n\t\t" << "\t%\t" << ran2;
	output << "\n\t\t\t____________" << "\n\t\t\t\t";


	if (answer1 == (static_cast<int>(ran1) % static_cast<int>(ran2)))
	{
		cout << "\n\n\t\tCongratulation! Correct Answer!";
		output << "\n\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

		score1++;
	}
	else
	{
		cout << "\n\n\t\tWrong Answer, Try Again : ";
		output << "\n\n\t\tWrong Answer,Your First  Try \t\t\t: " << answer1;

		cin >> answer1;
		cin.ignore();

		getNum(answer1);

		if (answer1 == (static_cast<int>(ran1) % static_cast<int>(ran2)))
		{
			cout << "\n\t\tCongratulation! Correct Answer!";
			output << "\n\t\tCongratulation! Correct Answer! The Answer was  : " << answer1;

			score2++;
		}
		else
		{
			cout << "\n\t\tWrong Again! The Answer was : " << (static_cast<int>(ran1) % static_cast<int>(ran2));
			output << "\n\t\tWrong Again! Your Second Try \t\t\t: " << answer1;
			output << "\n\t\tThe Correct Answer was\t\t\t\t: " << (static_cast<int>(ran1) % static_cast<int>(ran2));
		}
	}


}

void seventh_function(int ran1, int ran2, int ran3)                                     //  addition & substraction function
{

	if (ran3 == 1)
		addition(ran1, ran2);
	else
		substraction(ran1, ran2);
}

void eighth_function(int ran1, int ran2, int ran3)                                        //  addition, substraction, & multiplication function
{
	if (ran3 == 1)
		addition(ran1, ran2);
	else if (ran3 == 2)
		substraction(ran1, ran2);
	else
		multiplication(ran1, ran2);
}

void ninth_function(int ran1, int ran2, int ran3)                                        //  addition, substraction, multiplication, & division function
{
	cout << "\n\n\t\t----------------- IMPORTANT NOTICE -----------------------";
	cout << "\n\n\t\tFor DIVISION Provide the Answer to 2 Decimal Places ONLY\n\n";
	cout << "\t\t----------------------------------------------------------";

	if (ran3 == 1)
		addition(ran1, ran2);
	else if (ran3 == 2)
		substraction(ran1, ran2);
	else if (ran3 == 3)
		multiplication(ran1, ran2);
	else
		real_division(ran1, ran2);
}

void tenth_function(int ran1, int ran2, int ran3)                                        //  all of above function
{
	cout << "\n\n\t\t----------------- IMPORTANT NOTICE -----------------------";
	cout << "\n\n\t\tFor DIVISION Provide the Answer to 2 Decimal Places ONLY\n\n";
	cout << "\t\t----------------------------------------------------------";

	if (ran3 == 1)
		addition(ran1, ran2);
	else if (ran3 == 2)
		substraction(ran1, ran2);
	else if (ran3 == 3)
		multiplication(ran1, ran2);
	else if (ran3 == 4)
		real_division(ran1, ran2);
	else
		modulo(ran1, ran2);
}


void menu()                                                                             //  menu function with switch(case)
{
	int random1, random2, random3, random4, random5, random6;
	const int MIN_VALUE = 1, MAX_VALUE = 99, MIN_OPERATOR = 1, TWO_OPERATOR = 2, THREE_OPERATOR = 3, FOUR_OPERATOR = 4, FIVE_OPERATOR = 5;

	unsigned seed = time(0);
	srand(seed);

	random1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	random2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	random3 = (rand() % (TWO_OPERATOR - MIN_OPERATOR + 1)) + MIN_OPERATOR;
	random4 = (rand() % (THREE_OPERATOR - MIN_OPERATOR + 1)) + MIN_OPERATOR;
	random5 = (rand() % (FOUR_OPERATOR - MIN_OPERATOR + 1)) + MIN_OPERATOR;
	random6 = (rand() % (FIVE_OPERATOR - MIN_OPERATOR + 1)) + MIN_OPERATOR;

	switch (static_cast<int>(userchoice))
	{
	case 1:addition(random1, random2);
		break;
	case 2:substraction(random1, random2);
		break;
	case 3:multiplication(random1, random2);
		break;
	case 4:integer_division(random1, random2);
		break;
	case 5:real_division(random1, random2);
		break;
	case 6:modulo(random1, random2);
		break;
	case 7:seventh_function(random1, random2, random3);
		break;
	case 8:eighth_function(random1, random2, random4);
		break;
	case 9:ninth_function(random1, random2, random5);
		break;
	case 10:tenth_function(random1, random2, random6);
		break;
	case 11:cout << "\n\n\t\tTHANK YOU & GOOD BYE!";
		break;
	default:cout << "\n\n\t\tWRONG INPUT";
	}



}

void first_menu()                                                                       //  menu-display function
{

	cout << "\n\t\tPress [1] for Addition Only";
	cout << "\n\t\tPress [2] for Subtraction Only";
	cout << "\n\t\tPress [3] for Multiplication Olny";
	cout << "\n\t\tPress [4] for Integer Division Only";
	cout << "\n\t\tPress [5] for Real Division Only";
	cout << "\n\t\tPress [6] for Modulos Only";
	cout << "\n\t\tPress [7] for Addition & Subtraction";
	cout << "\n\t\tPress [8] for Addition, Subtraction & Multiplication";
	cout << "\n\t\tPress [9] for Addition, Sub., Multiplication, & Real Divison";
	cout << "\n\t\tPress [10] for All Operators";
	cout << "\n\t\tPress [11] for End Program";

	cin.clear();
}

void score_sheet()                                                                      //  score sheet function
{
	double percent = (score1 + (score2*0.5)) / question_number * 100;

	cout << "\n\n\n\t\t------------------------------------------------";
	output << "\n\n\n\t\t------------------------------------------------";

	cout << "\n\n\t\tYou Scored : " << (score1 + (score2*0.5)) << " out of " << question_number << ",\tAnd That Is " << round(percent, 2) << "%";
	output << "\n\n\t\tYou Scored : " << (score1 + (score2*0.5)) << " out of " << question_number << ",\tAnd That Is " << round(percent, 2) << "%";

	cout << "\n\n\t\t------------------------------------------------";
	output << "\n\n\t\t------------------------------------------------";


	score1 = 0, score2 = 0;

}

double round(double value, int digits)												//	rounding function
{
	return floor(value * pow(10, digits) + 0.5) / pow(10, digits);
}