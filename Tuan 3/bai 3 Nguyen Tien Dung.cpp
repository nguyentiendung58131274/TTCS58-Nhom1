#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct NhanVien{
	char HoTen[20];
	char MaNV[4];
	int SoNgayCong;
	int Luong;
};

typedef NhanVien NV;

vector<NhanVien> dsNV;

void NhapNV(NhanVien &NV){
	cout << "Nhap ho ten NV: " <<endl;
	fflush(stdin);	gets(NV.HoTen);
	cout << "Nhap ma nhan vien: " << endl;
	fflush(stdin);	gets(NV.MaNV);
	cout << "Nhap so ngay cong: " << endl;
	cin >> NV.SoNgayCong;
	NV.Luong = NV.SoNgayCong * 300000;
	cout << "Luong nhan vien: " << NV.Luong << endl;
}

void NhapDS(int n){
	NV temp;
	for(int i=0;i<n;i++){
		cout << "Nhan vien thu " << i+1 << ": " << endl;
		NhapNV(temp);
		dsNV.push_back(temp);
	}
}

void InDS(){
	int n=dsNV.size();
	for(int i=0;i<n;i++)
	{
		cout << dsNV[i].HoTen << "\t";
		cout << dsNV[i].MaNV << "\t";
		cout << dsNV[i].SoNgayCong << "\t";
		cout << dsNV[i].Luong << endl;
	}
}

int TimKiem(char *MaNV){
	int n=dsNV.size();
	for(int i=0;i<n;i++)
	{
		return i;
	}
	return -1;
}

void SapXep(){
	int n=dsNV.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dsNV[i].SoNgayCong > dsNV[j].SoNgayCong)
			{
				NV tam;
				tam = dsNV[i];
				dsNV[i] = dsNV[j];
				dsNV[j] = tam;
			}
		}
	}
	InDS();
}

void TimKiem(){
	int n=dsNV.size();
	char ID[4];
	int tam=-1;
	cout << "Nhap ID de kiem tra: ";
	fflush(stdin);	gets(ID);
	for(int i=0;i<n;i++)
	{
		if(strcmp(dsNV[i].MaNV,ID) == 0)
		{
			tam = i;
			break;
		}
	}
	if(tam == -1)
		cout << "Khong tim thay nhan vien" << endl;
	else{
			cout << dsNV[tam].HoTen << "\t";
			cout << dsNV[tam].MaNV << "\t";
			cout << dsNV[tam].SoNgayCong << "\t";
			cout << dsNV[tam].Luong << endl;
	} 
}

void ThemNV(){
	int n=dsNV.size();
	char ID[4];
	NV tam;
	cout << "Nhap ma nhan vien can them: ";
	fflush(stdin);	gets(ID);
	for(int i=0;i<n;i++)
	{
		while(strcmp(dsNV[i].MaNV,ID)==1){
			cout << "Ma nhan vien da co hay nhap lai: ";
			fflush(stdin);	gets(ID);
		}
	}
	NhapNV(tam);
	dsNV.push_back(tam);
	cout << "Danh sach sau khi them: " << endl;
	SapXep();
}

void xoaNV(){
	char IDdele[4];
	int n=dsNV.size();
	int vt=-1;
	cout << "Nhap ID nhan vien can xoa: ";
	fflush(stdin);	gets(IDdele);
	for(int i=0;i<n;i++){
		if(strcmp(dsNV[i].MaNV,IDdele)==0){
			vt=i;
			break;
		}
	}
	if(vt!=-1){
		dsNV.erase(dsNV.begin()+vt);
		cout << "Danh sach sau khi xoa: " << endl;
		InDS();
	}
	else cout << "Khong tim thay nhan vien de xoa!!" << endl;
}

void CapNhatNV(){
	NhanVien nvMoi;
	int n=dsNV.size();
	cout << "Nhap ma nhan vien can cap nhat: ";
	fflush(stdin);	gets(nvMoi.MaNV);
	int vtCapNhat=-1;
	for(int i=0;i<n;i++)
	if(strcmp(nvMoi.MaNV,dsNV[i].MaNV)==0){
		//vtCapNhat=i;
		cout << "Nhap ho ten NV: " <<endl;
		fflush(stdin);	gets(dsNV[i].HoTen);
		cout << "Nhap ma nhan vien: " << endl;
		fflush(stdin);	gets(dsNV[i].MaNV);
		cout << "Nhap so ngay cong: " << endl;
		cin >> dsNV[i].SoNgayCong;
		dsNV[i].Luong = dsNV[i].SoNgayCong * 300000;
		cout << "Luong nhan vien: " << dsNV[i].Luong << endl;
		break;
	}
//	if(vtCapNhat!=-1){	
//		strcpy(dsNV[vtCapNhat].MaNV,nvMoi.MaNV);
//		strcpy(dsNV[vtCapNhat].HoTen,nvMoi.HoTen);
//		dsNV[vtCapNhat].SoNgayCong=nvMoi.SoNgayCong;
//		dsNV[vtCapNhat].Luong=nvMoi.Luong;
//	}
}

int main(){
	cout << "=====Code by Nguyen Tien Dung=====" << endl;
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	while(n>10){
		cout << "Nhap lai so luong: ";
		cin >> n;
	}
	NhapDS(n);
	cout << "danh sach vua nhap: " << endl;
	InDS();
	cout << "sap xep: " << endl;
	SapXep();
	cout << "Thong tin nhan vien: " << endl;
	TimKiem();
	cout << "Them nhan vien: " << endl;
	ThemNV();
	cout << "Xoa nhan vien: " << endl;
	xoaNV();
	cout << "Cap nhat nhan vien: " << endl;
	CapNhatNV();
	return 0;
}
