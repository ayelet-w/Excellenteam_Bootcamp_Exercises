//
// Created by ayelet on 12/16/20.
//
//
//#include "ex.h"
//vector<int> getBox() { return box; }
//int run() {
//    std::vector<pthread_t> threads;
//    for (size_t i = 0; i < 3; i++) {
//        pthread_t t;
//        pthread_create(&t, NULL, Product::producer, this);
//        threads.push_back(t);
//    }
//    for (size_t i = 0; i < 3; i++) {
//        void *ret_value;
//        pthread_join(threads[i], &ret_value);
//    }
//    std::vector<pthread_t> threads_consumer;
//    for (size_t i = 0; i < 4; i++) {
//        pthread_t t;
//        pthread_create(&t, NULL, Product::consumer, this);
//        threads.push_back(t);
//    }
//    for (size_t i = 0; i < 4; i++) {
//        void *ret_value;
//        pthread_join(threads_consumer[i], &ret_value);
//    }
//    return box.size();
//}
//
//vector<int> box;
//
//static void *producer(void *param) {
//    Product *_this = (Product *) param;
//    for (int i = 0; i < 40; ++i) {
//        pthread_mutex_lock(&_this->mutex);
//        int product = rand() % 1000000;
//        _this->box.push_back(product);
//        cout << "Producer iteration " << i << "the product: " << product << endl;
//        pthread_mutex_unlock(&_this->mutex);
//    }
//    return NULL;
//}
//
//static void *consumer(void *param) {
//    Product *_this = (Product *) param;
//    for (int i = 0; i < 30; ++i) {
//        pthread_mutex_lock(&_this->mutex);
//        int product = _this->box[_this->box.size()];
//        _this->box.resize(_this->box.size() - 1);
//        cout << "Consumer iteration " << i << "the product: " << product << endl;
//        pthread_mutex_unlock(&_this->mutex);
//    }
//    return NULL;
//}
