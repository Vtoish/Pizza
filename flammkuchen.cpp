// flammkuchen.cpp
#include "flammkuchen.h"

// Function to calculate the ingredients for flammkuchen pizza dough
// Parameters:
// - total: total weight of the dough in grams
// - hydro: hydration level as a decimal (e.g., 0.65 for 65% hydration)
// Returns:
// - Ingredients struct containing the calculated amounts of each ingredient
Ingredients flammkuchen(double total, double hydro) {
    // Subtract 25% of the total flour weight to the total flour weight
    // Calculate the amount of semolina flour as 30% of the total weight
    // Calculate the amount of regular flour as 70% of the total weight
    // Calculate the amount of water based on the hydration level
    // Calculate the amount of yeast as 0.3% of the total weight
    // Calculate the amount of salt as 3% of the total weight
    // Calculate the amount of malt as 1.5% of the total weight
    // Calculate the amount of oil as 0.5% of the total weight
    // Return the struct containing the calculated ingredient amounts
    total -= (total * 0.25);
    Ingredients result;
    result.semolina = total * 0.3;
    result.flour = total * 0.7;
    result.water = total * hydro;
    result.yeast = total * 0.003;
    result.salt = total * 0.03;
    result.malt = total * 0.015;
    result.oil = total * 0.005;
    return result;
}