﻿#include "ClassMenu.h"

ClassMenu::ClassMenu()
{
	
}

ClassMenu::~ClassMenu()
{}

void ClassMenu::ThemMenu(ClassHangHoa *HH)
{
	HH->NhapMatHang();
	HH->GhiMHVaoFile(fileout);
}

void ClassMenu::DocFilePhuKien() // doc gile dong do cho len vector sau do hien thi ra
{
	string MaHHIn;
	string TenHHIn;
	string HangSXIn;
	string ChatLieuIn;
	string MauSacIn;
	double GiaIn;
	int NamSXIn;
	string temp;
	filein.open("PHUKIEN.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\n FILE KHONG TON TAI !!!";
	}
	while (!filein.eof())
	{
		getline(filein, MaHHIn, ',');
		getline(filein, TenHHIn, ',');
		getline(filein, HangSXIn, ',');
		getline(filein, ChatLieuIn, ',');
		getline(filein, MauSacIn, ',');
		filein >> NamSXIn;
		filein >> GiaIn;
		getline(filein, temp);
		ClassPhuKien* PhuKien = new ClassPhuKien;
		PhuKien->SetInfo(MaHHIn, TenHHIn, HangSXIn, GiaIn, NamSXIn, MauSacIn, ChatLieuIn);
		DSHH.push_back(PhuKien); 
		/*cout << MaHHIn << "\t" << TenHHIn << "\t" << HangSXIn << "\t" << ChatLieuIn << "\t" << MauSacIn << "\t" << NamSXIn <<"\t" << GiaIn << "\t" << ChatLieuIn << endl;*/
	}
	filein.close();
}


void ClassMenu::DocFileDongHo()
{
	string MaHHIn;
	string TenHHIn;
	string HangSXIn;
	double GiaIn;
	int NamSXIn;
	string ChatLieuDayDeoIn;
	string MatDongHoIn;
	float ChieuDaiDayIn;
	filein.open("DONGHO.TXT", ios_base::in);
	string temp;
	if (filein.fail() == true)
	{
		cout << "\n FILE KHONG TON TAI !!!";
	}
	while (!filein.eof())
	{
		getline(filein, MaHHIn, ',');
		getline(filein, TenHHIn, ',');
		getline(filein, HangSXIn, ',');
		getline(filein, ChatLieuDayDeoIn, ',');
		getline(filein, MatDongHoIn, ',');
		filein >> NamSXIn;
		filein >> GiaIn;
		filein >> ChieuDaiDayIn;
		getline(filein, temp);
		ClassDongHo* DongHo = new ClassDongHo();
		DongHo->SetInfo(MaHHIn, TenHHIn, HangSXIn, GiaIn, NamSXIn, ChatLieuDayDeoIn, MatDongHoIn, ChieuDaiDayIn);
		DSHH.push_back(DongHo);
		/*cout << MaHHIn << "\t" << TenHHIn << "\t" << HangSXIn << "\t" << ChatLieu << "\t" << MatDH << "\t" << NamSX <<"\t" << Gia << "\t" << CD << endl;*/
	}
		filein.close();
}

void ClassMenu::DieuKhien()
{
	while (true)
	{
		int LC;
		system("cls");
		cout << "\n\t\t=======QUAN LY MAT HANG===========";
		cout << "\n\t\t 1. Quan ly dong ho.";
		cout << "\n\t\t 2. Quan ly phu kien. ";
		cout << "\n\t\t 3. Quan ly thiet bi dien tu. ";
		cout << "\n\t\t 4. Tim kiem. ";
		cout << "\n\t\t 5. Tinh thue. ";
		cout << "\n\t\t 6. Xoa mot mat hang. ";
		cout << "\n\t\t 7. Sua thong tin mot mat hang. ";
		cout << "\n\t\t 8. Dem so mat hang. ";
		cout << "\n\t\t 9. An 0 de thoat. ";
		cout << "\n\t\t Nhap lua chon. ";
		cin >> LC;
		if (LC == 1)
		{
			while (true)
			{
				int LCDH;
				system("cls");
				cout << "\n\t\t ======QUAN LY DONG HO=========";
				cout << "\n\t\t 1. Them moi mot mat hang. ";
				cout << "\n\t\t 2. Hien thi danh sach mat hang. ";
				cout << "\n\t\t 3. Dem so mat hang dong ho. ";
				cout << "\n\t\t 4. An 0 de thoat. ";
				/*cout << "\n\t\t 4. TEST. "; */
				cout << "\n\t\t Nhap lua chon: "; cin >> LCDH;
				if (LCDH == 1)
				{
					ClassHangHoa* DongHo = new ClassDongHo();
					this->ThemMenu(DongHo);
				}
				else if (LCDH == 2)
				{
					this->DocFileDongHo();
					this->XuatFieRaMH();
					DSHH.clear();
				}
				else if (LCDH == 0) break;
				else if (LCDH == 3)
				{
					this->DocFileDongHo();
					this->DemSoHH();
					DSHH.clear();
				}
				else if (LCDH == 4)
				{
					DSHH.clear();
					this->DocFilePhuKien();
					DSHH.erase(DSHH.begin() + 1);
					fileout.open("PHUKIEN.TXT", ios_base::trunc);
					fileout.close();
				}
				else cout << "\n Lua chon khong hop le: ";
			}
		}
		else if (LC == 2)
		{
			while (true)
			{
				int LCPK;
				system("cls");
				cout << "\n\t\t=======QUAN LY PHU KIEN===========";
				cout << "\n\t\t 1. Them moi mot phu kien.";
				cout << "\n\t\t 2. Hien thi danh sach phu kien. ";
				cout << "\n\t\t 3. Dem so mat phu kien. ";
				cout << "\n\t\t 4. An 0 de thoat. ";
				cout << "\n\t\t Nhap lua chon. ";
				cin >> LCPK;
				if (LCPK == 1)
				{
					ClassHangHoa* PhuKien = new ClassPhuKien();
					this->ThemMenu(PhuKien);
				}
				else if (LCPK == 2)
				{
					this->DocFilePhuKien();
					this->XuatFieRaMH();
					DSHH.clear();
				}
				else if (LCPK == 3)
				{
					this->DocFilePhuKien();
					this->DemSoHH();
					DSHH.clear();
				}
				else if (LCPK == 0) break;
				else
				{
					cout << "\n Lua chon khong hop le: ";
				}
			}
		}
		else if (LC == 3)
		{
			while (true)
			{
				int LCTBDT;
				system("cls");
				cout << "\n\t\t=======QUAN LY THIET BI DIEN TU===========";
				cout << "\n\t\t 1. Quan ly dien thoai: ";
				cout << "\n\t\t 2. Quan ly lap top: ";
				cout << "\n\t\t 3. An 0 de thoat: ";
				cout << "\n Nhap lua chon: "; cin >> LCTBDT;
				if (LCTBDT == 1)
				{
					while (true)
					{
						int LCDT;
						system("cls");
						cout << "\n\t\t=======QUAN LY DIEN THOAI===========";
						cout << "\n\t\t 1. Them moi: ";
						cout << "\n\t\t 2. Hien thi danh sach dien thoai: ";
						cout << "\n\t\t 3. Dem so mat hang: ";
						cout << "\n\t\t 4. Chon 0 de thoat: ";
						cout << "\n Nhap lua chon: ";  cin >> LCDT;// dang lam do
						if (LCDT == 1)
						{
							ClassHangHoa* DienThoai = new ClassDienThoai();
							this->ThemMenu(DienThoai);
						}
						else if (LCDT == 2)
						{
							this->DocFileDienThoai();
							this->XuatFieRaMH();
							DSHH.clear();
						}
						else if (LCDT == 3)
						{
							this->DocFileDienThoai();
							this->DemSoHH();
							DSHH.clear();
						}
						else if (LCDT == 0) break;
						else cout << "\n lua chon khong hop le: ";
					}

				}
				else if (LCTBDT == 2)
				{
					while (true)
					{
						int LCMT;
						system("cls");
						cout << "\n\t\t=======QUAN LY LAPTOP===========";
						cout << "\n\t\t 1. Them moi: ";
						cout << "\n\t\t 2. Hien thi danh sach may tinh: ";
						cout << "\n\t\t 3. Dem so LapTop";
						cout << "\n\t\t 4. Chon 0 de thoat: ";
						cout << "\n Nhap lua chon: ";  cin >> LCMT;// dang lam do
						if (LCMT == 1)
						{
							ClassHangHoa* LapTop = new ClassLapTop();
							this->ThemMenu(LapTop);
						}
						else if (LCMT == 2)
						{
							this->DocFileLapTop();
							this->XuatFieRaMH();
							DSHH.clear();
						}
						else if (LCMT == 3)
						{
							this->DocFileDienThoai();
							this->DemSoHH();
							DSHH.clear();
						}
						else if (LCMT == 0) break;
						else cout << "\n lua chon khong hop le: ";
					}
				}
				else if (LCTBDT == 0) break;
			}
		}
		else if (LC == 4)
		{
		string MaHHIn;
		cin.ignore();
		cout << "\n Nhap Ma hang hoa muon tim kiem: ";  getline(cin, MaHHIn);
		TimKiem(MaHHIn);

		}
		else if (LC == 5)
		{
		string MaHHIn;
		cin.ignore();
		cout << "\n Nhap Ma hang hoa muon tinh thue: ";  getline(cin, MaHHIn);
		TinhThue(MaHHIn);
		}
		else if (LC == 6)
		{
		string MaHHIn;
		cin.ignore();
		cout << "\n Nhap ma hang hoa muon xoa: ";
		getline(cin, MaHHIn);
		this->Xoa(MaHHIn);
			// Truyền file vào vector sau đó xóa một đối tượng trong vector rồi lại ghi vào file.
		}
		else if (LC == 7)
		{

		}
		else if (LC == 8)
		{
		this->DemSoHH();
		}
		else if (LC == 0) break;
		else
		{
			cout << "\n Lua chon khong hop le moi nhap lai: ";
		}
	}
}

void ClassMenu::DocFileDienThoai()
{
	filein.open("DIENTHOAI.TXT", ios_base::in);
	string MaHHIn;
	string TenHHIn;
	string HangSXIn;
	double GiaIn;
	int NamSXIn;
	float ManHinhIn;
	float PinIn;
	float CameraIn;
	float RamIn;
	string HDHIn; // He dieu hanh
	string ChipIn; // Chip 
	int SoSimIn;
	float BoNhoTrongIn;
	string temp;
	if (filein.fail() == true)
	{
		cout << "\n FILE KHONG TON TAI !!!";
	}
	while (!filein.eof())
	{
		getline(filein, MaHHIn, ',');
		getline(filein, TenHHIn, ',');
		getline(filein, HangSXIn, ',');
		getline(filein, HDHIn, ',');
		getline(filein, ChipIn, ',');
		filein >> NamSXIn >> GiaIn >> ManHinhIn >> CameraIn >> PinIn >> RamIn >> SoSimIn >> BoNhoTrongIn;
		getline(filein, temp);
		ClassDienThoai* DienThoai = new ClassDienThoai;
		DienThoai->SetInfo(MaHHIn, TenHHIn, HangSXIn, GiaIn, NamSXIn, ManHinhIn, PinIn, CameraIn, RamIn, HDHIn, ChipIn, SoSimIn, BoNhoTrongIn);
		DSHH.push_back(DienThoai);
		/*cout << MaHHIn << " " << TenHHIn << " " << HangSXIn << " " << HDHIn << " " << ChipIn << " " << NamSXIn << "\t" << GiaIn << "\t" << ManHinhIn << "\t" << CameraIn << "\t" << PinIn << "\t" << SoSimIn << "\t" << BoNhoTrongIn << endl;*/
	}
	filein.close();
}


void ClassMenu::DocFileLapTop()
{
	filein.open("LAPTOP.TXT", ios_base::in);
	string MaHHIn;
	string TenHHIn;
	string HangSXIn;
	double GiaIn;
	int NamSXIn;
	float ManHinhIn;
	float PinIn;
	float CameraIn;
	float RamIn;
	string HDHIn; // He dieu hanh
	string ChipIn; // Chip 
	int SoKheRamIn;
	float SSDIn;
	float CardDoHoaIn;
	string temp;
	if (filein.fail() == true)
	{
		cout << "\n FILE KHONG TON TAI !!!";
	}
	while (!filein.eof())
	{
		getline(filein, MaHHIn, ',');
		getline(filein, TenHHIn, ',');
		getline(filein, HangSXIn, ',');
		getline(filein, HDHIn, ',');
		getline(filein, ChipIn, ',');
		filein >> NamSXIn >> GiaIn >> ManHinhIn >> CameraIn >> PinIn >> RamIn >> CardDoHoaIn >> SoKheRamIn >> SSDIn;
		getline(filein, temp);
		ClassLapTop* LapTop = new ClassLapTop;
		LapTop->SetInfo(MaHHIn, TenHHIn, HangSXIn, GiaIn, NamSXIn, ManHinhIn, PinIn, CameraIn, RamIn, HDHIn, ChipIn, CardDoHoaIn, SoKheRamIn, SSDIn);
		DSHH.push_back(LapTop);
		/*cout << MaHHIn << " " << TenHHIn << " " << HangSXIn << " " << HDHIn << " " << ChipIn << " " << NamSXIn << "\t" << GiaIn << "\t" << ManHinhIn << "\t" << CameraIn << "\t" << PinIn << "\t" << SoSimIn << "\t" << BoNhoTrongIn << endl;*/
	}
	filein.close();
}

void ClassMenu::XuatFieRaMH()
{
	for (rsize_t i = 0; i < DSHH.size() -1; i++)
	{
		cout << "\n \t\t\t\t HANG HOA THU: " << i+1 << endl;
		DSHH[i]->HienThi();
	}
	system("pause");
}
void ClassMenu::TimKiem(string MaHHIn)
{
	this->DocFileDienThoai(); 
	this->DocFileDongHo();
	this->DocFileLapTop();
	this->DocFilePhuKien();
	// Đọc các file vào vector sau đó tìm kiếm trong vector
	cout << "\n KET QUA: ";
	for (size_t i = 0; i < DSHH.size() - 1; ++i)
	{
		if (DSHH[i]->GetMaHH() == MaHHIn)
			DSHH[i]->HienThi();
	}
	system("pause");
	DSHH.clear();
}

void ClassMenu::TinhThue(string MaHHIn)
{
	this->DocFileDienThoai();
	this->DocFileDongHo();
	this->DocFileLapTop();
	this->DocFilePhuKien();
	// Đọc các file vào vector sau đó tìm kiếm trong vector
	for (size_t i = 0; i<DSHH.size()-1; ++i)
	{
		if (DSHH[i]->GetMaHH() == MaHHIn)
		{
			cout << "\n Thue cua mat hang la: " << DSHH[i]->TinhThue() <<endl;
		}
	}
	system("pause");
	DSHH.clear();
}

void ClassMenu::Xoa(string MaHHIn)
{
	size_t ViTriXoa = -1;
	this->DocFileDienThoai();
	this->DocFileDongHo();
	this->DocFileLapTop();
	this->DocFilePhuKien();
	for (size_t i = 0; i < DSHH.size() - 1 ; ++i)
	{
		if (DSHH[i]->GetMaHH() == MaHHIn)
			ViTriXoa = i;
	}
	if (ViTriXoa == -1) // Khong tim thay hang hoa trong danh sach de xoa
	{
		cout << "\n Khong tim thay hang hoa: ";
		system("pause");
	}
	else
	{
		DSHH.erase (DSHH.begin() + ViTriXoa); // Xoa phan tu trong vector
		// ghi vector vao trong file
		fileout.open("DIENTHOAI.TXT", ios_base::trunc);
		for (size_t i = 0; i < DSHH.size() - 1; ++i)
		{
			DSHH[i]->GhiMHVaoFile(fileout);
		}
		fileout.close();
		cout << "\n Xoa thanh cong";
		system("pause");
	}
}

void ClassMenu::DemSoHH()
{
	this->DocFileDienThoai();
	this->DocFileDongHo();
	this->DocFileLapTop();
	this->DocFilePhuKien();
	int Dem = 0;
	for (size_t i = 0; i < DSHH.size() - 1; ++i)
	{
		Dem++;
	}
	cout << "\n So hang hoa la: " << Dem <<"\n";
	system("pause");
}