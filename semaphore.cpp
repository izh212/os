#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

sem_t s1,s2,s3,s4;

void* A(void* arg){
    cout<<"A ";
    sem_post(&s1);
    return nullptr;
}

void* B(void* arg){
    sem_wait(&s1);
    cout<<"B ";
    sem_post(&s2);
    sem_post(&s2);
    return nullptr;
}

void* C(void* arg){
    sem_wait(&s2);
    cout<<"C ";
    sem_post(&s4);
    return nullptr;
}

void* D(void* arg){
    sem_wait(&s2);
    cout<<"D ";
    sem_post(&s3);
    return nullptr;
}

void* E(void* arg){
    sem_wait(&s3);
   cout<<"E ";
   sem_post(&s4);
    return nullptr;
}

void* F(void* arg){
    sem_wait(&s4);
    sem_wait(&s4);
    cout<<"F ";
    return nullptr;
}

int main(){
    sem_init(&s1,0,0);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);
    sem_init(&s4,0,0);
    pthread_t a,b,c,d,e,f;
    pthread_create(&a,NULL,A,NULL);
    pthread_create(&b,NULL,B,NULL);
    pthread_create(&c,NULL,C,NULL);
    pthread_create(&d,NULL,D,NULL);
    pthread_create(&e,NULL,E,NULL);
    pthread_create(&f,NULL,F,NULL);
    pthread_join(a,NULL);
    pthread_join(b,NULL);
    pthread_join(c,NULL);
    pthread_join(d,NULL);
    pthread_join(e,NULL);
    pthread_join(f,NULL);
    return 0;
}