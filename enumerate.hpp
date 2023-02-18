#ifndef ENUMERATE_HPP
#define ENUMERATE_HPP

#include <utility>
#include <tuple>
#include <cstddef>

constexpr auto enumerate(auto&& inner_iterable) {
  using InnerIterable = decltype(inner_iterable);
  using InnerIterator = decltype(std::begin(std::declval<InnerIterable>()));

  struct Iterator {
    size_t i;
    InnerIterator inner_iterator;
    auto operator!=(const Iterator& rhs) const {
      return inner_iterator != rhs.inner_iterator;
    }
    auto operator++() { i++; inner_iterator++; }
    auto operator*() const { return std::tie(i, *inner_iterator); }
  };

  struct Iterable {
    InnerIterable inner_iterable;
    auto begin() { return Iterator{0, std::begin(inner_iterable)}; }
    auto end() { return Iterator{0, std::end(inner_iterable)}; }
  };

  return Iterable{std::forward<InnerIterable>(inner_iterable)};
}

#endif // ifndef ENUMERATE_HPP
