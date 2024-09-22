#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int ves[500][10];
    int check[15];
    int key;
    int maxeras=1;
    int kolich=0;
    int sum0=0;
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int sum5=0;
    int sum6=0;
    int sum7=0;
    int sum8=0;
    int sum9=0;

    int cifri[10][10]=
    {
        {1,1,0,1,0,1,0,1,1,0}, //0
        {0,0,1,1,0,0,0,1,0,1}, //1
        {0,1,0,1,0,0,1,0,1,2}, //2
        {0,1,1,0,1,0,1,0,0,3}, //3
        {1,0,0,1,1,0,0,1,0,4}, //4
        {1,1,0,0,1,0,0,1,1,5}, //5 
        {0,0,1,0,1,1,0,1,1,6}, //6
        {0,1,1,0,0,1,0,0,0,7}, //7
        {1,1,0,1,1,1,0,1,1,8}, //8
        {1,1,0,1,1,0,1,0,0,9}  //9
    };

    int Omegi0[10]={1,2,3,4,5,6,7,8,9,0};
    int Omegi1[10]={2,3,4,5,6,7,8,9,1,1};
    int Omegi2[10]={3,4,5,6,7,8,9,1,2,2};
    int Omegi3[10]={4,5,6,7,8,9,1,2,3,3};
    int Omegi4[10]={5,6,7,8,9,1,2,3,4,4};
    int Omegi5[10]={6,7,8,9,1,2,3,4,5,5};
    int Omegi6[10]={7,8,9,1,2,3,4,5,6,6};
    int Omegi7[10]={8,9,1,2,3,4,5,6,7,7};
    int Omegi8[10]={9,1,2,3,4,5,6,7,8,8};
    int Omegi9[10]={1,2,3,4,5,6,7,8,9,9};



    int randommassiv[500]=
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9
    };
    int viborka[500][10];

    random_shuffle(randommassiv, randommassiv + 500);

    for (int i=0;i<500;i++)
    {
        for (int j=0;j<10;j++)
        {
            viborka[i][j]=cifri[randommassiv[i]][j];
        }
    }
    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311";
    cout << endl;

    cout << "Training sample: " << endl;
    for (int i = 0; i < 500; i++)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < 10; j++)
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }
    while (kolich<maxeras)
    {
        kolich++;
        for (int i=0;i<500;i++)
        {
            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi0[j]*viborka[i][j];
                sum0+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi1[j]*viborka[i][j];
                sum1+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi2[j]*viborka[i][j];
                sum2+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi3[j]*viborka[i][j];
                sum3+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi4[j]*viborka[i][j];
                sum4+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi5[j]*viborka[i][j];
                sum5+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi6[j]*viborka[i][j];
                sum6+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi7[j]*viborka[i][j];
                sum7+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi8[j]*viborka[i][j];
                sum8+=ves[i][j];
            }
            
            memset(ves, 0, sizeof(ves));

            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omegi9[j]*viborka[i][j];
                sum9+=ves[i][j];
            }
            int max=0;
            int MassivVes[10]={sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9};

            for (int x=0;x<10;x++)
            {
                if (MassivVes[x]>max)
                {
                    max=MassivVes[x];
                }        
            }
            int k=0;
            for (int x=0;x<10;x++)
            {
                if (MassivVes[x]==max)
                {
                    k++;
                }        
            }

            sum0=sum1=sum2=sum3=sum4=sum5=sum6=sum7=sum8=sum9=0;
            int kolvo=0;
            for (int j=0;j<10;j++)
            {
                if ((MassivVes[j]==max)&&(j!=viborka[i][9]))
                {
                    if (Omegi0[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi0[x]-=viborka[i][x];
                        }
                        kolvo++;

                    }

                    if (Omegi1[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi1[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi2[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi2[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi3[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi3[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi4[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi4[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi5[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi5[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi6[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi6[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (j==Omegi7[9])
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi7[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi8[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi8[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (Omegi9[9]==j)
                    {
                        for (int x=0;x<9;x++)
                        {
                            Omegi9[x]-=viborka[i][x];
                        }
                        kolvo++;
                    }

                    if (kolvo==k)
                    {
                        if (Omegi0[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi0[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi1[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi1[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi2[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi2[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi3[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi3[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi4[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi4[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi5[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi5[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi6[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi6[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi7[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi7[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi8[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi8[x]+=viborka[i][x];
                            }
                        }

                        if (Omegi9[9]==viborka[i][9])
                        {
                            for (int x=0;x<9;x++)
                            {
                                Omegi9[x]+=viborka[i][x];
                            }
                        }
                    }
                }
            }
        
            
        }
        for (int i=0;i<10;i++)
            {
                cout << Omegi0[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi1[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi2[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi3[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi4[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi5[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi6[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi7[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi8[i] << ' ';
            }
            cout << endl;

            for (int i=0;i<10;i++)
            {
                cout << Omegi9[i] << ' ';
            }

            cout << endl;
            cout << endl;
        }

    
        
    return 0;
}