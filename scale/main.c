#include <gtk/gtk.h>

static GtkWidget *button1;
static GtkWidget *button2;
static GtkWidget *quit;
static GtkWidget *hscale;
static GtkWidget *vscale;

/* Our new improved callback.  The data passed to this function
 * is printed to stdout. */
static void callback( GtkWidget *widget,
                      gpointer   data )
{
	if(widget == button1)
	{
		gtk_widget_hide(button1);
		gtk_widget_show(button2);
	}
	else if(widget == button2)
	{
		gtk_widget_hide(button2);
		gtk_widget_show(button1);
	}
		
	g_print ("Hello again - %s was pressed\n", (gchar *) data);
}

/* The quit routine. */
static void callback_quit( GtkWidget *widget,
                  gpointer   data)
{
	g_print ("Quitting.");
	gtk_main_quit ();
}

/* another callback */
static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
	gtk_main_quit ();
	return FALSE;
}

int main( int   argc,
          char *argv[] )
{
	/* GtkWidget is the storate type for widgets */
	GtkWidget *window;
	GtkWidget *table;

	/* This is called in all GTK applications.  Argument are parsed
	 * from the coommand line and are returned to the application. */
	gtk_init (&argc, &argv);

	/* Create a new window */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	/* This is a new call, which just sets the title of our
	 * new window to "Hello buttons!" */
	gtk_window_set_title (GTK_WINDOW (window), "Table Demo!");

	/* Here we just set a handler for delete_event that immediately
	 * exits GTK. */
	g_signal_connect (G_OBJECT (window), "delete_event",
                      G_CALLBACK (delete_event), NULL);

	/* Set the border width of the Window. */
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);

	/* Create the table */
	table = gtk_table_new( 4, 4, TRUE);

	/* Add the table to our window */
	gtk_container_add (GTK_CONTAINER (window), table );

	/* Set the row and column spacings */
	gtk_table_set_row_spacings( GTK_TABLE(table), 10);
	gtk_table_set_col_spacings( GTK_TABLE(table), 20);

	button1 = gtk_button_new_with_label ("Button 1");
	g_signal_connect (G_OBJECT (button1), "clicked",
                      G_CALLBACK (callback), (gpointer) "button 1");
	gtk_table_attach_defaults( GTK_TABLE(table), button1, 0, 1, 0, 1 );
	gtk_widget_show (button1);

	button2 = gtk_button_new_with_label ("Button 2");
	g_signal_connect (G_OBJECT (button2), "clicked",
                      G_CALLBACK (callback), (gpointer) "button 2");
	gtk_table_attach_defaults( GTK_TABLE(table), button2, 1, 2, 0, 1 );
	/* gtk_widget_show (button2); */


	/* Ron's edit:
	 * Add a quit button */
	quit = gtk_button_new_with_label ("Quit");
	g_signal_connect (G_OBJECT (quit), "clicked",
                      G_CALLBACK (callback_quit), NULL);
	gtk_table_attach_defaults( GTK_TABLE(table), quit, 0, 2, 1, 2 );
	gtk_widget_show (quit);

	hscale = gtk_hscale_new_with_range (0, 100, 1);
	vscale = gtk_vscale_new_with_range (0, 100, 1);
	vscale = gtk_vscale_new (gtk_range_get_adjustment( GTK_RANGE (hscale)));

	gtk_table_attach_defaults( GTK_TABLE(table), hscale, 0, 2, 2, 4);
	gtk_table_attach_defaults( GTK_TABLE(table), vscale, 2, 4, 0, 4);
	gtk_widget_show (hscale);
	gtk_widget_show (vscale);
	

	/* The order in which we show the buttons is not really important, but I
	 * recommend showing the window last, so it all pops up at once. */

	gtk_widget_show (table);

	gtk_widget_show (window);

	/* Rest in gtk_main and wait for the fun to begin! */
	gtk_main ();

	return 0;
}

