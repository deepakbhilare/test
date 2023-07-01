#include<stdio.h>

int main()
{

	printf("\nHello");

	FILE *fp = fopen("mylog.txt", "a+");
	fprintf(fp, "\nhere 1");
	fclose(fp);

	return 0;
	
}


