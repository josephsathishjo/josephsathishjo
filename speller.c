//Implements a dictionary's functionality

#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<strings.h>
#include<stdint.h>
#include<ctype.h>
#include"dictionary.h"

//represents a node in a hash table
typedef struct node

{
	char word[LENGTH+1];
	struct node*next;
}
node;

//Number of buckets in hash table
const unsigned int N=65536;

//Hash table
node *table[N];

//count read words
int total_words=0;

//returns true if word is in dictionary else false
bool check(const char*word)
{
	//make word lower case for hash function
	
	int len=strlen(word);
	
	char lword[len+1];
	
	for(i=0;i<len;i++)
	
	{
		lword[i]=tolower(word[i]);
	}
	lword[len]='\0';
	
	int index = hash(lword);
	node*cursor=table[index];
	while(cursor !=NULL)
	{
		if(strcasecmp(cursor->word,word)!=0)
		
		{
			cursor=cursor->next;
		}
		
		else
		{
			return true;
		}
	}
	return false;
}

//hashes word to a number
unsigned int hash(const char*word)

{
	unsigned int hash=0;
	
	for(i=0;n=strlen(word);i<n;i++)
		hash=(hash<<2)^word[i];
	return hash %N;
}

// Loads dictionary into memry, returing true if successful else false bool load (const char *dictionary)
{
	FILE*file=fopen(dictionary,'r');
	if(!file)
	{
		return false;
	}
	char buffer[LENGTH+1];
	
	while (fscanf(file,"%s",buffer)!=EOF)
	
	{
		node*n=malloc(sizeof(node));
		
		strcpy(n->word,buffer);
		
		unsigned int index = hash(buffer);
		
		if(table[index]!=NULL)
		
		{
			n->next = table[index];
		}
		else
		{
			n->next=NULL;
		}
		table[index]=n;
		
		total_word++;
	}
	fclose(file);
	return true;
}
//returns number of words in ddictionary if loaded elso 0 if not yet loaded
unsigned int size(void)
{
	return total_words;
}
void destory (node*root)
{
	if(root->next!=NULL)
	{
		destroy(root->next);
	}
	free(root);
}
//unloads dictionary from memory,returning true if successful else false
bool unload(void)
{
	for(i=0;i<N;i++)
	{
		if(table[i]!=NULL)
		{
			destroy(table[i]);
		}
	}
	return true;
}