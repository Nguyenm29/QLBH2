#pragma once
#include"ClassDongHo.h"
#include"ClassHangHoa.h"
#include<vector>
#include"ClassPhuKien.h"
#include"ClassDienThoai.h"
#include"ClassLapTop.h"
#include<string.h>
#include<stdio.h>
class ClassMenu
{
private:
	vector <ClassHangHoa*> DSHH;
	ofstream fileout; // ghifile
	ifstream filein; // docfile
	ClassHangHoa *HH; // Dung de them hang hoa
public:
	ClassMenu();
	void DieuKhien(); // dieu khien chuong trinh
	~ClassMenu();
	void ThemMenu(ClassHangHoa *HH);
	void DocFileDongHo();
	void DocFilePhuKien();
	void DocFileDienThoai();
	void DocFileLapTop();
	void XuatFieRaMH();
	void TimKiem(string MaHHIn); // Tim kiem theo ma hang hoa
	void TinhThue(string MaHHIn);
	void Xoa(string MaHHIn);
	void DemSoHH();
};

