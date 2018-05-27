/*
Artificial Neural Node
Last Revision 10/2/2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void perceptron(int,char*[]);
int countCharacters(int,char*[]);

int main(int args, char* argv[])
{

    perceptron(args,argv); // run main method (the perceptron)
    return 0;

} // end main

void perceptron(int args, char* argv[])
{
    int ** ra; // array of array of pointers
    FILE *ifp; // file pointer

    char cc; // char var for reading input from file

    int args5Flag = 0; // initialize args5Flag to false to determine whether or not to use default information or not
    int breakFlag = 0; // initialize break condition flag to 0
    int ctr = 0; // numbers in file counter
    int e = 0;
    int errorIn = 0; // threshold in
    int errorLastTime = 0;
    int errorThisTime = 0;
    int i = 0; // counter
    int itrCtr = 0; // iteration ctr
    int iterationError = 0;
    int j = 0; // counter
    int k = 0; // counter
    int lRin = 0; // learn rate input integer arg
    int n = 0;
    int maxIin = 0; // maximum iteration input
    int rows = 0; // will later be found by dividing the number of integers by 17
    int thHin = 0; // threshold rate input integer arg
    int totalEr = 0;
    int z = 0;

    double accuracy = 0;
    double d = 0;
    double itrErr = 0;
    double lR = 0; // learn rate
    double sum = 0;
    double thH = 0; // threshold

    double c [16];
    double w [16];

    if (args == 5)
    {
        args5Flag = 1; // 5 arguments is true
        ifp = fopen(argv[1],"r"); // read in file name... argv[0] is a string which refers to the input file
        lRin = atoi(argv[2]);
        thHin = atoi(argv[3]); // read in third argument for threshold
        maxIin = atoi(argv[4]); // read in fourth argument for maximum iterations

        lR = lRin/ 1000.0; // calculate learning rate by dividing by 1000
        thH = thHin/100.0; // calculate threshold by dividing by 100
        if (maxIin <= 500)
        {
            maxIin *= 1000; // calculate maximum iterations by multiplying by 1000
        }
        else
        {
            maxIin = 25000;
        }
    } // end if
    else
    {
        printf("Too few command line arguments detected! Using default values...");
        ifp = fopen("in.csv", "r");
        lR = .1;
        thH = .05;
        maxIin = 50000;
    } // end if-else chain

    for (i = 0; i < 17; i++) // array initializer loop
    {
        c[i] = 0;
        w[i] = 0;
    } // end initializer

    if (args5Flag)
    {
        ifp = fopen(argv[1], "r"); // open the file to begin from the beginning again
    }
    else
    {
        ifp = fopen("in.csv", "r"); // default file path if no argument was supplied from the command line
    }

    ctr = countCharacters(args,argv); // find out how many characters are in the file

    printf("\nTotal numbers detected: %d\n",ctr); // print it out for our viewing enjoyment

    rows = ctr/17; // used to determine how many arrays (rows) of characters are necessary

    ra = malloc(rows * sizeof(int*)); // create an array of the proper size

    for (i = 0; i < rows; i++)
        ra[i] = malloc(17 * sizeof(int*)); // make the single array of int pointers point to new arrays of characters

    for(i = 0; i < rows; i++)
    {
        do
        {
            cc = fgetc(ifp);  // read the next character from the file
            if (isdigit(cc))
            {
                ra[i][j] = (cc == 48 ? 0 : 1); // two dimensional array storing the state of cc as it is read it converts it to a 1 or 0 int value
                j++; // counter which increments if a digit is found (most of the time)
            }
        }
        while(j < 17);  // end do while
        j = 0;
    } // end for
    fclose(ifp);
    printf("\n");

    for(i = 0; i < rows; i++) //prints contents of "malloced" array for verification purposes.. decomment to see
    {
         for (j = 0; j < 17; j++)
        {
            printf("%d",ra[i][j]);
        }
        printf("\n");
    } //prints out all values read in 17 at a time (ignores comma)


    for (i = 0; i < maxIin; i++) // controls maximum iterations
    {
        for (j = 0; j < rows; j++)
        {
            z = ra[j][16]; // strip value to 'z' variable for programmer/debugging sanity

            for (k = 0; k < 16; k++) c[k] = ra[j][k]*w[k]; // get c "per sensor" values

            for (k = 0; k < 16; k++) sum += c[k]; // sum 0-15 (16) up

            n = (sum > thH ? 1 : 0); // ternary statement checking if sum is larger, if yes then 1 else 0
            e = z - n; // get e
            d = lR * e; // get d

            for (k = 0; k < 16; k++) w[k] += ra[j][k] * d; // calculate new weights

            if(e!=0) itrErr += (1.0/rows); // get iteration error in 1.0/(n rows) cast to double, increments if there's an error increment by .25 if there are 4, .333 if there are 3 etc.

            sum = 0; // reinitialize the sum to zero for next iteration
        } // end for

        accuracy = itrErr;
        if (itrErr*rows < .05) break;
        itrErr = 0;

    } // end outer for

    totalEr = rows - (int)floor(accuracy*rows);

    printf("\nError rate at finish: %.2f or %d out of %d",accuracy*rows, totalEr, rows); // prints out the error
    printf("\n\nFINAL WEIGHTS:\n");

    for (k = 0; k < 16; k++)
    {
        if (k % 4==0) printf("\n");
        printf("%15.10f ", w[k]);
    }

    printf("\n");
    free(ra); // deallocate array space
    return;
} // end perceptron method

int countCharacters(int args, char* argv[])
{
    int ctr = 0;
    FILE* ifp; // file pointer
    char cc;
    if (args==5)
    {
        ifp = fopen(argv[1],"r"); // read in file name... argv[0] is a string which refers to the input file
        if (ifp == NULL) perror ("Error opening file");

        else
        {
            do
            {
                cc = fgetc(ifp);  //read the next character from the file
                if (isdigit(cc))
                {
                    ctr++;
                } // end if
            }
            while(cc != EOF);   // end do while
        }
        fclose(ifp); // close the file
    } // end if
    else // if there are no command line arguments
    {
        ifp = fopen("in.csv", "r"); // default file path
        do
        {
            cc = fgetc(ifp);  //read the next character from the file
            if (isdigit(cc))
            {
                ctr++;
            } // end if
        }
        while(cc != EOF);   // end do while
        fclose(ifp); // close the file
    } // end else
    return ctr;
} // end countCharacters
