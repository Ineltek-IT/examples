/*
    Library to manage the time synch and system time management
*/

#include "app_priv.h"

void test_library(){
    printf("test riuscito");
}

void start_sntp_synch(void *time_sync_notification_cb){
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_set_time_sync_notification_cb(time_sync_notification_cb);
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    sntp_init();

}