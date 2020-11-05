/*
    Library to manage the time synch and system time management
*/

#include "app_priv.h"


/*
* @brief Setup the synch with the SNTP_SERVER e.g. pool.ntp.org
*  @param time_synch_notification_cb: callback function called after the synch event
* 
*/
void start_sntp_synch(void *time_sync_notification_cb){
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, SNTP_SERVER);
    sntp_set_time_sync_notification_cb(time_sync_notification_cb);
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    sntp_init();

}



