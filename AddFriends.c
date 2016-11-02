void AddFriends(char *name)
{
	struct User U1;
	int count=1, choice;
	char file[30], file1[30];
	FILE *Assignptr;
	FILE *Friends;
	if((Assignptr=fopen("Admin.txt", "r"))==NULL)
			printf("File not open!");
		strcpy(file1, name);
	char *A=strcat(file1, ".txt");
	if((Friends=fopen(A, "w"))==NULL)
			printf("File not open?");
	else
	{
		while(!feof(Assignptr))
			{
				fread(&U1, sizeof(struct User), 1, Assignptr);
				printf("\n%d. %s\n",count, U1.name);
				if(strcmp(U1.name, name)!=0)
				{
				printf("\nDo you want %s as friend? \n1.Yes\n2.No\n", U1.name);
				scanf("%d", &choice);
				if(choice==1) 
				{
					fprintf(Friends, "%s", U1.name);
					strcpy(file, name);
					strcat(file, U1.name);
					char *B=strcat(file, ".txt");
					printf("%s", B);
				}
				count++;
				}
			}
		fclose(Assignptr);
		fclose(Friends);
	}
}

