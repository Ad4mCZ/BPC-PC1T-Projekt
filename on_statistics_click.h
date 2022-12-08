void on_Statistics_Button_clicked(GtkButton *Statistics_Button, GtkWidget *Statistics_Window)
{
    gtk_widget_hide(window);
    gtk_widget_show(Statistics_Window);
}
char stat_math[MAX_LINES][MAX_LENGTH] = {{0}}; // 2d pole pro uchovavani radku
char stat_fyz[MAX_LINES][MAX_LENGTH] = {{0}};  // 2d pole pro uchovavani radku
char stat_ele[MAX_LINES][MAX_LENGTH] = {{0}};  // 2d pole pro uchovavani radku
void on_Statistics_Window_show(GtkWidget *Statistics_Window)
{
    FILE *load;
    load = fopen("stats_math.txt", "r");
    int line = 0; // pocitani radku

    while (!feof(load) && !ferror(load)) // pokud neni end of file nebo chyba
    {
        if (fgets(stat_math[line], MAX_LENGTH, load) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    float procenta;
    for (int i = 0; i < line; i++)
    {
        procenta += atof(stat_math[i]);
    }
    char percent[10];
    char lines[20];
    procenta = procenta / line * 100;
    sprintf(percent, "%0.2lf %%", procenta);
    sprintf(lines, "Počet testů: %d", line);
    gtk_label_set_text(GTK_LABEL(Percent_mat), percent);
    gtk_label_set_text(GTK_LABEL(Tests_mat), lines);
    line = 0;
    procenta = 0;
    fclose(load); // zavreni souboru

    load = fopen("stats_fyz.txt", "r");

    while (!feof(load) && !ferror(load)) // pokud neni end of file nebo chyba
    {
        if (fgets(stat_fyz[line], MAX_LENGTH, load) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    for (int i = 0; i < line; i++)
    {
        procenta += atof(stat_fyz[i]);
    }
    procenta = procenta / line * 100;
    sprintf(percent, "%0.2lf %%", procenta);
    sprintf(lines, "Počet testů: %d", line);
    gtk_label_set_text(GTK_LABEL(Percent_fyz), percent);
    gtk_label_set_text(GTK_LABEL(Tests_fyz), lines);
    line = 0;
    procenta = 0;
    fclose(load); // zavreni souboru    FILE *load;
    load = fopen("stats_elektro.txt", "r");

    while (!feof(load) && !ferror(load)) // pokud neni end of file nebo chyba
    {
        if (fgets(stat_ele[line], MAX_LENGTH, load) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    for (int i = 0; i < line; i++)
    {
        procenta += atof(stat_ele[i]);
    }
    procenta = procenta / line * 100;
    sprintf(percent, "%0.2lf %%", procenta);
    sprintf(lines, "Počet testů: %d", line);
    gtk_label_set_text(GTK_LABEL(Percent_ele), percent);
    gtk_label_set_text(GTK_LABEL(Tests_ele), lines);
    line = 0;
    procenta = 0;
    fclose(load); // zavreni souboru
}