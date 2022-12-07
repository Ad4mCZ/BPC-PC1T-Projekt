#include <gtk/gtk.h>
#include "login_box_check.h"
#include "on_confirm_button_clicked.h"
#include "on_next_button_clicked.h"
#include "on_next_button_clicked_third.h"
#include "on_next_button_clicked_fourth.h"
#include "init.h"
#include "on_repeat_button_clicked.h"
#include <time.h>

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv); // inicializace gtk

    builder = gtk_builder_new();                               // builder widgetu
    gtk_builder_add_from_file(builder, "Project.glade", NULL); // link builderu k xml stylu

    Init(); // inicializace promennych

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK); // zaznamenavani klaves
    gtk_builder_connect_signals(builder, NULL);

    g_timeout_add(500, (GSourceFunc)Check, NULL); // kontrola kazdych 500ms Check (vyplnene udaje)

    g_object_unref(G_OBJECT(builder)); // dereference builderu
    gtk_widget_show(window);           // nacteni hlavniho okna
    gtk_main();

    return 0;
}
