// sicilian.h

// Functions to calculate the ingredients for sicilian pizza dough

#ifndef SICILIAN_H
#define SICILIAN_H
// Ingredient class definition
#include "ingredients.h"

// Declare a function to calculate the required ingredients for sicilian pizza dough based on total flour weight and hydration level
Ingredients sicilian(double total, double hydro);

#endif // SICILIAN_H