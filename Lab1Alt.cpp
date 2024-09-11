#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int Q = 35;
    int Omega[15] = {62, -115, 1, 62, -58, 60, 0, 64, 1, -57, 3, 7, -118, -115, 7};
    int ves[300][15];
    int sum[300] = {0};
    int mycifra[15] = {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}; //Моя цифра 4 - по заданию
    int check[15];
    int key;
    int sumCheck = 0;

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


    random_shuffle(randommassiv, randommassiv + 300);

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

    memset(sum, 0, sizeof(sum)); 

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            ves[i][j]=Omega[j]*viborka[i][j];
            sum[i]+=ves[i][j];
        }
    }


    for (int i=0;i<300;i++)
    {
        cout << i+1 << ' ';
        cout << sum[i] << endl;
    }

    cout << "Training sample: " << endl;
    for (int i=0;i<300;i++)
    {
        cout << i+1 << " | ";
        for (int j=0;j<15;j++)
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }

    cout << endl;

    cout << "First Omega:" << endl;

    for (int i=0;i<15;i++)
    {
        cout << Omega[i] << ' ';
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < 300; i++) 
    {
        key=0;
        for (int j=0;j<15;j++)
        {
            if (viborka[i][j] == mycifra[j]) 
            {
                    key++;
            }
        }

        if ((key==15)&&(sum[i]<=Q))
        {
            for (int x=0;x<15;x++)
            {
                Omega[x] += viborka[i][x];
            }
            // cout << "Omega " << i+1 << " :";
            for (int x=0;x<15;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;

        }

        if ((key!=15)&&(sum[i]>Q))
        {
            for (int x=0;x<15;x++)
            {
                Omega[x] -= viborka[i][x];
            }
            for (int x=0;x<15;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
        }

        if ((key!=15)&&(sum[i]<=Q))
        {
            for (int x=0;x<15;x++)
            {
                Omega[x]+=0;
            }
            for (int x=0;x<15;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
        }

        if ((key==15)&&(sum[i]>Q))
        {
            for (int x=0;x<15;x++)
            {
                Omega[x]+=0;
            }
            for (int x=0;x<15;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
        }
    }
    

    cout << "Last Omega: " << endl;
    for (int i=0;i<15;i++)
    {
        cout << Omega[i] << ' ';
    }

    cout << endl;

    memset(check, 0, sizeof(check));

    for (int i=0;i<15;i++)
    {
        check[i]=mycifra[i]*Omega[i];
        sumCheck=sumCheck+check[i];
    }

    cout << endl;

    cout << "Check status: " << endl;
    if (sumCheck>Q)
    {
        cout << "Yes";
    }

    else
    {
        cout << "No";
    }

    memset(sum, 0, sizeof(sum));
    memset(ves, 0, sizeof(ves));

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            ves[i][j]=viborka[i][j]*Omega[j];
            sum[i]=sum[i]+ves[i][j];
        }
    }


    for (int i=0;i<300;i++)
    {
        cout << i+1 << ' ';
        cout << sum[i] << endl;
    }
}