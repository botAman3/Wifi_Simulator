#ifndef USER_H
#define USER_H

#include "Packet.h"

class User {
public:
    User(int id, Packet packet) : userId(id), packet(packet) {}

    Packet sendPacket() const {
        return packet;
    }

private:
    int userId;
    Packet packet;
};

#endif // USER_H