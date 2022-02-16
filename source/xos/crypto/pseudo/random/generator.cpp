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
///   File: generator.cpp
///
/// Author: $author$
///   Date: 2/16/2022
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/pseudo/random/generator.hpp"

#if !defined(XOS_CRYPTO_PSEUDO_RANDOM_GENERATOR_INSTANCE)
///#define XOS_CRYPTO_PSEUDO_RANDOM_GENERATOR_INSTANCE
#endif /// !defined(XOS_CRYPTO_PSEUDO_RANDOM_GENERATOR_INSTANCE)

namespace xos {
namespace crypto {
namespace pseudo {
namespace random {

///  Class: generatort
#if defined(XOS_CRYPTO_PSEUDO_RANDOM_GENERATOR_INSTANCE)
static generator the_generator;
#endif /// defined(XOS_CRYPTO_PSEUDO_RANDOM_GENERATOR_INSTANCE)


} /// namespace random
} /// namespace pseudo
} /// namespace crypto
} /// namespace xos
