#pragma once

extern "C" {
#include <libswscale/swscale.h>
}

namespace ffraii {
    class SwsContextR final {
    public:
        using WrappedType = SwsContext*;

        // Wraps over s_invalidValue
        SwsContextR();

        explicit SwsContextR(WrappedType resource);
        ~SwsContextR();

        // Resource types can not be copied

        SwsContextR(const SwsContextR&) = delete;
        SwsContextR& operator=(const SwsContextR&) = delete;

        // But can be moved

        SwsContextR(SwsContextR&& other);
        SwsContextR& operator=(SwsContextR&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        // returns true iff wrapped resource is valid
        bool ok() const;

        operator WrappedType() const;

        WrappedType unwrap() const;

        // Force release the resource
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
