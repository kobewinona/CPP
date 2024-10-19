#include "ScalarConverter.hpp"

char ScalarConverter::_charValue = '\0';
long ScalarConverter::_intValue = 0;
double ScalarConverter::_floatValue = 0.0f;
double ScalarConverter::_doubleValue = 0.0;
t_type ScalarConverter::_literalType = UNKNOWN;

// @defgroup constructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  (*this) = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other) {
    _charValue = other._charValue;
    _intValue = other._intValue;
    _floatValue = other._floatValue;
    _doubleValue = other._doubleValue;
    _literalType = other._literalType;
  }
  return *this;
}

// @def destructor
ScalarConverter::~ScalarConverter() {}

// @defgroup member functions
// -- @defgroup type printers
void ScalarConverter::_printChar() {
  std::cout << std::setw(TYPE_PRINT_WIDTH) << "char: ";

  if (_literalType == FLOAT || _literalType == DOUBLE) {
    if (std::isnan(_floatValue) || std::isinf(_floatValue) ||
        std::isnan(_doubleValue) || std::isinf(_doubleValue)) {
      std::cout << "impossible" << std::endl;
      return;
    }
  }

  if (_intValue >= std::numeric_limits<char>::min() &&
      _intValue <= std::numeric_limits<char>::max() &&
      std::isprint(_charValue)) {
    std::cout << _charValue << std::endl;
  } else {
    std::cout << "Non displayable" << std::endl;
  }
}

void ScalarConverter::_printInt() {
  std::cout << std::setw(TYPE_PRINT_WIDTH) << "int: ";

  double valueToCheck = _intValue;

  if (_literalType == FLOAT)
    valueToCheck = _floatValue;
  if (_literalType == DOUBLE)
    valueToCheck = _doubleValue;

  if (_literalType == FLOAT || _literalType == DOUBLE) {
    if (std::isnan(valueToCheck) || std::isinf(valueToCheck)) {
      std::cout << "impossible" << std::endl;
      return;
    }
  }

  if (valueToCheck < std::numeric_limits<int>::min() ||
      valueToCheck > std::numeric_limits<int>::max()) {
    std::cout << "impossible" << std::endl;
    return;
  }

  std::cout << _intValue << std::endl;
}

void ScalarConverter::_printFloat() {
  std::cout << std::setw(TYPE_PRINT_WIDTH) << "float: ";

  if (_literalType == FLOAT) {
    if (_floatValue < std::numeric_limits<float>::min() ||
        _floatValue > std::numeric_limits<float>::max()) {
      std::cout << "impossible" << std::endl;
      return;
    }
  }

  std::cout << std::fixed << std::setprecision(1) << _floatValue;
  std::cout << "f" << std::endl;
}

void ScalarConverter::_printDouble() {
  std::cout << std::setw(TYPE_PRINT_WIDTH) << "double: ";
  std::cout << std::fixed << std::setprecision(1) << _doubleValue << std::endl;
}

// -- @defgroup converters
t_type ScalarConverter::_getLiteralType(const std::string &literal) {
  if (literal.length() == 1) {
    _charValue = literal.at(0);
    if (!isdigit(_charValue))
      return CHAR;
  }

  char *longRest = NULL, *doubleRest = NULL;

  _intValue = strtol(literal.c_str(), &longRest, 10);
  _doubleValue = strtof(literal.c_str(), &doubleRest);
  _floatValue = static_cast<float>(_doubleValue);

  if ((*longRest)) {
    if ((*doubleRest))
      return (*doubleRest) == 'f' ? FLOAT : UNKNOWN;
    return DOUBLE;
  }

  return INT;
}

void ScalarConverter::convert(const std::string &literal) {
  if (literal.empty())
    return;

  _literalType = _getLiteralType(literal);

  switch (_literalType) {
  case CHAR:
    _intValue = static_cast<int>(_charValue);
    _floatValue = static_cast<float>(_charValue);
    _doubleValue = static_cast<double>(_charValue);
    break;
  case INT:
    _charValue = static_cast<char>(_intValue);
    _floatValue = static_cast<float>(_intValue);
    _doubleValue = static_cast<double>(_intValue);
    break;
  case FLOAT:
    _charValue = static_cast<char>(_floatValue);
    _intValue = static_cast<int>(_floatValue);
    _doubleValue = static_cast<double>(_floatValue);
    break;
  case DOUBLE:
    _charValue = static_cast<char>(_doubleValue);
    _intValue = static_cast<int>(_doubleValue);
    _floatValue = static_cast<float>(_doubleValue);
    break;
  default:
    throw UnknownTypeException(literal);
  }

  std::cout << std::left;
  _printChar(), _printInt(), _printFloat(), _printDouble();
}
