// pizzaInput.cpp

#include "pizzaInput.h"

/**
 * Function to get input for ordering pizza.
 *
 * @param numPizza_str string reference to store number of pizzas input
 * @param hydro_str string reference to store hydration level input
 * @param style string reference to store pizza style input
 * @param size string reference to store pizza size input
 *
 * @return void
 *
 * @throws None
 */

void getPizzaInput(std::string& numPizza_str, std::string& hydro_str, std::string& style, std::string& size) {
    std::cout << "How many pizzas?" << std::endl << "    >";
    std::cin >> numPizza_str;

    std::cout << "Hydration level?" << std::endl << "    >";
    std::cin >> hydro_str;

    std::cout << "1.Neapolitan, 2. Sicilian, 3. New York, or 4. Flammkuchen?" << std::endl << "    >";
    std::cin >> style;

    std::cout << "1. Small (20cm), 2. Medium (30cm), or 3. Large (40cm)?" << std::endl << "    >";
    std::cin >> size;

}