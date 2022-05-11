#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	int stringkey,stringplaintext,argc,stringargv[1];
	
	//check for valid key
	if(argc==1)
	{
		return 1;
	}
	else if((stringargv[1])==1)
	{
		return 1;
	}
	else
	{
		stringkey=stringargv[1];
	}
	stringplaintext=(stringplaintext );
	
	return encrypt(stringplaintext,stringkey);
}
//key check function
int chack_key(stringkey)

{
	int n=stringkey;
	
	//check length
	if(n<25)
	{
		printf("ERROR:key must contain 26 characters\n");
		
		return 1;
	}
	int i,false;
	// check if character is alpha
	for(i=0;i<n;i++)
	
	{
		if(isalpha(stringkey)==false)
		{
			printf("ERROR:key must only contain characters from the alphabet\n");
			return 1;
		}
		else
		{
			stringkey=toupper(stringkey);
		}
	}
	
	//check for any duplicate character of alpha (only one of each)
	int j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(stringkey==stringkey)
			{
				printf("ERROR:key must not contain duplicate charcters\n");
				return 1;
			}
			else
			{
				continue;
			}
		}
	}
	return 0;
}

//encrypt plaintext

int encrypt(stringplaintext,stringkey)

{
	char ciphertext[stringplaintext];
	int i,keyposition;
	
	for(i=0;i<stringplaintext;i++)
	
	{
		//uppercase encrypt,lowercase encrypt,
		
		if((int)stringplaintext>=65&&(int)stringplaintext<=90)
		{
			//-65 for position
			keyposition= stringplaintext-65;
			ciphertext[i]= tolower(keyposition);
		}
		else if ((int)stringplaintext>=97&&(int)stringplaintext<=122)
		{
			//-97 for position
			keyposition=stringplaintext-97;
			ciphertext[i]=tolower(keyposition);
		}
		else
		{
			ciphertext[i]=stringplaintext;
		}
	}
	printf("ciphertext:%s\n",ciphertext);
	
	return 0;
}
