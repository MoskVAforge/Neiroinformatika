#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int Q = 30;
    int Omega[15] = {3,5,9,0,1,2,4,0,7,5,0,8,2,7,4};
    int ves[300][15];
    int sum[300];
    int mycifra[15] = {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}; //Моя цифра 4 - по заданию
    int chet = 0;

    int cifri[10][15] = 
    {
        {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}, //0
        {0,0,1,0,1,1,1,0,1,0,0,1,0,0,1}, //1
        {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}, //2
        {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}, //3
        {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}, //4
        {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}, //5 
        {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}, //6
        {1,1,1,0,0,1,0,1,0,0,1,0,0,1,0}, //7
        {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}, //8
        {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}  //9
    };

    int randommassiv[300] = 
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9

    };
    int viborka[300][15];


    random_shuffle(randommassiv, randommassiv + 300 );

    cout << endl;

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            if (randommassiv[i]==0)
            {
                viborka[i][j]=cifri[0][j];
            }

            if (randommassiv[i]==1)
            {
                viborka[i][j]=cifri[1][j];
            }

            if (randommassiv[i]==2)
            {
                viborka[i][j]=cifri[2][j];
            }

            if (randommassiv[i]==3)
            {
                viborka[i][j]=cifri[3][j];
            }

            if (randommassiv[i]==4)
            {
                viborka[i][j]=cifri[4][j];
            }

            if (randommassiv[i]==5)
            {
                viborka[i][j]=cifri[5][j];
            }

            if (randommassiv[i]==6)
            {
                viborka[i][j]=cifri[6][j];
            }

            if (randommassiv[i]==7)
            {
                viborka[i][j]=cifri[7][j];
            }

            if (randommassiv[i]==8)
            {
                viborka[i][j]=cifri[8][j];
            }

            if (randommassiv[i]==9)
            {
                viborka[i][j]=cifri[9][j];
            }
        }
    }

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            ves[i][j]=viborka[i][j]*Omega[j];
            sum[i]=sum[i]+ves[i][j];
        }
    }

    for (int i=0;i<15;i++)
    {
        cout << Omega[i] << ' ';
    }

    cout << endl;

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            bool isEqual=equal(viborka[i],viborka[i]+15,mycifra);
            if (sum[i]<=Q)
            {
                if (isEqual)
                {
                    Omega[j]=Omega[j]+viborka[i][j];
                    // break;
                }
            }
            if (sum[i]>Q)
            {
                if (!isEqual)
                {
                    Omega[j]=Omega[j]-viborka[i][j];
                    // break;
                }
            }
        }
    }


    for (int i=0;i<15;i++)
    {
        cout << Omega[i] << ' ';
    }

    
}