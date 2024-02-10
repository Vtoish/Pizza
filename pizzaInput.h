#ifndef PIZZA_INPUT_H  // If PIZZA_INPUT_H is not defined
#define PIZZA_INPUT_H  // Define PIZZA_INPUT_H to prevent multiple inclusions of this header file

#include <string>  // Include the standard string library
#include <iostream>  // Include the standard input/output stream library

// Declare a function called getPizzaInput that takes in references to four strings
void getPizzaInput(std::string& numPizza_str, std::string& hydro_str, std::string& style, std::string& size);

#endif // PIZZA_INPUT_H  // End of the conditional inclusion