#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main();
struct User
	{
		char name[20];
		char username[20];
		char password[20];
	};

void Read(char filenamefrommsg[40])
  //Reads from a file
{
    int c;
	FILE *file;
	file = fopen(filenamefrommsg, "r");
	if (file!=NULL)
		{
    		while ((c = getc(file)) != EOF)
        		putchar(c);
    			fclose(file);
		}
}
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
void MakeFile(char namefromsearch[20], char namefromlogin[20])
   //Creates a text file consisting messages of two users
{
		char filename[20];
		if(strcmp(namefromlogin, namefromsearch)<0)
		{
			strcpy(filename, namefromsearch);
			strcat(filename, namefromlogin);
			char *N=strcat(filename, ".txt");
		}
		else
		{
			strcpy(filename, namefromlogin);
			strcat(filename, namefromsearch);
			char *N=strcat(filename, ".txt");
		}
		ExchangeMessage(filename, namefromlogin);
}
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
void Search(char namefromlogin[20])
  //Search other existing users
{
	char name[30], X[30], temp[30];
		strcpy(temp, namefromlogin);
	char *filename=strcat(temp, ".txt");
	printf("\t\t***************************************************************************************\n");
	printf("\t\t\tSearch any username. \n");
		scanf("%s",name);
	struct User U;
	int c,check;
    FILE *fp;
	fp = fopen(filename,"r");
	if (fp==NULL)
	   	printf("File not opened.\n");
	else
	{
	    check=0;
		while (!feof(fp))
	    {
	      	fscanf(fp,"%s", X);
	        if (strcmpi(name, X)==0)
	        {
				printf("\t\t\t%s exist.\n", X);
				printf("\t\t\tSend Message?\n\t\t\t1.Yes\n\t\t\t2.No\n\t\t\tEnter choice: ");
				scanf("%d", &c);
			if(c==1)
				MakeFile(X, namefromlogin);
				break;
            }
            //else
            //printf("Not found! ");
       }
		fclose(fp);
        Exist(namefromlogin);
	}
}
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
int ReadUser(char *user, char *pass)
    //Checks the validity of user and gets user to the network
{
	struct User U1;
	int check=0;
	FILE *readptr;
	if((readptr=fopen("Admin.txt", "r"))==NULL)
			printf("File not open");
	else
	{
		while(!feof(readptr))
			{
				fscanf(readptr,"%s %s %s",U1.name, U1.username, U1.password);
				if(strcmp(U1.username, user)==0 && strcmp(U1.password, pass)==0)
                {
					check=1;
					break;
                }
			}
			if(check==1)
			{
				printf("\n\t\t\tWelcome %s!\n", U1.name);
				return 1;
			}
			else
			{
				printf("Try again!\n");
				return 0;
			}
	}
	fclose(readptr);
}
void Requests(char namefromfunction[20])
 //Checks for friends requests
{
		int fdecision;
		FILE *acceptor;
		FILE *sender;
		FILE *request;
		request=fopen("tempr.txt", "w");
		if (request==NULL)
	   	printf("File not opened.\n");
		fclose(request);
		char temp[20], X[20], C[20];
		int count=0;
		strcpy(X, namefromfunction);
		char *check=strcat(X,"request.txt");
		request=fopen(check,"r+");
			count=0;
			while(!feof(request))
			{
				fscanf(request,"%s",C);
				count++;
			}
			count=count/2;
			//printf("%d",count);
			rewind(request);
				//printf("%d",count);
			while(!feof(request))
			{
				if(count==0)
				{
					printf("No friend requests!\n\n");
					break;
					return;
				}
				fscanf(request,"%s",temp);
				printf("%s sent you a friend request?\nDo you want to be his friend?\n1.Yes\n2.No\n",temp);
				scanf("%d",&fdecision);
				if(fdecision==1)
				{
					char N[20];
					FILE *sender;
					char S[20];
					FILE *add;

					strcpy(N,namefromfunction);
					char *accept=strcat(N,".txt");
					add=fopen(accept,"a+");
					fprintf(add,"%s\n", temp);
					fclose(add);

					strcpy(S, temp);
					char *sent=strcat(S,".txt");
					sender=fopen(sent, "a+");
					fprintf(sender, "%s\n",namefromfunction);
					fclose(sender);
				}
			count--;
			if(count==0)
			break;
			}
		fclose(request);
		remove(check);
		rename("tempr.txt", check);
		Exist(namefromfunction);
}

int List(char username[])
{
    char N[20];
    char c[30];
    int count=0;
    strcpy(N, username);
    char *temp=strcat(N, ".txt");
    //Read(temp);
    FILE *file;
	file = fopen(temp, "r");
	while(!feof(file))
    {
        fscanf(file,"%s",c);
        count++;
    }
    rewind(file);
    count--;
	fflush(stdin);
	if (file!=NULL)
		{
    		while (!feof(file)&&count--)
            {
                fgets(c, 30, file);
                puts(c);
                fflush(stdin);
            }
    			fclose(file);
		}
		getchar();
		Exist(username);
    return 0;
}

void Exist(char username[20])
{
        system("COLOR 0A");
        int n;
        printf("\t\t\t1.Add Friends\n\t\t\t2.Send Message\n\t\t\t3.Check Requests\n\t\t\t4.Friends\n\t\t\t5.Logout\n\t\t\t");
        printf("Enter choice: ");
        scanf("%d", &n);
        switch(n)
            {
            case 1 :	system("cls");
                        Add(username);
                        break;
            case 2 :	system("cls");
                        Search(username);
                        break;
            case 3 :	system("cls");
                        Requests(username);
                        break;
            case 4 :    List(username);
                        break;
            case 5 :  	system("cls");
                        main();
                        break;
            }
}

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
