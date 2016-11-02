void Message(const char* file)
{
	FILE *inptr;
	char msg[30];
	int n;
	inptr=fopen(file, "a");
	if(inptr==NULL)
		printf("File not opened");
	else
	{
		printf("Enter EOF to quit.\n");
		fflush(stdin);
		printf("Type message: ");
		gets(msg);
		while(!feof(stdin))
		{
			fprintf(inptr, "%s", msg);
			printf("Type message: ");
			fflush(stdin);
			gets(msg);
		}
		fclose(inptr);
	}
}

