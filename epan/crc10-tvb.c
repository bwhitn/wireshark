/* crc10-tvb.c
 * CRC-10 tvb routines
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"

#include <glib.h>
#include <epan/tvbuff.h>
#include <wsutil/crc10.h>
#include <epan/crc10-tvb.h>

/* update the data block's CRC-10 remainder one byte at a time */
guint16
update_crc10_by_bytes_tvb(guint16 crc10, tvbuff_t *tvb, int offset, int len)
{
    const guint8 *buf;

    tvb_ensure_bytes_exist(tvb, offset, len);  /* len == -1 not allowed */
    buf = tvb_get_ptr(tvb, offset, len);

    return update_crc10_by_bytes(crc10, buf, len);
}

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
