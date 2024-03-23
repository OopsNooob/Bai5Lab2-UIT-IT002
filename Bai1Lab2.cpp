#include <iostream>
using namespace std;

typedef class PhanSo
{
private:
	int iTuSo;
	int iMauSo;

public:
	//1. Khởi tạo phân số
	void initPhanSo(int, int);

	//2. In phân số
	void printf();

	//3. Rút gọn phân số
	PhanSo rutGon();

	//4. So sánh 2 phân số
	int soSanh(PhanSo);

	//5. Cộng hai phân số
	PhanSo cong(PhanSo);

	//6. Trừ hai phân số
	PhanSo tru(PhanSo);

	//7. Nhân 2 phân số
	PhanSo nhan(PhanSo);

	//8. Chia hai phân số
	PhanSo chia(PhanSo);

	//9. Sao chép 2 phân số
	void saoChep(PhanSo);

	//10. Tìm phân số lớn nhất
	PhanSo timMax(PhanSo[], int);

}PS;

//1. Khởi tạo phân số
void PhanSo::initPhanSo(int iTuSo, int iMauSo)
{
	this->iTuSo = iTuSo;
	this->iMauSo = iMauSo;
}

//2. In phân số
void PhanSo::printf()
{
	if (iMauSo == 1)
	{
		cout << iTuSo << endl << endl;
	}
	else
	{
		cout << iTuSo << "/" << iMauSo << endl << endl;
	}
}

/* 3. Rút gọn phân số
Input:
	+ PhanSo A
Output:
	+ return PhanSo A đã rút gọn
*/
PhanSo PhanSo::rutGon()
{
	int gcd = 1;
	int temp1 = iTuSo;
	int temp2 = iMauSo;

	while (temp2 != 0)
	{
		int temp3 = temp2;

		temp2 = temp1 % temp2;

		temp1 = temp3;
	}
	gcd = temp1;

	this->iTuSo = this->iTuSo / gcd;

	iMauSo /= gcd;

	if (iMauSo < 0 && iTuSo > 0)
	{
		iMauSo = -iMauSo;
		iTuSo = -iTuSo;
	}

	//PS p;

	//p.initPhanSo(iTuSo, iMauSo);

	return *this;
}

/* 4. So sánh 2 phân số
Input:
	+ PhanSo A
	+ PhanSo B

Output:
	+ return 1(A>B), 0(A=B), -1(A<B)
*/
int PhanSo::soSanh(PS other)
{
	double a = 1.0 * this->iTuSo / this->iMauSo;
	double b = 1.0 * other.iTuSo / other.iMauSo;

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

/* 5. Cộng hai phân số
Input:
	+ PhanSo A, PhanSo B

Output:
	+ return PhanSo A + PhanSo B
*/
PhanSo PhanSo::cong(PhanSo other)
{
	int tu = this->iTuSo * other.iMauSo + other.iTuSo * this->iMauSo;
	int mau = this->iMauSo * other.iMauSo;

	PS sample;

	sample.initPhanSo(tu, mau);

	return sample.rutGon();
}

/* 6. Trừ hai phân số
Input:
	+ PhanSo A, B

Output:
	+ return PhanSo A - PhanSo B
*/
PhanSo PhanSo::tru(PhanSo other)
{
	int tu = this->iTuSo * other.iMauSo - other.iTuSo * this->iMauSo;
	int mau = this->iMauSo * other.iMauSo;

	PS sample;

	sample.initPhanSo(tu, mau);

	return sample.rutGon();
}

/* 7. Nhân 2 phân số
Input:
	+ PhanSo A
	+ PhanSo B

Output:
	+ return PhanSo A * PhanSo B
*/
PS PhanSo::nhan(PS other)
{
	int tu = this->iTuSo * other.iTuSo;
	int mau = this->iMauSo * other.iMauSo;

	PS sample;

	sample.initPhanSo(tu, mau);

	return sample.rutGon();
}

/* 8. Chia 2 phân số
Input:
	+ PhanSo A, B

Output:
	+ return PhanSo A / PhanSo B
*/
PhanSo PhanSo::chia(PhanSo other)
{
	int tu = this->iTuSo * other.iMauSo;
	int mau = this->iMauSo * other.iTuSo;

	PS sample;

	sample.initPhanSo(tu, mau);

	return sample.rutGon();
}

/* 9. Sao chép 2 phân số
Input:
	+ PhanSo A, B

Output:
	+ Gán PhanSo B cho PhanSo A
*/
void PhanSo::saoChep(PhanSo other)
{
	this->iTuSo = other.iTuSo;
	this->iMauSo = other.iMauSo;
}

/* 10. Tìm phân số lớn nhất trong nhiều phân số
Input:
	+ Mảng PS A
	+ int n

Output:
	+ return PhanSo lon nhat
*/
PhanSo PhanSo::timMax(PS arr[], int n)
{
	PS MaxPS = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i].soSanh(MaxPS) == 1)
		{
			MaxPS = arr[i];
		}
	}
	return MaxPS;
}

int main()
{
	PS a, b, c;

	//Test: 1. Khởi tạo phân số
	a.initPhanSo(1, 2);
	b.initPhanSo(2, 4);
	c.initPhanSo(3, 1);

	//Test: 2. In phân số
	cout << "Test: 2. In phan so: " << endl;

	a.printf();
	b.printf();
	c.printf();

	//Test: 3. Rút gọn các phân số
	cout << "Test: 3. Rut gon: " << endl;

	PS d = b.rutGon();

	d.printf();
	b.printf();

	//Test: 4. Rút gọn các phân số
	cout << "Test: 4. So sanh: " << endl << a.soSanh(b) << endl << endl;

	//Test: 5. Cộng hai phân số
	cout << "Test: 5. Cong 2 phan so: " << endl;

	PhanSo test = a.cong(b);

	test.printf();

	//Test: 6. Trừ hai phân số
	cout << "Test: 6. Tru 2 phan so: " << endl;

	test = a.tru(b);

	test.printf();

	//Test: 7. Nhân 2 phân số
	cout << "Test: 7. Nhan 2 phan so: " << endl;

	PhanSo x, y;

	x.initPhanSo(2, 6);
	y.initPhanSo(3, 9);

	PhanSo r = x.nhan(y);

	r.printf();

	//Test: 8. Chia 2 phân số
	cout << "Test: 8. Chia 2 phan so: " << endl;

	test = a.chia(b);

	test.printf();

	//Test: 9. Sao chép 2 phân số
	cout << "Test: 9. Sao chep 2 phan so: " << endl;

	a.saoChep(c);

	a.printf();

	//Test: 10. Tìm phân số lớn nhất trong các phân số
	cout << "Test: 10. Tim phan so lon nhat: " << endl;

	PS arr[100];

	arr[0].initPhanSo(1, 2);
	arr[1].initPhanSo(6, 9);
	arr[2].initPhanSo(2, 6);
	arr[3].initPhanSo(4, 1);

	int n = 4;

	test = a.timMax(arr, n);

	test.printf();
}
