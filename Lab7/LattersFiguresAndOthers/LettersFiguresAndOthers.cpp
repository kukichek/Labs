/*
Дана строка символов. Определить количество букв, 
количество цифр и количество остальных символов, присутствующих в строке

Гамезо Валерия, 1 курс, информатика
*/

#include<fstream>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const char* notExistingError = "The file is not existing";
const char* emptyFileError = "The file is empty";

void error(const char* typeOfError) {
	cout << typeOfError << endl;
	return;
}

int main() {
	FILE *fileIn; 
	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		char *initialString = new char[1000];

		if (fgets(initialString, 1000, fileIn) != NULL) {
			int counterFigures = 0;
			int counterLetters = 0;
			int counterOthers = 0;
			do {
				int stringLenght = strlen(initialString);
				for (int i = 0; i < stringLenght; ++i) {
					if (isdigit(initialString[i])) {
						counterFigures++;
					} else {
						if (isalpha(initialString[i])) {
							counterLetters++;
						} else {
							counterOthers++;
						}
					}
				}
			} while (fgets(initialString, 1000, fileIn) != NULL);

			ofstream fout("output.txt");
			fout << "A number of letters in the file is " << counterLetters << endl;
			fout << "A number of figures in the file is " << counterFigures << endl;
			fout << "A number of other simbols in the file is " << counterOthers << endl;
			fout.close();
		} else {
			error(emptyFileError);
		}

		fclose(fileIn);
	} else {
		error(notExistingError);
	}

	system("pause");

	return 0;
}