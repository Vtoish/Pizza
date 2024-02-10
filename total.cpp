#include "total.h"

// Function that calculates the total amount of flour needed
// Parameters:
//   - numPizza: number of pizzas (integer)
//   - hydro: hydration level (double)
//   - size: size of pizza (int)
// Return:
//   - total amount of flour needed (double)
double total(int numPizza, double hydro, int size){
    // Calculate the total amount of flour needed based on the number of pizzas and hydration level
    double total;
    if (size == 1) {
        total = 155 * numPizza / (1 + hydro);
    } 
    else if (size == 2) {
        total = 245 * numPizza / (1 + hydro);
    } 
    else if (size == 3) {
        total = 415 * numPizza / (1 + hydro);
    }

    return total;
}