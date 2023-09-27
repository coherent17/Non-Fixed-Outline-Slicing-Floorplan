#ifndef _UTIL_H_
#define _UTIL_H_

// Aspect Ratio Spec
#define MIN_ASPECT_RATIO 0.5
#define MAX_ASPECT_RATIO 2

// Soft Module Area Divder Precision Threshold
#define CALCULATION_ERROR_THRESHOLD 1e-10

// Dead Space for the floorplan: outline = sqrt(sum(area)) * (1 + DEAD_SPACE_RATIO)
#define DEAD_SPACE_RATIO 0.1

// V H Sign in Normalized Polish Expression
enum Node_Type{
    M = -1,     // Module
    V = -2,     // Vertical Split
    H = -3      // Horizontal Split
};

// Print Macro
#define PRINT_MODULE_DETAIL 0
#define PRINT_MODULE 0

#endif