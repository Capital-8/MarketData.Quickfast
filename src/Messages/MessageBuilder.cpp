// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/MessageBuilder.h>
#include <quickfast/Messages/FieldInt64.h>
#include <quickfast/Messages/FieldUInt64.h>
#include <quickfast/Messages/FieldInt32.h>
#include <quickfast/Messages/FieldUInt32.h>
#include <quickfast/Messages/FieldInt16.h>
#include <quickfast/Messages/FieldUInt16.h>
#include <quickfast/Messages/FieldInt8.h>
#include <quickfast/Messages/FieldUInt8.h>
#include <quickfast/Messages/FieldDecimal.h>
#include <quickfast/Messages/FieldString.h>
#include <quickfast/Messages/FieldAscii.h>
#include <quickfast/Messages/FieldUtf8.h>
#include <quickfast/Messages/FieldByteVector.h>

using namespace QuickFAST;
using namespace Messages;

MessageBuilder::MessageBuilder()
: vout_(0)
{
}

void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const int64 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldInt64::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const uint64 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldUInt64::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const int32 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldInt32::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const uint32 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldUInt32::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const int16 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldInt16::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const uint16 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldUInt16::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const int8 value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << std::hex << (0xFF & (static_cast<unsigned short>(value))) << std::dec << std::endl;
  }
  FieldCPtr field(FieldInt8::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const uchar value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << std::hex << static_cast<unsigned short>(value) << std::dec << std::endl;
  }
  FieldCPtr field(FieldUInt8::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const Decimal& value)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << value << std::endl;
  }
  FieldCPtr field(FieldDecimal::create(value));
  addField(identity, field);
}
void MessageBuilder::addValue(FieldIdentityCPtr & identity, ValueType::Type type, const unsigned char * value, size_t length)
{
  if(vout_)
  {
    (*vout_)
      << "Assign: " << identity->name() << " = " << std::string(reinterpret_cast<const char *>(value), length) << std::endl;
  }
  switch (type)
  {
  case ValueType::ASCII:
    addField(identity, FieldAscii::create(value, length));
    break;
  case ValueType::UTF8:
    addField(identity, FieldUtf8::create(value, length));
    break;
  case ValueType::BYTEVECTOR:
    addField(identity, FieldByteVector::create(value, length));
    break;
  default:
    addField(identity, FieldString::create(value, length));
  }
}
