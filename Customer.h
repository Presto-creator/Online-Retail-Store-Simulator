#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "DigitalDownload.h"
using namespace std;

class Customer { // Customer class

	 friend ostream& operator<< (ostream& out, const Customer& customer); // Overloaded friend operator so we can use it anywhere with customer

private:

	int numItemsOrdered; // Keeps track of number of items in cart for the customer
	string name; // The customer's name
	DigitalDownload* shoppingCart; // dynamic array of the customer 

public:

	Customer(); // Default constructor
	~Customer(); // Destructor
	void LogIn(); // Customer login function
	double Total() const; // Function to return the total of the cart
	void AddToShoppingCart(DigitalDownload item); // Add something to the cart
	
};

#endif

//End of Customer.h