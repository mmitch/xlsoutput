/*
 * xlsxinerama - display Xinerama screen configuration
 * Copyright (C) 2011  Christian Garbs <mitch@cgarbs.de>
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
#include <X11/extensions/Xinerama.h>

int
main(void)
{
  Display *dpy;
  XineramaScreenInfo *xinescreens;
  int xinescreencount;
  unsigned int i;

  if (!(dpy = XOpenDisplay(0))) {
    fprintf(stderr, "can't open X display\n");
    return 1;
  }

  if (! XineramaIsActive(dpy)) {
    fprintf(stderr, "Xinerama is not active\n");
    return 1;
  }

  xinescreens = XineramaQueryScreens(dpy, &xinescreencount);

  for(i = 0; i < xinescreencount; i++) {
    printf("screen #%d from (%5d,%5d) to (%5d,%5d) size (%5dx%5d)\n",
	   i,
	   xinescreens[i].x_org,
	   xinescreens[i].y_org,
	   xinescreens[i].x_org + xinescreens[i].width - 1,
	   xinescreens[i].y_org + xinescreens[i].height - 1,
	   xinescreens[i].width,
	   xinescreens[i].height
	   );

  }


  return 0;
}
