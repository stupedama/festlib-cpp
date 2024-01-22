//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <unordered_map>
#include <vector>

namespace festlib {
// default container used

template <typename T> using Container = std::vector<T>;
template <typename T, typename U> using Map = std::unordered_map<T, U>;

} // namespace festlib

#endif
