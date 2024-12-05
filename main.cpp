#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Packet.h"
#include "Channel.h"
#include "User.h"
#include "WiFi4.h"
#include "WiFi5.h"
#include "WiFi6.h"

using namespace std ;

void simulate(vector<User> users, Channel& channel) {

    cout << "<<========================================= START ==================================>>\n";

    cout << "Simulating for " << users.size() << " Users\n";

    // Simulate WiFi 4
    WiFi4 wifi4(users, channel);
    double totalTimeWiFi4 = wifi4.transmitData();
    cout << "WiFi 4 Throughput: " << wifi4.throughput(totalTimeWiFi4) << " Mbps" << endl;
    cout << "WiFi 4 Average Latency: " << wifi4.latency(totalTimeWiFi4) << " seconds" << endl;
    cout << "WiFi 4 Maximum Latency: " << wifi4.getMaxLatency() << " seconds" << endl;

    // Simulate WiFi 5
    WiFi5 wifi5(users, channel);
    double totalTimeWiFi5 = wifi5.transmitData();
    cout << "WiFi 5 Throughput: " << wifi5.throughput(totalTimeWiFi5) << " Mbps" << endl;
    cout << "WiFi 5 Average Latency: " << wifi5.latency(totalTimeWiFi5) << " seconds" << endl;
    cout << "WiFi 5 Maximum Latency: " << wifi5.getMaxLatency() << " seconds" << endl;

    // Simulate WiFi 6
    WiFi6 wifi6(users, channel);
    double totalTimeWiFi6 = wifi6.transmitData();
    cout << "WiFi 6 Throughput: " << wifi6.throughput(totalTimeWiFi6) << " Mbps" << endl;
    cout << "WiFi 6 Average Latency: " << wifi6.latency(totalTimeWiFi6) << " seconds" << endl;
    cout << "WiFi 6 Maximum Latency: " << wifi6.getMaxLatency() << " seconds" << endl;

    cout << "<<========================================= END ==================================>>\n\n\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Channel channel(20.0f);
    vector<User> users;

    users.emplace_back(0, Packet(1024));
    simulate(users, channel);

    for (int i = 1; i < 10; ++i) {
        users.emplace_back(i, Packet(1024));
    }
    simulate(users, channel);

    for (int i = 10; i < 100; ++i) {
        users.emplace_back(i, Packet(1024));
    }
    simulate(users, channel);

    return 0;
}