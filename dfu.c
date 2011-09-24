#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "libirecovery.h"

int device_iboot_mode;

int respond_dfu_counters() {
	if (device_iboot_mode != kDfuMode)
		start_cli();
}

int start_cli() {
	printf("\nPress 'enter' when/if the device is powered off...\n\n");
	getchar();

#ifdef _WIN32
system("Taskkill IM \ iTunes.exe");
#endif
 
	/* This is the important part ;P */

	printf("Plug in the device while holding the home button\n");

	do {
		if (client->mode == kRecoveryMode1 || client->mode == kRecoveryMode2 || client->mode == kRecoveryMode3 || client->mode == kRecoveryMode4) {
			printf("Home home & power\n");
			break;
		}

	} while (client->mode != kRecoveryMode1 || client->mode != kRecoveryMode2 || client->mode != kRecoveryMode3 || client->mode != kRecoveryMode4);

	/* Second part of the walkthrough, get's device out of recovery and into DFU */

	do {
		if (client-> == NULL) {
			printf("Release power but KEEP holding home...\n");
			break;
		}

	} while (client-> != NULL);

	/* The final check; check for DFU client */

	while (client->mode != kDfuMode) {
		/* Return NULL*/
		if (client->mode == kDfuMode)
			break;		
	} 

	printf("You are now in DFU!\n");

return 0;
			

}