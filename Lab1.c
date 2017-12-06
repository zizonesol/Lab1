/*
 * main.c
 *
 *		David Park
 *		ICS 53 Lab
 *		Jan 23, 2017
 *		Lab 1
 */

#include <stdio.h>
#include <string.h>

FILE *fr;
const int CHM = 200;

struct room
{
    int roomNo;
    char description[CHM];
    int north;
    int east;
    int west;
    int south;
};

struct coordinate
{
    int north;
    int east;
    int west;
    int south;
};

void printDesc(struct room r)
{
    printf(r.description);
    printf("\n$ ");
}

void processRoom(struct room arr[100])
{
    char *str[1000];
    struct room r;
    int i = 0;

    while (fgets(str, 1000, fr) != NULL)
    {
        sscanf(str, "%d $%[^$]$ %d %d %d %d", &r.roomNo,
               &r.description, &r.north, &r.south, &r.east, &r.west);
        arr[i].roomNo = r.roomNo;
        strcpy(arr[i].description, r.description);
        arr[i].north = r.north;
        arr[i].east = r.east;
        arr[i].west = r.west;
        arr[i].south = r.south;
        i++;
    }
}

int main()
{
    printf("Welcome to the dungeon game."
           "\nPlease load the game file by typing \"loaddungeon\":\n$ ");
    char s[20], dg[CHM];

    scanf("%s", s);
    scanf("%s", dg);

    fr = fopen(dg, "r");

    while (strcmp(s, "loaddungeon") != 0 || fr == NULL)
    {
        printf("Invalid input, please try again. \n$ ");
        scanf("%s", s);
        scanf("%s", dg);

        fr = fopen(dg, "r");
    }

    struct room arr[100];
    struct coordinate c;
    int i = 0;
    processRoom(arr);
    printDesc(arr[0]);

    c.north = arr[0].north;
    c.east = arr[0].east;
    c.west = arr[0].west;
    c.south = arr[0].south;

    while (strcmp(s, "quit") != 0)
    {

        scanf("%s", s);

        if (strcmp(s, "north") == 0)
        {
            if (c.north > 0)
            {
                i = 0;
                while (arr[i].roomNo != c.north)
                    ++i;
                printDesc(arr[i]);

                c.north = arr[i].north;
                c.east = arr[i].east;
                c.west = arr[i].west;
                c.south = arr[i].south;
            }
            else
                printf("this is a dead end.\n$ ");
        }
        else if (strcmp(s, "south") == 0)
        {
            if (c.south > 0)
            {
                i = 0;
                while (arr[i].roomNo != c.south)
                    ++i;
                printDesc(arr[i]);

                c.north = arr[i].north;
                c.east = arr[i].east;
                c.west = arr[i].west;
                c.south = arr[i].south;
            }
            else
                printf("This is a dead end.\n$ ");
        }
        else if (strcmp(s, "west") == 0)
        {
            if (c.west > 0)
            {
                i = 0;
                while (arr[i].roomNo != c.west)
                    ++i;
                printDesc(arr[i]);

                c.north = arr[i].north;
                c.east = arr[i].east;
                c.west = arr[i].west;
                c.south = arr[i].south;
            }
            else
                printf("This is a dead end.\n$ ");
        }
        else if (strcmp(s, "east") == 0)
        {
            if (c.east > 0)
            {
                i = 0;
                while (arr[i].roomNo != c.east)
                    ++i;
                printDesc(arr[i]);

                c.north = arr[i].north;
                c.east = arr[i].east;
                c.west = arr[i].west;
                c.south = arr[i].south;
            }
            else
                printf("This is a dead end.\n$ ");
        }
        else if (strcmp(s, "loaddungeon") == 0)
        {
            scanf("%s", dg);
            fclose(fr);
            fr = fopen(dg, "rt");

            while (fr == NULL)
            {
                printf("Invalid input, please try again. \n$ ");
                scanf("%s", s);
                scanf("%s", dg);

                fr = fopen(dg, "r");
            }

            processRoom(arr);
            printDesc(arr[0]);

            c.north = arr[0].north;
            c.east = arr[0].east;
            c.west = arr[0].west;
            c.south = arr[0].south;
        }
        else if (strcmp(s, "quit") == 0)
        {}
        else
            printf("Invalid input. Please try again.\n$ ");
    }

}
