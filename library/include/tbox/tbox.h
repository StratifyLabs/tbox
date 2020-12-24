// Copyright 2020-2021 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md

#ifndef TBOX_TBOX_H_
#define TBOX_TBOX_H_

// run whenever the core clock changes
void tbox_calibrate_swo();

typedef struct {
  const char *name;
  const char *version;
  const char *build_id;
} tbox_initialize_t;
void tbox_initialize(const tbox_initialize_t *options);

// fast, lightweight printf()-ing
void tbox_printf(const char *fmt, ...);
void tbox_log(int level, const char *fmt, ...);

// super-fast, variable tracing
void tbox_start_trace(int channel, const char *fmt);
void tbox_trace_value(int channel, int value);

// use hardware to watch a variable
void tbox_start_watching(int channel, const char *fmt, const void *data,
                         int size);
void tbox_stop_watching(int channel);

// for call graphs and cycle counting
void tbox_enter_function();
void tbox_exit_function();

void tbox_enable_program_counter_sampling(int period);
void tbox_disable_program_counter_sampling();

// control the Toolbox logic input
void tbox_logic_start_capture(int device_port);
void tbox_logic_stop_capture(int device_port);

// control the Toolbox uart
typedef struct {
  int bitrate;
  int stop_bits;
  int parity;
} tbox_uart_attributes_t;
void tbox_uart_set_attributes(const tbox_uart_attributes_t *attributes);
void tbox_uart_write(const void *data, int nbyte);
void tbox_uart_start_capture();
void tbox_uart_stop_capture();

// control the Toolbox Analog
typedef struct {

} tbox_analog_attributes_t;
void tbox_analog_set_attributes(const tbox_analog_attributes_t *attributes);
void tbox_analog_start_capture();
void tbox_analog_stop_capture();
typedef struct {
  int waveform;
  int amplitude;
  int offset;
  int frequency;
} tbox_analog_write_t;
void tbox_analog_write(const tbox_analog_write_t *options);

// control the Toolbox SPI
typedef struct {
  int bitrate;
  int mode;
  int width;
} tbox_spi_attributes_t;
void tbox_spi_set_attributes(const tbox_spi_attributes_t *attributes);
void tbox_spi_write(const void *data, int nbyte);
void tbox_spi_start_capture();
void tbox_spi_stop_capture();

// control the Toolbox I2C
void tbox_i2c_set_attributes();
void tbox_i2c_write(const void *data, int nbyte);
void tbox_i2c_start_capture();
void tbox_i2c_stop_capture();

#endif // TBOX_TBOX_H_
