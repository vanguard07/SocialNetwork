void Write(const char* file)
{
	int i;
	char A[20];
	FILE *inptr;
	if((inptr=fopen(file, "w"))==NULL)
		printf("%File not open");
	else
		{
			printf("Enter EOF to quit!\n");
			gets(A);
			while(!feof(stdin))
				{
					fprintf(inptr, "%s", A);
					fflush(stdin);
					gets(A);
				}
			fclose(inptr);
		}
}

