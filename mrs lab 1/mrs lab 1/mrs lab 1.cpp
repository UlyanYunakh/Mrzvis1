#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class algorithm {
private:
	vector<vector<string>> pairs;
	
	vector<vector<string>> calculation;

	vector<vector<bool>> check;

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
		vector<int> lenght(pairs.size(), 7);
		vector<bool> n_check(pairs.size(), true);
		vector<bool> s(3, true);
		vector<vector<bool>> s_chesk(8, s);
		int t_num = 1;
		for (int k = 0; k < 23 + pairs.size(); k++) {
			for (int j = 0; j < 8; j++) {
				s_chesk[j][0] = true;
				s_chesk[j][1] = true;
				s_chesk[j][2] = true;
			}
			for (int j = 0; j < pairs.size(); j++) n_check[j] = true;
			cout << "---Такт №" << t_num << "---" << endl;
			t_num++;
			vector<bool> column(24, false);
			// Произведение для 1 разряда
			for (int j = 0; j < pairs.size(); j++) { 
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[7][0] == true && lenght[j] == 7 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[0] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[7][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 2 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[6][0] == true && lenght[j] == 6 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[3] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[6][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 3 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[5][0] == true && lenght[j] == 5 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[6] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[5][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 4 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[4][0] == true && lenght[j] == 4 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[9] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[4][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 5 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[3][0] == true && lenght[j] == 3 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[12] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[3][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 6 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[2][0] == true && lenght[j] == 2 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[15] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[2][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 7 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[1][0] == true && lenght[j] == 1 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[18] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[1][0] = false;
					n_check[j] = false;
					break;
				}
			}
			// Произведение для 8 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == false && check[j][1] == false && check[j][2] == true && s_chesk[0][0] == true && lenght[j] == 0 && n_check[j] == true) {
					multiplication(pairs[j][1][lenght[j]], calculation[j][0], calculation[j][1], pairs[j][0]);
					column[21] = true;
					check[j][0] = true;
					check[j][1] = true;
					check[j][2] = false;
					cout << "Умножение. Результат: " << calculation[j][1] << endl;
					cout << endl;
					s_chesk[0][0] = false;
					n_check[j] = false;
					break;
				}
			}

			// Сумма для 1 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[7][1] == true && n_check[j] == true && lenght[j] == 7) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[1] = true;
					check[j][2] = true;
					s_chesk[7][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 2 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[6][1] == true && n_check[j] == true && lenght[j] == 6) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[4] = true;
					check[j][2] = true;
					s_chesk[6][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 3 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[5][1] == true && n_check[j] == true && lenght[j] == 5) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[7] = true;
					check[j][2] = true;
					s_chesk[5][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 4 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[4][1] == true && n_check[j] == true && lenght[j] == 4) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[10] = true;
					check[j][2] = true;
					s_chesk[4][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 5 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[3][1] == true && n_check[j] == true && lenght[j] == 3) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[13] = true;
					check[j][2] = true;
					s_chesk[3][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 6 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[2][1] == true && n_check[j] == true && lenght[j] == 2) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[16] = true;
					check[j][2] = true;
					s_chesk[2][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 7 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[1][1] == true && n_check[j] == true && lenght[j] == 1) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[19] = true;
					check[j][2] = true;
					s_chesk[1][1] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сумма для 8 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == false && s_chesk[0][1] == true && n_check[j] == true && lenght[j] == 0) {
					sum(calculation[j][2], calculation[j][1]);
					cout << "Сумма. Результат: " << calculation[j][2] << endl;
					column[22] = true;
					check[j][2] = true;
					s_chesk[0][1] = false;
					n_check[j] = false;
					break;
				}
			}
			
			// Сдвиг для 1 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[7][2] == true && n_check[j] == true && lenght[j] == 7) {
					shift(calculation[j][0]);
					column[2] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[7][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 2 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[6][2] == true && n_check[j] == true && lenght[j] == 6) {
					shift(calculation[j][0]);
					column[5] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[6][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 3 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[5][2] == true && n_check[j] == true && lenght[j] == 5) {
					shift(calculation[j][0]);
					column[8] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[5][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 4 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[4][2] == true && n_check[j] == true && lenght[j] == 4) {
					shift(calculation[j][0]);
					column[11] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[4][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 5 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[3][2] == true && n_check[j] == true && lenght[j] == 3) {
					shift(calculation[j][0]);
					column[14] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[3][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 6 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[2][2] == true && n_check[j] == true && lenght[j] == 2) {
					shift(calculation[j][0]);
					column[17] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[2][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 7 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[1][2] == true && n_check[j] == true && lenght[j] == 1) {
					shift(calculation[j][0]);
					column[20] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[1][2] = false;
					n_check[j] = false;
					break;
				}
			}
			// Сдвиг для 8 разряда
			for (int j = 0; j < pairs.size(); j++) {
				if (check[j][0] == true && check[j][1] == true && check[j][2] == true && s_chesk[0][2] == true && n_check[j] == true && lenght[j] == 0) {
					shift(calculation[j][0]);
					column[23] = true;
					check[j][0] = false;
					check[j][1] = false;
					check[j][2] = true;
					lenght[j]--;
					cout << "Произошел сдвиг" << endl;
					s_chesk[0][2] = false;
					n_check[j] = false;
					break;
				}
			}
			line.push_back(column);
			cout << endl;
		}
	}

	//**Методы вывода информации в консоль**//
	void print() {
		for (int i = 0; i < pairs.size(); i++) cout << "A = " << pairs[i][0] << endl << "B = " << pairs[i][1] << endl << "A*B = " << calculation[i][2] << endl << endl;
		cout << "Конвейер:" << endl;
		cout << "*Примечание: один столбец таблицы - 1 этап; 1 значит этап на данном такте был выполнен, 0 - не выполнялся." << endl << endl << setiosflags(ios::left);
		for (int j = 0; j < 23 + pairs.size(); j++){
			cout << "Такт " << j + 1 << '\t' << "  ";
			for (int i = 0; i < 24; i++) {
				cout << line[j][i] << "  ";
			}
			cout << endl;
		}
	}

public:
	algorithm(vector<vector<string>> input_pairs) {
		pairs = input_pairs;

		for (int i = 0; i < pairs.size(); i++) {
			vector<string> temp_string(3, "00000000");
			calculation.push_back(temp_string);
			vector<bool> temp_bool(3, false);
			temp_bool[2] = true;
			check.push_back(temp_bool);
		}
		find_result();
		print();
	};
};

int main() {
	setlocale(LC_ALL, "Russian");
	vector<vector<string>> pairs;
	vector<string> temp;

	temp.push_back("10001101"); //первое число первой пары
	temp.push_back("10001001"); //второе число первой пары
	pairs.push_back(temp);
	temp.clear();

	temp.push_back("10001100"); //2 пара
	temp.push_back("11101101");
	pairs.push_back(temp);
	temp.clear();

	temp.push_back("10101100"); //3 пара
	temp.push_back("11000101");
	pairs.push_back(temp);
	temp.clear();

	temp.push_back("10101011"); //4 пара
	temp.push_back("11110101");
	pairs.push_back(temp);
	temp.clear();

	temp.push_back("10100011"); //5 пара
	temp.push_back("11010101");
	pairs.push_back(temp);
	temp.clear();

	algorithm action(pairs);
	system("pause");
}