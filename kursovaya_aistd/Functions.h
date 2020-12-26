#pragma once
#pragma once
#include "MyList.h"
#include "Stack.h"
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES // for pi written like M_PI
#include <math.h>

enum functions { SIN, COS, TG, CTG, LOG, LN, SQRT, PI, EXP, NOT_FUNCTION };

enum priorities { brecket, minus_plus, multiply_divide, degree, function, not_operator };

void allResults(string str);
MyList* chek_and_separation(string str);
MyList* from_infix_to_prefix(MyList* elements);
MyList* reverse(MyList* reversed);
MyList* out_this_and_copy(MyList*);
double calculate_it(MyList*);
bool check_if_number(char);
bool check_if_letter(char);
int operation_priority(char);
int what_function(string);