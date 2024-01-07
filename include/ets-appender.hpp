#pragma once

#include "logging.hpp"

namespace esp32m
{

/**
 * Sends output to default UART logger using ets_write_char_uart(...)
 */
class ETSAppender : public FormattingAppender
{
  public:
    ETSAppender(const ETSAppender&) = delete;
    static ETSAppender& instance();
    const char* name() override {
      return "ETSAppender";
    }
  private:
    ETSAppender() {}

  protected:
    virtual bool append(const char* message);
};

}