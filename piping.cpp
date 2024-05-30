#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

// int main(){
//     int fd[2];
//     pipe(fd);
//     int pid=fork();
//     if(pid==0){
//         int a=5;
//         write(fd[1],&a,sizeof(a));
//         exit(0);
//     }
//     wait(NULL);
//     int a;
//     read(fd[0],&a,sizeof(a));
//     cout<<a<<endl;
//     return 0;
// }


// int main(){
//     int fd[2];
//     pipe(fd);
//     int pid=fork();
//     if(pid==0){
//         string a="ghsgh dfghdf dfyuyu";
//         write(fd[1],a.c_str(),sizeof(a));
//         exit(0);
//     }
//     wait(NULL);
//     char a[100];
//     read(fd[0],a,sizeof(a));
//     cout<<a<<endl;
//     return 0;
// }

// struct sensorData {
//     int a,b;
// };
// int main(){
//     int fd[2];
//     pipe(fd);
//     int pid=fork();
//     if(pid==0){
//         sensorData a={1,2};
//         write(fd[1],&a,sizeof(sensorData));
//         exit(0);
//     }
//     wait(NULL);
//     sensorData a;
//     read(fd[0],&a,sizeof(sensorData));
//     cout<<a.a<<" "<<a.b<<endl;
//     return 0;
// }



// int main(){
//     int fd[2];
//     pipe(fd);
//     int pid=fork();
//     if(pid==0){
//         int a[]={1,2,3};
//         write(fd[1],&a,sizeof(a));
//         exit(0);
//     }
//     wait(NULL);
//     int a[3];
//     read(fd[0],&a,sizeof(a));
//     for(int i=0;i<3;i++){
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

int main(){
    int fd[2];
    pipe(fd);
    int pid=fork();
    if(pid==0){
        int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        write(fd[1],&a,sizeof(a));
        exit(0);
    }
    wait(NULL);
    int a[3][3];
    read(fd[0],&a,sizeof(a));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}