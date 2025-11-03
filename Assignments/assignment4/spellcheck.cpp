#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
// #include <Iterator>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  auto space = find_all(source.begin(), source.end(), [](char c) { return std::isspace(c); });
  Token token1(source, source.begin(), source.end());

  // std::transform()
  return Corpus();
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  return std::set<Misspelling>();
};

/* Helper methods */

#include "utils.cpp"