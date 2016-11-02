void NewLogin(struct User U1)
{
			//struct User U1;
			fflush(stdin);
			FILE *logptr;
			if((logptr=fopen("Admin.txt", "a+"))==NULL)
			printf("File not open");
			else
			{
			printf("Enter Name, Username, Password: ");
			fscanf(stdin,"%s%s%s", U1.name, U1.username, U1.password);
			fwrite(&U1, sizeof( struct User ), 1, logptr);
			printf("New account made!\n");
			printf("\nYour Name is: %s\n Username: %s\n",  U1.name, U1.username);
			}
			fclose(logptr);
			
}

