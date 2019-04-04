#pragma once

#include <type_traits>

extern "C" {
#include <libavcodec/avcodec.h>
}

namespace ffraii {
    class AVCodecContextR final {
    public:
        using WrappedType = AVCodecContext*;

        AVCodecContextR();

        explicit AVCodecContextR(WrappedType resource);
        ~AVCodecContextR();

        // Resource types can not be copied

        AVCodecContextR(const AVCodecContextR&) = delete;
        AVCodecContextR& operator=(const AVCodecContextR&) = delete;

        // But can be moved

        AVCodecContextR(AVCodecContextR&& other);
        AVCodecContextR& operator=(AVCodecContextR&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        // returns true iff wrapped resource is valid
        bool ok() const;

        operator WrappedType() const;

        WrappedType unwrap() const;

        // Force release resource
        void release();

        WrappedType* p_value();

        const WrappedType* p_value() const;

        WrappedType operator->() {
            return m_resource;
        }

        const WrappedType operator->() const {
            return m_resource;
        }

        static const WrappedType s_invalidValue;

    private:
        WrappedType m_resource;
    };
}
