/*************************
Author:Michael McCabe
Date: February 18, 2018
IDE: Visual Studio
**************************/

#ifndef SIMPLEMENU_HPP
#define SIMPLEMENU_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "DoubleLinked.hpp"



using std::string;
using std::endl;
using std::cout;
using std::cin;

class simpleMenu {
private:
	doubleLinked llist;

	
public:
	simpleMenu();
	void printMenu(); // prints options
	void getChoice(); // handles option choice
	
	void readFromList();
	
	int getInt(const std::string p); // input validation
	int getAnyInt(const std::string p);

};


#endif // !SIMPLEMENU_HPP

