int List(char username[])//For displaying friendlist
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
