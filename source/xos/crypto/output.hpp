///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: output.hpp
///
/// Author: $author$
///   Date: 3/3/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_OUTPUT_HPP
#define XOS_CRYPTO_OUTPUT_HPP

#include "xos/io/console/output.hpp"

#include "talas/base/array.hpp"
#include "talas/base/string.hpp"

#include "talas/io/string/reader.hpp"
#include "talas/io/read/file.hpp"

#include "talas/io/hex/read_to_arrays.hpp"
#include "talas/io/hex/read_to_array.hpp"
#include "talas/io/hex/reader.hpp"

namespace xos {
namespace crypto {

/// class outputt
template 
<class TOutput = xos::io::console::output, 
 class TForwardedOutput = xos::io::forwarded::outputt<TOutput>, 
 class TExtends = TForwardedOutput, class TImplements = typename TExtends::implements>

class exported outputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef outputt derives; 
    
    typedef TOutput output_t;
    
    /// constructors / destructor
    outputt(const outputt& copy) {
    }
    outputt() {
    }
    virtual ~outputt() {
    }

    /// on_set_text_..._literal
    int (derives::*on_set_text_literal_)(::talas::byte_array_t &array, ::talas::string_t &literal);
    virtual int on_set_text_literal(::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        if (on_set_text_literal_) {
            err = (this->*on_set_text_literal_)(array, literal);
        } else {
            err = default_on_set_text_literal(array, literal);
        }
        return err;
    }
    virtual int default_on_set_text_literal(::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        err = on_set_text_string_literal(array, literal);
        return err;
    }
    virtual int on_set_text_string_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        const byte_t* bytes = 0; const char_t* chars = 0; size_t length = 0;
        if ((bytes = (const byte_t*)(chars = literal.has_chars(length)))) {
            array.assign(bytes, length);
        }
        return err;
    }
    virtual int on_set_text_file_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ::talas::io::read::char_file file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ::talas::io::read::char_file::char_t c = 0;
                byte_t b = 0;
                ssize_t count = 0;
    
                array.set_length(0);
                while (0 < (count = file.read(&c, 1))) {
                    b = (byte_t)c;
                    array.append(&b, 1);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int set_on_set_text_string_literal() {
        int err = 0;
        on_set_text_literal_ = &derives::on_set_text_string_literal;
        return err;
    }
    virtual int set_on_set_text_file_literal() {
        int err = 0;
        on_set_text_literal_ = &derives::on_set_text_file_literal;
        return err;
    }

    /// on_set_hex_..._literal
    int (derives::*on_set_hex_literal_)(::talas::byte_array_t &array, ::talas::string_t &literal);
    virtual int on_set_hex_literal(::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        if (on_set_hex_literal_) {
            err = (this->*on_set_hex_literal_)(array, literal);
        } else {
            err = default_on_set_hex_literal(array, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literal(::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        err = on_set_hex_string_literal(array, literal);
        return err;
    }
    virtual int on_set_hex_string_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&array, null);
        err = on_set_hex_string_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_file_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&array, null);
        err = on_set_hex_file_literals(to_arrays, literal);
        return err;
    }
    virtual int set_on_set_hex_string_literal() {
        int err = 0;
        on_set_hex_literal_ = &derives::on_set_hex_string_literal;
        return err;
    }
    virtual int set_on_set_hex_file_literal() {
        int err = 0;
        on_set_hex_literal_ = &derives::on_set_hex_file_literal;
        return err;
    }

    /// ...on_set_hex_literals
    int (derives::*on_set_hex_literals_)
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal);
    virtual int on_set_hex_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal) {
        int err = 0;
        if (on_set_hex_literals_) {
            err = (this->*on_set_hex_literals_)(to_arrays, literal);
        } else {
            err = default_on_set_hex_literals(to_arrays, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal) {
        int err = 0;
        err = on_set_hex_string_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_string_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ssize_t count = 0;
            ::talas::io::string::reader reader(literal);
            ::talas::io::hex::reader hex(to_arrays, reader);

            if (0 >= (count = hex.read())) {
                err = on_failed_set_hex_literals(to_arrays, literal);
            }
        }
        return err;
    }
    virtual int on_set_hex_file_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ::talas::io::read::char_file file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ssize_t count = 0;
                ::talas::io::hex::reader hex(to_arrays, file);
    
                if (0 >= (count = hex.read())) {
                    err = on_failed_set_hex_literals(to_arrays, literal);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int on_failed_set_hex_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays, ::talas::string_t &literal) {
        int err = 0;
        size_t length = 0;
        ::talas::io::hex::read_to_byte_arrays::arrays_t &arrays = to_arrays.arrays();
        ::talas::io::hex::read_to_byte_arrays::array_pointer_t *array_pointers = 0;

        if ((array_pointers = arrays.elements(length))) {
            ::talas::io::hex::read_to_byte_arrays::array_pointer_t array_pointer = 0;

            for (array_pointer = *array_pointers; length; --length, ++array_pointers) {
                if ((array_pointer)) {
                    array_pointer->set_length(0);
                }
            }
        }
        return err;
    }
    virtual int set_on_set_hex_string_literals() {
        int err = 0;
        on_set_hex_literals_ = &derives::on_set_hex_string_literals;
        return err;
    }
    virtual int set_on_set_hex_file_literals() {
        int err = 0;
        on_set_hex_literals_ = &derives::on_set_hex_file_literals;
        return err;
    }

    /// on_set_hex_literals
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, 
     ::talas::byte_array_t &a3, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, &a3, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, 
     ::talas::byte_array_t &a3, ::talas::byte_array_t &a4, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, &a3, &a4, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, 
     ::talas::byte_array_t &a3, ::talas::byte_array_t &a4, 
     ::talas::byte_array_t &a5, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, &a3, &a4, &a5, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, 
     ::talas::byte_array_t &a3, ::talas::byte_array_t &a4, 
     ::talas::byte_array_t &a5, ::talas::byte_array_t &a6, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, &a3, &a4, &a5, &a6, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (::talas::byte_array_t &a1, ::talas::byte_array_t &a2, 
     ::talas::byte_array_t &a3, ::talas::byte_array_t &a4, 
     ::talas::byte_array_t &a5, ::talas::byte_array_t &a6, 
     ::talas::byte_array_t &a7, ::talas::string_t &literal) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&a1, &a2, &a3, &a4, &a5, &a6, &a7, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }

    /// ...output_hex
    virtual ssize_t output_hex(const ::talas::byte_array_t &array) {
        ssize_t count = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        
        if ((bytes = array.elements(length))) {
            count = this->output_x(bytes, length);
        }
        return count;
    }

    /// ...output_x
    ssize_t (derives::*output_x_)(const void* out, size_t len);
    virtual ssize_t output_x(const void* out, size_t len) {
        ssize_t count = 0;
        if (output_x_) {
            count = (this->*output_x_)(out, len);
        } else {
            count = default_output_x(out, len);
        }
        return count;
    }
    virtual ssize_t default_output_x(const void* out, size_t len) {
        ssize_t count = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            size_t cols = 32, col = 0;
            ssize_t amount = 0;
            const char_t& nextln = this->nextln();

            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    if (0 < (amount = this->outln(&nextln, 1))) {
                        count += amount;
                    }
                    col = 0;
                }
                if (0 < (amount = this->outx(bytes, 1))) {
                    count += amount;
                }
            }
            if (0 < (amount = this->outln())) {
                count += amount;
            }
        }
        return count;
    }

    /// nextln
    virtual const char_t& nextln() const {
        static const char_t nextln = (char_t)'\\';
        return nextln;
    }

}; /// class outputt
typedef outputt<> output;

} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_OUTPUT_HPP
