//
// Created by nireus on 2018/5/16.
//

#ifndef XPLAY_IPLAYERPROXY_H
#define XPLAY_IPLAYERPROXY_H


#include <mutex>
#include "IPlayer.h"

class IPlayerProxy : public IPlayer {
public:
    static IPlayerProxy *Get() {
        static IPlayerProxy px;
        return &px;
    }

    void Init(void *vm = 0);

    virtual bool Open(const char *path);
    virtual void Close();

    virtual bool Start();

    virtual bool InitView(void *win);

protected:
    IPlayerProxy() {}

    IPlayer *player = 0;
    std::mutex mux;
};


#endif //XPLAY_IPLAYERPROXY_H
