#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;

int n, p;
int a[100], b[100];
int tam=0;

void docfile(){
	ifstream file;
	file.open("input4.txt",ios::in);
	file >> n >> p;
	for(int i=0;i<n;i++){
		file >> a[i];
	}
	file.close();
}

void xuat(){
	cout << "Du lieu file input4.txt la: " << endl;
	cout << n << "\t" << p << endl;
	for(int i=0;i<n;i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl << endl;
}

int inkq()
{
	int s=0;
	int j;
	for(j=0;j<n;j++)
	{
		if(b[j]==1)	s+=a[j];
	}
	if(s==p)
	{
		cout << endl;
		for(j=0;j<n;j++)
		{
			if(b[j]==1)	cout << setw(10) << 1;
			else	cout << setw(10) << 0;
		}
		cout << endl << endl;
	}
	ofstream of;
	of.open("output4.txt", ios::app);
	if (s==p)
	{
		for (j=0;j<n;j++)
		if(b[j]==1) of << setw(10)<<1;
			else of << setw(10)<<0;
		of << endl;
	}
}

void thu(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n-1)	thu(i+1);
		else
			inkq();
			b[i]=0;
	}
}

int main()
{
	docfile();
	xuat();
	cout << "Ket qua: " << endl;
	thu(0);
	system("pause");
}
