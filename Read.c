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

