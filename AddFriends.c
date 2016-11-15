void Add(char namefromlogin[20])
  //Adds other users as friends
{
	char name[30], check[30];
	char ch;
	int n;
	do
    {
        printf("\t\t\tSearch any username: ");
            scanf("%s",name);
        struct User U;
        int c, che,n;
        FILE *fp;
        FILE *temp;
        fp = fopen("Admin.txt","r");
        if (fp==NULL)
            printf("File not opened.\n");
        else
        {
            while (!feof(fp))
            {
                fscanf(fp,"%s%s%s", U.name, U.username, U.password);
                che=strcmpi(name, U.username);
                if (che==0)
                {
                    printf("\n\t\t\t%s exist.\n", U.username);
                    printf("\t\t\tAdd as friend?\n\t\t\t1.Yes\n\t\t\t2.No\n\t\t\tEnter choice: ");
                    scanf("%d", &c);
                    if(c==1)
                    {
                        char *friends=strcat(U.username,"request.txt");
                        temp=fopen(friends,"a");
                        fprintf(temp, "%s\n",namefromlogin);
                        fclose(temp);
                        printf("Friend request sent.\n");
                        printf("Search other name?\n1.Yes\n2.No\nEnter choice: ");
                        scanf("%d", &n);
                        if(n==2)
                        Exist(namefromlogin);
                    }
                    else
                    {
                        Exist(namefromlogin);
                        break;
                    }
                }
           }
		fclose(fp);
        }
    }while(n!=2);

}
