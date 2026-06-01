template <typename T>
class DataHolder {
  private:
    T storedValue;
    T maxValue;
    T minValue;
  public:
    DataHolder(T val, T min, T max) : maxValue(max), minValue(min) {
      if ((val < maxValue) && (val >= minValue)) {
        storedValue = val;
      } else if (val > max) {
        storedValue = max;
        std::cout << "WARNING: val is too high! Setting value to max!" << std::endl;
      } else {
        storedValue = min;
        std::cout << "WARNING: val is too low! Setting value to min!" << std::endl;
      }
    };
    void setValue(T newValue) {
      if ((newValue <= maxValue) && (newValue >= minValue)) {
        storedValue = newValue;
      } else if (newValue > maxValue) {
        storedValue = maxValue;
        std::cout << "WARNING: val is too high! Setting value to max!" << std::endl;
      } else {
        storedValue = minValue;
        std::cout << "WARNING: val is too low! Setting value to min!" << std::endl;
      }
    };
    T getValue() {
      return storedValue; 
    };
};

template <>
class DataHolder<std::string> {
  private:
    std::string storedValue;
  public:
    DataHolder(std::string val) : storedValue(val) {};
    void setValue(std::string newString) {
      storedValue = newString;
    }
    std::string getValue() {
      return storedValue;
    }
};