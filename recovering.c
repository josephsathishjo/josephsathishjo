#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

char*name[9]={"card.raw"};

int i,buffer[],recovered;

int a=-1;

char recoved[sizeof"050.jpg"];

unint8_tbuffer[512];

int main(int argc,char*argv[])

{
	//char for valid quantity of command line arguments
	
	if(argc!=2||(strcmp(argv[1],*name)!=0))
	
	{
		printf("usage: ./recover image\n");
		
		return 1;
	}
	
	FILE*card=fopen(argv[1],"r");
	
	//check if file card.raw exists
	
	if (card==NULL)
	
	{
		printf("Could not open file\n");
		
		return 1;
	}
	
	while(fread(& buffer,512,1,card))
	{
		if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&((buffer[3]&0xf0)==0xe0))
		{
			a++;
			sprintf(recovered,"%03d.jpg",a);
			
			FILE*output=fopen(recovered,"w");
			
			if(output==NULL)
			
			{
				printf("Could Not Create File %03d/n",a);
				
				return 1;
			}
			
			fwrite(buffer,512,1,output);
			
			while(fread(&buffer,512,1,card))
			
			{
				if(!(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&((buffer[3]&0xf0)==0xe0)))
			
				{
					fwrite(buffer,512,1,output);
			
				}
				
				else
				
				{
					break;
				}
			}
			
			fclose(output);
		}
	}
	
	fclose(card);
	
	return 0;
}
