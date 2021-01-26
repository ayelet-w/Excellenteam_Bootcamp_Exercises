//
// Created by ayelet on 12/16/20.
//

#ifndef PRODUCER_CONSUMER_PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_PRODUCER_CONSUMER_H


#include <iostream>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 6

using namespace std;
namespace ProducerConsumer {

    class Product{

    private:

        int m_buffer[BUFFER_SIZE];

        int m_index = 0;

        sem_t m_full,m_empty;

        pthread_mutex_t m_mutex;

        static void* produce(void* param)
        {
            Product* _this = (Product*)param;
            for (int i = 0; i < 40; ++i){
                sleep(1);
                sem_wait(&_this->m_empty);
                pthread_mutex_lock(&_this->m_mutex);
                int item = rand()%1000000;
                _this->m_buffer[_this->m_index++] = item;
                cout<<"Produced "<< item <<" iteration number: "<< i + 1 << endl;
                pthread_mutex_unlock(&_this->m_mutex);
                sem_post(&_this->m_full);
            }
        }

        static void* consume(void* param)
        {
            Product* _this = (Product*)param;
            for (int i = 0; i < 30; ++i)
            {
                sleep(1);
                sem_wait(&_this->m_full);
                pthread_mutex_lock(&_this->m_mutex);
                int item = _this->m_buffer[--_this->m_index];
                std::cout<<"Consumed "<<item << " iteration number: "<< i + 1 << endl;
                pthread_mutex_unlock(&_this->m_mutex);
                sem_post(&_this->m_empty);
            }
        }

    public:

        Product() {
            pthread_mutex_init(&m_mutex, NULL);
        }

        ~Product() {
            pthread_mutex_destroy(&m_mutex);
        }

        int run()
        {
            sem_init(&m_empty, 0, BUFFER_SIZE);
            sem_init(&m_full, 0, 0);

            std::vector<pthread_t> threads_producer;
            for (size_t i = 0; i < 3; i++)
            {
                pthread_t t;
                pthread_create(&t, NULL, Product::produce, this );
                threads_producer.push_back(t);
            }

            std::vector<pthread_t> threads_consumer;
            for (size_t i = 0; i < 4; i++)
            {
                pthread_t t;
                pthread_create(&t, NULL, Product::consume, this);
                threads_consumer.push_back(t);
            }

            for (size_t i = 0; i < 3; i++)
            {
                void* ret_value;
                pthread_join(threads_producer[i], &ret_value);
            }
            for (size_t i = 0; i < 4; i++)
            {
                void* ret_value;
                pthread_join(threads_consumer[i], &ret_value);
            }
            return m_index;
        }
   };
        void test() {
            int val = 0;
            // test it multiple times.
            for (int k = 0; k < 1; k++) {
                Product w;
                if ((val = w.run()) != 0)
                    cout << "Error on iteration no: " << k << " Products = " << val << std::endl;
            }
        }
    }

#endif //PRODUCER_CONSUMER_PRODUCER_CONSUMER_H


