//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef CHECK_EMPTY_H_
#define CHECK_EMPTY_H_

#include "container.h"
#include <optional>
#include <string>

namespace festlib {

template <typename T> constexpr std::optional<T> check_empty(const T &value) {
  if (value.long_value().empty())
    return {};

  return value;
}

template <typename T>
constexpr std::optional<Container<T>> check_empty(const Container<T> &value) {
  if (value.empty())
    return {};

  return value;
}

template <typename T = std::string>
std::optional<std::string> check_empty(const std::string &str) {
  if (str.empty())
    return {};

  return str;
}

} // namespace festlib

#endif
