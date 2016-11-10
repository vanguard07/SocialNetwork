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
