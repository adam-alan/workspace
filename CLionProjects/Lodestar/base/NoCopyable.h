//
// Created by zhuxingtian on 19-9-5.
//

#ifndef LODESTAR_NOCOPYABLE_H
#define LODESTAR_NOCOPYABLE_H
namespace lodestar{
    class NoCopyable {
    public:
        NoCopyable(const NoCopyable &) = delete;
        void operator=(const NoCopyable &) = delete;
    protected:
        NoCopyable() = default;
        ~NoCopyable() = default;
    };


}
#endif //LODESTAR_NOCOPYABLE_H
