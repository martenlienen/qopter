// MESSAGE LED PACKING

#define MAVLINK_MSG_ID_LED 0

typedef struct __mavlink_led_t
{
 uint32_t duration; ///< Duration in ms
} mavlink_led_t;

#define MAVLINK_MSG_ID_LED_LEN 4
#define MAVLINK_MSG_ID_0_LEN 4

#define MAVLINK_MSG_ID_LED_CRC 45
#define MAVLINK_MSG_ID_0_CRC 45



#define MAVLINK_MESSAGE_INFO_LED { \
	"LED", \
	1, \
	{  { "duration", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_led_t, duration) }, \
         } \
}


/**
 * @brief Pack a led message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param duration Duration in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_led_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LED_LEN];
	_mav_put_uint32_t(buf, 0, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LED_LEN);
#else
	mavlink_led_t packet;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LED_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LED;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LED_LEN);
#endif
}

/**
 * @brief Pack a led message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param duration Duration in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_led_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LED_LEN];
	_mav_put_uint32_t(buf, 0, duration);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LED_LEN);
#else
	mavlink_led_t packet;
	packet.duration = duration;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LED_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LED;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LED_LEN);
#endif
}

/**
 * @brief Encode a led struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param led C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_led_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_led_t* led)
{
	return mavlink_msg_led_pack(system_id, component_id, msg, led->duration);
}

/**
 * @brief Encode a led struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param led C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_led_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_led_t* led)
{
	return mavlink_msg_led_pack_chan(system_id, component_id, chan, msg, led->duration);
}

/**
 * @brief Send a led message
 * @param chan MAVLink channel to send the message
 *
 * @param duration Duration in ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_led_send(mavlink_channel_t chan, uint32_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LED_LEN];
	_mav_put_uint32_t(buf, 0, duration);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, buf, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, buf, MAVLINK_MSG_ID_LED_LEN);
#endif
#else
	mavlink_led_t packet;
	packet.duration = duration;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, (const char *)&packet, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, (const char *)&packet, MAVLINK_MSG_ID_LED_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_LED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_led_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t duration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, duration);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, buf, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, buf, MAVLINK_MSG_ID_LED_LEN);
#endif
#else
	mavlink_led_t *packet = (mavlink_led_t *)msgbuf;
	packet->duration = duration;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, (const char *)packet, MAVLINK_MSG_ID_LED_LEN, MAVLINK_MSG_ID_LED_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LED, (const char *)packet, MAVLINK_MSG_ID_LED_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE LED UNPACKING


/**
 * @brief Get field duration from led message
 *
 * @return Duration in ms
 */
static inline uint32_t mavlink_msg_led_get_duration(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a led message into a struct
 *
 * @param msg The message to decode
 * @param led C-struct to decode the message contents into
 */
static inline void mavlink_msg_led_decode(const mavlink_message_t* msg, mavlink_led_t* led)
{
#if MAVLINK_NEED_BYTE_SWAP
	led->duration = mavlink_msg_led_get_duration(msg);
#else
	memcpy(led, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_LED_LEN);
#endif
}
