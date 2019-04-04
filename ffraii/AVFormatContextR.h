#pragma once

extern "C" {
#include <libavformat/avformat.h>
}

namespace ffraii {
    class AVFormatContextR final {
    public:
        using WrappedType = AVFormatContext*;

        AVFormatContextR();

        explicit AVFormatContextR(WrappedType resource);
        ~AVFormatContextR();

        // Resource types can not be copied

        AVFormatContextR(const AVFormatContextR&) = delete;
        AVFormatContextR& operator=(const AVFormatContextR&) = delete;

        // But can be moved

        AVFormatContextR(AVFormatContextR&& other);
        AVFormatContextR& operator=(AVFormatContextR&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        // returns true iff wrapped resource is valid
        bool ok() const;

        operator WrappedType() const;

        WrappedType unwrap() const;

        // Force releasing the resource
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
