//newyork.cpp
#include "newyork.h"

// Function to calculate the ingredients for new york pizza dough
// Parameters:
// - total: total weight of the dough in grams (double)
// - hydro: hydration level as a decimal (double, e.g., 0.65 for 65% hydration)
// Returns:
// - Ingredients struct containing the calculated amounts of each ingredient
Ingredients newYork(double total, double hydro) {
    // Calculate the amount of semolina flour as 30% of the total weight
    // Calculate the amount of regular flour as 70% of the total weight
    // Calculate the amount of water based on the hydration level
    // Calculate the amount of yeast as 0.3% of the total weight
    // Calculate the amount of salt as 2% of the total weight
    // Calculate the amount of malt as 2% of the total weight
    // Calculate the amount of oil as 1.2% of the total weight
    // Return the struct containing the calculated ingredient amounts
    Ingredients result;
    result.semolina = total * 0.3;
    result.flour = total * 0.7;
    result.water = total * hydro;
    result.yeast = total * 0.003;
    result.salt = total * 0.02;
    result.malt = total * 0.02;
    result.oil = total * 0.012;
    return result;
}