// ResChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>


int main(int argc, char** argv)
{
	if (argc != 4)
	{
		printf("Usage: %s horizontal vertical refresh\r\n", argv[0]);
		printf("NOTE: There is no sanity checking! You may break something!\r\n");
		return 1;
	}

	DEVMODE devmode;
	SecureZeroMemory(&devmode, sizeof(devmode));

	int horiz = atoi(argv[1]);
	int vert = atoi(argv[2]);
	int refresh = atoi(argv[3]);
	
	devmode.dmPelsWidth = horiz;
	devmode.dmPelsHeight = vert;
	devmode.dmDisplayFrequency = refresh;
	devmode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
	devmode.dmSize = sizeof(devmode);
	ChangeDisplaySettings(&devmode, 0);
	return 0;
}

