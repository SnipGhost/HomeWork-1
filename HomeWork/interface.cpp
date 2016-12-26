//---------------------------------------------------------------------------
// File: interface.cpp
// By:   HeliSRaiN
//                                                Файл визуализации программы
//---------------------------------------------------------------------------
#include "interface.h"
//---------------------------------------------------------------------------
enum keys {           // Ключи для интерфейса меню
	KEY_CMD1 = '1',
	KEY_CMD2,
	KEY_CMD3,
	KEY_EXIT = 'q'
};
//---------------------------------------------------------------------------
void showMenu()
{
	system("cls");
	cout << "------ Выберите пункт ------\n";
	cout << (char)KEY_CMD1 << ". Ввести текст.\n";
	cout << (char)KEY_CMD2 << ". Индивидуальное задание.\n";
	cout << (char)KEY_EXIT << ". Заверешение программы.\n";
	cout << "----------------------------\n";
}
//---------------------------------------------------------------------------
int Menu()
{
	showMenu();
	char point;
	cin >> point;
	while (point < KEY_CMD1 && point > KEY_CMD3 && point != KEY_EXIT) 
	{
		showMenu();
		cout << " Неверная команда, попробуйте еще раз: ";	
		cin >> point;
	}
	return (int)point;
}
//---------------------------------------------------------------------------
//ИНТЕРФЕЙС СТРАНИЦЫ "ВВОД ТЕКСТА"
Text *entryTextInter(Text *text) 
{
	if (text != NULL) delete text;
	system("cls");

	cout << "Введите текст, ";
	cout << "звуковой сигнал означает, что символ недопустим.\n\n";

	text = getText(inputText());

	while (text == NULL)
	{
		system("cls");
		cout << "Некорректный текст, попробуйте снова.\n\n";
		text = getText(inputText());
	}
	return text;
}
//---------------------------------------------------------------------------
//ИНТЕРФЕЙС СТРАНИЦЫ "ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ"
Text *indivTaskInter(Text *text) 
{
	system("cls");
	bool checkExit = 0;
	if (text == NULL) { //Если не прошли первый пункт "ВВОД ТЕКСТА"
		cout << "Текст еще не введен! Сначала введите текст.\n";
		system("pause");
		return NULL;
	}
	text = doMyHomeWork(text);
	system("pause");
	return text;
}
//---------------------------------------------------------------------------
int menuRun(Text *&text) 
{
	system("chcp 1251 > nul");
	while (true) {
		int c = Menu(); // Вернет значения ТОЧНО из keys
		switch (c)
		{
			case KEY_CMD1: // ВВОД ТЕКСТА
				text = entryTextInter(text); 
			break;
			case KEY_CMD2: // ИНДИВИДУАЛЬНЫЕ ЗАДАНИЯ
				text = indivTaskInter(text);
			break;
			case KEY_CMD3: // ВЫХОД
			case KEY_EXIT: // АЛЬТЕРНАТИВНЫЙ ВЫХОД
				say("Завершение работы ...");
				delete text;
				return 0;
			break;
		}
	}
}
//---------------------------------------------------------------------------