


class Solution {
public:
    int clockwise(vector<int> &distance, int start, int destination) {
        int sum = 0;
        int i = start;

        while (i != destination) {
            sum += distance[i];
            i++;
            i %= distance.size();
        }

        /* Dead Loop ???
        for (int i = start; i != destination; i++) {
            //cout << i << " " << destination << endl;
            i %= distance.size();
            sum += distance[i];
            cout << i << " " << destination << " " << distance[i] << endl;
            //if (i == destination)
                //break;
        }*/
        //cout << sum << endl;
        return sum;
    }

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        return min(clockwise(distance, start, destination), clockwise(distance, destination, start));
    }
};
