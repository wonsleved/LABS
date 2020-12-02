#define MAXFILEPATH 100
#define RANDNUM 50
#define TRUE 1

#define FUNCTION_LIST   "\n\n" \
                        "1. Чтение данных из входного потока (с клавиатуры)\n" \
                        "2. Чтение данных из текстового файла\n" \
                        "3. Случайная генерация данных\n" \
                        "4. Выйти из программы\n"

char *get_str();
char *ReadFile();
int WriteFile(char *res);
char *Sort(const char *str);
char *Random();
void Symb(char *res);
