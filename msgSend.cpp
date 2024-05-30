#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

using namespace std;

// struct msg_buffer {
//     long type;
//     int a;
// };

// int main(){
//     int msgid=msgget((key_t)1234,0666 | IPC_CREAT);
//     msg_buffer message;
//     message.type=1;
//     message.a=25;
//     msgsnd(msgid,&message,sizeof(message.a),0);
//     return 0;
// }

// struct msg_buffer {
//     long type;
//     char a[100];
// };

// int main(){
//     int msgid=msgget((key_t)1245,0666 | IPC_CREAT);
//     msg_buffer message;
//     message.type=1;
//     strcpy(message.a,"this is string for test");
//     msgsnd(msgid,&message,sizeof(message.a),0);
//     return 0;
// }


// struct sensorData {
//     int a,b;
// };

// struct msg_buffer {
//     long msg_type;
//     sensorData data;
// };

// int main() {
//     int msgid = msgget((key_t)1236, 0666 | IPC_CREAT);
//     msg_buffer message;
//     message.msg_type = 1;
//     message.data.a = 25;
//     message.data.b= 1013;

//     msgsnd(msgid, &message, sizeof(message.data), 0);
//     return 0;
// }




// struct msg_buffer {
//     long msg_type;
//     int a[3];
// };

// int main() {
//     int msgid = msgget((key_t)1236, 0666 | IPC_CREAT);
//     msg_buffer message;
//     message.msg_type = 1;
//     message.a[0] = 25;
//     message.a[1] = 1013;
//     message.a[2] = 100;

//     msgsnd(msgid, &message, sizeof(message.a), 0);
//     return 0;
// }


struct msg_buffer {
    long msg_type;
    int a[2][2];
};

int main() {
    int msgid = msgget((key_t)1236, 0666 | IPC_CREAT);
    msg_buffer message;
    message.msg_type = 1;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            message.a[i][j] = i+j;
        }
    }

    msgsnd(msgid, &message, sizeof(message.a), 0);
    return 0;
}