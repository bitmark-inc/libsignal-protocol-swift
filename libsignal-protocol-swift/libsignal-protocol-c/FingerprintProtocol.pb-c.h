/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: FingerprintProtocol.proto */

#ifndef PROTOBUF_C_FingerprintProtocol_2eproto__INCLUDED
#define PROTOBUF_C_FingerprintProtocol_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Textsecure__LogicalFingerprint Textsecure__LogicalFingerprint;
typedef struct _Textsecure__CombinedFingerprints Textsecure__CombinedFingerprints;


/* --- enums --- */


/* --- messages --- */

struct  _Textsecure__LogicalFingerprint
{
  ProtobufCMessage base;
  protobuf_c_boolean has_content;
  ProtobufCBinaryData content;
  /*
   * Version 0
   */
  protobuf_c_boolean has_identifier;
  ProtobufCBinaryData identifier;
};
#define TEXTSECURE__LOGICAL_FINGERPRINT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&textsecure__logical_fingerprint__descriptor) \
    , 0,{0,NULL}, 0,{0,NULL} }


struct  _Textsecure__CombinedFingerprints
{
  ProtobufCMessage base;
  protobuf_c_boolean has_version;
  uint32_t version;
  Textsecure__LogicalFingerprint *localfingerprint;
  Textsecure__LogicalFingerprint *remotefingerprint;
};
#define TEXTSECURE__COMBINED_FINGERPRINTS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&textsecure__combined_fingerprints__descriptor) \
    , 0,0, NULL, NULL }


/* Textsecure__LogicalFingerprint methods */
void   textsecure__logical_fingerprint__init
                     (Textsecure__LogicalFingerprint         *message);
size_t textsecure__logical_fingerprint__get_packed_size
                     (const Textsecure__LogicalFingerprint   *message);
size_t textsecure__logical_fingerprint__pack
                     (const Textsecure__LogicalFingerprint   *message,
                      uint8_t             *out);
size_t textsecure__logical_fingerprint__pack_to_buffer
                     (const Textsecure__LogicalFingerprint   *message,
                      ProtobufCBuffer     *buffer);
Textsecure__LogicalFingerprint *
       textsecure__logical_fingerprint__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   textsecure__logical_fingerprint__free_unpacked
                     (Textsecure__LogicalFingerprint *message,
                      ProtobufCAllocator *allocator);
/* Textsecure__CombinedFingerprints methods */
void   textsecure__combined_fingerprints__init
                     (Textsecure__CombinedFingerprints         *message);
size_t textsecure__combined_fingerprints__get_packed_size
                     (const Textsecure__CombinedFingerprints   *message);
size_t textsecure__combined_fingerprints__pack
                     (const Textsecure__CombinedFingerprints   *message,
                      uint8_t             *out);
size_t textsecure__combined_fingerprints__pack_to_buffer
                     (const Textsecure__CombinedFingerprints   *message,
                      ProtobufCBuffer     *buffer);
Textsecure__CombinedFingerprints *
       textsecure__combined_fingerprints__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   textsecure__combined_fingerprints__free_unpacked
                     (Textsecure__CombinedFingerprints *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Textsecure__LogicalFingerprint_Closure)
                 (const Textsecure__LogicalFingerprint *message,
                  void *closure_data);
typedef void (*Textsecure__CombinedFingerprints_Closure)
                 (const Textsecure__CombinedFingerprints *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor textsecure__logical_fingerprint__descriptor;
extern const ProtobufCMessageDescriptor textsecure__combined_fingerprints__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_FingerprintProtocol_2eproto__INCLUDED */
