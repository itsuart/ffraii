#pragma once
extern "C" {
#include <libavutil/frame.h>
}
namespace ffraii {
    class AVFrameR final {
    public:
        using WrappedType = AVFrame*;

        AVFrameR();

        explicit AVFrameR(WrappedType resource);
        ~AVFrameR();

        // Resource types can not be copied

        AVFrameR(const AVFrameR&) = delete;
        AVFrameR& operator=(const AVFrameR&) = delete;

        // But can be moved

        AVFrameR(AVFrameR&& other);
        AVFrameR& operator=(AVFrameR&& other);

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
