// neapolitan.h

// Functions to calculate the ingredients for neapolitan pizza dough

#ifndef NEAPOLITAN_H
#define NEAPOLITAN_H
// Ingredient class definition
#include "ingredients.h"

// Declare a function to calculate the required ingredients for neapolitan pizza dough based on total flour weight and hydration level
Ingredients neapolitan(double total, double hydro);

#endif // NEAPOLITAN_H