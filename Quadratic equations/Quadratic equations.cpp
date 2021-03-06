#include "pch.h"
#include "iostream"
#include "cmath"
#include "clocale"
#include "windows.h"
#include "iomanip"
using namespace std;

void russian() {                                      //инициализация ввода русских символов
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void english() {                                      //инициализация ввода английских символов
	SetConsoleCP(437);                                                                    //Установка вывода сложных символов ASCII кода
	SetConsoleOutputCP(437);
	setlocale(LC_ALL, "C");
}

int main()
{
	int n;
	double a, b, c;
	char z = '\n';
	long long D, root_D;
	setlocale(0, "");                                                                      //Установка вывода русских символов
	cout << "        " << "ПРОГРАММА ДЛЯ РЕШЕНИЯ КВАДРАТНЫХ УРАВНЕНИЙ" << endl << endl;
	cout << "   Квадратное уравнение имеет вид: ";
	english();                                                               //Устаовка вывода английских символов
	cout << "ax" << char(253) << "+bx+c=0" << endl;
	russian();
	cout << "   где a, b, c - коэффициенты уравнения, введите их:" << endl;
label_1:
	cout << "   a = ";
	cin >> a;
	n = cin.rdstate();                 //Проверяет состояние потока ввода
	if (n & ios::failbit) {                      //если введен символ неверного формата
		cout << "   Недопустимый символ, введите еще раз: " << "\n";
		while (getchar() != z);
		cin.clear();
		goto label_1;
	}
	else {
		if (a > 1000 || a < -1000)
		{
			cout << "   Значение превышает границы ввода, попробуйте еще раз:" << endl;
			goto label_1;
		}
	}
label_2:
	cout << "   b = ";
	cin >> b;
	n = cin.rdstate();
	if (n & ios::failbit) {
		cout << "   Недопустимый символ, введите еще раз: " << "\n";
		while (getchar() != z);
		cin.clear();
		goto label_2;
	}
	else {
		if (b > 1000 || b < -1000)
		{
			cout << "   Значение превышает границы ввода, попробуйте еще раз:" << endl;
			goto label_2;
		}
	}
label_3:
	cout << "   c = ";
	cin >> c;
	n = cin.rdstate();
	if (n & ios::failbit) {
		cout << "   Недопустимый символ, введите еще раз: " << "\n";
		while (getchar() != z);
		cin.clear();
		goto label_3;
	}
	else {
		if (c > 1000 || c < -1000)
		{
			cout << "   Значение превышает границы ввода, попробуйте еще раз:" << endl;
			goto label_3;
		}
	}
	//Проверка коеффициентов на 0
	cout << "   Получаем:  ";
	english();
	if (a == 0 && b != 0 && c != 0) {
		if (c < 0) {
			cout << b << "x" << c << "=0" << endl;
			if (float(c / b) == int(c / b)) {
				cout << setw(18) << "   x = " << -c / b << endl;
			}
			else {
				cout << setw(18) << "   x = " << -c << "/" << b << endl;
			}

		}
		else {
			cout << b << "x+" << c << "=0" << endl;
			if (float(c / b) == int(c / b)) {
				cout << setw(18) << "   x = " << -c / b << endl;
			}
			else {
				cout << setw(18) << "   x = " << -c << "/" << b << endl;
			}
		}
		goto exit;
	}
	if (a == 0 && b == 0 && c == 0) {
		russian();
		cout << "0=0" << endl;
		cout << setw(18) << "   Уравнение имеет бесконечное множество решений!" << endl;
		goto exit;
	}
	if (a == 0 && b != 0 && c == 0) {
		russian();
		cout << b << "x=0" << endl;
		cout << setw(19) << "     x = 0" << endl;
		goto exit;
	}
	if (a == 0 && b == 0 && c != 0) {
		russian();
		cout << c << "=0" << endl;
		cout << setw(18) << "   Уравнение не имеет решений!" << endl;
		goto exit;
	}
	if (a != 0 && b != 0 && c != 0) {
		if (b > 0 && c > 0) {
			cout << a << "x" << char(253) << "+" << b << "x+" << c << "=0" << endl;
		}
		if (b < 0 && c < 0) {
			cout << a << "x" << char(253) << b << "x" << c << "=0" << endl;
		}
		if (b < 0 && c > 0) {
			cout << a << "x" << char(253) << b << "x+" << c << "=0" << endl;
		}
		if (b > 0 && c < 0) {
			cout << a << "x" << char(253) << "+" << b << "x" << c << "=0" << endl;
		}
	}
	if (a != 0 && b == 0 && c == 0) {
		cout << a << "x" << char(253) << "=0" << endl;
		russian();
		cout << setw(19) << "     x = 0" << endl;
		goto exit;
	}
	if (a != 0 && b != 0 && c == 0) {
		if (b > 0) {
			cout << a << "x" << char(253) << "+" << b << "x=0" << endl;
		}
		if (b < 0) {
			cout << a << "x" << char(253) << b << "x=0" << endl;
		}
	}
	if (a != 0 && b == 0 && c != 0) {
		if (c > 0) {
			cout << a << "x" << char(253) << "+" << c << "=0" << endl;
		}
		if (c < 0) {
			cout << a << "x" << char(253) << c << "=0" << endl;
		}
	}
	//Нахождение корней уравнения
	D = b * b - 4 * a * c;
	cout << setw(18) << "   D = " << D;
	if (D < 0) {
		russian();
		cout << "   Уравнение не имеет решений!" << endl;
	}
	if (D == 0) {
		russian();
		cout << "   Уравнение имеет только один корень!" << endl;
		double result_1 = -b / (2 * a);
		if (result_1 == (long long)result_1)
		{
			cout << setw(18) << "   x = " << result_1 << endl;
		}
		else {
			cout << setw(18) << "   x = " << -b << "/" << 2 * a << endl;
		}
	}
	if (D > 0) {
		russian();
		cout << "   Уравнение имеет два корня!" << endl;
		root_D = sqrt(D);
		root_D = root_D * root_D;
		if (D != root_D) {
			english();
			cout << setw(20) << "    x1 = (" << -b << " - " << char(251) << D << ")/" << 2 * a << ";";
			cout << "     " << "x2 = (" << -b << " + " << char(251) << D << ")/" << 2 * a << "." << endl;
		}
		else {
			float z = (-b - sqrt(D)) / (2 * a);
			if (float(z) != int(z)) {
				cout << setw(19) << "   x1 = " << (-b - sqrt(D)) << "/" << (2 * a) << ";";
				cout << "     x2 = " << (-b + sqrt(D)) << "/" << (2 * a) << "." << endl;
			}
			else {
				cout << setw(19) << "   x1 = " << (-b - sqrt(D)) / (2 * a) << ";";
				cout << "     x2 = " << (-b + sqrt(D)) / (2 * a) << "." << endl;
			}
		}
	}
exit:
	cout << endl;
	russian();
	cout << "   Хотите попробовать еще раз?" << endl;
	cout << "   Y - продолжить;   N - выход." << endl;
	char Zhykl[100];
exit_3:
	cin >> Zhykl;
	if (char(Zhykl[0]) == 'Y') {
		goto label_1;
	}
	if (char(Zhykl[0]) == 'N') {
		goto exit_2;
	}
	else {
		cout << "   Некорректный ввод!" << endl;
		goto exit_3;
	}
exit_2:
	cout << endl;
	system("pause");
	return 0;
}