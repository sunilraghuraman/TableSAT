//coded by Sunil Raghuraman
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{	int n=0;
	string line;
	ifstream file("gyrodata.txt");
	if(file.is_open())
	{
        while(!file.eof())
		{
            getline(file,line);
            n++;
        }
	}
	file.close();
	double Y[n][1], A[n][2], z[2][1],T[2][n],M[2][2],I[2][2],S[2][n],F[2][1],alpha,beta;
	for(int i=0;i<n;i++)
		A[i][1] = 1;	
	
	ifstream yfile("gyrodata.txt"); // y , t
	double num = 0.0;
	int i = 0,j = 0;
	while(yfile >> num)
	{
		Y[i++][0] = num;
		yfile>>num;
		A[j++][0] = num;
	}
	yfile.close();
	
	
	cout<<"\nEntered Y Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<Y[i][0]<<'\n';
          

	cout<<"\nEntered A Matrix: \n";
    for(int i = 0; i < n; ++i)
	{
        for(int j = 0; j < 2; ++j)
        {
            cout << A[i][j]<<" ";
        }
		cout << '\n';
	}
	for(int i = 0; i < n; ++i)
        for(int j = 0; j < 2; ++j)
			T[j][i]=A[i][j];
	
	for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    M[i][j] = M[i][j] + T[i][k] * A[k][j];
                }
            }
        }
     
	I[0][0]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[0][0];
	I[0][1]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[0][1];
	I[1][0]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[1][0];
	I[1][1]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[1][1];
	
	for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    S[i][j] = S[i][j] + I[i][k] * T[k][j];
                }
            }
        }
		
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    F[i][0] = F[i][0] + S[i][k] * Y[k][0];

		
	alpha=F[0][0];
	beta=F[1][0];
	
	cout<<"\nAlpha = "<<alpha;
	cout<<"\nBeta = "<<beta;
	return 0;
}