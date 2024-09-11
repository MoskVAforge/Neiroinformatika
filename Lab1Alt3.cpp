#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int Q = 8;
    int Omega[4] = {1,2,3,4};
    int ves[8][4];
    int sum[8] = {0};
    int mycifra[4] = {1,0,1,0}; //Моя цифра 4 - по заданию
    int check[4];
    int key;
    int sumCheck = 0;

    int cifri[4][4] = 
    {
        {1,0,0,0},
        {1,0,0,1},
        {1,0,1,0},
        {1,0,1,1}
    };

    int randommassiv[8] = 
    {
        0,0,1,1,2,2,3,3

    };
    int viborka[8][4];


    random_shuffle(randommassiv, randommassiv + 8);

    cout << endl;

    for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
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
        }
    }

    memset(sum, 0, sizeof(sum)); // Обнуление массива sum

    for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
        {
            ves[i][j]=Omega[j]*viborka[i][j];
            sum[i]+=ves[i][j];
        }
    }


    for (int i=0;i<8;i++)
    {
        cout << i+1 << ' ';
        cout << sum[i] << endl;
    }

    cout << "Training sample: " << endl;
    for (int i=0;i<8;i++)
    {
        cout << i+1 << " | ";
        for (int j=0;j<4;j++)
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }

    cout << endl;

    cout << "First Omega:" << endl;

    for (int i=0;i<4;i++)
    {
        cout << Omega[i] << ' ';
    }

    cout << endl;
    cout << endl;

    // Обновление весов
    for (int i = 0; i < 8; i++) 
    {
        key=0;
        for (int j=0;j<4;j++)
        {
            if (viborka[i][j] == mycifra[j]) 
            {
                    key++;
            }
        }

        // cout << key << ' ';

        if ((key==4)&&(sum[i]<=Q))
        {
            for (int x=0;x<4;x++)
            {
                Omega[x] += viborka[i][x];
            }
            for (int x=0;x<4;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
            
        }

        if ((key!=4)&&(sum[i]>Q))
        {
            for (int x=0;x<4;x++)
            {
                Omega[x] -= viborka[i][x];
            }
            for (int x=0;x<4;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
            
        }

        if ((key!=4)&&(sum[i]<=Q))
        {
            for (int x=0;x<4;x++)
            {
                Omega[x]+=0;
            }
            for (int x=0;x<4;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
            
        }

        if ((key==4)&&(sum[i]>Q))
        {
            for (int x=0;x<4;x++)
            {
                Omega[x]+=0;
            }
            for (int x=0;x<4;x++)
            {
                cout << Omega[x] << ' ';
            }
            cout << endl;
            
        }
    }
    

    cout << "Last Omega: " << endl;
    for (int i=0;i<4;i++)
    {
        cout << Omega[i] << ' ';
    }

    cout << endl;

    memset(check, 0, sizeof(check));

    for (int i=0;i<4;i++)
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

    for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
        {
            ves[i][j]=viborka[i][j]*Omega[j];
            sum[i]=sum[i]+ves[i][j];
        }
    }


    for (int i=0;i<8;i++)
    {
        cout << i+1 << ' ';
        cout << sum[i] << endl;
    }
}