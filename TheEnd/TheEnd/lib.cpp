#include"lib.h"
#include<iostream>


void Chia2(std::string &dec, std::string &bi){
	std::string tam;
	int thuong = 0, sodu = 0, number = 0;

	//Xu ly chia
	for (int i = 0; i < dec.length(); i++){
		number = dec[i] - 48 + sodu * 10;
		thuong = number / 2;
		sodu = number % 2;
		tam.push_back(thuong + 48);
	}
	//Sau khi chia thay doi gia tri cua bi
	bi.push_back(sodu + 48);
	//Thay doi gia tri cua dec
	dec.clear();
	int flag = 1;
	for (int i = 0; i < tam.length(); i++)
	{
		if (tam[i] != '0')
			flag = 0;
		if (flag == 0)
			dec.push_back(tam[i]);
	}
}

std::string DinhDang_Bi(std::string bi){
	int len = bi.length();
	for (int i = 0; i < 128 - len; i++)
		bi.insert(0, "0");
	return bi;
}
std::string DinhDang_Hex(std::string hex){
	int len = hex.length();
	for (int i = 0; i < 32 - len; i++)
		hex.insert(0, "0");
	return hex;
}




std::string Nhan2(std::string dec){
	std::string ans;
	int nho = 0;
	int len = dec.length();
	for (int i = 0; i < len; i++){
		int number = dec[len - 1 - i] - 48;

		if (number >= 5){
			ans.push_back(number * 2 - 10 + nho + 48);
			nho = 1;
		}
		else {
			ans.push_back(number * 2 + nho + 48);
			nho = 0;
		}
	}
	if (nho == 1)
		ans.push_back(nho + 48);
	std::reverse(ans.begin(), ans.end());
	return ans;
}



