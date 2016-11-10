void NewLogin()
{
	struct User U1;
	int n;
	fflush(stdin);
	FILE *logptr;
	if((logptr=fopen("Admin.txt", "a+"))==NULL)
	printf("File not open");
	else
	{
	printf("Enter Name, Username, Password: ");
	fscanf(stdin,"%s%s%s", U1.name, U1.username, U1.password);
	fprintf(logptr, "%s %s %s\n", U1.name, U1.username, U1.password);
	printf("New account made!\n");
	printf("\nYour Name is: %s\n Username: %s\n",  U1.name, U1.username);
	fflush(stdin);
	}
	fclose(logptr);
	printf("Search Friends?\n1.Yes\n2.No\n");
	scanf("%d", &n);
	if(n==1)
	Search(U1.username);
}

