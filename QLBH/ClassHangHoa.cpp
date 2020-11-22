#include "ClassHangHoa.h"


ClassHangHoa::ClassHangHoa() // Ham tao khong doi
{
	this->MaHH = " ";
	this->TenHH = " ";
	this->HangSX = " ";
	this->Gia = 0;
	this->NamSX = 0;
}

ClassHangHoa::ClassHangHoa(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn) // Ham tao co doi
{
	this->MaHH = MaHHIn;
	this->TenHH = TenHHIn;
	this->HangSX = HangSXIn;
	this->Gia = GiaIn;
	this->NamSX = NamSXIn;
}
ClassHangHoa::~ClassHangHoa()// Ham huy
{
}


void ClassHangHoa::HienThi()
{
	cout << "\n Ma hang hoa: " << this->MaHH;
	cout << "\n Ten hang hoa: " << this->TenHH;
	cout << "\n Hang san xua: " << this->HangSX;
	cout << "\n Gia: " << this->Gia;
	cout << "\n Nam San xuat: " << this->NamSX;
}


string ClassHangHoa::GetMaHH()
{
	return this->MaHH;
}

void ClassHangHoa::NhapMatHang()
{
	cin.ignore();
	cout << "\n Nhap thong tin mat hang: ";
	cout << "\n Nhap ma hang hoa: "; getline(cin, this->MaHH);
	cout << "\n Nhap ten hang hoa: "; getline(cin, this->TenHH);
	cout << "\n Nhap ten hang san xuat: "; getline(cin, this->HangSX);
	cout << "\n Nhap gia: "; cin >> this->Gia;
	cout << "\n Nhap nam san xuat: "; cin >> this->NamSX;
}
