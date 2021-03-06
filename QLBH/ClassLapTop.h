﻿#pragma once
#include "ClassTBDienTu.h"
class ClassLapTop : public  ClassTBDienTu
{
private:
	float CardDoHoa;
	int SoKheRam;
	float SSD;
public:
	ClassLapTop();
	ClassLapTop(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, float ManHinhIn, float PinIn, float CameraIn, float RamIn, string HDHIn, string ChipIn, float CardDoHoa, int SoKheRamIn, float SSDIn);
	~ClassLapTop();
	void HienThi(); // Hàm hiển thị thông tin class
	void SetInfo(string MaHHIn, string TenHHIn, string HangSXIn, double GiaIn, int NamSXIn, float ManHinhIn, float PinIn, float CameraIn, float RamIn, string HDHIn, string ChipIn, float CardDoHoa,int SoKheRamIn, float SSDIn); // Phương thức set giá trị cho class
	void GhiMHVaoFile(ofstream& fileout);
	void NhapMatHang(); // Phương thức nhập một mặt hàng

};

