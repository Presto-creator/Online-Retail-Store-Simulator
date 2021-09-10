/*

//This program was made to test the DigitalDownload class
 
#include <iostream>
#include "DigitalDownload.h"
#include <cassert>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile; // to be able to open file
	string fileopen = "digitaldownloadlist.txt"; // to easily change the file being tested
	bool isopen = false; // file is not open at start
	DigitalDownload testdownload; // create our own object for testing
	int numSongsInTxt = 5; // CHANGE THIS TO THE NUMBER OF TITLES IN DIGITALDOWNLOAD OR ASSERT WONT WORK
	int numSongs = 0;

	
	cout << "testing opening the file" << endl;
	inFile.open(fileopen); // opening the file 
	if (inFile) {
		isopen = true;
	}
	else {
		isopen = false;
	} // if the file is open, the isopen is true but if it failed then isopen stays false

	assert(isopen == true);

	cout << "testing closing the file" << endl;
	inFile.close(); // closing the file
	isopen = false; //can't use assert to check if file is open or not, so this is the best solution. if the file doesn't close then the program doesn't reach isopen = false
	assert(isopen == false);
	cout << "testing of opening and closing of file complete" << endl; //finished testing of the file

	cout << "testing default class" << endl;
	assert(testdownload.getName() == "no name"); // is the default name "no name"
	assert(testdownload.getAuthor() == "no author"); // is the default author "no author"
	assert(testdownload.getBookType() == "no book"); // is the default book type "no book"
	assert(testdownload.getPrice() == -1); // is the default price -1
	assert(testdownload.getPublishYear() == -1); // is the default publish year -1
	cout << "testing of default class complete" << endl; // finished testing default class

	
	testdownload = DigitalDownload("testname", "testauthor", "testbook", 2020, 100); // Set the title name, author, type of book, cost and publish year


	cout << "testing default class with functions" << endl; // time to test if our set functions worked
	assert(testdownload.getName() == "testname"); // is the new name what we set it as
	assert(testdownload.getAuthor() == "testauthor"); // is the new author what we set it as
	assert(testdownload.getBookType() == "testbook"); // is the new book type what we set it as
	assert(testdownload.getPrice() == 100); // is the new price what we set it as
	assert(testdownload.getPublishYear() == 2020); // is the new publish year what we set it as
	cout << "testing default class with functions complete" << endl;

	cout << "testing checking number of titles in digital download list" << endl;

	inFile.open(fileopen); // opening the file 
	if (inFile) {
		isopen = true;
	}
	else {
		isopen = false;
	} // if the file is open, the isopen is true but if it failed then isopen stays false

	assert(isopen == true);
	string temp;

	while (!inFile.eof())
	{
		getline(inFile, temp);
		if (DigitalDownload::findNumSongs(temp) == true) {
			numSongs++;
		}
	}

	assert(numSongs == numSongsInTxt);

	inFile.close();

	cout << "testing checking number of titles in digital download list complete" << endl;

	cout << "testing of overloaded << operator" << endl;

	cout << testdownload; // Overloaded << operator outputs the infomation of the digitaldownload

	cout << "testing of overloaded << operator complete" << endl;

	cout << "all testing complete" << endl; // nothing else to test



	return 0;
}

*/

// End of DDTester.cpp

