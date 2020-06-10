#pragma once
#include<string>
#define QInt_Size 4

class QInt
{
private:
	int arrayBits[QInt_Size];//Dung 4 ky tu Int luu 16 byte
public:
	QInt();
	~QInt();
	QInt(const QInt &Q);
	//--------------------Kiem tra cac gia tri dac biet--------------------
	//Kiem tra QInt co phai la so 0 
	bool IsZero()const;
	//Kiem tra QInt co phai la so 1 
	bool IsOne()const;
	//Kiem tra QInt co phai la so am
	bool SoAm()const;


	//--------------------Thao tac voi Bit --------------------------------

	//Lay gia tri cua bit o vi tri n (n -> 0 -> 127)
	int GetBit(int n)const;
	//Dat gia tri cho bit o vi tri n
	void SetBit(int n, bool value);
	//Ham lay chieu dai chuoi bit // So am chieu dai mac dinh se la 128
	int GetLength()const;


	//--------------------Nhap xuat so nguyen ------------------------------
	//Nhap gia tri cho so nguyen QInt
	void Nhap(std::string str, int base);
	//Xuat gia tri cua so nguyen QInt
	std::string Xuat(int base);
	//Luu chuoi nhi phan trong arrayBits
	void SaveBit(std::string bin);
	//Lay gia tri chuoi nhi phan duoc luu trong arrayBits
	std::string PrintBit();

	//----------------------Chuyen he co so ---------------------------------

	//Chuyen tu he co so 10 -> 2
	QInt DecToBin(std::string dec);
	//Chuyen tu he co so 16 -> 2
	std::string HexToBin(std::string hex);
	//Chuyen tu he co so 2 -> 16
	std::string BinToHex();
	//Chuyen tu he co so 2 -> 10
	std::string BinToDec();
	//-----------------Phep toan AND OR XOR NOT------------------------
	//Phep toan AND
	QInt operator& (const QInt& Q) const;
	//Phep toan OR
	QInt operator| (const QInt& Q)const;
	//Phep Toan XOR
	QInt operator^ (const QInt& Q)const;
	//Phep Toan NOT
	QInt operator~ ()const;
	//----------------PHep dich Bit << >> -------------------------------
	//Phep dich phai
	QInt operator>>(int nums)const;
	//Phep dich trai
	QInt operator<<(int nums)const;
	//----------------Phep xoay bit ror va rol --------------------------
	//Phep xoay phai
	QInt ror(int nums)const;
	//Phep xoay trai
	QInt rol(int nums)const;
	//----------------Phep + - * / = --------------------------------------
	QInt& operator=(const QInt& Q);
	QInt operator+(const QInt& Q)const;
	QInt operator-(const QInt& Q)const;
	QInt operator-()const;
	QInt operator*(const QInt& Q)const;
	QInt operator/(const QInt& Q)const;
	//---------------Phep toan so sanh > < = ------------------------------
	bool operator>(const QInt& Q)const;
	bool operator<(const QInt& Q)const;
	bool operator==(const QInt& Q)const;
	bool operator!=(const QInt& Q)const;
	bool operator<=(const QInt& Q)const;
	bool operator>=(const QInt& Q)const;

};

