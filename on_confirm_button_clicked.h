#include "open_file.h"

void on_Confirm_Button_clicked(GtkButton *Confirm_Button, GtkWidget *Popup_Confirm)
{

        int response;
        response = gtk_dialog_run(GTK_DIALOG(Popup_Confirm));
        if (response == 0)
        {
                gtk_widget_hide(Popup_Confirm);
        }
        else
        {
                gtk_widget_hide(Popup_Confirm);
        }
}

void on_Popup_Yes_clicked_second(GtkButton *Popup_Yes, GtkWidget *Second_window)
{
        if (selected_test[0] == '1')
        {
                Open_File("questions.txt");
                gtk_widget_show(Second_window);
        }
}
void on_Popup_Yes_clicked_third(GtkButton *Popup_Yes, GtkWidget *Third_window)
{
        if (selected_test[0] == '2')
        {
                Open_File("fyzika_test.txt");
                gtk_widget_show(Third_window);
        }
}
void on_Popup_Yes_clicked_fourth(GtkButton *Popup_Yes, GtkWidget *Fourth_window)
{
        if (selected_test[0] == '3')
        {
                Open_File("elektro_test.txt");
                gtk_widget_show(Fourth_window);
        }
}
void on_Popup_Yes_clicked(GtkButton *Popup_Yes, GtkWidget *window)
{
        gtk_widget_hide(window);
}