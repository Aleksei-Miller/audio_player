#pragma once
#pragma comment(lib, "winmm.lib")

#include <string.h>

#include <windows.h>
#include <mmsystem.h>

//MCI
char mci_error_text[255] = {0};

bool mciSendCmd(const char *command)
{
	int mci_error = mciSendString(command, NULL, 0, 0);
 
	if (mci_error != 0)
	{
		mciGetErrorString(mci_error, mci_error_text, sizeof(mci_error_text));

		return false;
	}

	return true;
}

bool play(const char *path)
{
	char command[255] = {0};

	strcpy(command, "play ");

	strcat(command, path);

	if (!mciSendCmd(command))
		return false;

	return true;
}

bool pause(const char *path)
{
	char command[255] = {0};

	strcpy(command, "pause ");
	strcat(command, path);

	if (!mciSendCmd(command))
		return false;

	return true;
}

