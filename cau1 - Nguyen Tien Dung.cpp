#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string a = "";

void ghifile()
{
   	a = "";
	do {
		cout << "Nhap xau chuoi: ";
		cin.ignore(10, '\n');
		getline(cin, a);
		if (a.length() > 255) {
			cout << "Nhap lai: ";
		}
	} while (a.length() > 255);
}

void mofile()
{
	ofstream file("input1.txt");
	if (file.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	file << a << endl;
	file.close();
}

void bokhoangtrang()
{
	int n = a.length();
	for(int i=0;i<n-1;i++)
	{
		if(a[i] == ' ' && a[i+1] == ' ')
		{
			for(int j=0;j<n-1;j++)
			{
				a[j] = a[j+1];
			}
			n--;
			i--;
		}
	}
}

void proper()
{
	int n=a.length();
	//Doi kytu a[0] thanh chu hoa neu da la chu hoa thi giu nguyen
	if(a[0]>='A' && a[0]<='Z')
		a[0] = a[0];
	else
		a[0] = a[0] - 32;
	//Doi 1 ky tu sau khoang trang thanh chu hoa
	for(int i=1;i<n;i++)
	{
		if(a[i]>= 97 && a[i]<= 122) //kiem tra ky tu do la chu thuong
			if(a[i-1] == ' ') //kiem tra truoc ky tu co phai la khoang trang khong
				a[i]= a[i] - 32;
	}
	//Chuyen ky tu sau ky tu dau tien cua chu ve chu thuong
	for(int j=1;j<n;j++)
	{
		if(a[j]>='A'&& a[j]<='Z') //kiem tra co phai chu hoa
				if(a[j-1]!=' ' || a[j+1]==' ') //kiem tra truoc ky tu do khong phai khoang trang hoac sau ky tu do la khoang trang
					a[j] = a[j] + 32;
	}
}

int SLkytuhoa()
{
	int dem=0;
	for(int i=0;i<=a.length()-1;i++)
	{
		if(a[i]>='A' && a[i]<='Z') //kiem tra ky tu co phai la chu hoa khong
		{
			dem += 1;
		}
	}
	return dem;
}

void xuatkqoutput()
{
	ofstream file("output1.txt", ios::app);
	file << a << endl;
	file.close();
}

void Hienthi();
void Menu(){
    printf("\n========================MENU==========================\n");
    printf("1/Nhap 1 chuoi toi da 255 ky tu\n");
    printf("2/Bo khoang trang\n");
    printf("3/Chuoi proper\n");
    printf("4/Thong ke ky tu hoa\n");
    printf("5/Xuat kq vao file output\n");
    printf("6/Ket thuc chuong trinh\n");
}
void Chon(){
	int i;
	printf("Chon: "); 
	scanf("%d",&i);
	switch(i){
	case 1:
		ghifile();
		mofile();
		system("cls");
		Hienthi();
		break;
	case 2:
		bokhoangtrang();
		system("cls");
		printf("khoang trang da bo\n");
		Hienthi();
		break;
	case 3:
		proper();
		system("cls");
		printf("Da xu ly chuoi\n");
		Hienthi();
		break;
	case 4:
		system("cls");
		printf("so luong ky tu hoa la: %d\n",SLkytuhoa());
		Hienthi();
		break;
	case 5:
		xuatkqoutput();
		system("cls");
		printf("da ghi ket qua vao file output\n");
		Hienthi();
		break;
	case 6:
		return;
	default:
		system("cls");
		printf("Khong co trong menu\n");
		Hienthi();
		break;
	}
}

void Hienthi(){
	Menu();
	Chon();
}

int main(){
	printf("Code by Nguyen Tien Dung 58131274");
	Hienthi();
	system("pause");
}
