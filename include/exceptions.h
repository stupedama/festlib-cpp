//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace festlib {
namespace exceptions {

class FileNotFound : public std::runtime_error {
public:
  FileNotFound(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

class IoError : public std::runtime_error {
public:
  IoError(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

class OutOfMemory : public std::runtime_error {
public:
  OutOfMemory(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

class NoDocument : public std::runtime_error {
public:
  NoDocument(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

class BadDocument : public std::runtime_error {
public:
  BadDocument(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

class BadFestFormat : public std::runtime_error {
public:
  BadFestFormat(const std::string &error)
      : std::runtime_error{error} // std::runtime_error will handle the string
  {}
};

} // namespace exceptions
} // namespace festlib

#endif
