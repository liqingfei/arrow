// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef ARROW_UTIL_BIT_UTIL_H
#define ARROW_UTIL_BIT_UTIL_H

#include <cstdint>
#include <cstdlib>
#include <memory>

#include "arrow/util/buffer.h"

namespace arrow {

class Status;

namespace util {

static inline int64_t ceil_byte(int64_t size) {
  return (size + 7) & ~7;
}

static inline int64_t ceil_2bytes(int64_t size) {
  return (size + 15) & ~15;
}

static inline bool get_bit(const uint8_t* bits, int i) {
  return bits[i / 8] & (1 << (i % 8));
}

static inline void set_bit(uint8_t* bits, int i, bool is_set) {
  bits[i / 8] |= (1 << (i % 8)) * is_set;
}

static inline int64_t next_power2(int64_t n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;
  n++;
  return n;
}

void bytes_to_bits(uint8_t* bytes, int length, uint8_t* bits);
Status bytes_to_bits(uint8_t*, int, std::shared_ptr<Buffer>*);

} // namespace util

} // namespace arrow

#endif // ARROW_UTIL_BIT_UTIL_H
