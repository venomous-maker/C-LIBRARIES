#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#define NAN ((double) ~0)
#define bool _Bool
#define true 1
#define false 0
#ifndef NULL
#define NULL 0
#endif
// MULTIPLICATION MACRO AND FUNCTIONS
#define multiply(x, y) _Generic((x, y),\
    float: _multiplyf,\
    int: _multiplyi,\
    double: _multiply,\
    long double: _multiplyl,\
    long long: _multiplyll,\
    long: _multiplyll_,\
    default: _multiply\
    )(x, y)

float _multiplyf(float x, float y);
int _multiplyi(int x, int y);
double _multiply(double x, double y);
long double _multiplyl(long double x, long double y);
long long _multiplyll(long long x, long long y);
long _multiplyll_(long x, long y);

// POWER MACRO AND FUNCTIONS
#define power(a, b) _Generic((a, b), \
    int: power_int, \
    long: power_long, \
    long long: power_long_long, \
    float: power_float, \
    double: power_double, \
    long double: power_long_double \
)(a, b)
int power_int(int a, int b);
long power_long(long x, long y);
long long power_long_long(long long x, long long y);
float power_float(float x, float y);
double power_double(double x, double y);
long double power_long_double(long double x, long double y);

// SQUARE ROOTS
typedef double (*sqrt_t)(double);
typedef double (*sqrt_xy_t)(double, double);

double sqr(double x);
int sqrt_int(int x);
float sqrtf(float x);
long double sqrtl(long double x);

double sqr_(double x, double y);
float sqrtf_(float x, float y);
long double sqrtl_(long double x, long double y);
/* MACRO TO HANDLE SQUARE ROOTS*/
//{
#define sqrt(x) _Generic((x), \
    float: sqrtf, \
    int: sqrt_int, \
    double: sqr, \
    long double: sqrtl)(x)

#define sqrt_(x, y) _Generic((x), \
    float: sqrtf_, \
    double: sqr_, \
    long double: sqrtl_)(x, y)
//}
#endif
