#include "mathematics.h"

double _multiply(double x, double y) {
    double result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

float _multiplyf(float x, float y) {
    float result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

long double _multiplyl(long double x, long double y) {
    long double result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

long long _multiplyll(long long x, long long y) {
    long long result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

long _multiplyll_(long x, long y) {
    long result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

int _multiplyi(int x, int y) {
    int result = 0;
    bool negative = false;
    if (x < 0)
    {
        x = -x;
        negative = !negative;
    }
    if (y < 0)
    {
        y = -y;
        negative = !negative;
    }
    /*while (y > 0)
    {
        result += x;
        y--;
    }*/
    result = x*y;
    return negative ? -result : result;
}

int power_int(int a, int b)
{
	/*RETURNS THE POWER OF TWO INTEGERS A^B*/
    int result = 1;
    while (b > 0)
    {
        result = multiply(result, a);
        b--;
    }
    return result;
}

long power_long(long x, long y)
{
    if (y < 0) {
        return 1 / power_long(x, -y);
    } else if (y > 0) {
        long result = 1;
        while (y > 0) {
            result = multiply(result, x);
            y--;
        }
        return result;
    } else {
        return 1;
    }
}

long long power_long_long(long long x, long long y)
{
    if (y < 0) {
        return 1 / power_long_long(x, -y);
    } else if (y > 0) {
        long long result = 1;
        while (y > 0) {
            result = multiply(result, x);
            y--;
        }
        return result;
    } else {
        return 1;
    }
}

float power_float(float x, float y)
{
    if (y < 0) {
        return 1 / power_float(x, -y);
    } else if (y > 0) {
        float result = 1;
        while (y > 0) {
            result = multiply(result, x);
            y--;
        }
        return result;
    } else {
        return 1;
    }
}

double power_double(double x, double y)
{
    if (y < 0) {
        return 1 / power_double(x, -y);
    } else if (y > 0) {
        double result = 1;
        while (y > 0) {
            result = multiply(result, x);
            y--;
        }
        return result;
    } else {
        return 1;
    }
}

long double power_long_double(long double x, long double y)
{
    if (y < 0) {
        return 1 / power_long_double(x, -y);
    } else if (y > 0) {
        long double result = 1;
        while (y > 0) {
            result = multiply(result, x);
            y--;
        }
        return result;
    } else {
        return 1;
    }
}

double sqr(double x)
{
	double y = x;
	if (y < 0){
		return NAN;
	}
	double i = 30;
	while(i > 0){
		y = sqrt_(x, y);
		i = i - 1;
	}
	return y;
}

int sqrt_int(int x)
{
    if (x < 0)
    {
        return -1; // Return a negative value to indicate an error
    }
    if (x == 0 || x == 1)
    {
        return x;
    }
    for (int i = 2; i <= x / 2; i++)
    {
        if (i * i == x)
        {
            return i;
        }
    }
    return -1; // Return a negative value to indicate that no integer square root was found
}


float sqrtf(float x)
{
	float y = x;
	if (y < 0){
		return NAN;
	}
	float i = 30;
	while(i > 0){
		y = sqrtf_(x, y);
		i = i - 1;
	}
	return y;
}
long double sqrtl(long double x)
{
	long double y = x;
	if (y < 0){
		return NAN;
	}
	long double i = 30;
	while(i > 0){
		y = sqrtl_(x, y);
		i = i - 1;
	}
	return y;
}

double sqr_(double x, double y)
{
	return (0.5 * (y+ (x/y)));
}

float sqrtf_(float x, float y)
{
    return (0.5f * (y + (x / y)));
}

long double sqrtl_(long double x, long double y)
{
    return (0.5l * (y + (x / y)));
}
