#include<helpers.h>
#include<math.h>

//convert image to grayscale

void grayscale(int height,int width,int i,int j,RGBTRIPLE image[height][width])

{
	float rgbgray;
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			rgbgray=round((image[i][j].rgbtblue+image[i][j].rgbtgreen+image[i][j].rgbtred)/3.00)
			
			image[i][j].rgbtblue=rgbgray;
			
			image[i][j].rgbtgreen=rgbgray;
			
			image[i][j].rgbtred=rgbgray;
		}
	}
	return;
}
bdfjbjfd
int limit(int RGB)

{
	if(RGB>255)
	{
		RGB=255;
	}
	return RGB;
}
//convert image to sepia
void sepia(int height, int i,int j,int width,RGBTRIPLE image[height][width])
{
	int sepiablue;
	int sepiared;
	int sepiagreen;
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			sepiablue=limit(round(0.272*image[i][j].rgbtred+0.534*image[i][j].rgbtgreen+0.131*image[i][j].rgbtblue));
			
			sepigreen=limit(round(0.349*image[i][j].rgbtred+0.686*image[i][j].rgbtgreen+0.168*image[i][j].rgbtblue));
			
			sepired=limit(round(0.393*image[i][j].rgbtred+0.769*image[i][j].rgbtgreen+0.189*image[i][j].rgbtblue));
			
			image[i][j].rgbtblue=sepiablue;
			
			image[i][j].rgbtgreen=sepiagreen;
			
			image[i][j].rgbtred=sepired;
			
		}
	}
	return;
}
//reflect image horizontally

void reflect(int height,int i,int j,int width,rgbtrple image [height][weidth])
{
	int temp[3];
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width/2;j++)
		{
			/**swap pixels from left to right*/
			temp[0]=image[i][j].rgbtblue;
			
			temp[1]=image[i][j].rgbtgreen;
			
			temp[2]=image[i][j].rgbtred;
			
			image[i][j].rgbtblue=image[i][width-j-1].rgbtblue;
			
			image[i][j].rgbtgreen=image[i][width-j-1].rgbtgreen;
			
			image[i][j].rgbtred=image[i][width-j-1].rgbtred;
			
			image[i][width-j-1].rgbtblue=temp[0];
			
			image[i][width-j-1].rgbtgreen=temp[1];
			
			image[i][width-j-1].rgbtred=temp[2];
		}
	}
	return;
}
int getblue(int i,int j,int height,int width,rgbtriple image[height][width],int color_position)
{
	float counter=0;
	int sum=0;
	
	/**start from 1 row before it and end at 1 row after it-total of 3 rows*/
	
	for(k=i-1;k<(i+2);k++)
	{
		/**start from 1 block befrom it and end at 1 block after it-total of 3blocks*/
		
		for(l=j-1;l<(j+2);l++)
		{
			if(k<0||l<0||k>=height||l>=width)
			{
				continue;
			}
			if(color_position==0)
			{
				sum+=image[k][l].rgbtred;
			}
			else if (color_position==1)
			{
				sum+=image[k][l].rgbtgreen;
			}
			else
			{
				sum+=image[k][l].rgbtblue;
			}
			counter++;
		}
	}
	return round(sum/counter);
}
//blur image
void blur(int height, int width,int i,int j,rgbtriple image[height][width])
{
	rgbtriple copy[height][width];
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			copy[i][j]=image[i][j];
		}
	}
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			image[i][j].rgbtred=getblur(i,j,height,width,copy,0);
			
			image[i][j].rgbtgreen=getblur(i,j,height,width,copy,1);
			
			image[i][j].rgbtblue=getblur(i,j,height,width,copy,2);
		}
	}
	return;
}
