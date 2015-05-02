/** @file
 *	@brief MAVLink comm protocol testsuite generated from cqql.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef CQQL_TESTSUITE_H
#define CQQL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_cqql(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_cqql(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_led(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_led_t packet_in = {
		963497464
    };
	mavlink_led_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.duration = packet_in.duration;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_led_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_led_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_led_pack(system_id, component_id, &msg , packet1.duration );
	mavlink_msg_led_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_led_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.duration );
	mavlink_msg_led_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_led_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_led_send(MAVLINK_COMM_1 , packet1.duration );
	mavlink_msg_led_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cqql(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_led(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // CQQL_TESTSUITE_H
