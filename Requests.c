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
