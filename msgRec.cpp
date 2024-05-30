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
//     msgrcv(msgid,&message,sizeof(message.a),1,0);
//     cout<<"message : "<<message.a<<endl;
//     return 0;
// }

// struct msg_buffer {
//     long type;
//     char a[100];
// };

// int main(){
//     int msgid=msgget((key_t)1245,0666 | IPC_CREAT);
//     msg_buffer message;
//     msgrcv(msgid,&message,sizeof(message.a),1,0);
//     cout<<"message : "<<message.a<<endl;
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

//     msgrcv(msgid, &message, sizeof(message.data), 1, 0);
//     cout << "Received sensor data: Temperature = " << message.data.a
//          << ", Pressure = " << message.data.b << endl;
//     return 0;
// }


// struct msg_buffer {
//     long msg_type;
//     int a[3];
// };

// int main() {
//     int msgid = msgget((key_t)1236, 0666 | IPC_CREAT);
//     msg_buffer message;

//     msgrcv(msgid, &message, sizeof(message.a), 1,0);
//     for(int i=0;i<3;i++){
//         cout<<message.a[i]<<" ";
//     }
//     return 0;
// }

struct msg_buffer {
    long msg_type;
    int a[2][2];
};

int main() {
    int msgid = msgget((key_t)1236, 0666 | IPC_CREAT);
    msg_buffer message;

    msgrcv(msgid, &message, sizeof(message.a), 1,0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<message.a[i][j]<<" ";
        }
    }
    return 0;
}