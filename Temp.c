#include<stdio.h>
#include<string.h>
struct User
	{
		char name[20];
		char username[20];
		char password[20];
	};

void Read(char filenamefrommsg[40])
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
{
	char msg[20];
	FILE *temp;
	if((temp=fopen(filename, "a"))==NULL)
	printf("File not open?");
	else
		{
		printf("Enter EOF to quit.\n");
		fflush(stdin);
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
		Read(filename);

}

void MakeFile(char namefromsearch[20], char namefromlogin[20])
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

void Search(char namefromlogin[20])
{
	char name[30];
	printf("Search any name. \n");
		scanf("%s",name);
	struct User U;
	int c,check;
    FILE *fp;
	fp = fopen("Admin.txt","r");
	if (fp==NULL)
	   	printf("File not opened.\n");
	else
	{
		while (!feof(fp))
	    {
	      	fscanf(fp,"%s", U.name);
	      	//fread( &U, sizeof(struct User), 1, fp);
	        check=strcmpi(name, U.name);
	        if (check==0)
	        {
			printf("%s exist.\n", U.name);
			printf("Add as friend? ");
			scanf("%d", &c);
			if(c==1)
			{
			fscanf(fp,"%s", U.username);
			MakeFile(U.username, namefromlogin);
			}
       	  	}
       }
		fclose(fp);
	}
}

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

int ReadUser(char *user, char *pass)
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
					check=1;
			}
			if(check==1)
			{
			printf("Welcome!\n");
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

int main()
{
		char username[20], password[20];
		int x, n, a;
		struct User U;
		printf("1.New User\n2.Existing user\nEnter choice: ");
		scanf("%d", &a);
		fflush(stdin);
		system("cls");
		if(a==1)
			NewLogin();
		else
		{
			printf("\n\tEnter Username or EOF to quit: ");
			scanf("%s", username);
			if(strcmp(username, "EOF")!=0)
				{
					printf("\n\tEnter Password: ");
					scanf("%s", password);
				}
				if((ReadUser(username, password))==1)
				{
			printf("1.Add Friends\n2.Send Message\n3.Friendlist\n4.Logout\n");
			printf("Enter choice: ");
			scanf("%d", &n);
			if(n==2)
				{
					system("cls");
					Search(username);
				}
				}
		return 0;
		}
}
