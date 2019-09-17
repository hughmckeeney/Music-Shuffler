// Written by Hugh Mc Keeney
// Music Shuffler

#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <time.h>
#include <stdlib.h>

//sorting the artists using the quick sort algorithm
void sortArtists(char sortedArtists[][80] , int numOfArtists)
{
    char temp[80];
    int minIndex, i, j;

    for(i=0; i<numOfArtists; i++)
    {
        minIndex = i;
        for(j = i+1; j<numOfArtists; j++)
        {
            if(strcmp(sortedArtists[minIndex],sortedArtists[j]) > 0)
                {
                    minIndex = j;
                }

        }
        strcpy(temp, sortedArtists[minIndex]);
        strcpy(sortedArtists[minIndex], sortedArtists[i]);
        strcpy(sortedArtists[i], temp);
    }
    return;
}

//sorting the songs using the quick sort algorithm
void sortSongs(char songsOfAnArtist[][80], int numOfSongs)
{
    char temp[80];
    int minIndex, i, j;

    for(i=0; i<numOfSongs; i++)
    {
        minIndex = i;
        for(j = i+1; j<numOfSongs; j++)
        {
            if(strcmp(songsOfAnArtist[minIndex],songsOfAnArtist[j]) > 0)
                {
                    minIndex = j;
                }

        }
        strcpy(temp, songsOfAnArtist[minIndex]);
        strcpy(songsOfAnArtist[minIndex], songsOfAnArtist[i]);
        strcpy(songsOfAnArtist[i], temp);
    }
    return;
}

//shuffling the songs using the Fisher Yates algorithm
void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
{
    int i, j, x, y;
    char temp[80];

    for(i = 0; i < numOfSongs; i++)
    {
        j = rand()%(i+1);
        if (j!=i)
        {
           strcpy(temp, songsToBeShuffled[j]);
           strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
           strcpy(songsToBeShuffled[i], temp);
        }


        }

       return;
}







