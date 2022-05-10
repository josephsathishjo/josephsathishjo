#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void caesarcode(char*,int);

int main(int argc,char*argv[])
{
	//validate key here
	
	char*plaintext=("Enter text to encrypt:");
	
	printf(plaintext);
}
void caesar(char*t,int argc,int k,int i,char*argv[])
{
	//If and for used to validate key prompted by the user
	if (argc!=2)
	{
		printf("usage:./caesar key\n");
		
	}
	for(i=0;argv[1][i]!='\0';i++)
	{
		if(isalpha(argv[1][i])!=0)
		{
			printf("usage:./caesar key\n");
		}
	}
	//Converts key from alpha to integer
	
	int key =atoi(argv[1]);
	
	//Asks user for a text
	
	char *plaintext=("Enter text to encrypt:");
	
	//Runs function that ciphers the text
	
	printf("ciphertext:");
}
void alphabetical(char *t,int k, int i)
{
	printf("ciphertext:");
	//Iterates through each letter of the text
	for(i=0;t[i]!='\0';i++)
	{
		//Check if it's alphabetical
		if (isalpha(t[i])!=0)
		{
			//Check if it's uppercase
			if(isupper(t[i])!=0)
			{
				//Applies formula to ASCII uppercase letters
				printf("%c",((t[i]-'A'+k)%26)+'A');
			}
			//Same, but lowercase
			else
			{
				printf("%c",((t[i]-'a'+k)%26)+'a');
			}
		}
		//Keeps all non-alphabetical characters
		else
		{
			printf("%c",t[i]);
		}
	}
	printf("\n");
}
