#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t sensor_code;
    uint8_t work_mode;
    uint8_t alarm_flag;
    uint8_t channel_num;
} TelemetryData;

uint16_t pack_telemetry(uint8_t sensor, uint8_t mode, uint8_t alarm, uint8_t channel);
TelemetryData unpack_telemetry(uint16_t packet);

int main(void) {
    uint8_t sensor = 0xA5;
    uint8_t mode = 0x0C;
    uint8_t alarm = 0x01;
    uint8_t channel = 0x06;

    printf("Original values:\n");
    printf("Sensor: %u, Mode: %u, Alarm: %u, Channel: %u\n\n", sensor, mode, alarm, channel);

    uint16_t packet = pack_telemetry(sensor, mode, alarm, channel);
    printf("Packed word: 0x%04X\n\n", packet);

    TelemetryData restored = unpack_telemetry(packet);
    printf("Unpacked values:\n");
    printf("Sensor: %u, Mode: %u, Alarm: %u, Channel: %u\n", 
           restored.sensor_code, restored.work_mode, restored.alarm_flag, restored.channel_num);

    return 0;
}

uint16_t pack_telemetry(uint8_t sensor, uint8_t mode, uint8_t alarm, uint8_t channel) {
    uint16_t packet = 0;
    packet |= (sensor & 0xFF);
    packet |= ((mode & 0x0F) << 8);
    packet |= ((alarm & 0x01) << 12);
    packet |= ((channel & 0x07) << 13);
    return packet;
}

TelemetryData unpack_telemetry(uint16_t packet) {
    TelemetryData data;
    data.sensor_code = packet & 0xFF;
    data.work_mode = (packet >> 8) & 0x0F;
    data.alarm_flag = (packet >> 12) & 0x01;
    data.channel_num = (packet >> 13) & 0x07;
    return data;
}
