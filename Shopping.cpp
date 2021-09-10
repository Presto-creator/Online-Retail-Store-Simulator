/*
This program is a shopping simulator created by Preston Leigh on 12/11/2020
Program includes:
Shopping.cpp, DigitalDownload.cpp, Customer.cpp, DigitalDownload.h, Customer.h, CustomerTester.cpp, DDTester.cpp, digitaldownloadlist.txt
THIS IS WHERE MAIN IS LOCATED, THIS IS THE MAIN FILE
*/

#include <iostream>
#include "DigitalDownload.h"
#include "Customer.h"
#include <vector>
#include <string.h>


void customerLookingatSearch(Customer &customer, vector<DigitalDownload> searchResults); //Allows customer to choose from the search results and add the item to cart
void displayMenu(bool &customerLoggedIn, char &keepGoing, vector<DigitalDownload> Stock, Customer &customer, vector<DigitalDownload> &searchResults); // Allows user to choose from the main menu
void Checkout(bool& customerLoggedIn, Customer &customer); // Allows customer to check out and show them their receipt
void displayMenuOptions(); // Displays what the user can choose from

//The above four declarations are for the four functions we will need in the shopping program.

using namespace std; // Included this because I made this when I was in CS1, and it looks cleaner to me. I know it isn't as efficient as just doing std:: before every std object, though

int main() 
{
	vector<DigitalDownload> Inventory, searchResults; //In order for our program to work, we need to have a vector of downloads for both the inventory and searchresults, so it's easier to organize the shop's stock and customer's search results
	Customer customer; //The customer also needs to be able to have an account, so there's a customer object
	char keepGoing = 'Y'; // Char variable that will keep the menu and program going until the user wants to leave the shop
	bool customerLoggedIn = false; // Boolean variable to let the program know if the user has logged in or not

	

	DigitalDownload::getInventoryofStock(Inventory); //This function is located in DigitalDownload.cpp and goes through digitaldownloadlist.txt and puts the song into the Inventory vector

	if (Inventory.size() == 0) //Checks if the file failed to open the getInventoryofStock function and nothing was put into inventory. If it is empty, end the program.
	{
		cout << "There is no inventory! Either there is no stock or the stock list cannot be found.";
		return 1;
	}


	searchResults = Inventory; // This starts searchResults as Inventory, in case some monkey decides to add something to the cart before searching
	
	cout << "Welcome to the Preston Online Store!" << endl << "You may:";

	while ((keepGoing == 'Y') || (keepGoing == 'y')) //While the user wants to keep shopping, loop the displayMenu function
	{
		displayMenu(customerLoggedIn, keepGoing, Inventory, customer, searchResults); // As explained at the declaration, this allows the user to choose from the main menu, and interact with the variables.
	}

	return 0;
}


// FUNCTIONS DEFINITIONS BELOW

void displayInventory(vector<DigitalDownload> Stock) // Displays what the user can choose from
{
	cout << endl << endl;
	for (unsigned int i = 0; i < Stock.size(); i++) //Used unsigned int instead of int because the compiler warning was annoying me
	{
		cout << "Item #" << i + 1 << ": ";
		cout << Stock[i]; // Overloaded operator << to easily display the contents of each DigitalDownload
	}
	//This for statement just goes through the DigitalDownloads in the vector brought in by the function and displays them to the user

}

void Checkout(bool& customerLoggedIn, Customer& customer) // Allows customer to check out and show them their receipt
{

	if (customerLoggedIn) // If the customer is logged in, they don't need to log in again
	{
		cout << "Thanks for shopping at our store! Here is your receipt:\n";
		cout << customer;
		cout << "Thanks for shopping with us!" << endl;
	}
	else // If customer is not logged in, then make them log in first and then they can checkout
	{
		cout << "You're not logged in! Please create an account or log in.\n";
		customer.LogIn();
		customerLoggedIn = true;
		cout << customer;
		cout << "Thanks for shopping with us!" << endl;
	}
}

void displayMenuOptions() // Just outputs to the user the options they can choose from
{
	cout << endl;
	cout << "1.	Login\n";
	cout << "2.	See the catalog of items\n";
	cout << "3.	Search for an item\n";
	cout << "4.	Add an item to the cart\n";
	cout << "5.	Display the contents of your cartt\n";
	cout << "6.	Checkout\n";
	cout << "7.	Exit the store without purchasing\n";
}

void customerLookingatSearch(Customer &customer, vector<DigitalDownload> searchResults) //Allows customer to choose from the search results and add the item to cart
// Instead of having to fully type a name, which can be annoying with capitalization, this function is designed to let the user choose from the list using a number input
{
	int customerInput; //Lets the user tell the program which list item they want to add to cart
	string customerChoiceTemp; // Temp variable for taking in everything the user types, for validation purposes
	char customerChoice = 'Y'; // If the user wants to add more than one item from the list

	while (customerChoice == 'Y' || customerChoice == 'y') // While the customer wants to keep adding things to the list
	{
		cout << "Type in what you would like to add. Type '1' for #1, and so on." << endl; // Instructions for the user

		cin >> customerChoiceTemp; // Take computer input into string for validation
		customerChoiceTemp = customerChoiceTemp.at(0); // Only take the first character of the string for validation
		customerInput = stoi(customerChoiceTemp); // Convert the first character of the string to an interger
		//This was done to prevent a customer from typing in "3093084" or something
		
		if (customerInput > searchResults.size())  // More validation, if the list goes up to 5 but the customer types 6
		{
			cout << "Please enter a valid option from your search.\n";
			customerInput = 0;
		}
		else // If the customer chooses a valid input
		{
			customer.AddToShoppingCart(searchResults[customerInput - 1]); // It's customerInput - 1 instead of customerInput because 1 is actually 0 to a vector
			cout << "\nAnything else from your search that you'd like to add? Type 'Y' for yes, or anything else to go back to the main store." << endl;
			cin >> customerChoiceTemp;
			customerChoice = customerChoiceTemp.at(0); // Only take the first character of the string for validation
			
		}
	}
}

void displayMenu(bool& customerLoggedIn, char& keepGoing, vector<DigitalDownload> Stock, Customer &customer, vector<DigitalDownload> &searchResults) // Allows user to choose from the main menu
{
	int customerChoice; // Lets the user tell the program which menu option they want to choose
	string customerChoiceTemp; // Temp string for validation
	
	displayMenuOptions(); // Display the menu to the user

	cout << "\nChoose what you'd like to do.\nType a number that corresponds with the option.\nEX. Type '1' for Login.\n"; // Instructions to the user

	cin >> customerChoiceTemp; // Take computer input into string for validation
	customerChoiceTemp = stoi(customerChoiceTemp); // Only take the first character of the string for validation
	customerChoice = customerChoiceTemp.at(0);// Convert the first character of the string to an interger
	//This was done to prevent a customer from typing in "3093084" or something
	
	switch (customerChoice) // Easier and nicer looking than if statement, case changes depending on customerChoice
	{
	case 1:
		if (!customerLoggedIn) // If the customer is not logged in, log them in
		{
			customer.LogIn();
			customerLoggedIn = true;
		}
		else // Alert the user that they are already logged in
		{
			cout << "Already logged in!" << endl;
		}
		break;

	case 2:
		displayInventory(Stock); // Display the inventory of the store as in digitaldownloadlist.txt
		break;

	case 3:
		DigitalDownload::search(Stock, searchResults); // Let the user search from stock and store results in searchResults
		break;

	case 4:
		if (!(searchResults.empty())) // If searchResults is empty, this means the user has searched before and therefore we need to let them use the searchResults vector of objects
		{
			customerLookingatSearch(customer, searchResults); 
		}
		else 
		{
			customerLookingatSearch(customer, Stock); // If user hasn't searched before, then let them choose from the Stock
		}
		break;

	case 5:
		cout << customer; // Output the customer's cart
		break;

	case 6: 
		keepGoing = 'N'; // Prevent program from looping again
		Checkout(customerLoggedIn, customer); //Run checkout
		break;

	case 7:
		cout << "\nThanks for visiting our store!" << endl;
		keepGoing = 'N'; // Prevent program from looping again
		break;

	default: // Default case if user inputs an invalid option
		cout << "Since you did not choose a valid option, we are going to show you our catalog.\n";
		displayInventory(Stock);
		break;
	}
}

//End of shopping.cpp

