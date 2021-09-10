#ifndef DIGITALDOWNLOAD_H
#define DIGITALDOWNLOAD_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class DigitalDownload { // DigitalDownload class

	friend ostream& operator<< (ostream& out, const DigitalDownload& cart); // Overloaaded friend << operator to easily cout digitaldownload

private:

	string downloadName; //Title of the item
	string authorName; // Author of the item
	string bookType; // Type of the item
	int publishYear; // Release year of the item
	double bookPrice; // Price of the item

public:

	DigitalDownload(); // Default constructor
	DigitalDownload(string name, string author , string type , int publish, double price); // Constructor for putting things into the object
	
	static void search(const vector<DigitalDownload> Stock, vector<DigitalDownload>& results); // Allows us to search through the digitaldownload things using their names
	static void getInventoryofStock(vector<DigitalDownload>& Inventory); // Looks through digitaldownloadlist.txt and puts everything into the Inventory

	static bool findNumSongs(string file); // Finds the number of songs and returns true each time a line has **

	double getPrice() const; // Returns the price
	string getName() const; // Returns the name
	string getAuthor() const; // Returns the author
	string getBookType() const; // Returns the book type
	int getPublishYear() const; // Returns the pulish year

};

#endif

//End of DigitalDownload.h
