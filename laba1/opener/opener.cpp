#include <stdio.h>

int main()
{
	FILE* fptr;
	fopen_s(&fptr, "file.mkhoyan", "r+"); //открываем файл

	if (fptr == 0) {
		return -1;
	}

	//считываем его содержимое
	char buf[1024] = { 0 };
	fread_s(buf, 1024, sizeof(char), 1024, fptr);

	//выводим содержимое на экран
	printf_s("FILE CONTENTS:%s\n\n", buf);

	//перезаписываем
	char buf_to_write[1024] = { "--- TestData ---" };
	fseek(fptr, 0, 0);
	fwrite(buf_to_write, sizeof(char), 1024, fptr);
	fflush(fptr); // записывает на диск поток stream, Указатель на структуру FILE.
	fclose(fptr); // закрытие файла

	return 0;
}