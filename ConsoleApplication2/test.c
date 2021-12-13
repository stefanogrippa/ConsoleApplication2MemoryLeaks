#include	<malloc.h>
#include	"leak_detector_c.h"
#include <stdlib.h> 
int test()
{
	char * ptr1 = (char *)calloc(10, sizeof(char));
	int * ptr2 = (int *)calloc(10, sizeof(int));
	float * ptr3 = (float *)calloc(15, sizeof(float));
	free(ptr2);
	int ret = atexit(report_mem_leak);
	return ret;
}

int main()
{
	return test();
}
