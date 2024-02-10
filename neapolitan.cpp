// neapolitan.cpp
#include "neapolitan.h"

// Function to calculate the ingredients for neapolitan pizza dough
// Parameters:
// - total: total weight of the dough in grams
// - hydro: hydration level as a decimal (e.g., 0.65 for 65% hydration)
// Returns:
// - Ingredients struct containing the calculated amounts of each ingredient
Ingredients neapolitan(double total, double hydro) {
    // Calculate the amount of semolina flour as 20% of the total weight
    // Calculate the amount of regular flour as 80% of the total weight
    // Calculate the amount of water based on the hydration level
    // Calculate the amount of yeast as 0.8% of the total weight
    // Calculate the amount of salt as 3% of the total weight
    // Calculate the amount of malt as 1% of the total weight
    // Calculate the amount of oil as 0.5% of the total weight
    // Return the struct containing the calculated ingredient amounts
    Ingredients result;
    result.semolina = total * 0.2;
    result.flour = total * 0.8;
    result.water = total * hydro;
    result.yeast = total * 0.008;
    result.salt = total * 0.03;
    result.malt = total * 0.01;
    result.oil = total * 0.005;
    return result;
}