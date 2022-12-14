#include <stdio.h>

int main(){

    int letterfreq[9];
    int c, tick;
    c = 0;
    tick = -1;
    int max = 0;

    for (int i = 0; i<9; i++)
    letterfreq[i] = 0;

    printf("\nPlease type a string and indicate its end by typing a space followed by a '|'\ni.e.)'test test |'\nThe length of each word in the string will then be graphed.\n\n");

    while((c = getchar()) != '|')
    {

        if ((c == ' ')||(c == '\n')||(c=='\t'))
        {
            if (tick >9)
            tick = 8;
        
            letterfreq[tick]++;
            tick = -1;
        }
        
        else if ((c < 65)||(c > 122))
        {
        }
        
        else
            tick++;
    }

    for(int i = 0; i<9; i++)        //find maximum value in array
    {
        if (letterfreq[i]>max)
        max = letterfreq[i]; 
    }  

    printf("\nThe following is your graph:\n\n\n");

    for (int i = max; i>0; i--)     //looping from top to bottom row
    {
        if (((max- (max-i))>9)&&((max- (max-i))<99))    //printing y axis value
            printf("%d ", (max - (max-i)));         
        else if ((max- (max-i))>99)
            printf("%d ", (max - (max-i)));
        else
            printf("%d  ", (max - (max-i)));       

        for (int j = 0; j<9; j++)   //looping through array values
        {

            if(letterfreq[j] == (max- (max-i)))    //print top of bar if index is equal to max
            {
                printf("|---|");
            }
            else if(letterfreq[j]>(max-(max -i)))  //print filler bars if index is greater than max - j
            {
                printf("|   |");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }
    printf("\n     ");          //printing out the x axis
    for (int i = 1; i<9; i++)       
    printf("%d    ",i);
    printf("9+");
    printf("\n\nY Axis: Frequency of words with respective length\nX Axis: Length of word\n\n");

return 0;
}
