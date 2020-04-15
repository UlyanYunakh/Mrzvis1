#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class algorithm {
private:
	string A1;
	string B1;

	string A2;
	string B2;

	string A3;
	string B3;
	
	string multi_calc1 = "00000000";
	string multi_result1 = "00000000";
	string sum_result1 = "00000000";

	string multi_calc2 = "00000000";
	string multi_result2 = "00000000";
	string sum_result2 = "00000000";

	string multi_calc3 = "00000000";
	string multi_result3 = "00000000";
	string sum_result3 = "00000000";

	bool multi_check1 = false;
	bool sum_check1 = false;
	bool shift_check1 = true;

	bool multi_check2 = false;
	bool sum_check2 = false;
	bool shift_check2 = true;

	bool multi_check3 = false;
	bool sum_check3 = false;
	bool shift_check3 = true;

	vector <vector <bool>> line;

	//**Метод умножения**//
	void multiplication(char curr_num, string &multi_calc, string &multi_result, string A){
		if (curr_num == '1') {
			for (int i = 0; i < A.length(); i++)
				multi_calc[i] = A[i];
			multi_result = multi_calc;
		}
		if (curr_num == '0') {
			for (int i = 0; i < A.length(); i++)
				multi_calc[i] = '0';
			multi_result = multi_calc;
		}
	}

	//**Метод нахождения частичной суммы**//
	void sum(string &sum_result, string &multi_result) {
		while (sum_result.length() != multi_result.length())
			sum_result = "0" + sum_result;
		int sum_check = 0;
		for (int i = multi_result.length() - 1; i >= 0; i--) {
			if (sum_result[i] == '1' && multi_result[i] == '1' && sum_check == 1) {
				sum_result[i] = '1';
				continue;
			}
			if (sum_result[i] == '1' && multi_result[i] == '0' && sum_check == 1 || sum_result[i] == '0' && multi_result[i] == '1' && sum_check == 1) {
				sum_result[i] = '0';
				sum_check = 1;
				continue;
			}
			if (sum_result[i] == '0' && multi_result[i] == '0' && sum_check == 1) {
				sum_result[i] = '1';
				sum_check = 0;
				continue;
			}
			if (sum_result[i] == '1' && multi_result[i] == '1') {
				sum_result[i] = '0';
				sum_check = 1;
				continue;
			}
			if (sum_result[i] == '1' && multi_result[i] == '0' || sum_result[i] == '0' && multi_result[i] == '1') {
				sum_result[i] = '1';
				continue;
			}
			if (sum_result[i] == '0' && multi_result[i] == '0') {
				sum_result[i] = '0';
				continue;
			}
		}
		if (sum_check == 1)
			sum_result = "1" + sum_result;
	}

	//**Метод сдвига**//
	void shift(string &multi_calc) {
		multi_calc = multi_calc + "0";
	}

	//**Метод нахождения произведения А на В**//
	void find_result() {
		int i = B1.length() - 1;
		int j = B2.length() - 1;
		int y = B3.length() - 1;
		int t_num = 1;
		for (int k = 0; k < 26; k++) {
			bool S1 = true;
			bool S2 = true;
			bool S3 = true;
			bool N1 = true;
			bool N2 = true;
			bool N3 = true;
			cout << "---Такт №" << t_num << "---" << endl;
			t_num++;
			vector<bool> column(3, false);
			if (multi_check1 == false && sum_check1 == false && shift_check1 == true && S1 == true && i != -1 && N1 == true) {
				multiplication(B1[i], multi_calc1, multi_result1, A1);
				column[0] = true;
				multi_check1 = true;
				sum_check1 = true;
				shift_check1 = false;
				cout << "Умножение. Результат: " << multi_result1 << endl;
				cout << endl;
				S1 = false;
				N1 = false;
			} 
			if (multi_check2 == false && sum_check2 == false && shift_check2 == true && S1 == true && j != -1 && N2 == true) {
				multiplication(B2[j], multi_calc2, multi_result2, A2);
				column[0] = true;
				multi_check2 = true;
				sum_check2 = true;
				shift_check2 = false;
				cout << "Умножение. Результат: " << multi_result2 << endl;
				cout << endl;
				S1 = false;
				N2 = false;
			}
			if (multi_check3 == false && sum_check3 == false && shift_check3 == true && S1 == true && y != -1 && N3 == true) {
				multiplication(B3[y], multi_calc3, multi_result3, A3);
				column[0] = true;
				multi_check3 = true;
				sum_check3 = true;
				shift_check3 = false;
				cout << "Умножение. Результат: " << multi_result3 << endl;
				cout << endl;
				S1 = false;
				N3 = false;
			}

			if (multi_check1 == true && sum_check1 == true && shift_check1 == false && S2 == true && N1 == true) {
				sum(sum_result1, multi_result1);
				cout << "Сумма. Результат: " << sum_result1 << endl;
				column[1] = true;
				shift_check1 = true;
				S2 = false;
				N1 = false;
			}
			if (multi_check2 == true && sum_check2 == true && shift_check2 == false && S2 == true && N2 == true) {
				sum(sum_result2, multi_result2);
				cout << "Сумма. Результат: " << sum_result2 << endl;
				column[1] = true;
				shift_check2 = true;
				S2 = false;
				N2 = false;
			}
			if (multi_check3 == true && sum_check3 == true && shift_check3 == false && S2 == true && N3 == true) {
				sum(sum_result3, multi_result3);
				cout << "Сумма. Результат: " << sum_result3 << endl;
				column[1] = true;
				shift_check3 = true;
				S2 = false;
				N3 = false;
			}

			if (multi_check1 == true && sum_check1 == true && shift_check1 == true && S3 == true && N1 == true) {
				shift(multi_calc1);
				column[2] = true;
				multi_check1 = false;
				sum_check1 = false;
				shift_check1 = true;
				i--;
				cout << "Произошел сдвиг" << endl;
				S3 = false;
				N1 = false;
			}
			if (multi_check2 == true && sum_check2 == true && shift_check2 == true && S3 == true && N2 == true) {
				shift(multi_calc2);
				column[2] = true;
				multi_check2 = false;
				sum_check2 = false;
				shift_check2 = true;
				j--;
				cout << "Произошел сдвиг" << endl;
				S3 = false;
				N2 = false;
			}
			if (multi_check3 == true && sum_check3 == true && shift_check3 == true && S3 == true && N3 == true) {
				shift(multi_calc3);
				column[2] = true;
				multi_check3 = false;
				sum_check3 = false;
				shift_check3 = true;
				y--;
				cout << "Произошел сдвиг" << endl;
				S3 = false;
				N3 = false;
			}
			line.push_back(column);
			cout << endl;
		}
	}

	//**Методы вывода информации в консоль**//
	void print() {
		cout << "A1 = " << A1 << endl << "B1 = " << B1 << endl << "A1*B1 = " << sum_result1 << endl << endl;
		cout << "A2 = " << A2 << endl << "B2 = " << B2 << endl << "A2*B2 = " << sum_result2 << endl << endl;
		cout << "A3 = " << A3 << endl << "B3 = " << B3 << endl << "A3*B3 = " << sum_result3 << endl << endl;
		cout << "Конвейер:" << endl;
		cout << "*Примечание: один столбец таблицы - 1 такт; 1 значит процесс на данном такте был вызван, 0 - не был вызван." << endl << endl << setiosflags(ios::left);
		cout << setw(30) << "Процесс 1: умножение" << '\t';
		for (int i = 0; i < line.size(); i++)
			cout << line[i][0] << ' ';
		cout << endl << "Процесс 2: частичная сумма" << '\t';
		for (int i = 0; i < line.size(); i++)
			cout << line[i][1] << ' ';
		cout << setw(30) << endl << "Процесс 3: сдвиг" << '\t';
		for (int i = 0; i < line.size(); i++)
			cout << line[i][2] << ' ';
		cout << endl;
	}

public:
	algorithm(string inputA1, string inputB1, string inputA2, string inputB2, string inputA3, string inputB3) {
		A1 = inputA1;
		B1 = inputB1;

		A2 = inputA2;
		B2 = inputB2;

		A3 = inputA3;
		B3 = inputB3;

		find_result();
		print();
	};
};

int main() {
	setlocale(LC_ALL, "Russian");
	algorithm action("10001101", "10001001", "10001100", "11101101", "10101100", "11000101");
}