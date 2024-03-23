#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef class NhanVien
{
	int maNV;
	string hoTen;
	float luongCB;
	int soSP;
	float luongHT;

public:

	void initNV(int, string, float, int);

	void printf();

	float tinhLuongHT();

	bool timNV(int);

	void capNhatLuongCB(float);

	int  soSanhLuongHT(NhanVien);

	int soSanhSoSP(NhanVien);


}NV;

typedef class CongTy
{
	// Thành phần dữ liệu
	int maCT;

	string tenCT;

	vector<NhanVien> mangNV;


	//Thành phần xử lí
public:

	//1. Tạo dữ liệu nhân viên
	void initNhanVienCongTy();

	//2. Xuất dữ liệu nhân viên
	void printNV();

	//3. Tính lương nhân viên trong công ty
	void tinhLuongCongTy();

	//4. Tìm nhân viên theo mã nhân viên
	NV timNVCongTy(int);

	//5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
	void capNhatLuongCBCongTy(int, float);

	//6. Tìm nhân viên lương cao nhất
	NV timNVLuongCaoNhatCongTy();

	//7. Tìm nhân viên có số sản phẩm thấp nhất
	NV timNVSoSPThapNhatCongTy();

	//8. Tìm 10 nhân viên lương cao nhất
	vector <NV> tim10NVLuongCaoNhat();

}CT;

//1. Tạo dữ liệu nhân viên
void CongTy::initNhanVienCongTy() {

	NhanVien nv1, nv2, nv3;

	nv1.initNV(123, "Nguyen Van A", 5e6, 156);
	nv2.initNV(124, "Do Dinh Khang", 6e6, 67);
	nv3.initNV(125, "Furina de Fontaine", 7e6, 200);

	mangNV.push_back(nv1);
	mangNV.push_back(nv2);
	mangNV.push_back(nv3);
}

//2. Xuất dữ liệu nhân viên
void CongTy::printNV()
{
	cout << "Nhan vien trong mang: " << endl;

	for (int i = 0; i < mangNV.size(); i++)
	{
		mangNV[i].printf();
	}
}

//3. Tính lương nhân viên trong công ty
void CongTy::tinhLuongCongTy()
{
	for (int i = 0; i < mangNV.size(); i++)
	{
		mangNV[i].tinhLuongHT();
	}
}

//4. Tìm nhân viên theo mã nhân viên
NV CongTy::timNVCongTy(int maNV)
{
	for (int i = 0; i < this->mangNV.size(); i++)
	{
		if (mangNV[i].timNV(maNV) == true)
		{
			return mangNV[i];
		}
	}
}

//5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
void CongTy::capNhatLuongCBCongTy(int maNV, float luongCB)
{
	for (int i = 0; i < this->mangNV.size(); i++)
	{
		if (mangNV[i].timNV(maNV) == true)
		{
			mangNV[i].capNhatLuongCB(luongCB);
		}
	}
}

//6. Tìm nhân viên lương cao nhất
NV CongTy::timNVLuongCaoNhatCongTy()
{
	NV MaxLuongHT = mangNV[0];
	for (int i = 1; i < this->mangNV.size(); i++)
	{
		if (mangNV[i].soSanhLuongHT(MaxLuongHT) == 1)
		{
			MaxLuongHT = mangNV[i];
		}
	}
	return MaxLuongHT;
}

//7. Tìm nhân viên có số sản phẩm thấp nhất
NV CongTy::timNVSoSPThapNhatCongTy()
{
	NV MinSoSP = mangNV[0];

	for (int i = 0; i < this->mangNV.size(); i++)
	{
		if (mangNV[i].soSanhSoSP(MinSoSP) == -1)
		{
			MinSoSP = mangNV[i];
		}
	}
	return MinSoSP;
}

//8. Tìm 10 nhân viên lương cao nhất
vector<NV> CongTy::tim10NVLuongCaoNhat()
{
	vector<NV> mang10NV;
	NV temp = this->timNVLuongCaoNhatCongTy();

	int k = 0;

	for (int i = 0; i < this->mangNV.size(); i++)
	{
		if (mangNV[i].soSanhLuongHT(temp) == 0)
		{
			mang10NV.push_back(mangNV[i]);

			k++;
		}
		if (k == 10)
		{
			break;
		}
	}
	return mang10NV;
}

void NV::initNV(int maNV, string hoTen, float luongCB, int soSP)
{
	this->maNV = maNV;
	this->hoTen = hoTen;
	this->luongCB = luongCB;
	this->soSP = soSP;
	this->luongHT = 0;
}

void NV::printf()
{
	cout << endl << "Thong tin nhan vien: " << endl;
	cout << "\t+ Ma nv   : " << this->maNV << endl;
	cout << "\t+ Ho ten  : " << this->hoTen << endl;
	cout << "\t+ Luong CB: " << this->luongCB << endl;
	cout << "\t+ So sp   : " << this->soSP << endl;
	cout << "\t+ Luong HT: " << this->luongHT << endl;
}

float NV::tinhLuongHT()
{
	this->luongHT = luongCB + soSP * 175000;

	if (this->luongHT >= 10e6)
	{
		this->luongHT += this->luongHT * 0.1;
	}
	return this->luongHT;
}

bool NV::timNV(int maNV)
{
	return this->maNV == maNV;
}

void NV::capNhatLuongCB(float LuongCB)
{
	this->luongCB = LuongCB;
}

int NV::soSanhLuongHT(NV other)
{
	float a = this->luongHT;
	float b = other.luongHT;

	if (a > b)
	{
		return 1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
	return -1;
    }
}

int NV::soSanhSoSP(NV other)
{
	int a = this->soSP;
	int b = other.soSP;

	if (a > b)
	{
		return 1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	CongTy ct;

	//Test: 1. Tạo dữ liệu
	ct.initNhanVienCongTy();
	cout << "" << endl;

	//Test: 2. In toàn bộ nhân viên
	cout << "2. In nhan vien: " << endl;
	ct.printNV();

	//Test: 3. Tính lương nhân viên
	cout << endl << "Test: 3. Tinh luong nhan vien: " << endl << endl;

	ct.tinhLuongCongTy();

	ct.printNV();

	//Test: 4. Tìm nhân viên theo mã nhân viên
	cout << endl << "Test: 4. Tim nhan vien theo maNV: " << endl << endl;

	NV timNV;

	timNV = ct.timNVCongTy(125);

	timNV.printf();

	//Test: 5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
	cout << endl << "Test: 5. Cap nhat luongCB: " << endl << endl;

	ct.capNhatLuongCBCongTy(125, 12e6);

	ct.tinhLuongCongTy();

	ct.printNV();

	//Test: 6. Tìm nhân viên lương cao nhất
	cout << endl << "Test: 6. Nhan vien luong cao nhat: " << endl << endl;

	NV TimLuongCaoNhat;

	TimLuongCaoNhat = ct.timNVLuongCaoNhatCongTy();

	TimLuongCaoNhat.printf();


	//Test: 7. Tìm nhân viên có số sản phẩm thấp nhất
	cout << endl << "Test: 7. Nhan vien co soSP thap nhat: " << endl << endl;

	NV MinSoSP;

	MinSoSP = ct.timNVSoSPThapNhatCongTy();

	MinSoSP.printf();

	//Test: 8. Tìm 10 nhân viên lương cao nhất
	cout << endl << "Test: 8. Tim 10 nhan vien luong cao nhat: " << endl << endl;

	vector<NV> top10NV;

	top10NV = ct.tim10NVLuongCaoNhat();

	for (int i = 0; i < top10NV.size(); ++i)
	{
		top10NV[i].printf();
	}
}
