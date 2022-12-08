GtkWidget *Radio1;
GtkWidget *Radio2;
GtkWidget *Radio3;
GtkWidget *Radio4;
GtkWidget *Otazka_label;
GtkWidget *Radio_label1;
GtkWidget *Radio_label2;
GtkWidget *Radio_label3;
GtkWidget *Radio_label4;
GtkButton *Next_button;
GtkButton *Previous_button;
GtkWidget *Correct_label;
GtkWidget *Result_window;
GtkWidget *Correctwrong;
GtkWidget *Percent_label;
GtkProgressBar *Correct_bar;
time_t start, end; // timer

int currentAnswer = 0;
int currentQuestion = 0;
int toggledRadio = 1;
char userAnswers[sizeof(otazky) / sizeof(otazky[0])][sizeof(odpovedi[0]) / sizeof(char)] = {{0}};
char SpravneOdpovedi[sizeof(otazky) / sizeof(otazky[0])][sizeof(odpovedi[0]) / sizeof(char)] = {{0}};

void on_Second_Window_show(GtkWidget *Second_Window, GtkBox *Test_Box) // vypsani prvni otazky
{
   start = time(NULL); // zapnuti timeru
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

   gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0]);
   gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)tmpOdpovedi[0]);
   gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)tmpOdpovedi[1]);
   gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)tmpOdpovedi[2]);
   gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)tmpOdpovedi[3]);
}

void on_Next_button_clicked(GtkButton *Next_button, GtkWidget *Second_Window)
{
   const gchar *radio1 = {gtk_label_get_text(GTK_LABEL(Radio_label1))}; // ulozeni radio labels do promenne
   const gchar *radio2 = {gtk_label_get_text(GTK_LABEL(Radio_label2))};
   const gchar *radio3 = {gtk_label_get_text(GTK_LABEL(Radio_label3))};
   const gchar *radio4 = {gtk_label_get_text(GTK_LABEL(Radio_label4))};

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

   switch (toggledRadio) // ukladani userAnswers pomoci radiobuttonToggled
   {
   case 1:
      strcpy(userAnswers[currentQuestion], radio1);
      break;

   case 2:
      strcpy(userAnswers[currentQuestion], radio2);
      break;

   case 3:
      strcpy(userAnswers[currentQuestion], radio3);
      break;

   case 4:
      strcpy(userAnswers[currentQuestion], radio4);
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
      currentAnswer += 4;
      currentQuestion += 1;

      gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0 + currentQuestion]); // posun a vypis na dalsi serii otazky
      gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)tmpOdpovedi[0 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)tmpOdpovedi[1 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)tmpOdpovedi[2 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)tmpOdpovedi[3 + currentAnswer]);

      gtk_widget_set_sensitive(GTK_WIDGET(Previous_button), TRUE);
   }
   int body = 0;

   if (strcmp(gtk_button_get_label(Next_button), "konec") == 0)
   {

      for (int i = 0; i < sizeof(otazky) / sizeof(otazky[0]); i++) // kontrola spravnych odpovedi
      {
         if (SpravneOdpovedi[i][0] != '\0' && (strcmp(SpravneOdpovedi[i], userAnswers[i]) == 0))
         {
            body++;
         }
      }

      end = time(NULL); // ukonceni timeru
      double timedouble = difftime(end, start);
      gtk_widget_show(Result_window); // zavreni okna a otevreni okna vysledku
      gtk_widget_hide(Second_Window);
      char bodyArray[40];
      char percent[30];
      char time[50];
      double Percent = (double)body / ((float)currentQuestion + 1);
      currentAnswer = 0;
      currentQuestion = 0;
      gtk_button_set_label(Next_button, "další");
      sprintf(bodyArray, "počet správných odpovědí: %d", body); // prevod z intu/floatu na gchar a vypis vysledku
      sprintf(percent, "%0.2lf %%", Percent * 100);
      sprintf(time, "Test ti zabral %0.0f sekund", timedouble);
      gtk_label_set_text(GTK_LABEL(Correct_label), (const gchar *)bodyArray);
      gtk_label_set_text(GTK_LABEL(Percent_label), (const gchar *)percent);
      gtk_progress_bar_set_fraction(Correct_bar, Percent);
      gtk_label_set_text(GTK_LABEL(Correctwrong), (const gchar *)time);
      FILE *stats;
      stats = fopen("stats_math.txt", "a+");
      fprintf(stats, "\n%f", Percent);
      fclose(stats);
   }

   if (otazky[currentQuestion + 1][0] == '\0') // check jestli posledni otazka
   {
      gtk_button_set_label(Next_button, "konec");
   }
}

void on_Previous_button_clicked(GtkButton *Previous_button, GtkWidget *Second_Window)
{
   if (currentQuestion != 0) // prechod na predchozi otazku
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
      currentAnswer -= 4;
      currentQuestion -= 1;
      gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0 + currentQuestion]);
      gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)tmpOdpovedi[0 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)tmpOdpovedi[1 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)tmpOdpovedi[2 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)tmpOdpovedi[3 + currentAnswer]);

      if (otazky[currentQuestion + 1][0] != '\0')
      {
         gtk_button_set_label(Next_button, "další");
      }

      if (currentQuestion == 0)
      {
         gtk_widget_set_sensitive(GTK_WIDGET(Previous_button), FALSE);
      }
   }
}
// zjisteni stavu radiobuttonu
void on_radio1_toggled(GtkToggleButton *radio1)
{
   toggledRadio = 1;
}
void on_radio2_toggled(GtkToggleButton *radio1)
{
   toggledRadio = 2;
}
void on_radio3_toggled(GtkToggleButton *radio1)
{
   toggledRadio = 3;
}
void on_radio4_toggled(GtkToggleButton *radio1)
{
   toggledRadio = 4;
}
