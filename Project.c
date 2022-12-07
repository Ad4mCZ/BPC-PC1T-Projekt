#include <gtk/gtk.h>
#include "login_box_check.h"
#include "on_confirm_button_clicked.h"
#include "on_next_button_clicked.h"
#include "on_next_button_clicked_third.h"
#include "init.h"
#include <time.h>

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Project.glade", NULL);

    Init();

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    gtk_builder_connect_signals(builder, NULL);

    g_timeout_add(500, (GSourceFunc)Check, NULL);

    g_object_unref(G_OBJECT(builder));
    gtk_widget_show(window);
    gtk_main();

    return 0;
}
