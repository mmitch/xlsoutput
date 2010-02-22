/*
 * xlsoutput - display status of X output devices (XRANDR)
 * Copyright (C) 2010  Christian Garbs <mitch@cgarbs.de>
 * licensed under GNU GPL v2 (or later)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

int
main(void)
{
	Display *dpy;
	XRRScreenResources *res;
	XRROutputInfo *info;
	Window root;
	int i;

	if (!(dpy = XOpenDisplay(0))) {
		fprintf(stderr, "can't open X display\n");
		return 1;
	}

	root = RootWindow(dpy, DefaultScreen(dpy));
	

	if (!(res = XRRGetScreenResources(dpy, root))) {
		fprintf(stderr, "can't get screen resources\n");
		return 1;
	}

	for (i = 0; i < res->noutput; i++) {

		if (!(info = XRRGetOutputInfo(dpy, res, res->outputs[i]))) {
			fprintf(stderr, "can't get output info #%d\n", i);
			return 1;
		}

		printf("%s %s\n", info->name,
		       (info->connection == RR_Connected ? "connected" :
			(info->connection == RR_Disconnected ? "disconnected" : "unknown")));

	}

	return 0;
}
