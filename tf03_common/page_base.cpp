#include "page_base.h"
#include <QLabel>

PageBase::PageBase()
{

}

PageBase::~PageBase() {}

void PageBase::SetCommandEchoHandler(
    std::shared_ptr<CommandEchoHandler> echo_handler) {
  echo_handler_ = echo_handler;
}

std::shared_ptr<CommandEchoHandler> PageBase::EchoHandler() {
  return echo_handler_;
}

void PageBase::Update() {
}

void PageBase::SetLabelFontCommon(QLabel* label) {
  SetWidgetFontCommon(label);
}

void PageBase::SetWidgetFontCommon(QWidget *widget) {
  widget->setFont(GetCommonFont());
}

QFont PageBase::GetCommonFont() {
  QFont font;
  font.setPointSize(10);
  return font;
}

QFont PageBase::GetLargeBoldFont() {
  QFont font;
  font.setPointSize(15);
  font.setBold(true);
  return font;
}

void PageBase::SetWidgetFontLargeBold(QWidget *widget) {
  widget->setFont(GetLargeBoldFont());
}
