// Written by Hugh Mc Keeney
// Music Shuffler

#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <time.h>
#include <stdlib.h>


int main(void)
{
    //The array containing artists names
    char artists[4][80];
    //The array containing the sorted artists
    char sortedArtists[4][80];
    //Songs for Artist 1
    char songsArtist1[3][80];
    //Songs for Artist 2
    char songsArtist2[3][80];
    //Songs for Artist 3
    char songsArtist3[3][80];
    //Songs for Artist 4
    char songsArtist4[3][80];
    //The total number of artists (Note it can be less than 4)
    int numOfArtists =0;
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[4];

    int i,y,x,totalNumOfSongs = 0;
    int j=1; // used to tell the user what number of song they are inputing for each artist
    srand(time(NULL)); // declared for use in shuffling function

//***PART 1 - INPUTS***

    printf("If at any time you wish to stop entering songs for an artist or stop entering artists\n");
    printf("just press enter\n");

    printf("Insert an artist/group-name:\n");
    fgets(sortedArtists[0], 80, stdin);
    numOfArtists = 1;


    //I repeat this loop every time for each artist to input their songs
    for(i=0; i<=2; i++)
        {
          printf("Insert song %d for %s\n",j,sortedArtists[0]);
          fgets(songsArtist1[i], 80, stdin);
        // the condition to test if the user has decided not to put in any more songs for this artist
          if (songsArtist1[i][0] == '\n')
          {
              break;
          }
        numSongsPerArtist[0] = i+1; // counting the number of songs for each particular artist
        j++;// used to tell the user what number of song they are entering for the artist
        }

    j = 1; //resetting the counter to tell the user what number of song they are inputting

    printf("Insert an artist/group-name:\n");
    fgets(sortedArtists[1], 80, stdin);
    //testing if the user wants to stop entering artists
    if (sortedArtists[1][0] == '\n')
          {
              goto label; // the goto statement is used to skip the rest of the code used for input and start sorting
          }
      numOfArtists = 2; // counting the number of artists

   for(i=0; i<=2; i++)
        {
          printf("Insert song %d for %s\n",j,sortedArtists[1]);
          fgets(songsArtist2[i], 80, stdin);

          if (songsArtist2[i][0] == '\n')
          {
              break;
          }
        numSongsPerArtist[1] = i+1;
        j++;
        }

    j = 1;


    printf("Insert an artist/group-name:\n");
    fgets(sortedArtists[2], 80, stdin);

         if (sortedArtists[2][0] == '\n')
          {
              goto label;
          }
      numOfArtists = 3;

    for(i=0; i<=2; i++)
        {
          printf("Insert song %d for %s\n",j,sortedArtists[2]);
          fgets(songsArtist3[i], 80, stdin);

          if (songsArtist3[i][0] == '\n')
          {
              break;
          }
        numSongsPerArtist[2] = i+1;
        j++;
        }

    j = 1;

    printf("Insert an artist/group-name:\n");
    fgets(sortedArtists[3], 80, stdin);

     if (sortedArtists[3][0] == '\n')
          {
              goto label;
          }
      numOfArtists = 4;

      for(i=0; i<=2; i++)
        {
          printf("Insert song %d for %s\n",j,sortedArtists[3]);
          fgets(songsArtist4[i], 80, stdin);

          if (songsArtist4[i][0] == '\n')
          {
              break;
          }
        numSongsPerArtist[3] = i+1;
        j++;
        }

        goto label;
    label:


// ***PART 2 - SORTING ARTISITS***

    // I copied all the artists below so I could match them up later on with their respective array
    // when it came to printing out the songs and artists in alphabetical order
    strcpy(artists[0], sortedArtists[0]);
    strcpy(artists[1], sortedArtists[1]);
    strcpy(artists[2], sortedArtists[2]);
    strcpy(artists[3], sortedArtists[3]);
    // calling the function to sort artists
    sortArtists(sortedArtists, numOfArtists);
    // testing how many artists their were to determine what arrays of songs needed to be shuffled
    // also calling the sort songs function when this has been determined
    if(numOfArtists == 1)
    {
        sortSongs(songsArtist1, numSongsPerArtist[0]);
    }
    if(numOfArtists == 2)
    {
        sortSongs(songsArtist1, numSongsPerArtist[0]);
        sortSongs(songsArtist2, numSongsPerArtist[1]);
    }
    if(numOfArtists == 3)
    {
        sortSongs(songsArtist1, numSongsPerArtist[0]);
        sortSongs(songsArtist2, numSongsPerArtist[1]);
        sortSongs(songsArtist3, numSongsPerArtist[2]);
    }
    if(numOfArtists == 4)
    {
        sortSongs(songsArtist1, numSongsPerArtist[0]);
        sortSongs(songsArtist2, numSongsPerArtist[1]);
        sortSongs(songsArtist3, numSongsPerArtist[2]);
        sortSongs(songsArtist4, numSongsPerArtist[3]);
    }

    // printing out the artists and songs in alphabetical order
    printf("**********************************************************************\n");
    printf("Sorted list of songs:\n");
    for(y = 0; y<numOfArtists; y++)
    {
        printf("Artist: %s\n", sortedArtists[y]);
        for(j = 0; j<numOfArtists; j++)
        {

            if(strcmp(sortedArtists[y], artists[j]) == 0)// these comparisons between the original list of artists and the sorted
                                                        //ones is used to determine what list of songs to print
            {
                if(j == 0)
                {
                    for(x = 0; x<=2; x++)
                    {
                         if(songsArtist1[x][0] != '\n')// checking if a song exists in the position
                            {
                                printf("%s", songsArtist1[x]);
                            }
                            else
                            {
                                break;
                            }
                    }
                }

                if(j == 1)
                {
                    for(x = 0; x<=2; x++)
                    {
                         if(songsArtist2[x][0] != '\n')
                            {
                                printf("%s", songsArtist2[x]);
                            }
                            else
                            {
                                break;
                            }
                    }
                }

                if(j == 2)
                {
                    for(x = 0; x<=2; x++)
                    {
                         if(songsArtist3[x][0] != '\n')
                            {
                                printf("%s", songsArtist3[x]);
                            }
                            else
                            {
                                break;
                            }
                    }
                }

                if(j == 3)
                {
                    for(x = 0; x<=2; x++)
                    {
                         if(songsArtist4[x][0] != '\n')
                            {
                                printf("%s", songsArtist4[x]);
                            }
                            else
                            {
                                break;
                            }
                    }
                }
            }
        }
    }


//***PART 3 - SHUFFLING AND PRINTING***

    //calculates the total number of songs
    for(i = 0; i< numOfArtists; i++)
    {
        totalNumOfSongs += numSongsPerArtist[i];
    }

    char allSongs[totalNumOfSongs][80]; // an array created to store all the songs in one large array
                                        // this was done to facilitate shuffling
    x = 0; // resetting x to 0

    // this section of code concatenates each song with it's artist, preparing for the printing stage in shuffle
  for(i = 0; i<numSongsPerArtist[0]; i++)
  {
      for(j = 1; j<=80; j++)
      {
           if(songsArtist1[i][j] == '\n')
           {
               songsArtist1[i][j] = '-';
               strcat(songsArtist1[i], artists[0]);
               break;
           }
      }
  }

  if(numOfArtists > 1)
  {
    for(i = 0; i<numSongsPerArtist[1]; i++)
      {
          for(j = 1; j<=80; j++)
          {
               if(songsArtist2[i][j] == '\n')
               {
                   songsArtist2[i][j] = '-';
                   strcat(songsArtist2[i], artists[1]);
                   break;
               }
          }
      }
      if(numOfArtists > 2)
      {
         for(i = 0; i<numSongsPerArtist[2]; i++)
          {
              for(j = 1; j<=80; j++)
              {
                   if(songsArtist3[i][j] == '\n')
                   {
                       songsArtist3[i][j] = '-';
                       strcat(songsArtist3[i], artists[2]);
                       break;
                   }
              }
          }
          if(numOfArtists > 3)
          {
              for(i = 0; i<numSongsPerArtist[3]; i++)
              {
                  for(j = 1; j<=80; j++)
                  {
                       if(songsArtist4[i][j] == '\n')
                       {
                           songsArtist4[i][j] = '-';
                           strcat(songsArtist4[i], artists[3]);
                           break;
                       }
                  }
              }
          }
      }

  }


    // the following section of loops and if statements is used to put all the songs into
    // the one array, "allsongs"

    // this loop copies the songs for artist one into "allsongs". This is repeated for each artist
   for(j = 0; j<numSongsPerArtist[0]; j++)
    {
        if(songsArtist1[j][0] != '\n')
        {
            strcpy(allSongs[x], songsArtist1[j]);
            x++;
        }
    }
    if(numOfArtists > 1)//these if statements are used to determine if there is another artist who's
                        //songs need to be entered into the array
    {
        for(j = 0; j<numSongsPerArtist[1]; j++)
        {
            if(songsArtist2[j][0] != '\n')
            {
                strcpy(allSongs[x], songsArtist2[j]);
                x++;
            }
        }
        if(numOfArtists > 2)
           {
             for(j = 0; j<numSongsPerArtist[2]; j++)
            {
                if(songsArtist3[j][0] != '\n')
                {
                    strcpy(allSongs[x], songsArtist3[j]);
                    x++;
                }
            }
            if(numOfArtists > 3)
            {
                for(j = 0; j<numSongsPerArtist[3]; j++)
                {
                    if(songsArtist4[j][0] != '\n')
                    {
                        strcpy(allSongs[x], songsArtist4[j]);
                        x++;
                    }
                }
            }
            }
    }


//***SHUFFLING***


    char shuffled[totalNumOfSongs*2][80]; // this array is to store the shuffled songs

    printf("**********************************************************************\n");
    printf("Shuffled Songs:\n");
    repeat:
    //I call the function twice to print out twice the number of songs that were input
    shuffleSongs(allSongs, totalNumOfSongs);// calling the function to shuffle the songs
    // copying the output of the function into the "shuffled" array
    for(i = 0; i <= totalNumOfSongs-1; i++)
    {
        strcpy(shuffled[i], allSongs[i]);
    }

    shuffleSongs(allSongs, totalNumOfSongs);// calling the function to shuffle the songs
    // copying the output of the function into the "shuffled" array
    for(x = 0, i = totalNumOfSongs; i <= (totalNumOfSongs*2)-1; i++, x++)
    {
        strcpy(shuffled[i], allSongs[x]);
    }

    // if and loop used to test if a song repeats and 5 other songs have not been played yet
     if(totalNumOfSongs*2 > 10)
        {
            for(i = 0; i < totalNumOfSongs*2; i++)
            {
                for(x = i+5; x> i; x--)
                {
                   y = strcmp(shuffled[i], shuffled[x]);
                   if(y == 0)
                {
                         goto repeat; // if it is found a song has been repeated without 5 other songs being played
                                      // the calling of the shuffling functions is repeated
                }
                }
            }

            // loop to print out the shuffled songs
            for(i = 0; i < totalNumOfSongs*2; i++)
            {
                printf("%s", shuffled[i]);
            }
        }

    // if 5 or less songs were input then we can't have the condition where
    // a song cant repeat it self until 5 or more songs are played
    // therefore the songs are shuffled just once and then repeated
    else{
        for(i = 0; i < totalNumOfSongs*2; i++)
        {
            printf("%s", shuffled[i]);
        }
        }
       return 0;
}




