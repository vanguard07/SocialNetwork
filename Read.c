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
