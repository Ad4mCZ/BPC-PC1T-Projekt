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

int currentAnswer = 0;
int currentQuestion = 0;

void on_Second_Window_show(GtkWidget *Second_window, GtkBox *Test_Box) // vypsani prvni otazky
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

   gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0]);
   gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)tmpOdpovedi[0]);
   gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)tmpOdpovedi[1]);
   gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)tmpOdpovedi[2]);
   gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)tmpOdpovedi[3]);
}

void on_Next_button_clicked(GtkButton *Next_button, GtkBox *Test_Box)
{
   // g_print("%s", spravne_odpovedi[currentQuestion]);
   // char *spravnaOdpoved[1] = {spravne_odpovedi[currentQuestion]};
   const gchar *radio1 = {gtk_label_get_text(GTK_LABEL(Radio_label1))};
   const gchar *radio2 = {gtk_label_get_text(GTK_LABEL(Radio_label2))};
   const gchar *radio3 = {gtk_label_get_text(GTK_LABEL(Radio_label3))};
   const gchar *radio4 = {gtk_label_get_text(GTK_LABEL(Radio_label4))};

   // g_print("%s \t", *spravnaOdpoved);
   g_print(radio1);
   g_print(radio2);
   g_print(radio3);
   g_print(radio4);

   // switch (*spravnaOdpoved[1]) // NUTNO DODELAT se simonem

   if (otazky[currentQuestion + 1][0] != '\0')
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
      gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0 + currentQuestion]);
      gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)tmpOdpovedi[0 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)tmpOdpovedi[1 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)tmpOdpovedi[2 + currentAnswer]);
      gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)tmpOdpovedi[3 + currentAnswer]);

      if (otazky[currentQuestion + 1][0] == '\0')
      {
         gtk_button_set_label(Next_button, "konec");
      }

      gtk_widget_set_sensitive(GTK_WIDGET(Previous_button), TRUE);
   }
}
void on_Previous_button_clicked(GtkButton *Previous_button, GtkBox *Test_Box)
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
