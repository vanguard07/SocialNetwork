void NewLogin()
  //Makes an account of the new user
{
	struct User U1;
	int n;
	char ch;
	fflush(stdin);
	FILE *logptr;
	if((logptr=fopen("Admin.txt", "a+"))==NULL)
	printf("File not open");
	else
	{
	    system("cls");
        printf("\t\t*************************New Login****************************************\n");
		printf("\n\t\t\tEnter Name: ");
		fscanf(stdin, "%s", U1.name);
		printf("\n\t\t\tEnter Username: ");
		fscanf(stdin, "%s", U1.username);
		printf("\n\t\t\tEnter Password: ");
		fscanf(stdin,"%s",U1.password);
		fprintf(logptr, "%s %s %s\n", U1.name, U1.username, U1.password);
		printf("\n\t\t\tNew account made!\n");
		printf("\n\t\t\tYour Name is: %s\n\t\t\tUsername: %s\n\n",  U1.name, U1.username);
			fflush(stdin);
	}
	FILE *fri;
	char *frie=strcat(U1.username,".txt");
	fri=fopen(frie,"w");

	fclose(fri);
	fclose(logptr);

	printf("Login again to continue. \n");
		printf("Press Q to return main menu");
		scanf("%c",&ch);
		if (ch=='q' || ch=='Q')
			 {
			 	system("cls");
			 	main();
	       	 }
}
