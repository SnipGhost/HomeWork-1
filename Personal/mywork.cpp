//---------------------------------------------------------------------------
// File: mywork.cpp
// By:   SnipGhost
//                                                     Индивидуальное задание
//---------------------------------------------------------------------------
#include "mywork.h"
//---------------------------------------------------------------------------
// Функция, выполняющая индивидуальное задание
//---------------------------------------------------------------------------
Text *doMyHomeWork(Text *text)
{
	cout << "Вариант 11" << endl;
	cout << "Оставить  в предложениях слова, отличающиеся от последнего\n";
	cout << "слова предложения и совпадающие с конечным отрезком алфавита.";
	cout << "\n\nИсходный текст: \n" << text;
	cout << "\nИзмененный текст: \n";
	for (int i = 0; i < text->size; ++i)
	{
		bool jack = false;
		Word *last = text->sent[i]->word[text->sent[i]->size-1];
		for (int j = 0; j < text->sent[i]->size; ++j)
		{
			Word *w = text->sent[i]->word[j];
			if (strcmp(w->symbols, last->symbols) == 0) w->flag = true;
			for (int k = 0; (k < strlen(w->symbols))&&(!w->flag); ++k)
				if (w->symbols[k] != 'z'-strlen(w->symbols)+1+k && 
					w->symbols[k] != 'Z'-strlen(w->symbols)+1+k ) 
					w->flag = true;
			if (!w->flag) {
				cout << *(w) << " ";
				jack = true;
			}
		}
		if (jack) cout << "\b. ";
	}
	cout << "\n\n";
	return text;
}
//---------------------------------------------------------------------------