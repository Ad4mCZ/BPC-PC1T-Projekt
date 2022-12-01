
#define MAX_LINES 100
#define MAX_LENGTH 20
char data[MAX_LINES][MAX_LENGTH] = {{0}}; // 2d pole pro uchovavani radku
char otazky[MAX_LINES][MAX_LENGTH] = {{0}};

void Open_File(char *filename)
{
    FILE *file;
    file = fopen(filename, "r"); // otevreni souboru
    if (file == NULL)            // kontrola jestli existuje
    {
        printf("no such file.");
    }

    int line = 0; // pocitani radku

    while (!feof(file) && !ferror(file)) // pokud neni end of file nebo chyba
    {
        if (fgets(data[line], MAX_LENGTH, file) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    fclose(file); // zavreni souboru

    // GetData(); Zeptani se na udaje o uzivateli

   
}