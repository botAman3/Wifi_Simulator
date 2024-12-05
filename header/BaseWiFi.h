#ifndef BASEWIFI_H
#define BASEWIFI_H

#include "User.h"
#include <vector>
#include "Channel.h"

class BaseWiFi {
public:
    BaseWiFi(std::vector<User> users, Channel & channel) 
        : users(users), channel(channel), maxLatency(0.0f), totalLatency(0.0f) {}

    double throughput(double totalTime) {
        double totalSize = 0;
        for (const auto& user : users) {
            totalSize += user.sendPacket().getSize();
        }
        return (totalSize * 8.0f / 1e6f) / totalTime; // Mbps
    }

    double latency(double totalTime) {
        return totalTime / users.size(); // Average latency
    }

    double getMaxLatency() const {
        return maxLatency;
    }

    double getAverageLatency() const {
        return totalLatency / users.size(); // Average latency
    }

protected:
    std::vector<User> users;
    Channel& channel;
    double maxLatency;
    double totalLatency;
};

#endif 