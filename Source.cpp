/*This program performs a bubble sort on the characters in a text file.*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void readFile(char*& file, long& fsize) {
	//TODO Allow user to specify filename
	FILE *f = fopen("Large.txt", "rb");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	file = (char *)malloc(fsize + 1);
	fread(file, fsize, 1, f);
	fclose(f);

	file[fsize] = NULL;
}

void bubbleSort(char*& text, long length) {
	int j, k;
	char temp;


	for (j = 1; j<length; j++)
	{
		for (k = 0; k<length - j; k++)
		{
			if ((int)text[k] >= (int)text[k + 1])
			{
				temp = text[k];
				text[k] = text[k + 1];
				text[k + 1] = temp;
			}
		}
	}
	printf("The sorted items are: %s", text);
}
int main() {
	
	char* allText;
	long size;
	readFile(allText, size);
	bubbleSort(allText, size);

	getchar();

}