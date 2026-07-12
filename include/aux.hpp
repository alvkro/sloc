#ifndef AUX_HPP
#define AUX_HPP

#include <string>

/*!
 * @brief Trims string up until first appearance of a certain character.
 *
 * @param s String to be trimmed.
 * @param t Character to serve as first position. Defaults as horizontal and vertical tabulation,
 * line break, carriage return and page advance.
 * @return Trimmed string.
 */
inline std::string ltrim(const std::string& s, const char* t = " \t\n\r\f\v") {
  std::string clone{ s };
  clone.erase(0, clone.find_first_not_of(t));
  return clone;
}

/*!
 * @brief Trims string from first appearance of a certain character to string end.
 *
 * @param s String to be trimmed.
 * @param t Character to serve as first position. Defaults as horizontal and vertical tabulation,
 * line break, carriage return and page advance.
 * @return Trimmed string.
 */
inline std::string rtrim(const std::string& s, const char* t = " \t\n\r\f\v") {
  std::string clone{ s };
  clone.erase(clone.size(), clone.find_last_not_of(t) + 1);
  return clone;
}

/*!
 * @brief Trims blank head and tail of a string.
 *
 * @param s String to be trimmed.
 * @return Trimmed string.
 */
inline std::string trim(const std::string& s) {
  std::string clone{ s };
  if (clone.empty())
    return clone;
  clone = ltrim(clone);
  clone = rtrim(clone);
  return clone;
}

#endif
