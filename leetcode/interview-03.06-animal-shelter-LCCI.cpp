

class AnimalShelf {
public:
    queue<vector<int>> qcat;
    queue<vector<int>> qdog;

    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
        if (animal[1] == 0)
            qcat.push(animal);
        else
            qdog.push(animal);
        //cout << "eq-" << qcat.size() << " " << qdog.size() << endl;
    }

    vector<int> dequeueAny() {
        vector<int> res;

        //cout << "deq any-" << qcat.size() << " " << qdog.size() << endl;
        if (qcat.empty() && qdog.empty())
            return {-1, -1};

        if (qdog.empty()) {
            res = qcat.front();
            qcat.pop();
        } else if (qcat.empty()) {
            res = qdog.front();
            qdog.pop();
        } else {
            if (qcat.front()[0] < qdog.front()[0]) {
                res = qcat.front();
                qcat.pop();
            } else {
                res = qdog.front();
                qdog.pop();
            }
        }

        return res;
    }

    vector<int> dequeueDog() {
        //cout << "deq dog-" << qcat.size() << " " << qdog.size() << endl;
        if (qdog.empty())
            return {-1, -1};
        vector<int> res = qdog.front();
        qdog.pop();
        return res;
    }

    vector<int> dequeueCat() {
        //cout << "deq cat-" << qcat.size() << " " << qdog.size() << endl;
        if (qcat.empty())
            return {-1, -1};
        vector<int> res = qcat.front();
        qcat.pop();
        return res;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
