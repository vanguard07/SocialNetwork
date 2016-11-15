void ExchangeMessage(char filename[40], char namefromlogin[20])
   //For exchanging of messages between two users
{
	system("COLOR 0E");
	char msg[200];
	FILE *temp;
	char ch;
	if((temp=fopen(filename, "a+"))==NULL)
	printf("File not open?");
	else
		{
		printf("Enter EOF to quit.\n");
		fflush(stdin);
		system("cls");
		Read(filename);
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
		fclose(temp);
		system("cls");
		Read(filename);
		printf("Press q to quit. ");
		scanf("%c",&ch);
		if (ch=='q')
			 {
			 	system("cls");
			 	Exist(namefromlogin);
			 }

}
