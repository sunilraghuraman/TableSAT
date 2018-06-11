//coded by Sunil Raghuraman
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
int main()
{	int n=0;
	string line;
	cout<<"Enter the value of w (Omega): ";
	double w;
	cin>>w;
	ifstream file("magnetometerdata.txt");
	if(file.is_open())
	{
        while(!file.eof())
		{
            getline(file,line);
            n++;
        }
	}
	file.close();
	double Y[n][1], A1[n][2],A2[n][2],Z[n][1],T1[2][n],T2[2][n],M1[2][2],M2[2][2],I1[2][2],I2[2][2],S1[2][n],S2[2][n],F[2][1],R[2][1],bx,bxo,by,byo;
	for(int i=0;i<n;i++)
	{	A1[i][1] = 1;
		A2[i][1] = 1;
	}

 ifstream yfile("magnetometerdata.txt"); //bx , by , t
	double num = 0.0;
	int p=0,q=0,r=0,s=0;
	while(yfile)
	{	yfile >> num;
		Y[p++][0] = num;
		yfile >> num;
		Z[q++][0] = num;
		yfile >> num;
		A1[r++][0] = num;
		A2[s++][0] = num;
	}
	yfile.close();
	
	for(int k=0;k<n;k++)
	{	A1[k][0]=cos(w*A1[k][0]);
		A2[k][0]=sin(w*A2[k][0]);
	}	
	
	cout<<"\nEntered Y (Bx) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<Y[i][0]<<'\n';
    
	cout<<"\nEntered Y (By) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<Z[i][0]<<'\n';

	cout<<"\nEntered A Matrix (cos): \n";
    for(int i = 0; i < n; ++i)
	{
        for(int j = 0; j < 2; ++j)
        {
            cout << A1[i][j]<<" ";
        }
		cout << '\n';
	}
	cout<<"\nEntered A Matrix (sin): \n";
    for(int i = 0; i < n; ++i)
	{
        for(int j = 0; j < 2; ++j)
        {
            cout << A2[i][j]<<" ";
        }
		cout << '\n';
	}
	
	for(int i = 0; i < n; ++i)
        for(int j = 0; j < 2; ++j)
			T1[j][i]=A1[i][j];
		
	for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < n; k++)
                    M1[i][j] = M1[i][j] + T1[i][k] * A1[k][j];

	I1[0][0]=(1/((M1[0][0]*M1[1][1])-(M1[0][1]*M1[1][0])))*M1[0][0];
	I1[0][1]=(1/((M1[0][0]*M1[1][1])-(M1[0][1]*M1[1][0])))*M1[0][1];
	I1[1][0]=(1/((M1[0][0]*M1[1][1])-(M1[0][1]*M1[1][0])))*M1[1][0];
	I1[1][1]=(1/((M1[0][0]*M1[1][1])-(M1[0][1]*M1[1][0])))*M1[1][1];

	for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 2; k++)
                    S1[i][j] = S1[i][j] + I1[i][k] * T1[k][j];

		
	for (int i = 0; i < 2; i++)
                for (int j = 0; j < 1; j++)
					for(int k = 0; k < n; k++)
                    F[i][0] = F[i][0] + S1[i][j] * Y[j][0];


	bx=F[0][0];
	bxo=F[1][0];
	cout<<"\nBx = "<<bx;
	cout<<"\nBxo = "<<bxo;
	
	for(int i = 0; i < n; ++i)
        for(int j = 0; j < 2; ++j)
			T2[j][i]=A2[i][j];
	
	for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < n; k++)
                    M2[i][j] = M2[i][j] + T2[i][k] * A2[k][j];

		
	I2[0][0]=(1/((M2[0][0]*M2[1][1])-(M2[0][1]*M2[1][0])))*M2[0][0];
	I2[0][1]=(1/((M2[0][0]*M2[1][1])-(M2[0][1]*M2[1][0])))*M2[0][1];
	I2[1][0]=(1/((M2[0][0]*M2[1][1])-(M2[0][1]*M2[1][0])))*M2[1][0];
	I2[1][1]=(1/((M2[0][0]*M2[1][1])-(M2[0][1]*M2[1][0])))*M2[1][1];

	for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 2; k++)
                    S2[i][j] = S2[i][j] + I2[i][k] * T2[k][j];
      
	for (int i = 0; i < 2; i++)
			for (int j=0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    R[i][j] = R[i][j] + S2[i][k] * Z[k][j];

	by=R[0][0];
	byo=R[1][0];
	cout<<"\nBy = "<<by;
	cout<<"\nByo = "<<byo;
	return 0;
}