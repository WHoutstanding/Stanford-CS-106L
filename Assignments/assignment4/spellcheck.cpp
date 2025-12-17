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
  auto space = find_all(source.begin(), source.end(), isspace);

  std::set<Token> tokens;
  std::transform(space.begin(), space.end()-1, space.begin() + 1, std::inserter(tokens, tokens.end()), [&source](auto it1, auto it2) { return Token(source, it1, it2); });

  std::erase_if(tokens, [](auto token){ return token.content.empty(); });
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view = source 
    | rv::filter([&dictionary](auto token) { return !dictionary.contains(token.content); })
    | rv::transform([&dictionary](auto token) {
      auto view = dictionary | rv::filter([&token](auto value) { return levenshtein(value, token.content) == 1;});
      std::set<std::string> suggestions(view.begin(), view.end());
      return Misspelling { token, suggestions };
    })
    | rv::filter([&dictionary](auto misspelling) { return !dictionary.contains(misspelling.token.content); })
    | rv::filter([](auto misspelling) { return !misspelling.suggestions.empty(); });
    // | rv::filter([&dictionary](auto misspelling) { return !dictionary.contains(misspelling.token.content); })
    // | rv::transform([&dictionary](auto misspelling) {
    //   auto view = dictionary | rv::filter([&misspelling](auto value) { return levenshtein(value, misspelling.token.content) == 1;});
    //   std::set<std::string> suggestions(view.begin(), view.end());
    //   return Misspelling { misspelling, suggestions };
    // });

  std::set<Misspelling> result(view.begin(), view.end());
  return result;
};

/* Helper methods */

#include "utils.cpp"