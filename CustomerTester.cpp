/*

//This program is for testing the Customer class


#include <iostream>
#include "Customer.h"
#include <cassert>
#include "DigitalDownload.h"

using namespace std;

int main() 
{

	Customer customer;

	DigitalDownload testDownload1 = { "Name1", "Author1" ,"Type1" ,2021 , 100.10 };
	DigitalDownload testDownload2 = { "Name2", "Author2" ,"Type2" ,2022 , 200.10 };
	DigitalDownload testDownload3 = { "Name3", "Author3" ,"Type3" ,2023 , 300.10 };

	cout << "testing default customer class" << endl;

	cout << customer;

	cout << "testing default customer class complete" << endl;

	cout << "Testing customerclass using testdownload 1,2,3 and add to cart" << endl;

	customer.AddToShoppingCart(testDownload1);
	customer.AddToShoppingCart(testDownload2);
	customer.AddToShoppingCart(testDownload3);


	cout << "\nTesting customerclass using testdownload 1,2,3 and add to cart complete" << endl;

	cout << "Login with username 'Bonkeysha Jr The Eighth'" << endl;
	cout << "You'll need to type it since assert be dumb and there's no function to set customer name with assert" << endl;
	cout << "You'll also need to type it in twice so just type whatever for the first cin since that's how it works in shopping.cpp" << endl;

	customer.LogIn();

	cout << "Login with username 'Bonkeysha Jr The Eighth' complete (or whatever you typed in)" << endl;


	cout << "testing customer total with testdownload 1,2,3 in cart" << endl;

	assert(customer.Total() == 600.30);

	cout << "testing customer total with testdownload 1,2,3 in cart complete" << endl;

	cout << "testing outputting customer with full cart using cout << customer" << endl;

	cout << customer;

	cout << "testing outputting customer using cout << customer complete" << endl;

	cout << "all testing complete" << endl;

	return 0;
}

*/

//End of CustomerTester.cpp