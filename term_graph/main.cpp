#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

// This is just declaring the functions above the main function
static void main_max ();
static void main_draw ();

int main (int argc, char *argv[])
{	
	std::cout << "Terminal, Graphics" << std::endl;
	
	main_max();
	return 0;
}

static void main_draw (int x, int y)
{
	int x_half = x/2;
	int y_half = y/2;
	
	std::cout << "Half Rows " << x_half << std::endl;
	std::cout << "Half Colums " << y_half << std::endl;	 	

	for (int center = 0; center < x_half; center++)
	{
		std::cout << " ";
	} 
	std::cout << "Hello, World" << std::endl;
}

static void main_max ()
{
	// Gets maximum number of rows and colums of screen
	struct winsize win;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	
	std::cout << "Rows " << win.ws_row << std::endl;
	std::cout << "Colums " << win.ws_col << std::endl;	
	
	int x = win.ws_row;
	int y = win.ws_col;
	
	// Passing rows and colums to x and y in draw
	main_draw(win.ws_row, win.ws_col);
}
