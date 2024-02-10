// sicilian.cpp
#include "sicilian.h"

// Function to calculate the ingredients for sicilian pizza dough
// Parameters:
// - total: total weight of the dough in grams
// - hydro: hydration level as a decimal (e.g., 0.65 for 65% hydration)
// Returns:
// - Ingredients struct containing the calculated amounts of each ingredient
Ingredients sicilian(double total, double hydro) {
    // Add 25% of the total flour weight to the total flour weight
    // Calculate the amount of semolina flour as 40% of the total weight
    // Calculate the amount of regular flour as 60% of the total weight
    // Calculate the amount of water based on the hydration level
    // Calculate the amount of yeast as 0.6% of the total weight
    // Calculate the amount of salt as 2% of the total weight
    // Calculate the amount of malt as 1% of the total weight
    // Calculate the amount of oil as 0.2% of the total weight
    // Return the struct containing the calculated ingredient amounts
    total += (total * 0.25);
    Ingredients result;
    result.semolina = total * 0.4;
    result.flour = total * 0.6;
    result.water = total * hydro;
    result.yeast = total * 0.006;
    result.salt = total * 0.02;
    result.malt = total * 0.01;
    result.oil = total * 0.02;
    return result;
}