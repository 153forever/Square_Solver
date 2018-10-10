//
//  main.cpp
//  Finding_roots
//
//  Created by Тимур Бариев on 29.08.2018.
//  Copyright © 2018 Тимур Бариев. All rights reserved.
//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <assert.h>
#include <math.h>
#include <stdio.h>

//- - - - - - - - - - - - - - - - - - - - - - - - - - - -

double Linear_Solver (double b, double c, double *px1);
int Square_Solver (double a, double b, double c, double *px1, double *px2);

//- - - - - - - - - - - - - - - - - - - - - - - - - - - -
//! @return 0 when everything is fine
//!
//! @details Asks to enter three coefficienties a, b, c of the square equation
//! @details Prints roots of the equation with entered coefficienties
//! @details Prints "Strange nRoots = ...(the root) in SolveSquare ...(coefficienties)" if the amount of roots is strange
//- - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main()
{
    printf("# Square Equation Solver v.0.1a (c)153_Timur\n\n");
    
    printf("# Enter a, b, c:\n");
    
    double a = NAN, b = NAN, c = NAN;
    scanf("%lg%lg%lg", &a, &b, &c);
    double x1 = 0, x2 = 0;
    int nRoots = Square_Solver(a, b, c, &x1, &x2);
    
    switch(nRoots) {
        case -1: printf ("No real solutions\n");
            break;
        case 0: printf ("No roots\n");
            break;
        case 1: printf ("One root: %lg\n", x1);
            break;
        case 2: printf ("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case 3: printf ("Infinite roots");
            break;
        default: printf("Strange nRoots = %d in SolveSquare (%lg, %lg, %lg)\n", nRoots, a, b, c); return 1;
    }
    
    return 0;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - -
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] px1 Pointer to the first root
//! @param [out] px2 Pointer to the second root
//!
//! @brief Change the value of x1 and x2 solving square equation ax^2+bx+c=0
//!
//! @return Number of roots
//!
//! @note Returns -1 if in square equation no real solutions (only complex solutions)
//! @note Returns 3 if in square equation infinite number of solutions
//- - - - - - - - - - - - - - - - - - - - - - - - - - - -


int Square_Solver (double a, double b, double c, double *px1, double *px2)
{
    assert (isfinite (a) != 0);
    assert (isfinite (b) != 0);
    assert (isfinite (c) != 0);
    
    assert (px1 != NULL);
    assert (px2 != NULL);
    assert (px1 != px2);
    
    if(a == 0)
    {
        return Linear_Solver(b, c, px1);
    }
    else /* if(a != 0) */
    {
        double d = b * b - 4 * a * c;
        if(d == 0)
        {
            *px1 = *px2 = -b / (2 * a);
            assert(*px1 != NAN);
            
            return 1;
        }
        else /* if(d != 0) */
        {
            *px1 = (-b + sqrt(d)) / (2 * a);
            assert(*px1 != NAN);
            
            *px2 = (-b - sqrt(d)) / (2 * a);
            assert(*px2 != NAN);
            
            if(d > 0)
                return 2;
            else /* if(d < 0) */
                return -1;
        }
    }
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - -
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] px1 Pointer to the root
//!
//! @brief Change the value of x1 solving liner equation bx+c=0
//!
//! @return Number of roots
//!
//! @note Returns 3 if in linear equation infinite number of solutions
//- - - - - - - - - - - - - - - - - - - - - - - - - - - -

double Linear_Solver (double b, double c, double *px1)
{
    assert (isfinite (b) != 0);
    assert (isfinite (c) != 0);
    assert (px1 != NULL);
    
    if(b == 0)
    {
        if(c == 0)
            return 3;
        
        else /* if(c != 0)*/
            return 0;
    }
    else /* if(b !=0) */
    {
        *px1 = -b/c;
        assert(*px1 != 0);
        
        return 1;
    }
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - -
