#include <stdbool.h>

int check = 0;
const gchar *selected;

gboolean on_Given_Name_key_press_event(GtkWidget *Given_Name, GdkEventKey *event)
{

  if (event->type == GDK_KEY_PRESS && check == 0 && selected != 0)
  {

    check++;
  }

  return 0;
}

gboolean on_Family_Name_key_press_event(GtkWidget *Family_Name, GdkEventKey *event, GtkButton *Confirm_Button)

{

  if (event->type == GDK_KEY_PRESS && check != 0 && selected != 0)
  {
    check++;
    gtk_widget_set_sensitive(GTK_WIDGET(Confirm_Button), TRUE);
  }

  return 0;
}

void on_Test_select_changed(GtkComboBox *Test_Select, GtkButton *Confirm_Button)
{

  selected = gtk_combo_box_get_active_id(GTK_COMBO_BOX(Test_Select));
  g_print("%s", selected);

  if (check != 0 && selected != NULL)
  {

    gtk_widget_set_sensitive(GTK_WIDGET(Confirm_Button), TRUE);
  }
}
