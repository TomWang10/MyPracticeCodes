// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Login.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Login.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Test {

namespace {

const ::google::protobuf::Descriptor* RetLogin_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RetLogin_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Login_2eproto() {
  protobuf_AddDesc_Login_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Login.proto");
  GOOGLE_CHECK(file != NULL);
  RetLogin_descriptor_ = file->message_type(0);
  static const int RetLogin_offsets_[13] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, sblx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, sjhm_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, yjxx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, jymm_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, syspm1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, syspm2_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, syspm3_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, syspm_ex_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, yybdm_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, user_id_lx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, user_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, ex_pwd_),
  };
  RetLogin_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RetLogin_descriptor_,
      RetLogin::default_instance_,
      RetLogin_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RetLogin, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RetLogin));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Login_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RetLogin_descriptor_, &RetLogin::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Login_2eproto() {
  delete RetLogin::default_instance_;
  delete RetLogin_reflection_;
}

void protobuf_AddDesc_Login_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Login.proto\022\004Test\"\326\001\n\010RetLogin\022\014\n\004sblx"
    "\030\001 \002(\005\022\014\n\004sjhm\030\002 \002(\t\022\014\n\004yjxx\030\003 \002(\t\022\014\n\004jy"
    "mm\030\004 \002(\t\022\016\n\006syspm1\030\005 \002(\t\022\016\n\006syspm2\030\006 \002(\t"
    "\022\016\n\006syspm3\030\007 \002(\t\022\020\n\010syspm_ex\030\010 \002(\t\022\014\n\004ty"
    "pe\030\t \002(\t\022\r\n\005yybdm\030\n \002(\t\022\022\n\nuser_id_lx\030\013 "
    "\002(\t\022\017\n\007user_id\030\014 \002(\t\022\016\n\006ex_pwd\030\r \002(\t", 236);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Login.proto", &protobuf_RegisterTypes);
  RetLogin::default_instance_ = new RetLogin();
  RetLogin::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Login_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Login_2eproto {
  StaticDescriptorInitializer_Login_2eproto() {
    protobuf_AddDesc_Login_2eproto();
  }
} static_descriptor_initializer_Login_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RetLogin::kSblxFieldNumber;
const int RetLogin::kSjhmFieldNumber;
const int RetLogin::kYjxxFieldNumber;
const int RetLogin::kJymmFieldNumber;
const int RetLogin::kSyspm1FieldNumber;
const int RetLogin::kSyspm2FieldNumber;
const int RetLogin::kSyspm3FieldNumber;
const int RetLogin::kSyspmExFieldNumber;
const int RetLogin::kTypeFieldNumber;
const int RetLogin::kYybdmFieldNumber;
const int RetLogin::kUserIdLxFieldNumber;
const int RetLogin::kUserIdFieldNumber;
const int RetLogin::kExPwdFieldNumber;
#endif  // !_MSC_VER

RetLogin::RetLogin()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Test.RetLogin)
}

void RetLogin::InitAsDefaultInstance() {
}

RetLogin::RetLogin(const RetLogin& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Test.RetLogin)
}

void RetLogin::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  sblx_ = 0;
  sjhm_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  yjxx_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  jymm_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  syspm1_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  syspm2_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  syspm3_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  syspm_ex_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  yybdm_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  user_id_lx_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  user_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ex_pwd_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RetLogin::~RetLogin() {
  // @@protoc_insertion_point(destructor:Test.RetLogin)
  SharedDtor();
}

void RetLogin::SharedDtor() {
  if (sjhm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sjhm_;
  }
  if (yjxx_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete yjxx_;
  }
  if (jymm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete jymm_;
  }
  if (syspm1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete syspm1_;
  }
  if (syspm2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete syspm2_;
  }
  if (syspm3_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete syspm3_;
  }
  if (syspm_ex_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete syspm_ex_;
  }
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (yybdm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete yybdm_;
  }
  if (user_id_lx_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete user_id_lx_;
  }
  if (user_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete user_id_;
  }
  if (ex_pwd_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete ex_pwd_;
  }
  if (this != default_instance_) {
  }
}

void RetLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RetLogin::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RetLogin_descriptor_;
}

const RetLogin& RetLogin::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Login_2eproto();
  return *default_instance_;
}

RetLogin* RetLogin::default_instance_ = NULL;

RetLogin* RetLogin::New() const {
  return new RetLogin;
}

void RetLogin::Clear() {
  if (_has_bits_[0 / 32] & 255) {
    sblx_ = 0;
    if (has_sjhm()) {
      if (sjhm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        sjhm_->clear();
      }
    }
    if (has_yjxx()) {
      if (yjxx_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        yjxx_->clear();
      }
    }
    if (has_jymm()) {
      if (jymm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        jymm_->clear();
      }
    }
    if (has_syspm1()) {
      if (syspm1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        syspm1_->clear();
      }
    }
    if (has_syspm2()) {
      if (syspm2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        syspm2_->clear();
      }
    }
    if (has_syspm3()) {
      if (syspm3_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        syspm3_->clear();
      }
    }
    if (has_syspm_ex()) {
      if (syspm_ex_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        syspm_ex_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & 7936) {
    if (has_type()) {
      if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        type_->clear();
      }
    }
    if (has_yybdm()) {
      if (yybdm_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        yybdm_->clear();
      }
    }
    if (has_user_id_lx()) {
      if (user_id_lx_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        user_id_lx_->clear();
      }
    }
    if (has_user_id()) {
      if (user_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        user_id_->clear();
      }
    }
    if (has_ex_pwd()) {
      if (ex_pwd_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        ex_pwd_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RetLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Test.RetLogin)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 sblx = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &sblx_)));
          set_has_sblx();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_sjhm;
        break;
      }

      // required string sjhm = 2;
      case 2: {
        if (tag == 18) {
         parse_sjhm:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sjhm()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->sjhm().data(), this->sjhm().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "sjhm");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_yjxx;
        break;
      }

      // required string yjxx = 3;
      case 3: {
        if (tag == 26) {
         parse_yjxx:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_yjxx()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->yjxx().data(), this->yjxx().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "yjxx");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_jymm;
        break;
      }

      // required string jymm = 4;
      case 4: {
        if (tag == 34) {
         parse_jymm:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_jymm()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->jymm().data(), this->jymm().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "jymm");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_syspm1;
        break;
      }

      // required string syspm1 = 5;
      case 5: {
        if (tag == 42) {
         parse_syspm1:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_syspm1()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->syspm1().data(), this->syspm1().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "syspm1");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_syspm2;
        break;
      }

      // required string syspm2 = 6;
      case 6: {
        if (tag == 50) {
         parse_syspm2:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_syspm2()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->syspm2().data(), this->syspm2().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "syspm2");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_syspm3;
        break;
      }

      // required string syspm3 = 7;
      case 7: {
        if (tag == 58) {
         parse_syspm3:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_syspm3()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->syspm3().data(), this->syspm3().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "syspm3");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_syspm_ex;
        break;
      }

      // required string syspm_ex = 8;
      case 8: {
        if (tag == 66) {
         parse_syspm_ex:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_syspm_ex()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->syspm_ex().data(), this->syspm_ex().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "syspm_ex");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_type;
        break;
      }

      // required string type = 9;
      case 9: {
        if (tag == 74) {
         parse_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->type().data(), this->type().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "type");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_yybdm;
        break;
      }

      // required string yybdm = 10;
      case 10: {
        if (tag == 82) {
         parse_yybdm:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_yybdm()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->yybdm().data(), this->yybdm().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "yybdm");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_user_id_lx;
        break;
      }

      // required string user_id_lx = 11;
      case 11: {
        if (tag == 90) {
         parse_user_id_lx:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_user_id_lx()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->user_id_lx().data(), this->user_id_lx().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "user_id_lx");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_user_id;
        break;
      }

      // required string user_id = 12;
      case 12: {
        if (tag == 98) {
         parse_user_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_user_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->user_id().data(), this->user_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "user_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_ex_pwd;
        break;
      }

      // required string ex_pwd = 13;
      case 13: {
        if (tag == 106) {
         parse_ex_pwd:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ex_pwd()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->ex_pwd().data(), this->ex_pwd().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "ex_pwd");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Test.RetLogin)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Test.RetLogin)
  return false;
#undef DO_
}

void RetLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Test.RetLogin)
  // required int32 sblx = 1;
  if (has_sblx()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->sblx(), output);
  }

  // required string sjhm = 2;
  if (has_sjhm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sjhm().data(), this->sjhm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sjhm");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->sjhm(), output);
  }

  // required string yjxx = 3;
  if (has_yjxx()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->yjxx().data(), this->yjxx().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "yjxx");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->yjxx(), output);
  }

  // required string jymm = 4;
  if (has_jymm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->jymm().data(), this->jymm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "jymm");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->jymm(), output);
  }

  // required string syspm1 = 5;
  if (has_syspm1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm1().data(), this->syspm1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm1");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->syspm1(), output);
  }

  // required string syspm2 = 6;
  if (has_syspm2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm2().data(), this->syspm2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm2");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->syspm2(), output);
  }

  // required string syspm3 = 7;
  if (has_syspm3()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm3().data(), this->syspm3().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm3");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->syspm3(), output);
  }

  // required string syspm_ex = 8;
  if (has_syspm_ex()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm_ex().data(), this->syspm_ex().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm_ex");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->syspm_ex(), output);
  }

  // required string type = 9;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      9, this->type(), output);
  }

  // required string yybdm = 10;
  if (has_yybdm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->yybdm().data(), this->yybdm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "yybdm");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      10, this->yybdm(), output);
  }

  // required string user_id_lx = 11;
  if (has_user_id_lx()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_id_lx().data(), this->user_id_lx().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_id_lx");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      11, this->user_id_lx(), output);
  }

  // required string user_id = 12;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_id().data(), this->user_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      12, this->user_id(), output);
  }

  // required string ex_pwd = 13;
  if (has_ex_pwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ex_pwd().data(), this->ex_pwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ex_pwd");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      13, this->ex_pwd(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Test.RetLogin)
}

::google::protobuf::uint8* RetLogin::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Test.RetLogin)
  // required int32 sblx = 1;
  if (has_sblx()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->sblx(), target);
  }

  // required string sjhm = 2;
  if (has_sjhm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sjhm().data(), this->sjhm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "sjhm");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->sjhm(), target);
  }

  // required string yjxx = 3;
  if (has_yjxx()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->yjxx().data(), this->yjxx().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "yjxx");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->yjxx(), target);
  }

  // required string jymm = 4;
  if (has_jymm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->jymm().data(), this->jymm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "jymm");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->jymm(), target);
  }

  // required string syspm1 = 5;
  if (has_syspm1()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm1().data(), this->syspm1().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm1");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->syspm1(), target);
  }

  // required string syspm2 = 6;
  if (has_syspm2()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm2().data(), this->syspm2().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm2");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->syspm2(), target);
  }

  // required string syspm3 = 7;
  if (has_syspm3()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm3().data(), this->syspm3().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm3");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->syspm3(), target);
  }

  // required string syspm_ex = 8;
  if (has_syspm_ex()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->syspm_ex().data(), this->syspm_ex().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "syspm_ex");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->syspm_ex(), target);
  }

  // required string type = 9;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        9, this->type(), target);
  }

  // required string yybdm = 10;
  if (has_yybdm()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->yybdm().data(), this->yybdm().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "yybdm");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->yybdm(), target);
  }

  // required string user_id_lx = 11;
  if (has_user_id_lx()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_id_lx().data(), this->user_id_lx().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_id_lx");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        11, this->user_id_lx(), target);
  }

  // required string user_id = 12;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->user_id().data(), this->user_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "user_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        12, this->user_id(), target);
  }

  // required string ex_pwd = 13;
  if (has_ex_pwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ex_pwd().data(), this->ex_pwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "ex_pwd");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        13, this->ex_pwd(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Test.RetLogin)
  return target;
}

int RetLogin::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 sblx = 1;
    if (has_sblx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->sblx());
    }

    // required string sjhm = 2;
    if (has_sjhm()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sjhm());
    }

    // required string yjxx = 3;
    if (has_yjxx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->yjxx());
    }

    // required string jymm = 4;
    if (has_jymm()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->jymm());
    }

    // required string syspm1 = 5;
    if (has_syspm1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->syspm1());
    }

    // required string syspm2 = 6;
    if (has_syspm2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->syspm2());
    }

    // required string syspm3 = 7;
    if (has_syspm3()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->syspm3());
    }

    // required string syspm_ex = 8;
    if (has_syspm_ex()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->syspm_ex());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // required string type = 9;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
    }

    // required string yybdm = 10;
    if (has_yybdm()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->yybdm());
    }

    // required string user_id_lx = 11;
    if (has_user_id_lx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->user_id_lx());
    }

    // required string user_id = 12;
    if (has_user_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->user_id());
    }

    // required string ex_pwd = 13;
    if (has_ex_pwd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->ex_pwd());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RetLogin::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RetLogin* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RetLogin*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RetLogin::MergeFrom(const RetLogin& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sblx()) {
      set_sblx(from.sblx());
    }
    if (from.has_sjhm()) {
      set_sjhm(from.sjhm());
    }
    if (from.has_yjxx()) {
      set_yjxx(from.yjxx());
    }
    if (from.has_jymm()) {
      set_jymm(from.jymm());
    }
    if (from.has_syspm1()) {
      set_syspm1(from.syspm1());
    }
    if (from.has_syspm2()) {
      set_syspm2(from.syspm2());
    }
    if (from.has_syspm3()) {
      set_syspm3(from.syspm3());
    }
    if (from.has_syspm_ex()) {
      set_syspm_ex(from.syspm_ex());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_yybdm()) {
      set_yybdm(from.yybdm());
    }
    if (from.has_user_id_lx()) {
      set_user_id_lx(from.user_id_lx());
    }
    if (from.has_user_id()) {
      set_user_id(from.user_id());
    }
    if (from.has_ex_pwd()) {
      set_ex_pwd(from.ex_pwd());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RetLogin::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RetLogin::CopyFrom(const RetLogin& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RetLogin::IsInitialized() const {
  if ((_has_bits_[0] & 0x00001fff) != 0x00001fff) return false;

  return true;
}

void RetLogin::Swap(RetLogin* other) {
  if (other != this) {
    std::swap(sblx_, other->sblx_);
    std::swap(sjhm_, other->sjhm_);
    std::swap(yjxx_, other->yjxx_);
    std::swap(jymm_, other->jymm_);
    std::swap(syspm1_, other->syspm1_);
    std::swap(syspm2_, other->syspm2_);
    std::swap(syspm3_, other->syspm3_);
    std::swap(syspm_ex_, other->syspm_ex_);
    std::swap(type_, other->type_);
    std::swap(yybdm_, other->yybdm_);
    std::swap(user_id_lx_, other->user_id_lx_);
    std::swap(user_id_, other->user_id_);
    std::swap(ex_pwd_, other->ex_pwd_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RetLogin::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RetLogin_descriptor_;
  metadata.reflection = RetLogin_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Test

// @@protoc_insertion_point(global_scope)
