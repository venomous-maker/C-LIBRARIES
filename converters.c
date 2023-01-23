#include "converters.h"
int str_to_int(const char *str)
{
    int result = 0;
    int sign = 1;

    // Skip leading white space
    while (is_space(*str))
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Check for leading zeros
    if (*str == '0')
    {
        str++;
        if (*str == '\0')
        {
            // Return zero for a single zero
            return 0;
        }
        if (*str == 'x' || *str == 'X')
        {
            // Hexadecimal number
            str++;
            while (*str)
            {
                if (is_digit(*str))
                {
                    result = result * 16 + (*str - '0');
                }
                else if (*str >= 'a' && *str <= 'f')
                {
                    result = result * 16 + (*str - 'a' + 10);
                }
                else if (*str >= 'A' && *str <= 'F')
                {
                    result = result * 16 + (*str - 'A' + 10);
                }
                else
                {
                    // Invalid character
                    return -1;
                }
                str++;
            }
            return result * sign;
        }
        // Octal number
        while (*str == '0')
        {
            str++;
        }
    }

    // Decimal number
    while (*str)
    {
        int digit = *str - '0';
        if (!is_digit(*str))
        {
            // Invalid character
            //return -2;
            digit = to_int(*str);
            digit = *str - '0';
        }
        if (result > (INT_MAX - digit) / 10)
        {
            // Overflow
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        str++;
    }
    return result * sign;
}

long long str_to_long_long(const char *str)
{
	long long result = 0;
	int sign = 1;
	
	// Skip leading white space
	while (is_space(*str))
	{
		str++;
	}
	
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	
	// Check for leading zeros
	if (*str == '0')
	{
		str++;
		if (*str == '\0')
		{
			// Return zero for a single zero
			return 0;
		}
		if (*str == 'x' || *str == 'X')
		{
			// Hexadecimal number
			str++;
			while (*str)
			{
				if (is_digit(*str))
				{
					result = result * 16 + (*str - '0');
				}
				else if (*str >= 'a' && *str <= 'f')
				{
					result = result * 16 + (*str - 'a' + 10);
				}
				else if (*str >= 'A' && *str <= 'F')
				{
					result = result * 16 + (*str - 'A' + 10);
				}
				else
				{
					// Invalid character
					return -1;
				}
				str++;
			}
			return result * sign;
		}
		// Octal number
		while (*str == '0')
		{
			str++;
		}
	}
	
	// Decimal number
	while (*str)
	{
		int digit = *str - '0';
		if (!is_digit(*str))
		{
			// Invalid character
			//return -2;
			digit = to_int(*str);
			digit = *str - '0';
		}
		if (result > (INT_MAX - digit) / 10)
		{
			// Overflow
			return (sign == 1) ? INT_MAX : INT_MIN;
		}
		result = result * 10 + digit;
		str++;
	}
	return result * sign;
}

int to_int_char(char x)
{
    return (int)x;
}

int to_int_short(short x)
{
    return (int)x;
}

int to_int_int(int x)
{
    return x;
}

int to_int_long(long x)
{
    return (int)x;
}

int to_int_long_long(long long x)
{
    return (int)x;
}

int to_int_float(float x)
{
    return (int)x;
}

int to_int_double(double x)
{
    return (int)x;
}

int to_int_long_double(long double x)
{
    return (int)x;
}

double str_to_double(const char *str)
{
    double result = 0;
    double sign = 1;
    double fraction = 0;
    double scale = 1;

    // Skip leading white space
    while (is_space(*str))
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Check for leading zeros
    if (*str == '0')
    {
        str++;
        if (*str == '\0')
        {
            // Return zero for a single zero
            return 0;
        }
        if (*str == 'x' || *str == 'X')
        {
            // Hexadecimal number
            str++;
            while (*str)
            {
                if (is_digit(*str))
                {
                    result = result * 16 + (*str - '0');
                }
                else if (*str >= 'a' && *str <= 'f')
                {
                    result = result * 16 + (*str - 'a' + 10);
                }
                else if (*str >= 'A' && *str <= 'F')
                {
                    result = result * 16 + (*str - 'A' + 10);
                }
                else
                {
                    // Invalid character
                    return NAN;
                }
                str++;
            }
            return result * sign;
        }
        // Octal number
        while (*str == '0')
        {
            str++;
        }
    }

    // Decimal number
    while (is_digit(*str))
    {
        int digit = *str - '0';
        if (result > (DBL_MAX - digit) / 10)
        {
            // Overflow
            return (sign == 1) ? DBL_MAX : -DBL_MAX;
        }
        result = result * 10 + digit;
        str++;
    }

    // Check for fraction
    if (*str == '.')
    {
        str++;
        while (is_digit(*str))
        {
            int digit = *str - '0';
            if (fraction > (DBL_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? DBL_MAX : -DBL_MAX;
            }
            fraction = fraction * 10 + digit;
            scale *= 10;
            str++;
        }
    }

    // Check for exponent
    if (*str == 'e' || *str == 'E')
    {
        str++;
        double exponent = 0;
        double exponent_sign = 1;
        if (*str == '-')
        {
            exponent_sign = -1;
            str++;
        }
        else if (*str == '+')
        {
            str++;
        }
        while (is_digit(*str))
        {
            int digit = *str - '0';
            if (exponent > (DBL_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? DBL_MAX : -DBL_MAX;
            }
            exponent = exponent * 10 + digit;
            str++;
        }
        exponent *= exponent_sign;
        if (exponent > 0)
        {
            while (exponent-- > 0)
            {
                if (result > DBL_MAX / 10)
                {
                    // Overflow
                    return (sign == 1) ? DBL_MAX : -DBL_MAX;
                }
                result *= 10;
            }
        }
        else if (exponent < 0)
        {
            while (exponent++ < 0)
            {
                if (result < DBL_MIN * 10)
                {
                    // Underflow
                    return (sign == 1) ? DBL_MIN : -DBL_MIN;
                }
                result /= 10;
            }
        }
    }
    return sign * result + fraction / scale;
}

double to_double_char(char x)
{
	return (double)x;
}

double to_double_short(short x)
{
	return (double)x;
}

double to_double_int(int x)
{
	return (double)x;
}

double to_double_long(long x)
{
	return (double)x;
}

double to_double_long_long(long long x)
{
	return (double)x;
}

double to_double_float(float x)
{
	return (double)x;
}

double to_double_double(double x)
{
	return (double)x;
}

double to_double_long_double(long double x)
{
	return (double)x;
}
/*
float str_to_float(const char *str)
{
    return (float)str_to_double(str);
}*/
float str_to_float(const char *str)
{
    float result = 0;
    float sign = 1;
    float fraction = 0;
    float scale = 1;

    // Skip leading white space
    while (is_space(*str))
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Check for leading zeros
    if (*str == '0')
    {
        str++;
        if (*str == '\0')
        {
            // Return zero for a single zero
            return 0;
        }
        if (*str == 'x' || *str == 'X')
        {
            // Hexadecimal number
            str++;
            while (*str)
            {
                if (is_digit(*str))
                {
                    result = result * 16 + (*str - '0');
                }
                else if (*str >= 'a' && *str <= 'f')
                {
                    result = result * 16 + (*str - 'a' + 10);
                }
                else if (*str >= 'A' && *str <= 'F')
                {
                    result = result * 16 + (*str - 'A' + 10);
                }
                else
                {
                    // Invalid character
                    return NAN;
                }
                str++;
            }
            return result * sign;
        }
        // Octal number
        while (*str == '0')
        {
            str++;
        }
    }

    // Decimal number
    while (is_digit(*str))
    {
        int digit = *str - '0';
        if (result > (FLT_MAX - digit) / 10)
        {
            // Overflow
            return (sign == 1) ? FLT_MAX : -FLT_MAX;
        }
        result = result * 10 + digit;
        str++;
    }

    // Check for fraction
    if (*str == '.')
    {
        str++;
        while (is_digit(*str))
        {
            int digit = *str - '0';
            if (fraction > (FLT_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? FLT_MAX : -FLT_MAX;
            }
            fraction = fraction * 10 + digit;
            scale *= 10;
            str++;
        }
    }

    // Check for exponent
    if (*str == 'e' || *str == 'E')
    {
        str++;
        float exponent = 0;
        float exponent_sign = 1;
        if (*str == '-')
        {
            exponent_sign = -1;
            str++;
        }
        else if (*str == '+')
        {
            str++;
        }
        while (is_digit(*str))
        {
            int digit = *str - '0';
            if (exponent > (FLT_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? FLT_MAX : -FLT_MAX;
            }
            exponent = exponent * 10 + digit;
            str++;
        }
        exponent *= exponent_sign;
        if (exponent > 0)
        {
            while (exponent-- > 0)
            {
                if (result > FLT_MAX / 10)
                {
                    // Overflow
                    return (sign == 1) ? FLT_MAX : -FLT_MAX;
                }
                result *= 10;
            }
        }
        else if (exponent < 0)
        {
            while (exponent++ < 0)
            {
                if (result < FLT_MIN * 10)
                {
                    // Underflow
                    return (sign == 1) ? FLT_MIN : -FLT_MIN;
                }
                result /= 10;
            }
        }
    }
    return sign * result + fraction / scale;
}
// Update the function to handle the exponentials correctly and comment the function above
/*
float str_to_float(const char *str)
{
    float result = 0;
    float sign = 1;
    float fraction = 0;
    float scale = 1;

    // Skip leading white space
    while (is_space(*str))
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Check for leading zeros
    if (*str == '0')
    {
        str++;
        if (*str == '\0')
        {
            // Return zero for a single zero
            return 0;
        }
        if (*str == 'x' || *str == 'X')
        {
            // Hexadecimal number
            str++;
            while (*str)
            {
                if (*str >= '0' && *str <= '9')
                {
                    result = result * 16 + (*str - '0');
                }
                else if (*str >= 'a' && *str <= 'f')
                {
                    result = result * 16 + (*str - 'a' + 10);
                }
                else if (*str >= 'A' && *str <= 'F')
                {
                    result = result * 16 + (*str - 'A' + 10);
                }
                else
                {
                    // Invalid character
                    return NAN;
                }
                str++;
            }
            return result * sign;
        }
        // Octal number
        while (*str == '0')
        {
            str++;
        }
    }

    // Decimal number
    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';
        if (result > (FLT_MAX - digit) / 10)
        {
            // Overflow
            return (sign == 1) ? FLT_MAX : -FLT_MAX;
        }
        result = result * 10 + digit;
        str++;
    }

    // Check for fraction
    if (*str == '.')
    {
        str++;
        while (is_digit(*str))
        {
            int digit = *str - '0';
            if (fraction > (FLT_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? FLT_MAX : -FLT_MAX;
            }
            fraction = fraction * 10 + digit;
            scale *= 10;
            str++;
        }
    }

    // Check for exponent
    if (*str == 'e' || *str == 'E')
    {
        str++;
        float exponent = 0;
        float exponent_sign = 1;
        if (*str == '-')
        {
            exponent_sign = -1;
            str++;
        }
        else if (*str == '+')
        {
            str++;
        }
        while (*str >= '0' && *str <= '9')
        {
            int digit = *str - '0';
            if (exponent > (FLT_MAX - digit) / 10)
            {
                // Overflow
                return (sign == 1) ? FLT_MAX : -FLT_MAX;
            }
            exponent = exponent * 10 + digit;
            str++;
        }
        exponent *= exponent_sign;
        scale = power(10, exponent);
    }
    return (result + fraction / scale) * sign;
}*/
float to_float_char(char x)
{
    return (float)x;
}

float to_float_short(short x)
{
    return (float)x;
}

float to_float_int(int x)
{
    return (float)x;
}

float to_float_long(long x)
{
    return (float)x;
}

float to_float_long_long(long long x)
{
    return (float)x;
}

float to_float_float(float x)
{
    return x;
}

float to_float_double(double x)
{
    return (float)x;
}

float to_float_long_double(long double x)
{
    return (float)x;
}


bool is_digit(char c)
{
    if (c >= '0' && c <= '9') return true;
    else return false;
}

bool is_space(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
        return true;
    else
        return false;
}

bool is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
bool is_symbol(char c)
{
    if (!is_alpha(c) && !is_digit(c) && !is_space(c)) return true;
    else return false;
}*/

bool is_symbol(char c) {
    if (c >= '!' && c <= '/') {
        return true;
    } else if (c >= ':' && c <= '@') {
        return true;
    } else if (c >= '[' && c <= '`') {
        return true;
    } else if (c >= '{' && c <= '~') {
        return true;
    } else if(is_punct(c)){
        return true;
    }
    // Check if the character is a mathematical symbol
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
        return true;
    }
    // Check if the character is a relational operator
    else if (c == '=' || c == '<' || c == '>') {
        return  true;
    }
    // Check if the character is a logical operator
    else if (c == '&' || c == '|' || c == '!') {
        return true;
    }
    // Check if the character is a bitwise operator
    else if (c == '&' || c == '|' || c == '^' || c == '~') {
        return true;
    }
    // Check if the character is a bracket
    else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
        return true;
    }
    return false;
}

bool is_punct(const char c) {
	// Unicode chars
    /*if((c >= '\u0021' && c <= '\u002F') || (c >= '\u003A' && c <= '\u0040')\
        || (c >= '\u005B' && c <= '\u0060') || (c >= '\u007B' && c <= '\u007E'))
        return true;
	// Symbols
    else*/ if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
        return true;
    else return false;
}

bool is_str(const char *s) {
  if (s == NULL) return false;
  if (!s) return false;
  if (*s == '\0') return false;
  while (*s != '\0') {
    if (!is_alpha(*s) && !is_digit(*s) && !is_space(*s)) return false;
    s++;
  }
  return true;
}
// USED TO MERGE ARRAYS
double *merge_array(double arr[], double arr1[], int size, int size1){
	
	double *temp = malloc(sizeof(arr[0]) * (size+size1));
	int iter = 0, whole = 0;
	for ( ; iter < size; iter++){
		temp[whole] = arr[iter];
		whole++;
	}
	for (iter = 0 ; iter < size1; iter++){
			temp[iter] = arr1[iter];
			whole++;
	}
	return temp;
}

float *merge_arrayf(float arr[], float arr1[], int size, int size1){
	
	float *temp = malloc(sizeof(arr[0]) * (size+size1));
	int iter = 0, whole = 0;
	for ( ; iter < size; iter++){
		temp[whole] = arr[iter];
		whole++;
	}
	for (iter = 0 ; iter < size1; iter++){
			temp[iter] = arr1[iter];
			whole++;
	}
	return temp;
}

int *merge_arrayi(int arr[], int arr1[], int size, int size1){
	
	int *temp = malloc(sizeof(arr[0]) * (size+size1));
	int iter = 0, whole = 0;
	for ( ; iter < size; iter++){
		temp[whole] = arr[iter];
		whole++;
	}
	for (iter = 0 ; iter < size1; iter++){
			temp[iter] = arr1[iter];
			whole++;
	}
	return temp;
}

long *merge_arrayl(long arr[], long arr1[], int size, int size1){
	
	long *temp = malloc(sizeof(arr[0]) * (size+size1));
	int iter = 0, whole = 0;
	for ( ; iter < size; iter++){
		temp[whole] = arr[iter];
		whole++;
	}
	for (iter = 0 ; iter < size1; iter++){
			temp[iter] = arr1[iter];
			whole++;
	}
	return temp;
}

long long*merge_arrayll(long long arr[], long long arr1[], int size, int size1){
	
	long long*temp = malloc(sizeof(arr[0]) * (size+size1));
	int iter = 0, whole = 0;
	for ( ; iter < size; iter++){
		temp[whole] = arr[iter];
		whole++;
	}
	for (iter = 0 ; iter < size1; iter++){
			temp[iter] = arr1[iter];
			whole++;
	}
	return temp;
}