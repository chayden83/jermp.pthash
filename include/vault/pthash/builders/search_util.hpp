#pragma once

#include <array>
#include <cstdint>

#include <vault/pthash/essentials/essentials.hpp>
#include <vault/pthash/utils/hasher.hpp>

namespace pthash {

  constexpr uint64_t search_cache_size = 1000;

  template <size_t... Indices>
  constexpr std::array<uint64_t, sizeof...(Indices)> create_cache(std::index_sequence<Indices...>) {
    return {mix(Indices)...};
  }

  constexpr auto hashed_pilots_cache = create_cache(std::make_index_sequence<search_cache_size>{});

} // namespace pthash
