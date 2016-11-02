#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct User 
	{
		char name[20];
		char username[20];
		char password[20];
	};
void Message(const char* file)
{
	FILE *inptr;
	char msg[30];
	int n;
	inptr=fopen(file, "a");
	if(inptr==NULL)
		printf("File not opened");
	else
	{
		printf("Enter EOF to quit.\n");
		fflush(stdin);
		printf("Type message: ");
		gets(msg);
		while(!feof(stdin))
		{
			fprintf(inptr, "%s", msg);
			printf("Type message: ");
			fflush(stdin);
			gets(msg);
		}
		fclose(inptr);
	}
}
void Read(const char* filename)
{
    int c;
	FILE *file;
	file = fopen(filename, "r");
	if (file!=NULL) 
		{
    		while ((c = getc(file)) != EOF)
        		putchar(c);
    			fclose(file);
		}
}
void Write(const char* file)
{
	int i;
	char A[20];
	FILE *inptr;
	if((inptr=fopen(file, "w"))==NULL)
		printf("%File not open");
	else
		{
			printf("Enter EOF to quit!\n");
			gets(A);
			while(!feof(stdin))
				{
					fprintf(inptr, "%s", A);
					fflush(stdin);
					gets(A);
				}
			fclose(inptr);
		}
}
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
			
