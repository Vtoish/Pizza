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

    std::cout << "1.Neapolitan, 2. Sicilian, 3. New York, or 4. Flammkuchen?" << std::endl << "    >";
    std::cin >> style;

    std::cout << "1. Small (20cm), 2. Medium (30cm), or 3. Large (40cm)?" << std::endl << "    >";
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
        ingredients = sicilian(totalFlour, hydro);
    }
    else if (style == "New York") {
        ingredients = newYork(totalFlour, hydro);
    }
    else if (style == "Flammkuchen") {
        ingredients = flammkuchen(totalFlour, hydro);
    }

    // Sum all ingredients
    double totalIngredients = 0;
    totalIngredients += ingredients.flour;
    totalIngredients += ingredients.semolina;
    totalIngredients += ingredients.water;
    totalIngredients += ingredients.yeast;
    totalIngredients += ingredients.salt;
    totalIngredients += ingredients.malt;
    totalIngredients += ingredients.oil;

    // Calculate weight of single dough ball
    double doughBall = totalIngredients / numPizza;
    
    // Calculate cost of ingredients
    double cost = (ingredients.flour * ppgFlour) + (ingredients.semolina * ppgSemolina) + (ingredients.yeast * ppgYeast) +
                       (ingredients.salt * ppgSalt) + (ingredients.malt * ppgMalt) + (ingredients.oil * ppgOil);

    // Print ingredients
    std::cout << std::setprecision(2);
    std::cout << "-------------------------" << std::endl
          << "   Flour:    " << std::fixed << ingredients.flour << "g" << std::endl
          << "   Semolina: " << std::fixed << ingredients.semolina << "g" << std::endl
          << "   Water:    " << std::fixed << ingredients.water << "g" << std::endl
          << "   Yeast:    " << std::fixed << ingredients.yeast << "g" << std::endl
          << "   Salt:     " << std::fixed << ingredients.salt << "g" << std::endl
          << "   Malt:     " << std::fixed << ingredients.malt << "g" << std::endl
          << "   Oil:      " << std::fixed << ingredients.oil << "g" << std::endl;

    // Print cost
    std::cout << "-------------------------" << std::endl
              << "Cost:            $" << std::fixed << std::setprecision(2) << cost << std::endl;

    // Print weight of single dough ball
    std::cout << "-------------------------" << std::endl
              << "Weight of single dough ball: ~" << std::fixed <<  std::setprecision(0) << doughBall << "g" << std::endl;
        
}

// create main function
int main() {
    char runAgain;
    do {
        pizzaCalc();
        std::cout << "Do you want to run the program again? (y/n): " << std::endl;
        std::cin >> runAgain;
    } while (runAgain == 'y' || runAgain == 'Y');
    
    return 0;
}
