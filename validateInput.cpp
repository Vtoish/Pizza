#include "validateInput.h"

int validateSizePizza(std::string size) {
    if (size == "small" || size == "Small" || size == "S" || size == "s" || size == "1") {
        return 1;
    } else if (size == "medium" || size == "Medium" || size == "M" || size == "m" || size == "2") {
        return 2;
    } else if (size == "large" || size == "Large" || size == "L" || size == "l" || size == "3") {
        return 3;
    } else {
        std::cout << "Small (20cm), Medium (30cm), or Large (40cm)?" << std::endl << "Enter a valid size!" << std::endl << "    >";
        std::cin >> size;
        return validateSizePizza(size);
    }
}

std::string validateStyle(std::string style) {
    if (style == "Neapolitan" || style == "neapolitan" || style == "NA" || style == "na" || style == "Na" || style == "1") {
        return "Neapolitan";
    } else if (style == "Sicilian" || style == "sicilian" || style == "S" || style == "s" || style == "2") {
        return "Sicilian";
    } else if (style == "New York" || style == "new york" || style == "Ny" || style == "ny" || style == "NY" || style == "3") {
        return "New York";
    } else if (style == "Flammkuchen" || style == "flammkuchen" || style == "F" || style == "f" || style == "4") {
        return "Flammkuchen";
    } else {
        std::cout << "Invalid input!" << std::endl;
        return ""; // or handle the invalid input in some other way
    }
}

double validateNumPizza(std::string numPizza_str) {
    double numPizza;
    while (true) {
        try {
            numPizza = std::stod(numPizza_str);
            return numPizza;
        } catch (const std::invalid_argument&) {
            std::cout << "How many pizzas?" << std::endl << "Enter a number!" << std::endl << "    >";
            std::cin >> numPizza_str;
        }
    }
}

double validateHydration(std::string hydro_str) {
    double hydro;
    while (true) {
        try {
            hydro = std::stod(hydro_str) / 100;
            return hydro;
        } catch (const std::invalid_argument&) {
            std::cout << "Hydration level?" << std::endl << "Enter a number!" << std::endl << "    >";
            std::cin >> hydro_str;
        }
    }
}