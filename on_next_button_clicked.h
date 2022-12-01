
GtkWidget *Radio1;
GtkWidget *Radio2;
GtkWidget *Radio3;
GtkWidget *Radio4;
GtkWidget *Otazka_label;
GtkWidget *Radio_label1;
GtkWidget *Radio_label2;
GtkWidget *Radio_label3;
GtkWidget *Radio_label4;

void on_Next_button_clicked(GtkButton *Next_button, GtkBox *Test_Box)
{
   for (int i = 0; i=5; i++)
   {
    gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[i]);
       gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)odpovedi[i]);
    gtk_label_set_text(GTK_LABEL(Radio_label2), (const gchar *)odpovedi[i]);
    gtk_label_set_text(GTK_LABEL(Radio_label3), (const gchar *)odpovedi[i]);        //TODO ADAM
    gtk_label_set_text(GTK_LABEL(Radio_label4), (const gchar *)odpovedi[i]);
   }
   
}