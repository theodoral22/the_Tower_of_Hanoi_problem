#include <stdio.h>

/***********************************************************************
recursive function that solves the Tower of Hanoi problem.
N: number of disks to move
source: the rod from which the disks are moved
dest: the destination rod
temp: the auxiliary rod used during the process
***********************************************************************/
void move(int N,int source,int dest,int temp)
{
    if (N==1) //if there is only one disk
    {
        //directly move the single disk from source to destination
        //no need to use the temporary rod in this case
        printf ("Move a disc from %d to %d\n",source,dest);
        return;
    }

    //step 1: move the top N-1 disks from the source rod to the temporary rod
    //the destination rod is used as an auxiliary in this step
    move (N-1,source,temp,dest);
    
    //step 2: move the largest disk (the Nth disk) from the source rod to the destination rod
    //this is the only disk that moves directly from source to destination
    move (1,source,dest,temp);
    
    //step 3: move the N-1 disks from the temporary rod to the destination rod
    //now the source rod is used as the auxiliary
    move (N-1,temp,dest,source);
}

int main()
{
    int N,source=1,dest=2,temp=3;
    
    //read the number of disks from the user, until he enters a positive number
    do {
        printf ("Give me the number of disks.\n");
        scanf ("%d",&N);
        if (N<=0)
            printf ("The number must be positive. Try again.\n");
    } while (N<=0);
    
    move (N,source,dest,temp); //begin the recursive disk-moving process
    
    return 0;
}