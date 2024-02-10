// create main.cpp include all .h files
#include "newyork.h"
#include "sicilian.h"
#include "neapolitan.h"
#include "total.h"
#include "flammkuchen.h"
#include <iostream>
#include <string>
#include <iomanip>

// create pizzaCalc function
void pizzaCalc() {
    // Price per gram of each ingredient
    const double ppgFlour = 0.19 / 28;
    const double ppgSemolina = 0.19 / 28;
    const double ppgYeast = 1.93 / 28;
    const double ppgSalt = 0.25 / 28;
    const double ppgMalt = 0.54 / 28;
    const double ppgOil = 0.25 / 28;

    // Number of pizzas, level of hydration, and style
    std::string numPizza_str, hydro_str, style, size;
    
    std::cout << "How many pizzas?" << std::endl << "    >";
    std::cin >> numPizza_str;

    std::cout << "Hydration level?" << std::endl << "    >";
    std::cin >> hydro_str;

    std::cout << "Neapolitan, Sicilian, New York, or Flammkuchen?" << std::endl << "    >";
    std::cin >> style;

    std::cout << "Small (20cm), Medium (30cm), or Large (40cm)?" << std::endl << "    >";
    std::cin >> size;


    // Validate size of pizza
    int sizePizza = -1;
    while (sizePizza == -1){
        if (size == "small" || size == "Small" || size == "S" || size == "s" || size == "1") {
        sizePizza = 1;
    } else if (size == "medium" || size == "Medium" || size == "M" || size == "m" || size == "2") {
        sizePizza = 2;
    } else if (size == "large" || size == "Large" || size == "L" || size == "l" || size == "3") {
        sizePizza = 3;
    } else {
        std::cout << "Small (20cm), Medium (30cm), or Large (40cm)?" << std::endl << "Enter a valid size!" << std::endl << "    >";
        std::cin >> size;
    }
    }

    // Validate style
    if (style == "Neapolitan" || style == "neapolitan" || style == "NA" || style == "na" || style == "Na" || style == "1") {
        style = "Neapolitan";
    } else if (style == "Sicilian" || style == "sicilian" || style == "S" || style == "s" || style == "2") {
        style = "Sicilian";
    } else if (style == "New York" || style == "new york" || style == "Ny" || style == "ny" || style == "NY" || style == "3") {
        style = "New York";
    } else if (style == "Flammkuchen" || style == "flammkuchen" || style == "F" || style == "f" || style == "4") {
        style = "Flammkuchen";
    } else {
        std::cout << "Invalid input!" << std::endl;
    }

    // Validate number of pizzas
    double numPizza;
    while (true) {
        try {
            numPizza = std::stod(numPizza_str);
            break;
        } catch (const std::invalid_argument&) {
            std::cout << "How many pizzas?" << std::endl << "Enter a number!" << std::endl << "    >";
            std::cin >> numPizza_str;
        }
    }

    // Validate hydration level
    double hydro;
    while (true) {
        try {
            hydro = std::stod(hydro_str) / 100;
            break;
        } catch (const std::invalid_argument&) {
            std::cout << "Hydration level?" << std::endl << "Enter a number!" << std::endl << "    >";
            std::cin >> hydro_str;
        }
    }
    
    // Calculate total amount of flour needed
    // Total amount of flour needed
    const double totalFlour = total(numPizza, hydro, sizePizza);

    Ingredients ingredients;
    ingredients.flour = 0;
    ingredients.semolina = 0;
    ingredients.yeast = 0;
    ingredients.salt = 0;
    ingredients.malt = 0;
    ingredients.oil = 0;

    // Calculate ingredients by calling functions
    if (style == "Neapolitan") {
        ingredients = neapolitan(totalFlour, hydro);
    }
    else if (style == "Sicilian") {
    }
    else if (style == "New York") {
        ingredients = newYork(totalFlour, hydro);
    }
    else if (style == "Flammkuchen") {
        ingredients = flammkuchen(totalFlour, hydro);
    }
    
    // Calculate cost of ingredients
    double cost = (ingredients.flour * ppgFlour) + (ingredients.semolina * ppgSemolina) + (ingredients.yeast * ppgYeast) +
                       (ingredients.salt * ppgSalt) + (ingredients.malt * ppgMalt) + (ingredients.oil * ppgOil);

    // Print ingredients
    std::cout << "-------------------------" << std::endl
              << "   Flour:    " << ingredients.flour << "g" << std::endl
              << "   Semolina: " << ingredients.semolina << "g" << std::endl
              << "   Water:    " << ingredients.water << "g" << std::endl
              << "   Yeast:    " << ingredients.yeast << "g" << std::endl
              << "   Salt:     " << ingredients.salt << "g" << std::endl
              << "   Malt:     " << ingredients.malt << "g" << std::endl
              << "   Oil:      " << ingredients.oil << "g" << std::endl;

    // Print cost
    std::cout << "-------------------------" << std::endl
              << "Cost:            $" << std::fixed << std::setprecision(2) << cost << std::endl;
}

// create main function
int main() {
    pizzaCalc();
    return 0;
}
