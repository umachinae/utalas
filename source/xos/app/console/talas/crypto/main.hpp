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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/30/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_TALAS_CRYPTO_MAIN_HPP
#define XOS_APP_CONSOLE_TALAS_CRYPTO_MAIN_HPP

#include "xos/app/console/talas/crypto/main_opt.hpp"

#include "talas/io/string/reader.hpp"
#include "talas/io/read/file.hpp"

namespace xos {
namespace app {
namespace console {
namespace talas {
namespace crypto {

/// class maint
template 
<class TExtends = xos::app::console::talas::crypto::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// on_set_text_..._literal
    virtual int on_set_text_string_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* bytes = 0; const char_t* chars = 0; size_t length = 0;
        if ((bytes = (const byte_t*)(chars = literal.has_chars(length)))) {
            array.assign(bytes, length);
        }
        return err;
    }
    virtual int on_set_text_file_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
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

    /// on_set_hex_..._literal
    virtual int on_set_hex_string_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&array, null);
        err = on_set_hex_string_literals(to_arrays, literal, argc, argv, env);
        return err;
    }
    virtual int on_set_hex_file_literal
    (::talas::byte_array_t &array, ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ::talas::io::hex::read_to_byte_arrays to_arrays(&array, null);
        err = on_set_hex_file_literals(to_arrays, literal, argc, argv, env);
        return err;
    }
    virtual int on_set_hex_string_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays,
     ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ssize_t count = 0;
            ::talas::io::string::reader reader(literal);
            ::talas::io::hex::reader hex(to_arrays, reader);

            if (0 >= (count = hex.read())) {
                err = on_failed_set_hex_literals(to_arrays, literal, argc, argv, env);
            }
        }
        return err;
    }
    virtual int on_set_hex_file_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays,
     ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
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
                    err = on_failed_set_hex_literals(to_arrays, literal, argc, argv, env);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int on_failed_set_hex_literals
    (::talas::io::hex::read_to_byte_arrays &to_arrays,
     ::talas::string_t &literal, int argc, char_t** argv, char_t** env) {
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

protected:
}; /// class maint
typedef maint<> main;

} /// namespace crypto
} /// namespace talas
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_TALAS_CRYPTO_MAIN_HPP
