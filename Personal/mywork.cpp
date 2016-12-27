﻿//---------------------------------------------------------------------------
// File: mywork.cpp
// By:   Nastya
//                                                     Индивидуальное задание
//---------------------------------------------------------------------------
#include "mywork.h"
//---------------------------------------------------------------------------
// Функция, выполняющая индивидуальное задание
//---------------------------------------------------------------------------
Text *doMyHomeWork(Text *text)
{
	cout << "Вариант 09" << endl;
	cout << "Оставить  в предложениях слова, отличающиеся от последнего\n";
	cout << "слова предложения, в которых буквы упорядочены по алфавиту.";

	 // Вывод текста с использованием перегруженного оператора
	cout << "\n\nИсходный текст: \n" << text; // Замечу, для указателя!

	cout << "\nИзмененный текст: \n";
	for (int i = 0; i < text->size; ++i) // Проходимся по всем предложениям
	{
		// Записываем указатель на последнее слово предложения (удобно!)
		Word *last = text->sent[i]->word[text->sent[i]->size-1];

		// Для каждого предложения проходимся по всем его словам
		for (int j = 0; j < text->sent[i]->size; ++j)
		{
			// Записываем указатель на текущее просматриваемое слово
			Word *w = text->sent[i]->word[j];

			// Если совпало с последним - поднимаем флаг (Ф.О.Н.)
			if (strcmp(w->symbols, last->symbols) == 0)
				w->flag = true;

			// Для каждого слова проходимся по всем его буквам
			// До тех пор пока слово будет нам удовлетворять - просматриваем
			// Если перестало (буквы не упорядочены по возрастанию)
			// То поднимем флаг (Ф.О.Н.), это дешевле, чем просто удалять
			for (unsigned k = 1; (k < strlen(w->symbols))&&(!w->flag); ++k)
				if (w->symbols[k] < w->symbols[k-1]) 
					w->flag = true;

			// Если после всех проверок флаг (Ф.О.Н.) не поднят (не истина)
			if (!w->flag)
				cout << *(w) << " "; // То выводим, разыменовав указатель
			
			// Оператор вывода через разыменование выводит слово "как есть"
			// А вот вывода через указатель - добавляет атрибуты (запятые)

			// Т.е. текст изначальный выводим не разыменовывая, а слова 
			// потом уже разыменовывая, чтобы не выводть лишнего!

		}
	}
	cout << "\n\n";
	return text;
}
//---------------------------------------------------------------------------