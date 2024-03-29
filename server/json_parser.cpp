#include "json_parser.h"
#include <sstream>

JsonParser::JsonParser() {
  Json::CharReaderBuilder reader_builder;
  Json::StreamWriterBuilder writer_builder;
  reader_ = std::unique_ptr<Json::CharReader>(reader_builder.newCharReader());
  writer_ = std::unique_ptr<Json::StreamWriter>(writer_builder.newStreamWriter());
}

std::shared_ptr<Json::Value> JsonParser::parse(const char* data, int size) {
  std::shared_ptr<Json::Value> value = std::make_shared<Json::Value>();

  if (reader_->parse(data, data + size - 1, value.get(), nullptr)) {
    return value;
  } else {
    return nullptr;
  }
}
