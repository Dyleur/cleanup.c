#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include "ipc_config.h"

int main() {
    key_t shm_key, msg_key_serv_to_tab, msg_key_tab_to_prod;
    int shm_id, msg_id_serv_to_tab, msg_id_tab_to_prod;

    shm_key = ftok(SHM_KEY_PATH, PROJ_ID_SHM);
    msg_key_serv_to_tab = ftok(MSG_KEY_SERV_TO_TAB, PROJ_ID_MSG_SERV_TO_TAB);
    msg_key_tab_to_prod = ftok(MSG_KEY_TAB_TO_PROD, PROJ_ID_MSG_TAB_TO_PROD);

    shm_id = shmget(shm_key, 0, 0666);
    msg_id_serv_to_tab = msgget(msg_key_serv_to_tab, 0666);
    msg_id_tab_to_prod = msgget(msg_key_tab_to_prod, 0666);

    if (shm_id != -1) shmctl(shm_id, IPC_RMID, NULL);
    if (msg_id_serv_to_tab != -1) msgctl(msg_id_serv_to_tab, IPC_RMID, NULL);
    if (msg_id_tab_to_prod != -1) msgctl(msg_id_tab_to_prod, IPC_RMID, NULL);

    printf("Nettoyage complet des ressources IPC effectué.\n");
    return 0;
}
