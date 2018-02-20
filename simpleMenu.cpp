/*************************
Author:Michael McCabe
Date: February 18, 2018
IDE: Visual Studio
**************************/

#include "simpleMenu.hpp"

simpleMenu::simpleMenu() {
	printMenu();
}

void simpleMenu::printMenu() {
	std::cout << "--------Doubly-Linked List----------" << std::endl;
	std::cout << "[1] Add a new node to the head" << std::endl;
	std::cout << "[2] Add a new node to the tail" << std::endl;
	std::cout << "[3] Delete the first node in the list" << std::endl;
	std::cout << "[4] Delete the last node in the list" << std::endl;
	std::cout << "[5] Traverse the list reversely," << std::endl;
	std::cout << "[6] Traverse the list" << std::endl;
	std::cout << "[7] Print the value of the Node the head is pointing to" << std::endl;
	std::cout << "[8] Print the value of the Node the tail is pointing to" << std::endl;
	std::cout << "[9] Read values from a pre-prepared list" << std::endl;
	std::cout << "[10] Quit" << std::endl;
	llist.traverse();
	getChoice();
}

void simpleMenu::getChoice() {
	int input = getInt("Please enter in a positive integer: ");

	while (input < 1 && input > 10) {
		input = getInt("Please reselect: ");
	}

	// exit
	if (input == 10) {
		std::cout << ">>>> Qutting" << std::endl;
		return;
	}
	
	// options
	if (input == 1) {
		llist.addNodetoHead(getAnyInt("Enter in any integer: "));
		printMenu();
	}
	else if (input == 2) {
		llist.addNodetoTail(getAnyInt("Enter in any integer: "));
		printMenu();
	}
	else if (input == 3) {
		llist.deleteFirstNode();
		printMenu();
	}
	else if (input == 4) {
		llist.deleteLastNode();
		printMenu();
	}
	else if (input == 5) {
		llist.traverseReverse();
		printMenu();
	}
	else if (input == 6) {
		llist.traverseReverse();
		printMenu();
	}
	else if (input == 7) {
		llist.printHead();
		printMenu();
	}
	else if (input == 8) {
		llist.printTail();
		printMenu();
	}
	else if (input == 9) {
		readFromList();
		printMenu();
	}
}

void simpleMenu::readFromList() {

	int numbers;

	std::ifstream myList("list.txt");
	if (!myList) {
		std::cout << ">>>>Error opening list.txt" << std::endl;
	}

	else {
		std::cout << ">>>>Reading numbers..." << std::endl;
		while (myList >> numbers) {
			llist.addNodetoTail(numbers);
		}
	}
}
int simpleMenu::getInt(const std::string prompt) {
	int integer;
	std::string input;

	bool isValid = true;

	do {
		std::cout << prompt;
		std::getline(std::cin, input);

		// Loop through all characters and determine if they are a digit or not
		for (unsigned i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				std::cout << "Invalid input" << std::endl;
				isValid = false;
				cin.clear();
				break;
			}

			else {
				isValid = true;
			}
		}
	} while (isValid == false);

	// After scrubbing, cast the input into an integer
	std::stringstream ss(input);

	ss >> integer;

	return integer;
}

int simpleMenu::getAnyInt(const std::string p) {
	int number;
	string input;
	char charTest;

	while (true)
	{
		cout << p;
		getline(cin, input);
		std::stringstream inputStream(input);
		if (!(inputStream >> number)) {
			cout << "Invalud input" << endl;
		}
		else if (inputStream >> charTest) {
			// Check for trailing characters
			cout << "Invalid input" << endl;
		}
		else
		{
			// Input Valid
			return number;
		}
	}
}
