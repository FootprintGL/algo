

class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> tbl;

    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        cleartimeout(currentTime);
        tbl[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        cleartimeout(currentTime);

        if (tbl.count(tokenId)) {
            tbl[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        cleartimeout(currentTime);
        return tbl.size();
    }

    void cleartimeout(int currentTime) {
        /* 删除过期token */
        /*
        for (auto &[tokenId, time] : tbl) {
            if (time <= currentTime)
                tbl.erase(tokenId);
        }
        */
        for (auto iter = tbl.begin(); iter != tbl.end();) {
            if (iter->second <= currentTime)
                tbl.erase(iter++);
            else
                iter++;
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
