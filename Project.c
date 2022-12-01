#include <gtk/gtk.h>
#include "on_confirm_button_clicked.h"
#include "on_key_press_check.h"
#include "open_file.h"

GtkWidget *Family_name;
GtkWidget *Given_name;
GtkWidget *Confirm_button;
GtkWidget *Test_select;
GtkWidget *window;
GtkWidget *Second_window;
GtkWidget *Radio1;
GtkWidget *Radio2;
GtkWidget *Radio3;
GtkWidget *Radio4;
GtkWidget *Otazka_label;
GtkWidget *Radio_label1;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main_Window"));
    Family_name = GTK_WIDGET(gtk_builder_get_object(builder, "Family_Name"));
    Given_name = GTK_WIDGET(gtk_builder_get_object(builder, "Given_Name"));
    Confirm_button = GTK_WIDGET(gtk_builder_get_object(builder, "Confirm_Button"));
    Test_select = GTK_WIDGET(gtk_builder_get_object(builder, "Test_Select"));
    Second_window = GTK_WIDGET(gtk_builder_get_object(builder, "Second_Window"));
    Radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
    Radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
    Radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
    Radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
    Otazka_label = GTK_WIDGET(gtk_builder_get_object(builder, "Otazka_Label"));
    Radio_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label1"));

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    gtk_builder_connect_signals(builder, NULL);
    selected = gtk_combo_box_get_active_id(GTK_COMBO_BOX(Test_select));

  

   Open_File("questions.txt");

    // GetData(); Zeptani se na udaje o uzivateli

    for (int i = 0, indexOtazky = 0; i < line; i++) // prochazeni dat
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            if (data[i][j] == '[')
            {
                for (int k = 1; data[i][j + k] != ']'; k++)
                {
                    otazky[indexOtazky][k - 1] = data[i][j + k];
                }
                indexOtazky++;
            }
        }
    }
    gtk_label_set_text(GTK_LABEL(Otazka_label), (const gchar *)otazky[0]);
    gtk_label_set_text(GTK_LABEL(Radio_label1), (const gchar *)otazky[0]);
    g_object_unref(G_OBJECT(builder));
    gtk_widget_show(window);
    gtk_main();

    return 0;
};
