#include "open_file.h"

void on_Confirm_Button_clicked(GtkButton *Confirm_Button, GtkWidget *Popup_Confirm) // vypnuti popup dialogu
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

void on_Popup_Yes_clicked_second(GtkButton *Popup_Yes, GtkWidget *Second_window) // nacteni prvniho testu
{
        if (selected_test[0] == '1')
        {
                Open_File("matika_test.txt");
                gtk_widget_show(Second_window);
        }
}
void on_Popup_Yes_clicked_third(GtkButton *Popup_Yes, GtkWidget *Third_window) // nacteni druheho testu
{
        if (selected_test[0] == '2')
        {
                Open_File("fyzika_test.txt");
                gtk_widget_show(Third_window);
        }
}
void on_Popup_Yes_clicked_fourth(GtkButton *Popup_Yes, GtkWidget *Fourth_window) // nacteni tretiho testu
{
        if (selected_test[0] == '3')
        {
                Open_File("elektro_test.txt");
                gtk_widget_show(Fourth_window);
        }
}
void on_Popup_Yes_clicked(GtkButton *Popup_Yes, GtkWidget *window) // zavreni main okna pokud ano
{
        gtk_widget_hide(window);
}