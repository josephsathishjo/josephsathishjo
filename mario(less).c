#include<stdio.h>

int main(void)

{
	int height,i,k,j;
	
	do
	{
		height=("height:");
	}
	while(height<1||height>8);
	
	//starting the row
	
	for(i=0;i<height;i++)
	
	{
		//printing dots (modification:empty spaces)
		for(k=(height-i);k>1;k--)
		{
			printf("");
		}
		
		//printing hashtags (columns)
		for(j=0;j<i+1;j++)
		{
			printf("#");
		}
		/*command to start a new row
		after the complete iteration of the inside for loops
		*/
		printf("\n");
	}
}
