// create main.cpp include all .h files
#include "newyork.h"
#include "sicilian.h"
#include "neapolitan.h"
#include "total.h"
#include "flammkuchen.h"
#include "pizzaInput.h"
#include "validateInput.h"
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

    std::string numPizza_str;
    std::string hydro_str;
    std::string style;
    std::string size;

    // Get user input for number of pizzas, hydration level, style, and size from the user
    getPizzaInput(numPizza_str, hydro_str, style, size);

    int sizePizza = validateSizePizza(size);

    style = validateStyle(style);

    double numPizza = validateNumPizza(numPizza_str);

    double hydro = validateHydration(hydro_str);
    
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

    // Sum all ingredientsy
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
