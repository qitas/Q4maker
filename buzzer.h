

#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "types.h"
#include "fastio.h"
#include "circularqueue.h"
#include "temperature.h"

#include "MarlinConfig.h"

#define TONE_QUEUE_LENGTH 4

struct tone_t {
  uint16_t duration;
  uint16_t frequency;
};

class Buzzer {
  private:
    struct state_t {
      tone_t   tone;
      uint32_t endtime;
    } state;

  protected:
    CircularQueue<tone_t, TONE_QUEUE_LENGTH> buffer;
    void invert() {
      TOGGLE(BEEPER_PIN);
    }
    void off() {
      WRITE(BEEPER_PIN, LOW);
    }
    void on() {
      WRITE(BEEPER_PIN, HIGH);
    }

    /**
     * @brief Resets the state of the class
     * @details Brings the class state to a known one.
     */
    void reset() {
      this->off();
      this->state.endtime = 0;
    }

  public:
    Buzzer() {
      SET_OUTPUT(BEEPER_PIN);
      this->reset();
    }

    /**
     * @brief Add a tone to the queue
     * @details Adds a tone_t structure to the ring buffer, will block IO if the
     *          queue is full waiting for one slot to get available.
     * @param duration Duration of the tone in milliseconds
     * @param frequency Frequency of the tone in hertz
     */
    void tone(uint16_t const &duration, uint16_t const &frequency = 0) {
      while (buffer.isFull()) {
        this->tick();
        thermalManager.manage_heater();
      }
      this->buffer.enqueue((tone_t){duration,frequency});
    }

    /**
     * @brief Loop function
     * @details This function should be called at loop, it will take care of playing the tones in the queue.
     */
    virtual void tick() {
      const millis_t now = millis();

      if (!this->state.endtime) {
        if (this->buffer.isEmpty()) return;

        this->state.tone = this->buffer.dequeue();
        this->state.endtime = now + this->state.tone.duration;

        if (this->state.tone.frequency > 0) {
          #if ENABLED(SPEAKER)
            CRITICAL_SECTION_START;
            ::tone(BEEPER_PIN, this->state.tone.frequency, this->state.tone.duration);
            CRITICAL_SECTION_END;
          #else
            this->on();
          #endif
        }
      }
      else if (ELAPSED(now, this->state.endtime)) this->reset();
    }
};
extern Buzzer buzzer;

#endif

