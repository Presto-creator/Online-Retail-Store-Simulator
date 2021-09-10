#include <iostream>
#include "DigitalDownload.h"
#include <string.h>
#include <iomanip>

using namespace std;

DigitalDownload::DigitalDownload() // Our default constructor, sets the default values of everything if they aren't set
{
	downloadName = "no name";
	authorName = "no author";
	bookType = "no book";
	publishYear = -1;
	bookPrice = -1;
}

DigitalDownload::DigitalDownload(string name, string author, string type, int publish, double price) { // The constructor we want to call to put variables in
	downloadName = name;
	authorName = author;
	bookType = type;
	publishYear = publish;
	bookPrice = price;

}

double DigitalDownload::getPrice() const // Returns the title price
{
	return bookPrice;
}

string DigitalDownload::getName() const // Returns the title name
{
	return downloadName;
}

string DigitalDownload::getAuthor() const // Returns the author name
{
	return authorName;
}

string DigitalDownload::getBookType() const // Returns title type
{
	return bookType;
}

int DigitalDownload::getPublishYear() const // Returns publish year
{
	return publishYear;
}


bool DigitalDownload::findNumSongs(string thing) // Looks through string and returns true or false based on if * is found

{
		if (thing.find("*") != string::npos) {
			return true;
		}
		else {
			return false;
		}
}



ostream& operator<<(ostream& out, const DigitalDownload& item) // Overloaded << operator to easily output a DigitalDownload item
{
	out << setprecision(2) << fixed;
	out << item.downloadName << ", by " << item.authorName << "." << endl;
	out << "Published in " << item.publishYear << ", costs $" << item.bookPrice << ", and is a(n) " << item.bookType << endl << endl;

	return out;
}


void DigitalDownload::getInventoryofStock(vector<DigitalDownload>& Inventory) 
// Function for looking through digitaldownloadlist.txt and getting a count for songs, and putting songs into the DigitalDownload vector in Shopping.cpp
{
	ifstream infile; // create an ifstream object so we can open a file

	int numSongs = 0; // int for keeping track of number of songs
	string temp; // temporary string variable for checking number of songs

	infile.open("digitaldownloadlist.txt"); // To open digitaldownloadlist

	if (!infile) // If file does not open, exit function
	{
		cout << "Failed to open store! Try to reconnect or something" << endl;
		return;
	}

	while (!infile.eof()) // While not at the end of the file, run through the lines and if the findnumsongs function turns true, add to the number of songs;
	{
		getline(infile, temp);
		if (DigitalDownload::findNumSongs(temp) == true) {
			numSongs++;
		}
	}

	infile.close(); // Close the file
	
	Inventory.resize(numSongs); // Resize the vector to the number of songs detected

	infile.open("digitaldownloadlist.txt"); // Open digitaldownloadlist again so we can start at the beginning

	if (!infile) // If file does not open, exit function
	{
		cout << "Failed to open store! Try to reconnect or something" << endl; 
		return;
		
	}

	string title, author, type, year, cost; // String variables for the information for each song

	for (int i = 0; i < numSongs; i++) // Goes through digitaldownloadlist.txt and inputs the information in the following format into each DigitalDownload item
	{
		getline(infile, title);
		getline(infile, author);
		getline(infile, type);
		getline(infile, year);
		getline(infile, cost);
		getline(infile, temp);

		Inventory[i] = DigitalDownload(title, author, type, stoi(year), stod(cost));

	}

	infile.close(); // Close the file

}

void DigitalDownload::search(vector<DigitalDownload> Stock, vector<DigitalDownload>& results) // Allows the user to search through the Inventory using text input
{
	string input; // String variable for what the user wants to look for

	cout << "Type in what you would like to look for!\n"; // Instructions for the user

	cin.ignore(); // Ignore previous input from cin, just in case
	getline(cin, input); // Get entire line so there can be spaces

	results.clear(); // Empties results, so it isn't bigger than what the function returns

	cout << "Here are the following items with '" << input << "' in them.\n\n"; // alert user to the results

	int n = 0; // int variable just for keeping count of number of items in the results, I put at 0 instead of 1 because I felt like it

	for (int i = 0; i < Stock.size(); i++) // Goes through each item in the stock
	{
	
		if ((Stock[i].authorName.find(input) != string::npos) || (Stock[i].downloadName.find(input) != string::npos) || (Stock[i].bookType.find(input) != string::npos)) 
			// If anything from the author, title or type is found in the input then return the item name and add to search results
		{
			cout << "Item #" << n + 1 << ": ";
			cout << Stock[i];
			results.push_back(Stock[i]);
			n++;
		}
	}

	if (results.size() == 0) //If nothing gets added to results, alert user that search turned up empty
	{
		cout << "Search turned up nothing!" << endl;
	}

	cout << "To add one of these items from your search to your cart,\njust use the 'Add to Cart' in the main menu and type the number corresponding to the product you'd like to purchase!" << endl;
}

//End of DigitalDownload.cpp


