void Add(char namefromlogin[20])
{
	char name[30], check[30];
	printf("Search any username. \n");
		scanf("%s",name);
	struct User U;
	int c, che;
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
			printf("%s exist.\n", U.username);
			printf("Add as friend? ");
			//char need[30];
			scanf("%d", &c);
			if(c==1)
			{
			//fscanf(fp,"%s",U.username);
			char *friends=strcat(U.username,"request.txt");
			temp=fopen(friends,"a");
				fprintf(temp, "%s\n",namefromlogin);
			fclose(temp);
			}
       	  	}
       }
		fclose(fp);  	         	
	}		
}
