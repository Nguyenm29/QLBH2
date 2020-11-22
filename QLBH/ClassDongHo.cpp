#include "ClassDongHo.h"
ClassDongHo::ClassDongHo():ClassHangHoa()
{
	this->ChatLieuDayDeo = " ";
	this->ChieuDaiDay = 0;
	this->MatDongHo = " ";
}
ClassDongHo::ClassDongHo(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, string ChatLieuDayDeoIn, string MatDongHoIn, float ChieuDaiDayIn):ClassHangHoa(TenHHIn, TenHHIn, HangSXIn, GiaIn, NamSXIn)
{
	this->ChatLieuDayDeo = ChatLieuDayDeoIn;
	this->MatDongHo = MatDongHoIn;
	this->ChieuDaiDay = ChieuDaiDayIn;
}

ClassDongHo::~ClassDongHo()
{}


void ClassDongHo::SetInfo(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, string ChatLieuDayDeoIn, string MatDongHoIn, float ChieuDaiDayIn)
{
	this->MaHH = MaHHIn;
	this->TenHH = TenHHIn;
	this->HangSX = HangSXIn;
	this->Gia = GiaIn;
	this->NamSX = NamSXIn;
	this->ChatLieuDayDeo = ChatLieuDayDeoIn;
	this->MatDongHo = MatDongHoIn;
	this->ChieuDaiDay = ChieuDaiDayIn;
}

void ClassDongHo::HienThi()
{
	ClassHangHoa::HienThi();
	cout << "\n Chat lieu day deo: " << this->ChatLieuDayDeo;
	cout << "\n May dong ho: " << this->MatDongHo;
	cout << "\n Chieu dai day: " << this->ChieuDaiDay << endl;
}

double ClassDongHo::TinhThue()
{
	return Gia * 0.1;
}

void ClassDongHo::NhapMatHang()
{
	ClassHangHoa::NhapMatHang();
	cin.ignore();
	cout << "\n Nhap chat lieu day deo: ";
	getline(cin, this->ChatLieuDayDeo);
	cout << "\n Nhap mat dong ho: ";
	getline(cin, this->MatDongHo);
	cout << "\n Nhap chieu dai day: ";
	cin >> this->ChieuDaiDay;
}
void ClassDongHo::GhiMHVaoFile(ofstream& fileout)
{
	fileout.open("DONGHO.TXT", ios_base::app);
	fileout << MaHH << "," << TenHH << "," << HangSX;
	fileout << "," << ChatLieuDayDeo << "," << MatDongHo << "," << NamSX << " " << Gia << " " << ChieuDaiDay << endl;
	fileout.close();
}