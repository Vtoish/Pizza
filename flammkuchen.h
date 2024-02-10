// flammkuchen.h

// Functions to calculate the ingredients for flammkuchen pizza dough

#ifndef FLAMMKUCHEN_H
#define FLAMMKUCHEN_H
// Ingredient class definition
#include "ingredients.h"

// Declare a function to calculate the required ingredients for flammkuchen pizza dough based on total flour weight and hydration level
Ingredients flammkuchen(double total, double hydro);

#endif // FLAMMKUCHEN_H