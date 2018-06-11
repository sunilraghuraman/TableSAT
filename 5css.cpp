//coded by Sunil Raghuraman
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
int main()
{	int n=0;
	string line;
	cout<<"Enter the value of w: ";
	double w;
	cin>>w;
	ifstream file("cssdata.txt");
	if(file.is_open())
	{
        while(!file.eof())
		{
            getline(file,line);
            n++;
        }
	}
	file.close();
	
	double W[n][1],X[n][1],Y[n][1], A[n][2],Z[n][1],T[2][n],M[2][2],I[2][2],S[2][n],F[2][1],G[2][1],H[2][1],J[2][1],c1,c10,c2,c20,c3,c30,c4,c40;
	for(int i=0;i<n;i++)
		A[i][1] = 1;	
	
	ifstream yfile("cssdata.txt");
	double num = 0.0;
	int p = 0,q=0,r=0,s=0,t=0;
	while(yfile)		//e1,e2,e3,e4,t
	{	
		yfile >> num;
		W[p++][0] = num;
		yfile >> num;
		X[q++][0] = num;
		yfile >> num;
		Y[r++][0] = num;
		yfile >> num;
		Z[s++][0] = num;
		yfile >> num;
		A[t++][0] = num;
	}
	yfile.close();
	
	
	
	for(int k=0;k<n;k++)
		A[k][0]=pow(sin(w*A[k][0]),2.0);
		
	
	cout<<"\nEntered Y (e1) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<W[i][0]<<'\n';
    
	cout<<"\nEntered Y (e2) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<X[i][0]<<'\n';
	cout<<"\nEntered Y (e3) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<Y[i][0]<<'\n';
		cout<<"\nEntered Y (e4) Matrix: \n";
    for(int i = 0; i < n; ++i)
            cout<<Z[i][0]<<'\n';
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
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < n; k++)
                    M[i][j] = M[i][j] + T[i][k] * A[k][j];
		
	I[0][0]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[0][0];
	I[0][1]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[0][1];
	I[1][0]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[1][0];
	I[1][1]=(1/((M[0][0]*M[1][1])-(M[0][1]*M[1][0])))*M[1][1];

	for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 2; k++)
                    S[i][j] = S[i][j] + I[i][k] * T[k][j];
		
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    F[i][0] = F[i][0] + S[i][k] * W[k][0];

	c1=F[0][0];
	c10=F[1][0];
	cout<<"\nC1 = "<<c1;
	cout<<"\nC10= "<<c10;
	
		
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    G[i][0] = G[i][0] + S[i][k] * X[k][0];
				
	c2=G[0][0];
	c20=G[1][0];
	cout<<"\nC2 = "<<c2;
	cout<<"\nC20 = "<<c20;
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    H[i][0] = H[i][0] + S[i][k] * Y[k][0];

	c3=H[0][0];
	c30=H[1][0];
	cout<<"\nC3 = "<<c3;
	cout<<"\nC30 = "<<c30;
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
                for (int k = 0; k < n; k++)
                    J[i][0] = J[i][0] + S[i][k] * Z[k][0];
					
	c4=J[0][0];
	c40=J[1][0];
	cout<<"\nC4 = "<<c4;
	cout<<"\nC40 = "<<c40;
	return 0;
}