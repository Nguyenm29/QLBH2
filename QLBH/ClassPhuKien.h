#pragma once
#include"ClassHangHoa.h"
class ClassPhuKien : public ClassHangHoa
{
private:
	string MauSac;
	string ChatLieu;
public:
	ClassPhuKien(); //
	ClassPhuKien(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, string MauSacIn, string ChatLieuIn); //Ham tao co doi
	~ClassPhuKien(); // Ham huy
	void HienThi(); // Hàm hiển thị thông tin một phụ kiện ra màn hình
	void SetInfo(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, string MauSacIn, string ChatLieuIn);
	double TinhThue();
	void NhapMatHang();
	void GhiMHVaoFile(ofstream& fileout);
};

