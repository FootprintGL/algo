

#include <semaphore.h>

class FizzBuzz {
private:
    int n;

public:
    /* 信号量同步 */
    sem_t f, b, fb, num;

    FizzBuzz(int n) {
        this->n = n;
        sem_init(&f, 0, 0);
        sem_init(&b, 0, 0);
        sem_init(&fb, 0, 0);
        sem_init(&num, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 15) {
                sem_wait(&f);
                printFizz();
                sem_post(&num);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 15) {
                sem_wait(&b);
                printBuzz();
                sem_post(&num);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                sem_wait(&fb);
                printFizzBuzz();
                sem_post(&num);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&num);
            if (i % 15 == 0) {
                sem_post(&fb);
            } else if (i % 3 == 0) {
                sem_post(&f);
            } else if (i % 5 == 0) {
                sem_post(&b);
            } else {
                printNumber(i);
                sem_post(&num);
            }
        }
    }
};
