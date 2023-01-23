#ifndef CONVERTERS_H
#define CONVERTERS_H
#include <stdlib.h>
#ifndef NAN
#define NAN ((double) ~0) // defined in mathematics.h too
#endif
#ifndef INT_MAX
#define INT_MAX ((int)(~0U>>1))//9223372036854775807
#endif
#ifndef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#endif
#define DBL_MAX 1.7976931348623158e+308
#define DBL_MIN 2.2250738585072014e-308
#ifndef FLT_MAX
#define FLT_MAX __FLT_MAX__//3.402823466e+38F
#endif
#ifndef FLT_MIN
#define FLT_MIN __FLT_MIN__//1.175494351e-38F
#endif
#ifndef bool
#define bool _Bool
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#ifndef NULL
#define NULL 0
#endif
#ifndef string
#define string char *
#endif
#ifndef sentence
#define sentence char **
#endif
/*Keep in mind that the commented definitions may not be 100% accurate 
and may differ slightly from the actual maximum and minimum values of 
the float type on your system.*/
double str_to_double(const char *str);
float str_to_float(const char *str);

// INT CONVERTERS
#define to_int(x) _Generic((x),\
    char: to_int_char,\
    short: to_int_short,\
    int: to_int_int,\
    char *: str_to_int,\
    long: to_int_long,\
    long long: to_int_long_long,\
    float: to_int_float,\
    double: to_int_double,\
    long double: to_int_long_double)(x)
int str_to_int(const char *str);
int to_int_char(char x);
int to_int_short(short x);
int to_int_int(int x);
int to_int_long(long x);
int to_int_long_long(long long x);
int to_int_float(float x);
int to_int_double(double x);
int to_int_long_double(long double x);
/* FLOAT CONVERTERS*/
#define to_float(x) _Generic((x),\
    char: to_float_char,\
    short: to_float_short,\
    int: to_float_int,\
    char *: str_to_float,\
    long: to_float_long,\
    long long: to_float_long_long,\
    float: to_float_float,\
    double: to_float_double,\
    long double: to_float_long_double)(x)
float str_to_float(const char *str);
float to_float_char(char x);
float to_float_short(short x);
float to_float_int(int x);
float to_float_long(long x);
float to_float_long_long(long long x);
float to_float_float(float x);
float to_float_double(double x);
float to_float_long_double(long double x);
/*DOUBLE CONVERTERS*/
#define to_double(x) _Generic((x),\
	char: to_double_char,\
	short: to_double_short,\
	int: to_double_int,\
	long double: to_double_long_double,\
	double: to_double_double,\
	float: to_double_float,\
	long long: to_double_long_long,\
	long: to_double_long,\
	string: str_to_double,\
	default: to_double_double)(x)
double to_double_long_double(long double x);
double to_double_double(double x);
double to_double_float(float x);
double to_double_long_long(long long x);
double to_double_long(long x);
double to_double_int(int x);
double to_double_short(short x);
double to_double_char(char x);

bool is_alpha(char c);
bool is_str(const char *s);
bool is_digit(char c);
bool is_space(int c);
bool is_symbol(char c);
bool is_symbol(char c);
bool is_punct(const char c);
//ARRAY MERGERS
#define mergeArrays(x, y, i, j) _Generic((x,y),\
	int*: merge_arrayi,\
	float*: merge_arrayf,\
	double*: merge_array,\
	long long*: merge_arrayll,\
	long*: merge_arrayl,\
	default: merge_arrayi)(x, y, i, j)
double *merge_array(double arr[], double arr1[], int size, int size1);
int *merge_arrayi(int arr[], int arr1[], int size, int size1);
float *merge_arrayf(float arr[], float arr1[], int size, int size1);
long *merge_arrayl(long arr[], long arr1[], int size, int size1);
long long *merge_arrayll(long long arr[], long long arr1[], int size, int size1);
#endif
