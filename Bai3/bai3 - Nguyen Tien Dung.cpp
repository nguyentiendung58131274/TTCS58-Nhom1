#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#define MAX 100
using namespace std;
int n,id,chon;
int maxi=0, mini=0;
struct NhanVien
{
	int MaNV;
	string Holot;
	string Ten;
	int Tienluong;
};

//Lay DS nhan vien trong file, n(<=>so luong nhan vien) lay tu trong file input3.txt
//Bo phan nhap DS nhan vien

NhanVien NV[MAX];
//void Nhap(NhanVien &NV)
//{
//	cout << "Nhap ma nhan vien: "; cin >> NV.MaNV;
//	cout << "Nhap ho lot nhan vien: ";
//	cin.ignore();
//	getline(cin, NV.Holot);
//	cout << "Nhap ten nhan vien: "; getline(cin, NV.Ten);
//	cout << "Nhap tien luong nhan vien: "; cin >> NV.Tienluong;
//}
//
//void NhapDSNhanVien(int &n, NhanVien NV[])
//{
//	ifstream f;
//	f.open("input3.txt",ios::out);
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap thong tin nhan vien thu " << i + 1 << "." << endl;
//		Nhap(NV[i]);
//		f << NV[i].MaNV << endl;
//		f << NV[i].Holot endl ;
//		f << NV[i].Ten << endl;
//		f << NV[i].Tienluong <<endl;
//	}
//}
void Docfile(ifstream &f, NhanVien &NV)
{
	f >> NV.MaNV;
	string temp;
	getline(f,temp);
	getline(f,NV.Holot);
	getline(f,NV.Ten);
	f>>NV.Tienluong;
}

void DocDS(ifstream &f, int &n, NhanVien NV[])
{
	for(int i = 0; i < n; i++)
	{
		Docfile(f,NV[i]);
	}
}

void HienNhanVien(NhanVien &NV)
{
	cout << "\t" << NV.MaNV << "\t\t";
	cout << NV.Holot << " " << NV.Ten << "\t\t";
	cout << NV.Tienluong << endl;
}

void HienDS(int n,NhanVien NV[])
{
	cout << endl;
	cout << "\t" << "Ma nhan vien" << "\t" << "Ho ten nhan vien" << "\t" << "Tien luong" << endl;
	for(int i = 0; i < n; i++)
	{
		HienNhanVien(NV[i]);
	}
	cout << endl;
}

void Tim(NhanVien NV[])
{
	cout << "Nhap ma NV can xem thong tin: ";
	cin >> id;
	int tam=0;
	cout << "Ma NV" << "\t\t" << "Ho" << "\t\t" << "Ten" << "\t\t" << "Tien luong" << endl;
	for(int i=0;i<n;i++)
	{
		if(NV[i].MaNV==id)
		{
			cout << NV[i].MaNV << "\t\t";
			cout << NV[i].Holot << "\t";
			cout << NV[i].Ten << "\t\t";
			cout << NV[i].Tienluong << endl;
			tam=0;
			break;
		}
		else tam = tam + 1;
	}
	if(tam != 0)
	{
		cout << "Khong tim thay nhan vien!" << endl;
	}
}

void maxluong()
{
	maxi = NV[0].Tienluong;
	for(int i=0;i<n;i++)
	{
		if(maxi < NV[i].Tienluong)
		{
			maxi = NV[i].Tienluong;
		}
	}
	for(int i=0;i<n;i++)
		if(NV[i].Tienluong==maxi)
			cout << "Ho ten nv co luong cao nhat la: " << NV[i].Holot << "\t" << NV[i].Ten << endl;
}

void minluong()
{
	mini = NV[0].Tienluong;
	for(int i=0;i<n;i++)
	{
		if(mini > NV[i].Tienluong)
		{
			mini = NV[i].Tienluong;
		}
	}
	for(int i=0;i<n;i++)
		if(NV[i].Tienluong==mini)
			cout << "Ho ten nv co luong thap nhat la: " << NV[i].Holot << "\t" << NV[i].Ten << endl;
}

void Sapxep(NhanVien NV[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(NV[i].Ten.compare(NV[j].Ten) ==0)
			{
				if(NV[i].Holot.compare(NV[j].Holot)==1){
					NhanVien tam = NV[i];
					NV[i] = NV[j];
					NV[j] = tam;
				}
			}
			else if(NV[i].Ten.compare(NV[j].Ten)==1){
					NhanVien tam = NV[i];
					NV[i] = NV[j];
					NV[j] = tam;
			}
		}
	}
	HienDS(n,NV);
}

void Ghifile()
{
	ofstream of;
	of.open("output3.txt", ios::out);
	of<<"Thong tin nhan vien tim bang id: " << endl;
	of << "Ma NV" << "\t\t" << "Ho" << "\t\t" << "Ten" << "\t\t" << "Tien luong" << endl;
	for(int i=0;i<n;i++)
	{
		if(NV[i].MaNV==id)
		{
			of << NV[i].MaNV << "\t\t";
			of << NV[i].Holot << "\t\t";
			of << NV[i].Ten << "\t\t";
			of << NV[i].Tienluong << endl;
		}
	}
	of<<"Nhan vien luong cao nhat:  " << endl;
	for(int i=0;i<n;i++)
	{
		if(NV[i].Tienluong==maxi)
			of << NV[i].Holot << "\t" << NV[i].Ten << endl;
	}
	of<<"Nhan vien luong thap nhat: " << endl;	
	for(int i=0;i<n;i++)
	{
		if(NV[i].Tienluong==mini)
			of << NV[i].Holot << "\t" << NV[i].Ten << endl;		
	}
	of<<"Danh sach sau khi duoc sap sep theo ten: " << endl;
	of<< "\t"<<"maNV"<<"\t"<<"Holot"<<"\t"<<"Ten"<<"\t"<<"Luong"<<endl;
	for(int i=0;i<n;i++)
	{
		of<<"\t"<<NV[i].MaNV;
		of<<"\t"<<NV[i].Holot;
		of<<"\t"<<NV[i].Ten;
		of<<"\t"<<NV[i].Tienluong;
		of<<endl;
	}
}

int main()
{
	ifstream f("input3.txt");
	f >> n;
	while(true){
        system("cls");
        cout << "=====Code by Nguyen Tien Dung=====" << endl;
        printf("***********************************************\n");
        printf("**                  Menu                     **\n");
        printf("**      1. Hien thi TT nhan vien doc tu file **\n");
        printf("**      2. Tim TT nhan vien bang maNV        **\n");
        printf("**      3. Luong nhan vien cao nhat          **\n");
        printf("**      4. Luong nhan vien thap nhat         **\n");
        printf("**      5. Sap xep nhan vien                 **\n");
        printf("**      6. Ghi ket qua nhan vien vao file    **\n");
        printf("**      0. Thoat                             **\n");
        printf("***********************************************\n");
        printf("**           Nhap lua chon cua ban           **\n");
        scanf("%d",&chon);
        switch(chon){
//            case 1:
//                cout << "Ban da chon nhap DS nhan vien!" << endl;
//                NhapDSNhanVien(n,NV);
//                printf("\nBan da nhap thanh cong!");
//                printf("\nBam phim bat ky de tiep tuc!");
//                break;
            case 1:
            	cout << "Ban da chon hien thi thong tin nhan vien!" << endl;
                    DocDS(f,n,NV);
                    HienDS(n,NV);
                cout << endl;
                system("pause");
                break;
            case 2:
            	cout << "Ban da chon tim thong tin nhan vien qua maNV!" << endl;
                    Tim(NV);
                cout << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                system("pause");
                break;
            case 3:
            	cout << "Ban da chon luong nhan vien cao nhat!" << endl;
                    maxluong();
                cout << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                system("pause");
                break;
            case 4:
                cout << "Ban da chon luong nhan vien thap nhat!" << endl;
                    minluong();
                cout << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                system("pause");
                break;
            case 5:
            	cout << "Ban da chon sap xep nhan vien!" << endl;
            		Sapxep(NV,n);
            	cout << endl;
            	cout << "Bam phim bat ky de tiep tuc!" << endl;
            	system("pause");
            	break;
            case 6:
				cout << "Ban da chon ghi nhan vien vao file!" << endl;	
                    Ghifile();
                cout << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                system("pause");
                break;
            case 0:
                cout << "Ban da chon thoat chuong trinh!" << endl;
                return 0;
            default:
                cout << "Khong co chuc nang nay!" << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                break;
    	    }
    	}
	system("pause");
}

