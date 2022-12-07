
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
        int choice = gtk_combo_box_get_active(Test_select);
        g_print("response %i", choice);
        // g_print("Response is %s\n", response == 1 ? "Ano" : "Ne");
}

void on_Popup_Yes_clicked_add(GtkButton *Popup_Yes, GtkWidget *Second_window)
{
        gtk_widget_show(Second_window);
}

void on_Popup_Yes_clicked(GtkButton *Popup_Yes, GtkWidget *window)
{
        gtk_widget_hide(window);
}