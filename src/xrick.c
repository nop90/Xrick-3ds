/*
 * xrick/src/xrick.c
 *
 * Copyright (C) 1998-2002 BigOrno (bigorno@bigorno.net). All rights reserved.
 *
 * The use and distribution terms for this software are contained in the file
 * named README, which can be found in the root of this distribution. By
 * using this software in any fashion, you are agreeing to be bound by the
 * terms of this license.
 *
 * You must not remove this notice, or any other, from this software.
 */

#include "system.h"
#include "game.h"

#include <SDL.h>
#ifdef _3DS
#include <3ds.h>
#endif

/*
 * main
 */
int
main(int argc, char *argv[])
{
#ifdef _3DS
	romfsInit();
	sys_init(argc, argv);
	data_setpath("romfs:/data.zip");
#else
	sys_init(argc, argv);
	if (sysarg_args_data)
		data_setpath(sysarg_args_data);
	else
		data_setpath("data.zip");
#endif
	game_run();
	data_closepath();
	sys_shutdown();
#ifdef _3DS
	romfsExit();
#endif
	return 0;
}

/* eof */
