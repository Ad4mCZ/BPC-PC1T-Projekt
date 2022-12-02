#include <gtk/gtk.h>
#include "login_box_check.h"
#include "on_confirm_button_clicked.h"
#include "open_file.h"
#include "on_next_button_clicked.h"

GtkWidget *window;
GtkWidget *Second_window;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main_Window"));
    Family_name = GTK_ENTRY(gtk_builder_get_object(builder, "Family_Name"));
    Given_name = GTK_ENTRY(gtk_builder_get_object(builder, "Given_Name"));
    Confirm_button = GTK_WIDGET(gtk_builder_get_object(builder, "Confirm_Button"));
    Test_select = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Test_Select"));
    Second_window = GTK_WIDGET(gtk_builder_get_object(builder, "Second_Window"));
    Radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
    Radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
    Radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
    Radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
    Otazka_label = GTK_WIDGET(gtk_builder_get_object(builder, "Otazka_Label"));
    Radio_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label1"));
    Radio_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label2"));
    Radio_label3 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label3"));
    Radio_label4 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label4"));
    age = GTK_ENTRY(gtk_builder_get_object(builder, "Age"));
    Gender_select = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Gender"));
    Login_box = GTK_WIDGET(gtk_builder_get_object(builder, "Login_Box"));

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    gtk_builder_connect_signals(builder, NULL);

    g_timeout_add(500, (GSourceFunc)Check, NULL);
    Open_File("questions.txt");
    g_object_unref(G_OBJECT(builder));
    gtk_widget_show(window);

    gtk_main();

    return 0;
}
