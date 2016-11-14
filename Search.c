void Search(char namefromlogin[20])
{
	char name[30], X[30], temp[30];
		strcpy(temp, namefromlogin);
	char *filename=strcat(temp, ".txt");
	printf("Search any username. \n");
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

	      	//fread( &U, sizeof(struct User), 1, fp);
	        if (strcmpi(name, X)==0)
	        {
				printf("%s exist.\n", X);
				printf("Send Message?\n1.Yes\n2.No\n ");
				scanf("%d", &c);
			if(c==1)
				MakeFile(X, namefromlogin);
				break;
            }
       }
		fclose(fp);
	}
}
