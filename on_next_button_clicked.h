GtkWidget *Radio1;
GtkWidget *Radio2;
GtkWidget *Radio3;
GtkWidget *Radio4;
GtkWidget *Otazka_label;
GtkWidget *Radio_label1;
GtkWidget *Radio_label2;
GtkWidget *Radio_label3;
GtkWidget *Radio_label4;

int nextAnswer = 0;
int nextQuestion = 0;

void on_Next_button_clicked(GtkButton *Next_button, GtkBox *Test_Box)
{

   srand(time(NULL));
   int random = rand() % 3;
   printf("%i", random);
   gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0 + nextQuestion]);
   gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)odpovedi[0 + nextAnswer]);
   gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)odpovedi[1 + nextAnswer]);
   gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)odpovedi[2 + nextAnswer]); // TODO ADAM
   gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)odpovedi[3 + nextAnswer]);
   nextAnswer += 4;
   nextQuestion += 1;
}