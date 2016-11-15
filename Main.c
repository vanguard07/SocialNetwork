
struct User 
	{
		char name[20];
		char username[20];
		char password[20];
	};


int main()
{
		char username[20], password[20];
		int x, n, a;
		struct User U;
		system("COLOR 60");
		printf("\t\t******************************Welcome to Postcard********************************************\n");
		printf("\t\t\t1.New User\n\t\t\t2.Existing user\n\t\t\t3.Quit\n\t\t\tEnter choice: ");
		//scanf("%d", &a);
		fflush(stdin);
		scanf("%d", &a);
		do
        {
            system("cls");
            switch(a)
            {

                case 1  :   NewLogin();
                            break;
                case 2  :   printf("\n\tEnter Username or EOF to quit: ");
                            scanf("%s", username);
                            if(strcmp(username, "EOF")!=0)
                                {
                                    printf("\n\tEnter Password: ");
                                        scanf("%s", password);
                                }
                                if((ReadUser(username, password))==1)
                                    Exist(username);
                                break;
                case 3  :   exit(0);
                default :   main();
            }
        }while(a!=3);
        return 0;
}
