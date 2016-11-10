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

