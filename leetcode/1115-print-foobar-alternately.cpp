

class FooBar {
private:
    int n;
    /* flag为true输出foo，flag为false，输出bar */
    bool flag;

public:
    FooBar(int n) {
        this->n = n;
        flag = true;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (!flag) {
                /* 放弃cup让其它线程调度 */
                this_thread::yield();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = false;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (flag) {
                /* 放弃cup让其它线程调度 */
                this_thread::yield();
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = true;
        }
    }
};


/* 超时 */
class FooBar {
private:
    int n;
    /* flag为true输出foo，flag为false，输出bar */
    bool flag;

public:
    FooBar(int n) {
        this->n = n;
        flag = true;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (!flag)
                continue;
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = false;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (flag)
                continue;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = true;
        }
    }
};
