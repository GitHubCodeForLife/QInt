#include<iostream>
#include"QInt.h"
#include<fstream>

//Chuyen chuoi str2 tu he co so base sang he co so str1
std::string ChuyenHeCoSo(std::string str1, int base, std::string str2){
	QInt Q;
	Q.Nhap(str2, base);
	if (str1 == "10")
		return Q.Xuat(10);
	if (str1 == "16")
		return Q.Xuat(16);
	if (str1 == "2")
		return Q.Xuat(2);
}
//Phep xu ly bit
std::string XuLyBit(std::string str1, int base, std::string str2){
	QInt Q;
	Q.Nhap(str2, base);
	if (str1 == "~"){
		Q = ~Q;
	}
	else if (str1 == "ror"){
		Q = Q.ror(1);
	}
	else if (str1 == "rol"){
		Q = Q.rol(1);
	}
	return Q.Xuat(base);
}

void XuLy(std::ifstream &fi, std::ofstream& fo){
	//B1: Lay he co so
	int base;
	fi >> base;
	if (fi.eof() == 1)
		return;
	//B2: Xet phan tu thu 2
	std::string str1;
	fi >> str1;
	if (str1 == "10" || str1 == "16" || str1 == "2"){
		std::string str2; fi >> str2;
		fo << ChuyenHeCoSo(str1, base, str2) << std::endl;
		std::cout << "\n" << base << "   " << str1 << " " << str2 << " = " << ChuyenHeCoSo(str1, base, str2);
	}
	else if (str1 == "~" || str1 == "rol" || str1 == "ror"){
		std::string str2; fi >> str2;
		fo << XuLyBit(str1, base, str2) << std::endl;
		std::cout << "\n" << base << "   " << str1 << " " << str2 << " = " << XuLyBit(str1, base, str2);
	}
	else{//Th cac phep tinh + - * /
		std::string pheptinh, str2;
		fi >> pheptinh; fi >> str2;

		QInt q1, q2, ans; q1.Nhap(str1, base); q2.Nhap(str2, base);
		if (pheptinh == "+"){
			ans = q1 + q2;
		}
		else if (pheptinh == "-"){
			ans = q1 - q2;
		}
		else if (pheptinh == "*"){
			ans = q1*q2;
		}
		else if (pheptinh == "/"){
			ans = q1 / q2;
		}
		else if (pheptinh == "|"){
			ans = q1 | q2;
		}
		else if (pheptinh == "^"){
			ans = q1^q2;
		}
		else if (pheptinh == "&"){
			ans = q1&q2;
		}
		else if (pheptinh == "<<"){
			int bit = std::stoi(str2);
			ans = q1 << bit;
		}
		else if (pheptinh == ">>"){
			int bit = std::stoi(str2);
			ans = q1 >> bit;
		}
		else {
			std::cout << "\nNgoai pham vi xu ly.";
			fo << "0" << std::endl;
		}
		fo << ans.Xuat(base) << std::endl;
		std::cout << "\n" << base << "   " << str1 << " " << pheptinh << " " << str2 << " = " << ans.Xuat(base);
	}

}


int main(int argc, char* argv[])
{
	if (argc == 3){
	std::ifstream fi(argv[1]);
		std::ofstream fo(argv[2]);
		if (fi.fail()){
		std::cout << "\nKhong the mo file ";
		}
		if (fo.fail()){
		std::cout << "\nKhong the tao file";
		}

		while (fi.eof() != 1){
		XuLy(fi, fo);
		}
		


		

	}
	else{
		std::cout << "\nKhong the mo hay doc FiLe. Nhap sai du lieu dau vao.";
	}
	system("pause");
	return 1;
}