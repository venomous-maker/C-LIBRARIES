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

long long int _multiplyi(int x, int y) {
    long long int result = 0;
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

long long int power_int(int a, int b)
{
	/*RETURNS THE POWER OF TWO INTEGERS A^B*/
    long long int result = 1;
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

long long int sqrt_int(int x)
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

// insertion sort
void insertionSort(int arr[], int left, int right)

{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertionSortf(float arr[], int left, int right)

{
    for (int i = left + 1; i <= right; i++)
    {
        float temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertionSortd(double arr[], int left, int right)

{
    for (int i = left + 1; i <= right; i++)
    {
        double temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertionSortl(long arr[], int left, int right)

{
    for (int i = left + 1; i <= right; i++)
    {
        long temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertionSorts(char** arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		char* temp = arr[i];
		int j = i - 1;
		while (j >= left && cmp(arr[j], temp) > 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void insertionSortll(long long arr[], int left, int right)

{
    for (int i = left + 1; i <= right; i++)
    {
        long long temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void mergeSortf(float arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortf(arr, l, m);
		mergeSortf(arr, m + 1, r);
		mergef(arr, l, m, r);
	}
}

void mergeSortd(double arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortd(arr, l, m);
		mergeSortd(arr, m + 1, r);
		merged(arr, l, m, r);
	}
}

void mergeSortl(long arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortl(arr, l, m);
		mergeSortl(arr, m + 1, r);
		mergel(arr, l, m, r);
	}
}

void mergeSortll(long long arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortll(arr, l, m);
		mergeSortll(arr, m + 1, r);
		mergell(arr, l, m, r);
	}
}

void mergeSorts(char* arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSorts(arr, l, m);
		mergeSorts(arr, m + 1, r);
		merges(arr, l, m, r);
	}
}

// merge two arrays
void merge(int arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergef(float arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    float left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergel(long arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    long left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergell(long long arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    long long left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void merged(double arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    double left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

int cmp(char left[], char right[]) {
	if(left == NULL || right == NULL) return 0;
	int i = 0, j = 0, l = stringlen(left), r = stringlen(right);
	while (left[i] != '\0' && right[j] != '\0') {
		if (left[i] != right[j]) {
			return left[i] - right[j];
		}
		i++;
		j++;
		if (i >= l)  return 1;
		if (j >= r)  return -1;
	}
	if (left[i] != '\0') {
		return 1;
	} else if (right[j] != '\0') {
		return -1;
	} else {
		return 0;
	}
}

void merges(char **arr, int l, int m, int r)
{
	int len1 = m - l + 1, len2 = r - m;
	printf("%d %d\n", len1, len2);
	char *left[len1], *right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i <len2; i++)
		right[i] = arr[m + 1 +i];
	
	int i = 0, j = 0, k = l;
	
	while (i < len1 && j < len2-1)
	{
		// Compare the characters at the current index of the left and right arrays
		int cmp_ = cmp(left[i], right[j]);
		
		if (cmp_ <= 0)
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	
	while (i < len1)
	{
		arr[k++] = left[i++];
	}
	
	while (j < len2)
	{
		arr[k++] = right[j++];
	}
}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n)
{
     //size_t n = get_pointer_size(arr);
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
         
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void timSortf(float arr[], int n)
{
     // n = size
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSortf(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
              if(mid < right)
                mergef(arr, left, mid, right);
        }
    }
}

void timSortd(double arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSortd(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
              if(mid < right)
                merged(arr, left, mid, right);
        }
    }
}

void timSortl(long arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSortl(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
              if(mid < right)
                mergel(arr, left, mid, right);
        }
    }
}

void timSortll(long long arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSortll(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
              if(mid < right)
                mergell(arr, left, mid, right);
        }
    }
}

void timSorts(char* arr[], int n)
{
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSorts(arr, i, min((i+RUN-1), (n-1)));
	
	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n; size = 2*size)
	{
		for (int left = 0; left < n; left += 2*size)
		{
			int mid = left + size - 1;
			int right = min((left + 2*size - 1), (n-1));
			if(mid < right)
				merges(arr, left, mid, right);
		}
	}
}
