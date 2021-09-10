#include <iostream>
#include "Customer.h"
#include <iomanip>
using namespace std;



Customer::Customer() // Default constructor sets our default variables
{
	name = "Please log in!";
	numItemsOrdered = 0;
	shoppingCart = nullptr;
}

Customer::~Customer() // Destructor for deleting the dynamic array
{
	
	delete[] shoppingCart; // Deletes the array of items
	
	shoppingCart = nullptr; // Sets the pointer to null
	
}

void Customer::LogIn() // Login function for the customer to set their name and create an account
{
	cout << "Please type in your full name below.\n";
	cin.ignore(256, '\n');
	getline(cin, name);
	cout << "Welcome, " << name << "!\n\n";
}


double Customer::Total() const // Returns the total of the cart of the customer
{

	double Total = 0.0;
	for (int i = 0; i < numItemsOrdered; i++) // Cycles through the shoppingcart's objects
	{
		Total += shoppingCart[i].getPrice();
	}

	return Total;
}

void Customer::AddToShoppingCart(DigitalDownload item) // Function for adding to shopping cart
{
	if (numItemsOrdered == 0) // Checks if numItemsOrdered is empty. If it is then a new array is created
	{
		shoppingCart = new DigitalDownload[numItemsOrdered + 1];
		numItemsOrdered += 1;
		shoppingCart[0] = item;
	}
	else //If there is something in the cart, then create a temp cart pointer, copy everything over to the pointer, delete the original array and set shoppingcart to tempcart, then makes tempcart point at nothing
	{
		DigitalDownload* tempCart = nullptr; 

		tempCart = new DigitalDownload[numItemsOrdered + 1];

		for (int i = 0; i < numItemsOrdered; i++) 
		{
			tempCart[i] = shoppingCart[i];
		}

		tempCart[numItemsOrdered] = item;

		delete[] shoppingCart;

		shoppingCart = tempCart;

		tempCart = nullptr;

		numItemsOrdered += 1;
	}

	cout << "\nAdded " << item.getName() << " to cart!\n";
}

ostream& operator<<(ostream& out, const Customer& customer) // Overloaded << operator so we can easily cout the customer and their cart and total
{
	
	out << customer.name << ". Here is what you have in your cart:\n" << endl;

	double Total = customer.Total();
	
	if (customer.numItemsOrdered > 0)
	{
		for (int i = 0; i < customer.numItemsOrdered; i++) // Goes through the cart and outputs it
		{
			out << "Item #" << i + 1 << ": ";
			out << setprecision(2) << fixed;
			out << customer.shoppingCart[i].getName() << ", by " << customer.shoppingCart[i].getAuthor() << "." << endl;
			out << "Published in " << customer.shoppingCart[i].getPublishYear() << ", costs $" << customer.shoppingCart[i].getPrice() << ", and is a(n) " << customer.shoppingCart[i].getBookType() << endl << endl;

		}
	}
	else
	{
		cout << "Cart Empty!" << endl;
	}

	out << "\nAnd here is the total of your cart: $" << Total << endl;

	return out;
	
}

//End of Customer.cpp

