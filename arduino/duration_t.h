
#ifndef __DURATION_T__
#define __DURATION_T__
 //鏃堕棿璁板綍鍜屽彉鎹㈠嚱鏁�
struct duration_t {
  /**
   * @brief Duration is stored in seconds  (s)
   */
  uint32_t value;

  duration_t()
    : duration_t(0) {};
  duration_t(uint32_t const &seconds) {
    this->value = seconds;
  }
  bool operator==(const uint32_t &value) const {
    return (this->value == value);
  }
  bool operator!=(const uint32_t &value) const {
    return ! this->operator==(value);
  }
  
  inline uint8_t year() const {
    return this->day() / 365;
  }
  inline uint16_t day() const {
    return this->hour() / 24;
  }
  inline uint32_t hour() const {
    return this->minute() / 60;
  }
  inline uint32_t minute() const {
    return this->second() / 60;
  }
  inline uint32_t second() const {
    return this->value;            //鍑芥暟杩唬
  }

  /**
   * @brief Formats the duration as a string
   * @details String will be formated using a "full" representation of duration
   *
   * @param buffer The array pointed to must be able to accommodate 21 bytes
   *
   * Output examples:
   *  123456789012345678901 (strlen)
   *  135y 364d 23h 59m 59s
   *  364d 23h 59m 59s
   *  23h 59m 59s
   *  59m 59s
   *  59s
   */
  void toString(char *buffer) const {
    int y = this->year(),
        d = this->day() % 365,
        h = this->hour() % 24,
        m = this->minute() % 60,
        s = this->second() % 60;

    if (y) sprintf_P(buffer, PSTR("%iy %id %ih %im %is"), y, d, h, m, s);
    else if (d) sprintf_P(buffer, PSTR("%id %ih %im %is"), d, h, m, s);
    else if (h) sprintf_P(buffer, PSTR("%ih %im %is"), h, m, s);
    else if (m) sprintf_P(buffer, PSTR("%im %is"), m, s);
    else sprintf_P(buffer, PSTR("%is"), s);
  }

  /**
   * @brief Formats the duration as a string
   * @details String will be formated using a "digital" representation of duration
   *
   * @param buffer The array pointed to must be able to accommodate 10 bytes
   *
   * Output examples:
   *  1234567890 (strlen)
   *  1193046:59
   */
  void toDigital(char *buffer) const {
    int h = this->hour() % 24,
        m = this->minute() % 60;

    sprintf_P(buffer, PSTR("%02i:%02i"), h, m);
  }
};

#endif // __DURATION_T__

