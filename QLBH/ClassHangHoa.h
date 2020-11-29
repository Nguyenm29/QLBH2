
// update 29 thang 11

#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class ClassHangHoa
{
protected:
	string MaHH;
	string TenHH;
	string HangSX;
	double Gia;
	int NamSX;
public: /// Update 22-11-2020 -- github 
	ClassHangHoa(); // Hàm tạo không đối
	ClassHangHoa(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn); // hàm khởi tạo có đối
	~ClassHangHoa(); // Ham huy
	virtual void HienThi(); // Phương thức ảo hiển thị một mặt hàng tương ứng ra màn hình 
	string GetMaHH(); // Hàm lấy mã hàng hóa
	virtual double TinhThue() = 0; // Phương thức thuần ảo tính thuế cho một mặt hàng
	virtual void GhiMHVaoFile(ofstream& fileout) = 0;
	virtual void NhapMatHang(); // Phương thức nhập một mặt hàng
};

 