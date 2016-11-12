#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
	int passwordlength=20;
	char password[passwordlength+1];
	char ch;
	
	int charposition=0;
	printf("enter your password maximum pasword length is 20");
	while(1){
		
		ch=getch();
		if(ch==13){
			break;
			}
		
		if(ch==8){
				
				if (charposition>0){
					charposition--;
					
					printf("\b") ;
					
					ch=NULL;
					printf("%c",ch);
					printf("\b");
					continue;
			}
				}
		if(ch==32||ch==9){
					continue;
					}
		
			if(charposition<passwordlength){
							password[charposition]=ch;
							charposition++;
							printf("*");
				
						}
						else{
							printf("yourpassword exceeds maximum length");
							break;
						}
					
				}
		
			
	password[charposition]='\0';
	printf("\n");
	if(strlen(password)==0){
		printf("no password entered");
	}	
	printf("your password is %s",password);
	return 0;
}

