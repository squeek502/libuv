/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "uv.h"
#include "task.h"
#include <string.h>


static void set_title(const char* title) {
  char buffer[512];
  uv_err_t err;

  err = uv_get_process_title(buffer, sizeof(buffer));
  ASSERT(UV_OK == err.code);

  err = uv_set_process_title(title);
  ASSERT(UV_OK == err.code);

  err = uv_get_process_title(buffer, sizeof(buffer));
  ASSERT(UV_OK == err.code);

  ASSERT(strcmp(buffer, title) == 0);
}


TEST_IMPL(process_title) {
  /* Check for format string vulnerabilities. */
  set_title("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s");
  set_title("new title");
  return 0;
}
