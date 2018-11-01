// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dht.proto

#ifndef PROTOBUF_INCLUDED_dht_2eproto
#define PROTOBUF_INCLUDED_dht_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_dht_2eproto 

namespace protobuf_dht_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_dht_2eproto
class BaseMsg;
class BaseMsgDefaultTypeInternal;
extern BaseMsgDefaultTypeInternal _BaseMsg_default_instance_;
class CDhtConfigCnf;
class CDhtConfigCnfDefaultTypeInternal;
extern CDhtConfigCnfDefaultTypeInternal _CDhtConfigCnf_default_instance_;
class CDhtConfigReq;
class CDhtConfigReqDefaultTypeInternal;
extern CDhtConfigReqDefaultTypeInternal _CDhtConfigReq_default_instance_;
namespace google {
namespace protobuf {
template<> ::BaseMsg* Arena::CreateMaybeMessage<::BaseMsg>(Arena*);
template<> ::CDhtConfigCnf* Arena::CreateMaybeMessage<::CDhtConfigCnf>(Arena*);
template<> ::CDhtConfigReq* Arena::CreateMaybeMessage<::CDhtConfigReq>(Arena*);
}  // namespace protobuf
}  // namespace google

enum OnOff {
  INVALID = 0,
  ON = 1,
  OFF = 2,
  ON_BUT_NOT_WORKING = 3,
  OnOff_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  OnOff_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool OnOff_IsValid(int value);
const OnOff OnOff_MIN = INVALID;
const OnOff OnOff_MAX = ON_BUT_NOT_WORKING;
const int OnOff_ARRAYSIZE = OnOff_MAX + 1;

const ::google::protobuf::EnumDescriptor* OnOff_descriptor();
inline const ::std::string& OnOff_Name(OnOff value) {
  return ::google::protobuf::internal::NameOfEnum(
    OnOff_descriptor(), value);
}
inline bool OnOff_Parse(
    const ::std::string& name, OnOff* value) {
  return ::google::protobuf::internal::ParseNamedEnum<OnOff>(
    OnOff_descriptor(), name, value);
}
enum Result {
  SUCCESS = 0,
  ERROR = 1,
  Result_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Result_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Result_IsValid(int value);
const Result Result_MIN = SUCCESS;
const Result Result_MAX = ERROR;
const int Result_ARRAYSIZE = Result_MAX + 1;

const ::google::protobuf::EnumDescriptor* Result_descriptor();
inline const ::std::string& Result_Name(Result value) {
  return ::google::protobuf::internal::NameOfEnum(
    Result_descriptor(), value);
}
inline bool Result_Parse(
    const ::std::string& name, Result* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Result>(
    Result_descriptor(), name, value);
}
// ===================================================================

class BaseMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:BaseMsg) */ {
 public:
  BaseMsg();
  virtual ~BaseMsg();

  BaseMsg(const BaseMsg& from);

  inline BaseMsg& operator=(const BaseMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BaseMsg(BaseMsg&& from) noexcept
    : BaseMsg() {
    *this = ::std::move(from);
  }

  inline BaseMsg& operator=(BaseMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BaseMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BaseMsg* internal_default_instance() {
    return reinterpret_cast<const BaseMsg*>(
               &_BaseMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(BaseMsg* other);
  friend void swap(BaseMsg& a, BaseMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BaseMsg* New() const final {
    return CreateMaybeMessage<BaseMsg>(NULL);
  }

  BaseMsg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BaseMsg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const BaseMsg& from);
  void MergeFrom(const BaseMsg& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BaseMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // int32 id = 2;
  void clear_id();
  static const int kIdFieldNumber = 2;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:BaseMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_dht_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CDhtConfigReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CDhtConfigReq) */ {
 public:
  CDhtConfigReq();
  virtual ~CDhtConfigReq();

  CDhtConfigReq(const CDhtConfigReq& from);

  inline CDhtConfigReq& operator=(const CDhtConfigReq& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CDhtConfigReq(CDhtConfigReq&& from) noexcept
    : CDhtConfigReq() {
    *this = ::std::move(from);
  }

  inline CDhtConfigReq& operator=(CDhtConfigReq&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CDhtConfigReq& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CDhtConfigReq* internal_default_instance() {
    return reinterpret_cast<const CDhtConfigReq*>(
               &_CDhtConfigReq_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(CDhtConfigReq* other);
  friend void swap(CDhtConfigReq& a, CDhtConfigReq& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CDhtConfigReq* New() const final {
    return CreateMaybeMessage<CDhtConfigReq>(NULL);
  }

  CDhtConfigReq* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<CDhtConfigReq>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const CDhtConfigReq& from);
  void MergeFrom(const CDhtConfigReq& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CDhtConfigReq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .BaseMsg baseId = 1;
  bool has_baseid() const;
  void clear_baseid();
  static const int kBaseIdFieldNumber = 1;
  private:
  const ::BaseMsg& _internal_baseid() const;
  public:
  const ::BaseMsg& baseid() const;
  ::BaseMsg* release_baseid();
  ::BaseMsg* mutable_baseid();
  void set_allocated_baseid(::BaseMsg* baseid);

  // .OnOff state = 2;
  void clear_state();
  static const int kStateFieldNumber = 2;
  ::OnOff state() const;
  void set_state(::OnOff value);

  // @@protoc_insertion_point(class_scope:CDhtConfigReq)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::BaseMsg* baseid_;
  int state_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_dht_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CDhtConfigCnf : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CDhtConfigCnf) */ {
 public:
  CDhtConfigCnf();
  virtual ~CDhtConfigCnf();

  CDhtConfigCnf(const CDhtConfigCnf& from);

  inline CDhtConfigCnf& operator=(const CDhtConfigCnf& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CDhtConfigCnf(CDhtConfigCnf&& from) noexcept
    : CDhtConfigCnf() {
    *this = ::std::move(from);
  }

  inline CDhtConfigCnf& operator=(CDhtConfigCnf&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CDhtConfigCnf& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CDhtConfigCnf* internal_default_instance() {
    return reinterpret_cast<const CDhtConfigCnf*>(
               &_CDhtConfigCnf_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(CDhtConfigCnf* other);
  friend void swap(CDhtConfigCnf& a, CDhtConfigCnf& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CDhtConfigCnf* New() const final {
    return CreateMaybeMessage<CDhtConfigCnf>(NULL);
  }

  CDhtConfigCnf* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<CDhtConfigCnf>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const CDhtConfigCnf& from);
  void MergeFrom(const CDhtConfigCnf& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CDhtConfigCnf* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Result result = 1;
  void clear_result();
  static const int kResultFieldNumber = 1;
  ::Result result() const;
  void set_result(::Result value);

  // .OnOff state = 2;
  void clear_state();
  static const int kStateFieldNumber = 2;
  ::OnOff state() const;
  void set_state(::OnOff value);

  // @@protoc_insertion_point(class_scope:CDhtConfigCnf)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int result_;
  int state_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_dht_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BaseMsg

// string name = 1;
inline void BaseMsg::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BaseMsg::name() const {
  // @@protoc_insertion_point(field_get:BaseMsg.name)
  return name_.GetNoArena();
}
inline void BaseMsg::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:BaseMsg.name)
}
#if LANG_CXX11
inline void BaseMsg::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:BaseMsg.name)
}
#endif
inline void BaseMsg::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:BaseMsg.name)
}
inline void BaseMsg::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:BaseMsg.name)
}
inline ::std::string* BaseMsg::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:BaseMsg.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BaseMsg::release_name() {
  // @@protoc_insertion_point(field_release:BaseMsg.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BaseMsg::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:BaseMsg.name)
}

// int32 id = 2;
inline void BaseMsg::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 BaseMsg::id() const {
  // @@protoc_insertion_point(field_get:BaseMsg.id)
  return id_;
}
inline void BaseMsg::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:BaseMsg.id)
}

// -------------------------------------------------------------------

// CDhtConfigReq

// .BaseMsg baseId = 1;
inline bool CDhtConfigReq::has_baseid() const {
  return this != internal_default_instance() && baseid_ != NULL;
}
inline void CDhtConfigReq::clear_baseid() {
  if (GetArenaNoVirtual() == NULL && baseid_ != NULL) {
    delete baseid_;
  }
  baseid_ = NULL;
}
inline const ::BaseMsg& CDhtConfigReq::_internal_baseid() const {
  return *baseid_;
}
inline const ::BaseMsg& CDhtConfigReq::baseid() const {
  const ::BaseMsg* p = baseid_;
  // @@protoc_insertion_point(field_get:CDhtConfigReq.baseId)
  return p != NULL ? *p : *reinterpret_cast<const ::BaseMsg*>(
      &::_BaseMsg_default_instance_);
}
inline ::BaseMsg* CDhtConfigReq::release_baseid() {
  // @@protoc_insertion_point(field_release:CDhtConfigReq.baseId)
  
  ::BaseMsg* temp = baseid_;
  baseid_ = NULL;
  return temp;
}
inline ::BaseMsg* CDhtConfigReq::mutable_baseid() {
  
  if (baseid_ == NULL) {
    auto* p = CreateMaybeMessage<::BaseMsg>(GetArenaNoVirtual());
    baseid_ = p;
  }
  // @@protoc_insertion_point(field_mutable:CDhtConfigReq.baseId)
  return baseid_;
}
inline void CDhtConfigReq::set_allocated_baseid(::BaseMsg* baseid) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete baseid_;
  }
  if (baseid) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      baseid = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, baseid, submessage_arena);
    }
    
  } else {
    
  }
  baseid_ = baseid;
  // @@protoc_insertion_point(field_set_allocated:CDhtConfigReq.baseId)
}

// .OnOff state = 2;
inline void CDhtConfigReq::clear_state() {
  state_ = 0;
}
inline ::OnOff CDhtConfigReq::state() const {
  // @@protoc_insertion_point(field_get:CDhtConfigReq.state)
  return static_cast< ::OnOff >(state_);
}
inline void CDhtConfigReq::set_state(::OnOff value) {
  
  state_ = value;
  // @@protoc_insertion_point(field_set:CDhtConfigReq.state)
}

// -------------------------------------------------------------------

// CDhtConfigCnf

// .Result result = 1;
inline void CDhtConfigCnf::clear_result() {
  result_ = 0;
}
inline ::Result CDhtConfigCnf::result() const {
  // @@protoc_insertion_point(field_get:CDhtConfigCnf.result)
  return static_cast< ::Result >(result_);
}
inline void CDhtConfigCnf::set_result(::Result value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:CDhtConfigCnf.result)
}

// .OnOff state = 2;
inline void CDhtConfigCnf::clear_state() {
  state_ = 0;
}
inline ::OnOff CDhtConfigCnf::state() const {
  // @@protoc_insertion_point(field_get:CDhtConfigCnf.state)
  return static_cast< ::OnOff >(state_);
}
inline void CDhtConfigCnf::set_state(::OnOff value) {
  
  state_ = value;
  // @@protoc_insertion_point(field_set:CDhtConfigCnf.state)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::OnOff> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::OnOff>() {
  return ::OnOff_descriptor();
}
template <> struct is_proto_enum< ::Result> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Result>() {
  return ::Result_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_dht_2eproto
