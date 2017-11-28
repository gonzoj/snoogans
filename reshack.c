/*
 * Copyright (C) 2014 gonzoj
 *
 * Please check the CREDITS file for further information.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "d2pointers.h"

static void set_viewing_mode(int mode) {
	if (mode >= 0 && mode <= 3) *p_D2CLIENT_crop = mode;
}

static void set_resolution(int x, int y) {
	*p_D2CLIENT_width = *p_D2CLIENT_size_x1 = *p_D2CLIENT_size_x2 = x;
	*p_D2CLIENT_height = *p_D2CLIENT_size_y1 = y;
	*p_D2CLIENT_map_x = x;
	*p_D2CLIENT_map_y = y - 40;
}

void switch_resolution(int width, int height) {
	set_viewing_mode(0);
	D2WIN_set_resolution_mode(3);
	set_resolution(width, height);
	D2CLIENT_resize();
}
