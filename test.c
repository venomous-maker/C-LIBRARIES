#include "mathematics.h"
#include "converters.h"
#include "customlib.h"
#include <stdio.h>
#include <stdlib.h>
char  **strings; int num_ = 0;
int *num, *num1;
void print(){
	//insertion_sort(num, 0, num_);
	sort(num1, num_);
}
void print1(){
	insertion_sort(num, 0, num_);
}

void print2(){
	merge_sort(num, 0, num_);
}
int main(int args, sentence_ argv){
    //float y = str_to_double(argv[1]);
	double d = to_int(argv[1]);
	char *file = "numbers.txt";
	int res = 0;//read_lines_from_file(file, &strings,&num_);
	/*int size = sizeof(strings)/sizeof(strings[0]);
	num = (int*)malloc(num_*sizeof(int));
	num1 = (int*)malloc(sizeof(num));*/
	char *str[]={"You", "you", "Abel", "James","ABel", "Jacob", "JAcob"};
	strings = str;
	num_ = 6;
	merge_sort(strings,0, num_);
	//for (int i = 0; i < num_; i++) num1[i] = num[i] = to_int(strings[i]);
	//printf("%f", d);
	//double t = time_execution((fn_ptr)print1);
	//printf("Insertion Sort: %.9f Seconds\n", t/1e6);
	//printf("Tim Sort: %.9f Seconds\n", time_execution((fn_ptr)print)/1e6);
	//("Merge Sort: %.9f Seconds\n", time_execution((fn_ptr)print2)/1e6);
	if(res == 0) for(int i = 0; i < num_; i++) printf("%s\n", (strings[i]));
	/*char *p = "";
	char *d = "12345";
	printf("%d", cmp(p, d));*/
	return 0;
}
