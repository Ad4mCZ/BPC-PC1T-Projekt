GtkWidget *Otazka_label_2;
GtkButton *Next_button_2;
GtkButton *Previous_button_2;
int selectedChoice;
GtkComboBox *odpovedi_2;

void on_Third_Window_show(GtkWidget *Third_Window, GtkBox *Text_Box_2)
{

    start = time(NULL);
    char tmpOdpovedi[sizeof(odpovedi) / sizeof(odpovedi[0])][sizeof(odpovedi[0]) / sizeof(char)] = {{0}};
    for (int i = 0; i < sizeof(tmpOdpovedi) / sizeof(tmpOdpovedi[0]); i++)
    {
        if (odpovedi[i][0] == '!')
        {
            for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
            {
                tmpOdpovedi[i][j] = odpovedi[i][j + 1];
            }
        }
        else
        {
            for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
            {
                tmpOdpovedi[i][j] = odpovedi[i][j];
            }
        }
    }
    gtk_label_set_text(GTK_LABEL(Otazka_label_2), (const gchar *)otazky[0]);
}

void on_Next_Button_2_clicked(GtkButton *Next_Button_2, GtkWidget *Third_Window)
{
    const gchar *selected = gtk_combo_box_get_active_id(odpovedi_2);
    if (selected[0] == '0')
    {
        selectedChoice = 0;
    }
    if (selected[0] == '1')
    {
        selectedChoice = 1;
    }
    for (int i = 0, index = 0; i < sizeof(SpravneOdpovedi) / sizeof(SpravneOdpovedi[0]); i++) // ulozeni spravnych odpoved do SpravneOdpovedi
    {
        if (odpovedi[i][0] == '!')
        {
            for (int j = 0; j < (sizeof(SpravneOdpovedi[0]) / sizeof(char)) - 1; j++)
            {
                SpravneOdpovedi[index][j] = odpovedi[i][j + 1];
            }
            index++;
        }
    }
    switch (selectedChoice)
    {
    case 1:
        strcpy(userAnswers[currentQuestion], "1");
        break;

    case 0:
        strcpy(userAnswers[currentQuestion], "0");
        break;

    default:
        break;
    }

    if (otazky[currentQuestion + 1][0] != '\0') // prepis odpovedi pro vypis bez vykricniku
    {
        char tmpOdpovedi[sizeof(odpovedi) / sizeof(odpovedi[0])][sizeof(odpovedi[0]) / sizeof(char)] = {{0}};
        for (int i = 0; i < sizeof(tmpOdpovedi) / sizeof(tmpOdpovedi[0]); i++)
        {
            if (odpovedi[i][0] == '!')
            {
                for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
                {
                    tmpOdpovedi[i][j] = odpovedi[i][j + 1];
                }
            }
            else
            {
                for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
                {
                    tmpOdpovedi[i][j] = odpovedi[i][j];
                }
            }
        }
        currentQuestion += 1;

        gtk_label_set_text(GTK_LABEL(Otazka_label_2), (const gchar *)otazky[0 + currentQuestion]); // posun a vypis na dalsi serii otazky

        gtk_widget_set_sensitive(GTK_WIDGET(Previous_button_2), TRUE);
    }
    int body = 0;
    if (strcmp(gtk_button_get_label(Next_button_2), "konec") == 0)
    {

        for (int i = 0; i < sizeof(otazky) / sizeof(otazky[0]); i++)
        {
            if (SpravneOdpovedi[i][0] != '\0' && (strcmp(SpravneOdpovedi[i], userAnswers[i]) == 0))
            {
                body++;
            }
        }
        end = time(NULL);
        double timedouble = difftime(end, start);
        gtk_widget_show(Result_window);
        gtk_widget_hide(Third_Window);
        char bodyArray[40];
        char percent[30];
        char time[50];
        double Percent = (double)body / ((float)currentQuestion + 1);
        sprintf(bodyArray, "počet správných odpovědí: %d", body);
        sprintf(percent, "%0.2lf %%", Percent * 100);
        sprintf(time, "Test ti zabral %0.0f sekund", timedouble);
        gtk_label_set_text(GTK_LABEL(Correct_label), (const gchar *)bodyArray);
        gtk_label_set_text(GTK_LABEL(Percent_label), (const gchar *)percent);
        gtk_progress_bar_set_fraction(Correct_bar, Percent);
        gtk_label_set_text(GTK_LABEL(Correctwrong), (const gchar *)time);
        FILE *stats;
        stats = fopen("stats_fyz.txt", "a+");
        fprintf(stats, "\n%f", Percent);
        fclose(stats);
    }
    if (otazky[currentQuestion + 1][0] == '\0') // check jestli posledni otazka
    {
        gtk_button_set_label(Next_button_2, "konec");
    }
}

void on_Previous_Button_2_clicked(GtkButton *Previous_button_2, GtkWidget *Third_Window)
{
    if (currentQuestion != 0)
    {
        char tmpOdpovedi[sizeof(odpovedi) / sizeof(odpovedi[0])][sizeof(odpovedi[0]) / sizeof(char)] = {{0}};
        for (int i = 0; i < sizeof(tmpOdpovedi) / sizeof(tmpOdpovedi[0]); i++)
        {
            if (odpovedi[i][0] == '!')
            {
                for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
                {
                    tmpOdpovedi[i][j] = odpovedi[i][j + 1];
                }
            }
            else
            {
                for (int j = 0; j < (sizeof(tmpOdpovedi[0]) / sizeof(char)) - 1; j++)
                {
                    tmpOdpovedi[i][j] = odpovedi[i][j];
                }
            }
        }
        currentQuestion -= 1;
        gtk_label_set_text(GTK_LABEL(Otazka_label_2), (const gchar *)otazky[0 + currentQuestion]);

        if (otazky[currentQuestion + 1][0] != '\0')
        {
            gtk_button_set_label(Next_button_2, "další");
        }

        if (currentQuestion == 0)
        {
            gtk_widget_set_sensitive(GTK_WIDGET(Previous_button_2), FALSE);
        }
    }
}
// random koment