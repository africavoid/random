#include <iostream>
#include <string>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>

// This is just declaring the functions above the main function
static void tty_info ();
static void center (std::string text_to_center);

int main (int argc, char *argv[])
{
	if (!strcmp("-v", argv[1]))
	{
		// For more verbose output
		tty_info();
		return 0;
	}else if (!strcmp("-n", argv[1]))
	{
		std::cout << "Normal Mode\n\n";	
	}

	// Outputs terminal info like resolution 	
	std::string input;	
	
	// Getting a string to center
	std::cout << "Enter A String: ";
	std::cin >> input;
        center(input);
	return 0;
}

static void center (std::string text_to_center)
{
	// Centers text you give it 
	struct winsize win;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	
	int x = win.ws_row;
	int y = win.ws_col;	
	
	// Prints a empty space until center = half of y	
	for (int center = 0; center != y/2; center++)
	{
		std::cout << " "; 
	}
	std::cout << text_to_center << std::endl; 
}

static void tty_info ()
{
	// Gets maximum number of rows and colums of screen
	struct winsize win;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	
	std::cout << "X = " << win.ws_row   << std::endl;
	std::cout << "Y = " << win.ws_col   << std::endl;	
	std::cout << "X Center = " << win.ws_row/2 << std::endl;
	std::cout << "Y Center = " << win.ws_col/2 << std::endl;	
	std::cout << "Terminal Size = "<< win.ws_col << " x " << win.ws_row << std::endl;

	int x = win.ws_row;
	int y = win.ws_col;
}
