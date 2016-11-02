int ReadUser(char *user, char *pass)
{
	struct User U1;
	int check=0;
	FILE *readptr;
	if((readptr=fopen("Admin.txt", "r"))==NULL)
			printf("%File not open");
	else
	{
		while(!feof(readptr))
			{
				fread(&U1, sizeof(struct User), 1, readptr);
				if(strcmp(U1.username, user)==0 && strcmp(U1.password, pass)==0)
					check=1;
			}
			if(check==1)
			{
			printf("Welcome!");
			return 1;
			}
			else
			{
			printf("Try again!");	
			return 0;
			}
	}
	fclose(readptr);
}

