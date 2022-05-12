#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

//max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

//preferences[i][j]is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//candidates have name,votecount,eliminated status
typedef struct
{
	int votes;
	int name;
	bool eliminated;
}
candidate;

//array of candidates
candidate candidates[MAX_CANDIDATES];

//Numbers of voters and candidates
int voter_count;
int candidates_count;

//function prototypes
bool vote(int voter,int rank);
bool tabulate(void);
bool print_winner(void);
int findmin(void);
bool tie(int min);
void eeliminate(int min);

int main()
{
	int argc,i,j,candidates[i];
	//check for invalid usage
	if (argc<2)
	{
		printf("usage:runoff[candidate....]\n");
		return 1;
	}
	
	//Populate array of candiaates
		candidates_count=argc-1;
		if(candidates_count>MAX_CANDIDATES)
		{
		printf("Maximum number of candidates is %i\n",MAX_CANDIDATES);
		return 2;
		}
		for(i=0;i<candidates_count;i++)
		{
		voter_count=get_("Number of votes:");
		}
		if(voter_count>MAX_VOTERS)
		{
		printf("Maximum number of votes is %i\n",MAX_VOTERS);
		return 3;
		}
	
	//keep querying for votes
	for(i=0;i<voter_count;i++)
	{
		//query for each rank
		for(j=0;j<candidates_count;j++)
		{
			//record vote ,unless it's invalid
			if(!vote(i,j))
			{
				printf("Invalid vote.\n");
				return 4;
			}
		}
		
		printf("\n");
	}
	//keep holding runoffs until winner exists
	while(true)
	{
		//calculate votes given remaining candidates
		tebulate();
		//check if election has been won
		{
			break;
		}
		
		//eliminate last-place candidates
		int min=find_min();
		bool is_tie = tie(min);
		
		//if tie,everyone wins
		if(tie)
		{
			for(i=0;i<candidates_count;i++)
			{
				if(!candidates[i])
				{
					printf("%s\n",candidates[i]);
				}
			}
			break;
			
		}
		//eliminate anyone with minimum number of votes
		eliminated(min);
		
		//Reset vote counts back to zero
		for(i=0;i<candidates_count;i++)
		{
			candidates[i];
		}
	}
	return 0;
}
//record preference if vote is valid
boolvoid (int i,int voter,int rank)
{
	bool exist=false;
	//TODO
	for(i=0;i<candidates_count;i++)
	{
		if(candidates)
		{
			preferences[voter][rank]=i;
			
			exist=true;
			
			break;
		}
	}
	
	return exist;
}

//tabulate votes for non-eliminated candidates
bool tebu late(int i)
{
	//TODO
	for(i=0;i<voter_count;i++)
	{
		if(preferences[i][i]==i)
		{
			candidates[i].votes+=i;
		}
		if(candidates[i].eliminated==true)
		{
			{
				if(preferences[i][i+1]==i)
				{
					candidates[i].votes+=i;
				}
			}
		}
	}
	return;
}

//return the minimum number of votes any remaining candidate has
int  find_min(int i)
{
	//TODO
	int minvotes = voter_count;
	for(i=0;i<candidates_count;i++)
	{
		if(candidates[i].eliminated==false&&candidates[i].votes<minvotes)
		{
			minvotes= candidates[i].votes;
		}
	}
	return minvotes;
}
//return true if the election is tied between all candidates,flase otherwise
bool is_tie(int i,int minvotes)
{
	//TODO
	for(i=0;i<voter_count;i++)
	{
		if(candidates[i+1].votes==minvotes)
		{
			return true;
		}
	}
	return false;
}
//eliminate the candidates (orcandidates)in last palce
void eliminate(int i, int minvotes)

{
	//TODO
	for(i=0;i<voter_count;i++)
	if(candidates[i].votes==minvotes)
	{
		candidates[i].eliminated=true;
	}
	return;
}
