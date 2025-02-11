#include <string.h>

#include "ets-appender.hpp"
#include "rom/ets_sys.h"

namespace esp32m {

ETSAppender& ETSAppender::instance()
{
  static ETSAppender i;
  return i;
}

bool ETSAppender::append(const char* message)
{
  if (message)
  {
    auto l = strlen(message);
    for (auto i = 0; i < l; i++) {
      ets_printf("%c", message[i]);
    }
    ets_printf("%c", '\n');
  }

  return true;
}

}