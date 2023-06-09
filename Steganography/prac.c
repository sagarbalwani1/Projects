#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *img1 = NULL,*img2 = NULL;
    FILE *text;
    int value = 0;
    img1 = fopen("prac.bmp","r");
    img2 = fopen("prac2.bmp","w");
    text = fopen("bm121.txt", "w");
   
    if(img1 == NULL)
    {
        perror("File Not Found");
        return;
    }
    while((value=getw(img1))!=EOF)
    {
        fwrite(&value, sizeof(int), 1, img2);
        //
        fprintf(text, "%d\n", value);
    }
    //
    printf("Operations Done.\n");
    fclose(img1);
    fclose(img2);
    fclose(text);
}         