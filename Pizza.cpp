#include <iostream>
#include <string>
#include <iomanip>

void pizzaCalc() {
    // Price per gram of each ingredient
    const double ppgFlour = 0.19 / 28;
    const double ppgSemolina = 0.19 / 28;
    const double ppgYeast = 1.93 / 28;
    const double ppgSalt = 0.25 / 28;
    const double ppgMalt = 0.54 / 28;
    const double ppgOil = 0.25 / 28;

    // Number of pizzas, level of hydration, and style
    std::string numPizza_str, hydro_str, style;
    
    std::cout << "How many pizzas?" << std::endl << "    >";
    std::cin >> numPizza_str;

    std::cout << "Hydration level?" << std::endl << "    >";
    std::cin >> hydro_str;

    std::cout << "Neapolitan, Sicilian, New York, or Flammkuchen?" << std::endl << "    >";
    std::cin >> style;

    bool done = false;

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

    // Total amount of flour needed
    const double total = 245 * numPizza / (1 + hydro);

    // Execute calculation for correct style
    double semolina;
    double flour;
    double water;
    double yeast;
    double salt;
    double malt;
    double oil;

    while (!done) {
        // Neapolitan
        if (style == "neapolitan") {
            semolina = total * 0.2;
            flour = total * 0.8;
            water = total * hydro;
            yeast = total * 0.008;
            salt = total * 0.03;
            malt = total * 0.01;
            oil = total * 0.005;
            done = true;
        }
        // New York
        else if (style == "new york") {
            semolina = total * 0.3;
            flour = total * 0.7;
            water = total * hydro;
            yeast = total * 0.003;
            salt = total * 0.02;
            malt = total * 0.02;
            oil = total * 0.012;
            done = true;
        }
        // Sicilian
        else if (style == "sicilian") {
            semolina = total * 0.4;
            flour = total * 0.6;
            water = total * hydro;
            yeast = total * 0.006;
            salt = total * 0.02;
            malt = total * 0.01;
            oil = total * 0.02;
            done = true;
        }
        // Flammkuchen
        else if (style == "flammkuchen") {
            semolina = total * 0.3;
            flour = total * 0.7;
            water = total * hydro;
            yeast = total * 0.003;
            salt = total * 0.03;
            malt = total * 0.015;
            oil = total * 0.005;
            done = true;
        }
        // Prompt for valid style
        else {
            std::cout << "Choose Neapolitan, Sicilian, New York, or Flammkuchen!" << std::endl << "    >";
            std::cin >> style;
        }
    }

    // Calculate cost of ingredients
    double cost = (flour * ppgFlour) + (semolina * ppgSemolina) + (yeast * ppgYeast) +
                       (salt * ppgSalt) + (malt * ppgMalt) + (oil * ppgOil);

    // Print ingredients
    std::cout << "-------------------------" << std::endl
              << "   Flour:    " << flour << "g" << std::endl
              << "   Semolina: " << semolina << "g" << std::endl
              << "   Water:    " << water << "g" << std::endl
              << "   Yeast:    " << yeast << "g" << std::endl
              << "   Salt:     " << salt << "g" << std::endl
              << "   Malt:     " << malt << "g" << std::endl
              << "   Oil:      " << oil << "g" << std::endl;

    // Print cost
    std::cout << "-------------------------" << std::endl
              << "Cost:            $" << std::fixed << std::setprecision(2) << cost << std::endl;
}

int main() {
    pizzaCalc();
    return 0;
}