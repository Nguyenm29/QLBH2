#include"ClassPhuKien.h"
#include"ClassMenu.h"
#include"ClassDienThoai.h"
#include"ClassLapTop.h"
int main()
{
	/*
	ofstream fileout;
	ClassPhuKien* a = new ClassPhuKien();
	a->NhapPhuKien();
	a->GhiPhuKienVaoFile(fileout);
	*/
	ClassMenu* a = new ClassMenu();
	a->DieuKhien();
}