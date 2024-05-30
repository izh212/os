#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

// int main(){
//     int shmid;
//     void* shared_memory;
//     // int a=5;

//     shmid=shmget((key_t)1234,sizeof(int), 0666|IPC_CREAT);
//     shared_memory=shmat(shmid,NULL,0);

//     // memcpy(shared_memory,&a,sizeof(int));
//     int* t=(int*)shared_memory;
//     cout<<"data : "<<*t<<endl;
// }

// int main(){
//     int shmid;
//     void* shared_memory;
//     // string a="this is string for testing shm";

//     shmid=shmget((key_t)1235,sizeof(string), 0666|IPC_CREAT);
//     shared_memory=shmat(shmid,NULL,0);

//     // strcpy((char*)shared_memory,a.c_str());
//     cout<<"data : "<<(char*)shared_memory<<endl;
// }


struct sdata{
    int a,b;
};

// int main(){
//     int shmid;
//     void* shared_memory;
//     // sdata s={1,2};

//     shmid=shmget((key_t)1236,sizeof(sdata), 0666|IPC_CREAT);
//     shared_memory=shmat(shmid,NULL,0);

//     // memcpy(shared_memory,&s,sizeof(sdata));
//     sdata* t=(sdata*)shared_memory;
//     cout<<"data : "<<t->a<<" "<<t->b<<endl;
// }


// int main(){
//     int shmid;
//     void* shared_memory;
//     // int a[]={1,2,3};

//     shmid=shmget((key_t)1237,3*sizeof(int), 0666|IPC_CREAT);
//     shared_memory=shmat(shmid,NULL,0);

//     // memcpy(shared_memory,&a,sizeof(a));
//     int* t=(int*)shared_memory;
//     for(int i=0;i<3;i++){
//         cout<<t[i]<<" ";
//     };
// }


int main(){
    int shmid;
    void* shared_memory;
    int a[3][3];;

    shmid=shmget((key_t)1238,3*3*sizeof(int), 0666|IPC_CREAT);
    shared_memory=shmat(shmid,NULL,0);

    // memcpy(shared_memory,a,sizeof(a));
    int (*t)[3] = static_cast<int(*)[3]>(shared_memory);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}