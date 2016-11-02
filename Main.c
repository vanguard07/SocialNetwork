
struct User 
	{
		char name[20];
		char username[20];
		char password[20];
	};


void main()
{
	char pass[20], user[20], file[30];
	int n, a;
	struct User U;
		char name[20];
		printf("1.New User\n2.Existing user\nEnter choice: ");	
		scanf("%d", &a);
		fflush(stdin);
		system("cls");
		if(a==1)
			{
			NewLogin(U);
			//strcpy(name, NewLogin());
			AddFriends(U.name);
			}
		else
		{
			printf("\n\tEnter Username or EOF to quit: ");
			scanf("%s", user);
			if(strcmp(user, "EOF")!=0)
				{
					printf("\n\tEnter Password: ");
					scanf("%s", pass);
				}
				if((ReadUser(user, pass))==1)
				{
			do
			{
			printf("1.Friend List\n2.Send Message\n3.Logout\n");
			printf("Enter choice: ");
			scanf("%d", &n);
			switch(n)
			{
				case 1	: 	strcpy(file, user);
							char *A = strcat(file, ".txt");
							Read(A);
							printf("\n");
							break;
				case 2	:	system("cls");
							//Message();
							break;
				case 3	:	system("cls");
							printf("Logged out successfully!\n");
							break;
				default	:	printf("Try again!\n");
			}
			}
			while(n!=3);
					}
				}
}

