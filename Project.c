#include <gtk/gtk.h>
#include "on_confirm_button_clicked.h"
#include "on_key_press_check.h"

GtkWidget *Family_name;
GtkWidget *Given_name;
GtkWidget *Confirm_button;
GtkWidget *Test_select;
GtkWidget *window;
GtkWidget *Second_window;

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
    // notebook = GTK_WIDGET(gtk_builder_get_object(builder, "notebook"));

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    gtk_builder_connect_signals(builder, NULL);
    selected = gtk_combo_box_get_active_id(GTK_COMBO_BOX(Test_select));

    g_object_unref(G_OBJECT(builder));
    gtk_widget_show(window);
    gtk_main();

    return 0;
};
