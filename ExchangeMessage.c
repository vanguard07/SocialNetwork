void ExchangeMessage(char filename[40], char namefromlogin[20])
{
	char msg[20];
	FILE *temp;
	if((temp=fopen(filename, "a+"))==NULL)
	printf("File not open?");
	else 
		{
		printf("Enter EOF to quit.\n");
		fflush(stdin);
		printf("Type message: ");
		gets(msg);
		while(!feof(stdin))
		{
			fprintf(temp, "%s: %s\n",namefromlogin, msg);
			printf("Type message: ");
			fflush(stdin);
			gets(msg);
		}
		}
		Read(filename);
		fclose(temp);
}
