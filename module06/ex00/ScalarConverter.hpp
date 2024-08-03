#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cstdlib>
#include <float.h>
#include <iomanip>
#include <iostream>

#define TYPE_PRINT_WIDTH 8

typedef enum e_type {
  UNKNOWN,
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
} t_type;

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  static char _charValue;
  static long _intValue;
  static double _floatValue;
  static double _doubleValue;
  static t_type _literalType;

  // @defgroup type printers
  static void _printChar();
  static void _printInt();
  static void _printFloat();
  static void _printDouble();

  static t_type _getLiteralType(const std::string &literal);

public:
  static void convert(const std::string &literal);

  // @defgroup exceptions
  class UnknownTypeException : public std::exception {
  private:
    std::string _message;

  public:
    UnknownTypeException(const std::string &literal) {
      _message = "Error: literal `" + literal + "` type is unknown";
    }
    virtual ~UnknownTypeException() throw() {}
    virtual const char *what() const throw() { return _message.c_str(); }
  };
};

#endif // SCALAR_CONVERTER_HPP
