Программа представляет из себя класс algorithm, в котором происходит вычисление.

Для начала работы необходимо создать объект класса algorithm и отправить на вход конструктору 
класса 6 8-рязрядных двоичных числа (произведение будет находится между 1 и 2, 3 и 4, 5 и 6 числами).

Поля класса:

	1. двоичные числа (между ними  будет происходить умножение):
		string A1;
		string B1;

		string A2;
		string B2;

		string A3;
		string B3;
		
	2. Переменные, которые хранят промежуточные значения:
		string multi_calc1 = "00000000";
		string multi_result1 = "00000000";
		string sum_result1 = "00000000";

		string multi_calc2 = "00000000";
		string multi_result2 = "00000000";
		string sum_result2 = "00000000";

		string multi_calc3 = "00000000";
		string multi_result3 = "00000000";
		string sum_result3 = "00000000";
		
	3. Переменные типа bool, нужные для проверки. В зависимости от их значения будут выполнятся разные
	процессорные элементы (методы).

		bool multi_check1 = false;
		bool sum_check1 = false;
		bool shift_check1 = true;

		bool multi_check2 = false;
		bool sum_check2 = false;
		bool shift_check2 = true;

		bool multi_check3 = false;
		bool sum_check3 = false;
		bool shift_check3 = true;
		
	4. Вектор vector <vector <bool>> line, необходимый для последующего вывода информации в консоль.

Методы класса:

	1. multiplication(char curr_num, string &multi_calc, string &multi_result, string A)
		В методе происходит умножение разряда curr_num на число А. В процессе вычисления все записывается
		в multi_calc, а  конечный результат - в multi_result.
		
	2. sum(string &sum_result, string &multi_result)
		Метод находит частичную сумму. На вход приходит sum_result, куда запишется ответ, 
		и multi_result, который мы получаем из метода multiplication.
		
	3. shift(string &multi_calc)
		Метод сдвига.
		
	4. find_result()
		Метод, который по идее и является конвейером. Тут вызываются процессорные элементы (методы, что описаны
		выше). Внутри метода есть вектор column, необходимый для последующего вывода информации в консоль.
		
	5. print()
		Метод, выводящий всю нужную информацию в консоль.