#include <gtk/gtk.h>

/* Create an arra widget with the specified parameters
 * and pack it into a button */

static GtkWidget *create_arrow_button (GtkArrowType   arrow_type,
                                       GtkShadowType  shadow_type )
{
	GtkWidget *button;
	GtkWidget *arrow;

	button = gtk_button_new ();
	arrow = gtk_arrow_new (arrow_type, shadow_type);

	gtk_container_add (GTK_CONTAINER (button), arrow);

	gtk_widget_show (button);
	gtk_widget_show (arrow);

	return button;
}

int main (int    argc,
          char  *argv[])
{
	/* GtkWidget is the storage type for all widgets */
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *vbox, *hbox;
	GtkWidget *label;
	GtkTooltips *tooltips;

	/* Initialize the toolkit */
	gtk_init (&argc, &argv);

	/* Create a new window */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (window), "Arrow Buttons");

	/* It's a good idea to do this for all windows. */
	g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);

	/* Sets the border width of the window. */
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);

	/* Ron's edit */
	vbox = gtk_vbox_new (FALSE, 0);

	/* Create a box to hold the arrows/buttons */
	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_set_border_width (GTK_CONTAINER (hbox), 2);

	/* Create the label */
	label = gtk_label_new ("Don't forget to view the tooltips!");
	gtk_box_pack_start (GTK_BOX (vbox), label, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

	gtk_container_add (GTK_CONTAINER (window), vbox);

	/* Pack and show all our widgets */
	gtk_widget_show (label);
	gtk_widget_show (vbox);
	gtk_widget_show (hbox);

	/* Create our tooltips */
	tooltips = gtk_tooltips_new();

	button = create_arrow_button (GTK_ARROW_UP, GTK_SHADOW_IN);
	gtk_tooltips_set_tip (tooltips, button, "Up", NULL);
	gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 3);

	button = create_arrow_button (GTK_ARROW_DOWN, GTK_SHADOW_OUT);
	gtk_tooltips_set_tip (tooltips, button, "Down", NULL);
	gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 3);

	button = create_arrow_button (GTK_ARROW_LEFT, GTK_SHADOW_ETCHED_IN);
	gtk_tooltips_set_tip (tooltips, button, "Left", NULL);
	gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 3);

	button = create_arrow_button (GTK_ARROW_RIGHT, GTK_SHADOW_ETCHED_OUT);
	gtk_tooltips_set_tip (tooltips, button, "Right", NULL);
	gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 3);

	gtk_widget_show (window);

	/* Rest in gtk_main and wait for the fun to begin! */
	gtk_main ();

	return 0;
}
