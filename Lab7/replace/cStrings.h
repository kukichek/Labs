#pragma once

void error(const char* typeOfError); // оповещает об ошибках при чтении из файла

char* deleteWord(char* word, char* initialString); // удаление слова word из строки 
												   // (с учетом того, что слово word есть в заданной строке)

bool isEqual(char* word1, char* word2); // сравнивает две строки на равенство

char* turnOverWord(char* word); // переворачивает слово задом наперед

char* replace(char* initialString, char* str1, char* str2); // заменяет подстроку str1 в строке на str2
															// (с учетом того, что подстрокf str1 есть в заданной строке)