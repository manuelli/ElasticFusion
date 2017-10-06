/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef __bot_core_image_metadata_t_hpp__
#define __bot_core_image_metadata_t_hpp__

#include <lcm/lcm_coretypes.h>

#include <string>
#include <vector>

namespace bot_core
{

class image_metadata_t
{
    public:
        std::string key;

        int32_t    n;

        std::vector< uint8_t > value;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "image_metadata_t"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int image_metadata_t::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int image_metadata_t::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int image_metadata_t::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t image_metadata_t::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* image_metadata_t::getTypeName()
{
    return "image_metadata_t";
}

int image_metadata_t::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    char* key_cstr = const_cast<char*>(this->key.c_str());
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &key_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->n, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->n > 0) {
        tlen = __byte_encode_array(buf, offset + pos, maxlen - pos, &this->value[0], this->n);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int image_metadata_t::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    int32_t __key_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__key_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__key_len__ > maxlen - pos) return -1;
    this->key.assign(((const char*)buf) + offset + pos, __key_len__ - 1);
    pos += __key_len__;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->n, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    if(this->n) {
        this->value.resize(this->n);
        tlen = __byte_decode_array(buf, offset + pos, maxlen - pos, &this->value[0], this->n);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int image_metadata_t::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += this->key.size() + 4 + 1;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __byte_encoded_array_size(NULL, this->n);
    return enc_size;
}

uint64_t image_metadata_t::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x4d25b1a682bbfdc7LL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
